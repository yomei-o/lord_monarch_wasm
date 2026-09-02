"""Disassemble a range of DEPTH.EXE's one code segment, with names filled in.

(Named disasm.py, not dis.py: the latter shadows the standard library module
capstone imports, and the import fails in a way that reads like a capstone bug.)

    python tools/disasm.py 0x8ae2 0x200          # 0x200 bytes from 0x8ae2
    python tools/disasm.py 0x8ae2 0x200 --raw    # without the annotations

Ghidra's 16-bit decompilation is good enough to read the shape of a routine but
it loses arguments: a pushed constant often comes out as a local, and a pushed
return address often comes out looking like a constant.  tools/callsites.py
recovers the immediate ones; this recovers the rest, because sometimes the only
way to know what a call was given is to read the instructions.

Annotations:
  * `call`/`jmp` targets get the FUN_1000_xxxx name out of decomp/index.csv
  * a `mov` of a constant that lands in DGROUP is flagged with the string it
    points at, when there is one
  * `int 21h`/`int 18h` and the PC-98 ports the game uses are named

Needs capstone (`pip install capstone`).
"""
import csv
import os
import struct
import sys

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
HDR = 512               # e_cparhdr 32 paragraphs
CODE_END = 0xfd40       # DGROUP starts here

PORTS = {
    0x00: 'PIC EOI', 0x02: 'PIC mask', 0x37: 'beeper gate',
    0x42: 'system port (clock family)', 0x60: 'CRT status (bit5 = VBLANK)',
    0x62: 'GDC', 0x64: 'VSYNC interrupt reset', 0x68: 'mode flip-flop',
    0x6a: 'mode select', 0x71: '8253 counter 0', 0x77: '8253 control',
    0x7c: 'GRCG mode', 0x7e: 'GRCG tile', 0xa4: 'displayed page',
    0xa6: 'drawn page', 0xa8: 'palette index', 0xaa: 'palette green',
    0xac: 'palette red', 0xae: 'palette blue', 0x3fdb: 'beeper divisor',
    0x3fdf: '8253 control (beeper)',
}


def load_code():
    with open(os.path.join(ROOT, 'orig', 'DEPTH.EXE'), 'rb') as f:
        return f.read()[HDR:HDR + CODE_END]


def load_names():
    names = {}
    path = os.path.join(ROOT, 'decomp', 'index.csv')
    if not os.path.exists(path):
        return names
    with open(path, newline='') as f:
        for row in csv.DictReader(f):
            seg, off = row['address'].split(':')
            names[int(off, 16)] = row['name']
    return names


def load_dgroup():
    """The DGROUP image, so a constant can be checked for pointing at text."""
    with open(os.path.join(ROOT, 'orig', 'DEPTH.EXE'), 'rb') as f:
        return f.read()[HDR + CODE_END:]


def dgroup_string(data, off):
    if off < 0 or off >= len(data):
        return None
    end = off
    while end < len(data) and data[end] and end - off < 40:
        end += 1
    if end == off or end - off < 3:
        return None
    s = data[off:end]
    if not all(32 <= c < 127 or c in (13, 10, 9) for c in s):
        return None
    return s.decode('latin1')


def main():
    start = int(sys.argv[1], 16)
    length = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x80
    raw = '--raw' in sys.argv

    code = load_code()
    names = {} if raw else load_names()
    dg = b'' if raw else load_dgroup()

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    md.detail = False
    for ins in md.disasm(code[start:start + length], start):
        note = ''
        text = '%s %s' % (ins.mnemonic, ins.op_str)
        if ins.mnemonic in ('call', 'jmp', 'je', 'jne', 'jl', 'jg', 'jle',
                            'jge', 'jb', 'ja', 'jbe', 'jae', 'js', 'jns',
                            'loop'):
            try:
                tgt = int(ins.op_str, 16)
            except ValueError:
                tgt = None
            if tgt is not None and tgt in names:
                note = '-> %s' % names[tgt]
        if ins.mnemonic in ('in', 'out'):
            for p, what in PORTS.items():
                if ('0x%x' % p) in ins.op_str:
                    note = what
                    break
        if not note and ins.mnemonic in ('mov', 'push') and '0x' in ins.op_str:
            try:
                v = int(ins.op_str.rsplit(', ', 1)[-1], 16)
            except ValueError:
                v = None
            if v is not None:
                s = dgroup_string(dg, v)
                if s:
                    note = 'DS:0x%04x = %r' % (v, s)
        print('%04x  %-24s %-30s %s' %
              (ins.address, ins.bytes.hex(), text, note))


main()
