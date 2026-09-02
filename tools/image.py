"""Build the flat memory image the boot loader would have produced.

    python tools/image.py tmp/mem.bin

PROG.BIN is not an executable with a header; the disk's own boot sector loads two
raw files and jumps into one of them:

    PROG.DAT -> 0000:1000    (data and tables)
    PROG.BIN -> 1000:0000    (code)
    ljmp 0x1000:0

and the code's first act is `xor sp,sp / mov ds,sp / mov es,sp / mov ss,sp`, so it
runs with **DS = 0**: every `mov ax,[0x3e7c]` in it is an absolute address in the
first 64K, not an offset into itself.

Handing Ghidra PROG.BIN on its own therefore leaves all of that dangling, and the
auto-analyser gives up after a handful of functions.  Assembling the flat image
first and importing THAT at 0000:0000 puts the code at linear 0x10000 - which
Ghidra shows as 1000:0000, the address the code actually runs at - and resolves
the low-memory accesses at the same time.

The image stops just past the end of PROG.BIN rather than running to 1MB, so the
analyser is not handed 900K of zeros to chew on.
"""
import os
import sys

DAT_AT = 0x1000       # 0000:1000
BIN_AT = 0x10000      # 1000:0000
PAD = 0x800           # a little room past the end for the work area


def build(disk='disk'):
    dat = open(os.path.join(disk, 'PROG.DAT'), 'rb').read()
    bin_ = open(os.path.join(disk, 'PROG.BIN'), 'rb').read()
    size = BIN_AT + len(bin_) + PAD
    mem = bytearray(size)
    mem[DAT_AT:DAT_AT + len(dat)] = dat
    mem[BIN_AT:BIN_AT + len(bin_)] = bin_
    return bytes(mem), len(dat), len(bin_)


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else 'tmp/mem.bin'
    mem, ndat, nbin = build()
    os.makedirs(os.path.dirname(out) or '.', exist_ok=True)
    open(out, 'wb').write(mem)
    print('%s  %d bytes: PROG.DAT %d at 0x%05x (0000:%04x), '
          'PROG.BIN %d at 0x%05x (1000:0000)' %
          (out, len(mem), ndat, DAT_AT, DAT_AT, nbin, BIN_AT))


if __name__ == '__main__':
    main()
