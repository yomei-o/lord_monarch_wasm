"""Flow-following 16-bit disassembler for PROG.BIN.

    python tools/lmdis.py map                    # coverage, function list
    python tools/lmdis.py fn 0x5db7              # one function
    python tools/lmdis.py dis 0x8de0 0x40        # a range, at real boundaries
    python tools/lmdis.py xref 0x8e0c            # who reaches this
    python tools/lmdis.py imm 0x8e0c 6           # ... and the immediates first
    python tools/lmdis.py ports                  # every in/out, by port
    python tools/lmdis.py mem 0x2400 0x2600      # who touches this RAM range
    python tools/lmdis.py strings                # what PROG.DAT holds

Why not a linear sweep: there are data tables between the functions, and the
code is hand-written and reuses bytes.  Following flow from the entry point
gives boundaries that are right by construction.

Two things this has to do that an off-the-shelf disassembler will not:

* **8086 undocumented forms.**  `FE /2../7` is INC/DEC on an 8086 - only bit 0
  of the reg field is decoded - and both capstone and objdump reject it, which
  desynchronises everything after the rejection.  Decoded here by hand.
* **Segments.**  PROG.BIN is loaded at 1000:0000 and immediately does
  `xor sp,sp / mov ds,sp`, so **CS = 0x1000 but DS = 0**.  An address in the
  listing is a file offset and a code address at once, while every `[0x1234]`
  operand is *linear* low memory - PROG.DAT sits at 0x1000 and the work area
  above it - and has nothing to do with this file's contents.
"""
import os
import struct
import sys

import capstone

import lmz

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CODE = os.path.join(ROOT, 'disk', 'PROG.BIN')
DATA = os.path.join(ROOT, 'disk', 'PROG.DAT')
ENTRY = 0x0000
DAT_BASE = 0x1000               # PROG.DAT is read to 0000:1000 by the boot sector

PORTS = {
    0x00: 'PIC ICW/EOI', 0x02: 'PIC mask', 0x0a: 'PIC2 mask',
    0x0c: 'FM addr', 0x0e: 'FM data', 0x31: 'system port',
    0x32: 'sound sw', 0x40: '8255 A', 0x42: '8255 B', 0x43: '8255 ctrl',
    0x60: 'GDC char', 0x62: 'GDC char', 0x64: 'VSYNC set', 0x68: 'CRT mode',
    0x6a: 'CRT mode 2', 0x6c: 'border', 0x6e: 'border',
    0x71: 'PIT ctrl', 0x73: 'PIT ch0', 0x75: 'PIT ch1', 0x77: 'PIT ch2',
    0x7c: 'GRCG mode', 0x7e: 'GRCG tile',
    0xa0: 'GDC gfx', 0xa2: 'GDC gfx', 0xa4: 'display page',
    0xa6: 'draw page', 0xa8: 'PAL index', 0xaa: 'PAL green',
    0xac: 'PAL red', 0xae: 'PAL blue',
    0x188: 'FM addr(26K)', 0x18a: 'FM data(26K)', 0x18c: 'FM addr2',
    0x18e: 'FM data2',
}

COND = ('je', 'jz', 'jne', 'jnz', 'jl', 'jnl', 'jg', 'jng', 'jle', 'jge',
        'jb', 'jnb', 'jbe', 'jae', 'ja', 'js', 'jns', 'jo', 'jno', 'jp',
        'jnp', 'jcxz', 'loop', 'loope', 'loopne')
STOP = ('ret', 'retf', 'iret', 'hlt', 'ljmp')

REG8 = ('al', 'cl', 'dl', 'bl', 'ah', 'ch', 'dh', 'bh')


class Ins:
    """Just enough of capstone's instruction to print and follow."""

    def __init__(self, address, size, raw, mnemonic, op_str):
        self.address = address
        self.size = size
        self.bytes = raw
        self.mnemonic = mnemonic
        self.op_str = op_str


def load(path):
    """The file as the machine sees it: unpacked.

    Both PROG.BIN and PROG.DAT go through the boot sector's LZSS - see lmz.py -
    so the bytes on the disk are not the bytes that run.  Unpacking here rather
    than requiring a separate step is the difference between 80% of the file
    decoding and all of it.
    """
    with open(path, 'rb') as f:
        return lmz.unpack(f.read())[0]


class Dis:
    def __init__(self, data):
        self.data = data
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
        self.md.detail = False

    def at(self, a):
        """One instruction, filling in what capstone will not decode."""
        if a < 0 or a >= len(self.data):
            return None
        got = list(self.md.disasm(self.data[a:a + 16], a, count=1))
        if got:
            i = got[0]
            return Ins(i.address, i.size, i.bytes, i.mnemonic, i.op_str)
        b = self.data[a]
        # FE /r with reg > 1: an 8086 decodes only bit 0 of the reg field, so
        # /2 /4 /6 are INC and /3 /5 /7 are DEC.  Register form (mod = 11) only,
        # which is all this binary uses.
        if b == 0xfe and a + 1 < len(self.data):
            m = self.data[a + 1]
            if (m >> 6) == 3:
                name = 'dec' if ((m >> 3) & 1) else 'inc'
                return Ins(a, 2, self.data[a:a + 2], name, REG8[m & 7])
        return None


def target(ins):
    try:
        return int(ins.op_str, 16) & 0xffff
    except ValueError:
        return None


class Prog:
    def __init__(self, data, seeds=(ENTRY,)):
        self.dis = Dis(data)
        self.data = data
        self.ins = {}
        self.xref = {}
        self.calls = set()
        self.bad = set()
        self.walk(list(seeds))

    def ref(self, to, kind, frm):
        if 0 <= to < len(self.data):
            self.xref.setdefault(to, []).append((kind, frm))

    def walk(self, work):
        seen = set()
        while work:
            a = work.pop()
            while 0 <= a < len(self.data) and a not in seen:
                seen.add(a)
                ins = self.dis.at(a)
                if ins is None:
                    self.bad.add(a)
                    break
                self.ins[a] = ins
                mn, t = ins.mnemonic, target(ins)
                if mn == 'call':
                    if t is not None and t < len(self.data):
                        self.ref(t, 'call', a)
                        self.calls.add(t)
                        work.append(t)
                elif mn in COND:
                    if t is not None:
                        self.ref(t, 'jcc', a)
                        work.append(t)
                elif mn == 'jmp':
                    if t is not None:
                        self.ref(t, 'jmp', a)
                        work.append(t)
                    break
                elif mn in STOP:
                    break
                a += ins.size

    def note(self, ins):
        if ins.mnemonic in ('in', 'out'):
            for p, what in PORTS.items():
                s = '0x%x' % p
                if ins.op_str.split(', ')[0] == s or \
                   ins.op_str.split(', ')[-1] == s:
                    return what
        t = target(ins)
        if t is not None and t in self.calls:
            return '-> sub_%04x' % t
        return ''

    def line(self, a):
        ins = self.ins.get(a)
        if ins is None:
            return '%04x  %-20s (data %02x)' % (a, '%02x' % self.data[a],
                                                self.data[a])
        label = 'sub_%04x:' % a if a in self.calls else ''
        return '%04x  %-18s %-32s %-11s %s' % (
            a, ins.bytes.hex(), '%s %s' % (ins.mnemonic, ins.op_str), label,
            self.note(ins))

    def body(self, start):
        out, work, seen = [], [start], set()
        while work:
            a = work.pop()
            while a in self.ins and a not in seen:
                seen.add(a)
                out.append(a)
                ins = self.ins[a]
                mn, t = ins.mnemonic, target(ins)
                if mn in COND:
                    if t is not None:
                        work.append(t)
                elif mn == 'jmp':
                    if t is not None and t not in self.calls:
                        work.append(t)
                    break
                elif mn in STOP:
                    break
                a += ins.size
        return sorted(set(out))


# Word tables that only an indexed `jmp` reaches, so following flow cannot find
# what is in them.  Each entry is (address, count).
#
#   0x3a47  the unit order handlers.  The dispatcher at 0x385a does
#           `mov bl,[si+0x0a] / and bx,0x0f / add bx,bx / jmp cs:[bx+0x3a47]`,
#           so the low nibble of a unit's byte at +0x0a picks one of sixteen.
JUMP_TABLES = (
    (0x3a47, 16),
    # sub_2786 dispatches on [0x34ca], the mode the panel is in: eight
    # handlers, one per command icon.
    (0x2a8a, 8),
    # sub_1175, the sound sequence's commands 0xf0..0xff.  It subtracts 0xf0,
    # doubles, and jumps through this table, having already fetched one operand
    # byte - so every one of the sixteen takes at least one.
    (0x11a6, 16),
)


# The game panel's fourteen commands are called through a table that lives in
# PROG.DAT, not in the code, so nothing in PROG.BIN points at them: they have to
# be named here.  DS:0x202d, read with tools/lmz.py, holds
#   1afa 1b5f 1c06 1c36 1c21 1c4d 1cb0 2368 1ee5 1e0f 1ff3 2081 206c 203e
# which is icon 0..13 in the order sub_4db2 walks them (two columns, seven rows).
PANEL_HANDLERS = (0x1afa, 0x1b5f, 0x1c06, 0x1c36, 0x1c21, 0x1c4d, 0x1cb0,
                  0x2368, 0x1ee5, 0x1e0f, 0x1ff3, 0x2081, 0x206c, 0x203e)


def seeds_from_tables(data):
    out = set()
    for at, n in JUMP_TABLES:
        for i in range(n):
            if at + i * 2 + 2 > len(data):
                break
            v = struct.unpack_from('<H', data, at + i * 2)[0]
            if v < len(data):
                out.add(v)
    return out


def seeds_from_calls(data):
    """Every plausible near-call target, so the sweep starts everywhere the
    code actually calls into rather than only where flow happens to reach."""
    out = {ENTRY} | seeds_from_tables(data) | set(PANEL_HANDLERS)
    for i in range(len(data) - 3):
        if data[i] == 0xe8:
            t = (i + 3 + struct.unpack_from('<h', data, i + 1)[0]) & 0xffff
            if t < len(data):
                out.add(t)
    return out


def mem_operands(p, lo, hi):
    """Instructions whose absolute [imm16] operand lands in a range."""
    hits = []
    for a, ins in sorted(p.ins.items()):
        s = ins.op_str
        k = s.find('[0x')
        if k < 0:
            continue
        end = s.find(']', k)
        try:
            v = int(s[k + 3:end], 16)
        except ValueError:
            continue
        if lo <= v <= hi:
            hits.append((a, v, ins))
    return hits


def strings():
    d = load(DATA)
    out, i = [], 0
    while i < len(d):
        j = d.find(b'\0', i)
        if j < 0:
            break
        s = d[i:j]
        if len(s) >= 4:
            try:
                t = s.decode('shift_jis')
            except UnicodeDecodeError:
                t = None
            if t and all(c >= ' ' or c in '\t' for c in t):
                out.append((i, i + DAT_BASE, t))
        i = j + 1
    return out


def main():
    what = sys.argv[1] if len(sys.argv) > 1 else 'map'
    if what == 'strings':
        for off, lin, t in strings():
            print('DAT+%04x  DS:%04x  %s' % (off, lin, t))
        return

    data = load(CODE)
    p = Prog(data, seeds_from_calls(data))

    if what == 'map':
        covered = sum(i.size for i in p.ins.values())
        print('%d instructions cover %d of %d bytes (%.1f%%)' %
              (len(p.ins), covered, len(data), 100.0 * covered / len(data)))
        print('%d call targets, %d addresses that would not decode' %
              (len(p.calls), len(p.bad)))
        print()
        print('functions, by number of callers:')
        rank = sorted(p.calls, key=lambda t: -len(p.xref.get(t, [])))
        for t in rank[:30]:
            print('   sub_%04x  %3d callers  %3d instructions' %
                  (t, len(p.xref.get(t, [])), len(p.body(t))))
    elif what == 'fn':
        for a in p.body(int(sys.argv[2], 16)):
            print(p.line(a))
    elif what == 'dis':
        a = int(sys.argv[2], 16)
        end = a + (int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x60)
        while a < end:
            print(p.line(a))
            a += p.ins[a].size if a in p.ins else 1
    elif what == 'xref':
        t = int(sys.argv[2], 16)
        for kind, frm in p.xref.get(t, []):
            print('%-5s from %04x' % (kind, frm))
        print('%d reference(s)' % len(p.xref.get(t, [])))
    elif what == 'imm':
        t = int(sys.argv[2], 16)
        n = int(sys.argv[3]) if len(sys.argv) > 3 else 6
        for kind, frm in p.xref.get(t, []):
            print('=== %s from %04x' % (kind, frm))
            for a in [x for x in sorted(p.ins) if x < frm][-n:]:
                print('    ' + p.line(a))
    elif what == 'ports':
        by = {}
        for a, ins in sorted(p.ins.items()):
            if ins.mnemonic in ('in', 'out'):
                by.setdefault(p.note(ins) or ins.op_str, []).append(a)
        for k in sorted(by, key=lambda k: -len(by[k])):
            print('%-16s %3d: %s' % (k, len(by[k]),
                                     ' '.join('%04x' % a for a in by[k][:14])))
    elif what == 'mem':
        lo = int(sys.argv[2], 16)
        hi = int(sys.argv[3], 16) if len(sys.argv) > 3 else lo
        for a, v, ins in mem_operands(p, lo, hi):
            print('%04x  %-30s -> DS:%04x' %
                  (a, '%s %s' % (ins.mnemonic, ins.op_str), v))
    else:
        raise SystemExit(__doc__)


if __name__ == '__main__':
    main()
