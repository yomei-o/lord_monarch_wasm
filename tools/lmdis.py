"""Recursive-descent 16-bit disassembler for PROG.BIN.

    python tools/lmdis.py dis 0x8de0 0x40      # a range, using known boundaries
    python tools/lmdis.py fn  0x8de1           # one function, following flow
    python tools/lmdis.py xref 0x8e0c          # who reaches this address
    python tools/lmdis.py imm 0x8e0c           # ... and the immediates set first
    python tools/lmdis.py map                  # coverage summary
    python tools/lmdis.py ports                # every in/out, grouped by port

A *linear* sweep desynchronises constantly here: the code is hand-written and
reuses bytes (0x8e22 is a `rep` prefix that a jump lands on so the loop re-runs
the store), and jump tables sit between functions.  Guessing a start offset and
reading forward produced `aam`/`ljmp` nonsense that looked like encryption but
was just a boundary being off by one.  Following flow from the entry point
instead gives boundaries that are correct by construction.

Addressing, which is the thing that trips up every tool pointed at this file:
PROG.BIN is loaded at 1000:0000 and immediately does `xor sp,sp / mov ds,sp`,
so **CS = 0x1000 but DS = 0**.  An address in this listing is a file offset and
a CS-relative code address at once, while every `[0x1234]` operand is *linear*
low memory - PROG.DAT's load area at 0x1000 and the work area above it - and has
nothing to do with this file's contents.
"""
import os
import struct
import sys

import capstone

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CODE = os.path.join(ROOT, 'disk', 'PROG.BIN')
ENTRY = 0x0000

PORTS = {
    0x00: 'PIC ICW/EOI', 0x02: 'PIC mask', 0x0c: 'FM addr', 0x0e: 'FM data',
    0x32: 'sound sw', 0x40: '8255', 0x42: '8255', 0x43: '8255',
    0x60: 'GDC char', 0x62: 'GDC char', 0x64: 'VSYNC set', 0x68: 'CRT mode',
    0x6a: 'CRT mode 2', 0x6c: 'border', 0x6e: 'border',
    0x71: 'PIT ctrl', 0x73: 'PIT ch0', 0x75: 'PIT ch1', 0x77: 'PIT ch2',
    0x7c: 'GRCG mode', 0x7e: 'GRCG tile',
    0xa0: 'GDC gfx', 0xa2: 'GDC gfx', 0xa4: 'display page',
    0xa6: 'draw page', 0xa8: 'PAL index', 0xaa: 'PAL green',
    0xac: 'PAL red', 0xae: 'PAL blue',
}

STOP = ('ret', 'retf', 'iret', 'iretd', 'hlt', 'jmp', 'ljmp')
COND = ('je', 'jz', 'jne', 'jnz', 'jl', 'jnl', 'jg', 'jng', 'jle', 'jge',
        'jb', 'jnb', 'jbe', 'jae', 'ja', 'js', 'jns', 'jo', 'jno', 'jp',
        'jnp', 'jcxz', 'loop', 'loope', 'loopne')


def load():
    with open(CODE, 'rb') as f:
        return f.read()


def cs16():
    m = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    m.detail = False
    return m


def target(ins):
    try:
        return int(ins.op_str, 16)
    except ValueError:
        return None


class Prog:
    """Instruction boundaries and cross references, found by following flow."""

    def __init__(self, data, seeds=(ENTRY,)):
        self.data = data
        self.md = cs16()
        self.ins = {}                 # addr -> capstone instruction
        self.xref = {}                # addr -> [(kind, from_addr)]
        self.calls = set()
        self.walk(list(seeds))

    def ref(self, to, kind, frm):
        if 0 <= to < len(self.data):
            self.xref.setdefault(to, []).append((kind, frm))

    def decode(self, a):
        got = list(self.md.disasm(self.data[a:a + 16], a, count=1))
        return got[0] if got else None

    def walk(self, work):
        seen = set()
        while work:
            a = work.pop()
            while 0 <= a < len(self.data):
                if a in seen:
                    break
                seen.add(a)
                ins = self.decode(a)
                if ins is None:
                    break
                self.ins[a] = ins
                mn, t = ins.mnemonic, target(ins)
                if mn == 'call' and t is not None:
                    self.ref(t, 'call', a)
                    self.calls.add(t)
                    work.append(t)
                elif mn in COND and t is not None:
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
                if ins.op_str.startswith('0x%x' % p) or \
                   ins.op_str.endswith('0x%x' % p):
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
        mark = 'sub_%04x:' % a if a in self.calls else ''
        return '%04x  %-20s %-34s %-10s %s' % (
            a, ins.bytes.hex(), '%s %s' % (ins.mnemonic, ins.op_str),
            mark, self.note(ins))


def body(p, start):
    """Addresses belonging to one function, in address order."""
    out, work, seen = [], [start], set()
    while work:
        a = work.pop()
        while a in p.ins and a not in seen:
            seen.add(a)
            out.append(a)
            ins = p.ins[a]
            mn, t = ins.mnemonic, target(ins)
            if mn in COND and t is not None:
                work.append(t)
            elif mn == 'jmp':
                if t is not None and t not in p.calls:
                    work.append(t)
                break
            elif mn in STOP:
                break
            a += ins.size
    return sorted(set(out))


def main():
    data = load()
    what = sys.argv[1] if len(sys.argv) > 1 else 'map'
    extra = [int(a, 16) for a in sys.argv[2:] if a.startswith('0x')]
    p = Prog(data, [ENTRY] + (extra if what in ('fn', 'dis') else []))

    if what == 'dis':
        a = int(sys.argv[2], 16)
        n = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x60
        while a < int(sys.argv[2], 16) + n:
            print(p.line(a))
            a += p.ins[a].size if a in p.ins else 1
    elif what == 'fn':
        start = int(sys.argv[2], 16)
        for a in body(p, start):
            print(p.line(a))
    elif what == 'xref':
        t = int(sys.argv[2], 16)
        for kind, frm in p.xref.get(t, []):
            print('%s from %04x' % (kind, frm))
        print('%d reference(s)' % len(p.xref.get(t, [])))
    elif what == 'imm':
        t = int(sys.argv[2], 16)
        want = int(sys.argv[3], 16) if len(sys.argv) > 3 else 8
        for kind, frm in p.xref.get(t, []):
            print('=== %s from %04x' % (kind, frm))
            addrs = sorted(a for a in p.ins if a < frm)[-want:]
            for a in addrs:
                print('    ' + p.line(a))
    elif what == 'ports':
        by = {}
        for a, ins in sorted(p.ins.items()):
            if ins.mnemonic in ('in', 'out'):
                by.setdefault(p.note(ins) or ins.op_str, []).append(a)
        for k in sorted(by):
            print('%-14s %d: %s' % (k, len(by[k]),
                                    ' '.join('%04x' % a for a in by[k][:16])))
    else:
        print('%d instructions cover %d of %d bytes (%.0f%%), %d functions' %
              (len(p.ins), sum(i.size for i in p.ins.values()), len(data),
               100.0 * sum(i.size for i in p.ins.values()) / len(data),
               len(p.calls)))


if __name__ == '__main__':
    main()
