"""Build the flat memory image the boot loader produces, for Ghidra.

    python tools/image.py tmp/mem.bin

The disk's own boot sector loads two files and jumps into one of them:

    PROG.DAT -> 0000:1000    data, strings, tables
    PROG.BIN -> 1000:0000    code
    ljmp 0x1000:0

**Both are packed** with the boot sector's LZSS (see lmz.py), so the bytes on
the disk are not the bytes that run: PROG.BIN is 42040 on the disk and 58268 in
memory, PROG.DAT 8020 and 11290.  Handing Ghidra the disk copy gets a listing
that looks like code in patches and nonsense in between - those patches are the
literal runs of the LZ stream.

The code's first act is `cli / xor sp,sp / mov ds,sp / mov es,sp / mov ss,sp`,
so it runs with **DS = 0**: every `mov ax,[0x3e7c]` in it is an absolute address
in the first 64K, not an offset into itself.  Assembling the flat image and
importing THAT at 0000:0000 puts the code at linear 0x10000 - which Ghidra shows
as 1000:0000, the address it really runs at - and resolves the low-memory
accesses at the same time.

The image stops just past the end of the code rather than running to 1MB, so the
analyser is not handed 900K of zeros to chew on.
"""
import os
import sys

import lmz

DAT_AT = 0x1000       # 0000:1000
BIN_AT = 0x10000      # 1000:0000
PAD = 0x800           # a little room past the end for the work area


def unpacked(disk, name):
    with open(os.path.join(disk, name), 'rb') as f:
        return lmz.unpack(f.read())[0]


def build(disk='disk'):
    dat = unpacked(disk, 'PROG.DAT')
    bin_ = unpacked(disk, 'PROG.BIN')
    size = BIN_AT + len(bin_) + PAD
    mem = bytearray(size)
    mem[DAT_AT:DAT_AT + len(dat)] = dat
    mem[BIN_AT:BIN_AT + len(bin_)] = bin_
    return bytes(mem), len(dat), len(bin_)


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else 'tmp/mem.bin'
    disk = sys.argv[2] if len(sys.argv) > 2 else 'disk'
    mem, ndat, nbin = build(disk)
    os.makedirs(os.path.dirname(out) or '.', exist_ok=True)
    with open(out, 'wb') as f:
        f.write(mem)
    print('%s  %d bytes\n'
          '  PROG.DAT %d unpacked at 0x%05x (DS:%04x..DS:%04x)\n'
          '  PROG.BIN %d unpacked at 0x%05x (1000:0000..1000:%04x)' %
          (out, len(mem), ndat, DAT_AT, DAT_AT, DAT_AT + ndat - 1,
           nbin, BIN_AT, nbin - 1))


if __name__ == '__main__':
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
