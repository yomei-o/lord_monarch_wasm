"""Unpack PROG.BIN and PROG.DAT — the boot sector's own LZSS.

    python tools/lmz.py disk/PROG.BIN tmp/prog.bin
    python tools/lmz.py disk/PROG.DAT tmp/prog.dat

Neither file is BZ, and neither is plain code: **every one of the 180 directory
entries has `time & 0x1f == 0x1f`**, and the boot loader tests exactly that -

    mov ax,[di+0x16] / and ax,0x1f / cmp ax,0x1f / je 0x1bb

so the plain `rep movsw` path at 0x179 is dead and everything goes through the
unpacker at 0x1bb.  That is why disassembling PROG.BIN directly gave clean code
interrupted by nonsense: the clean stretches are literal runs in the LZ stream.

The format, straight off the boot sector:

    uint16  decompressed size
    uint16  first flag word, then flag words as needed
    ...     blocks

Flag words are consumed MSB first, sixteen bits to a word.

    bit 0   a literal block: one count byte `n`
              n & 1 == 0  ->  copy n >> 1 bytes verbatim
              n & 1 == 1  ->  one byte follows, written n >> 1 times
    bit 1   a match: one uint16 w
              length   = (w >> 12) + 3          (3..18)
              distance = w & 0x0fff             (back into the output)

The match copy is deliberately byte at a time: distance may be shorter than the
length, which is how the format spreads a short pattern.

The size word is what convinced us this is right before a single byte was
decoded.  PROG.BIN starts `9c e3` = 0xe39c, and the resident code calls
0xe36c - just inside it.  PROG.DAT starts `1a 2c` = 0x2c1a, and it loads at
0x1000, so it ends at 0x3c1a - which is exactly the address the startup code
writes at 0x0016 (`mov [0x3c1a], bx`), the first word of the work area.
"""
import os
import sys

# Where the boot sector puts each file, as a linear address with DS = 0.
LOAD = {'PROG.BIN': 0x0000, 'PROG.DAT': 0x1000}


def unpack(data):
    """Returns (bytes, source bytes consumed)."""
    if len(data) < 4:
        raise ValueError('too short to hold a header')
    size = data[0] | (data[1] << 8)
    out = bytearray()
    pos = 2

    def word():
        nonlocal pos
        if pos + 2 > len(data):
            raise ValueError('ran out of source at %d/%d output bytes'
                             % (len(out), size))
        v = data[pos] | (data[pos + 1] << 8)
        pos += 2
        return v

    flags = word()
    left = 16

    while len(out) < size:
        bit = (flags >> 15) & 1
        flags = (flags << 1) & 0xffff
        left -= 1
        # The refill happens on the sixteenth shift, *before* that item's own
        # operand bytes are read - `dec dl / jne / lodsw` sits between the shift
        # and the `jb` in the boot sector.  Refilling after the operand instead
        # decodes fifteen items correctly and then desynchronises, which is a
        # remarkably convincing way to be wrong.
        if left == 0:
            flags = word()
            left = 16

        if not bit:
            n = data[pos]
            pos += 1
            count = n >> 1
            if n & 1:
                out += bytes([data[pos]]) * count
                pos += 1
            else:
                out += data[pos:pos + count]
                pos += count
        else:
            w = data[pos] | (data[pos + 1] << 8)
            pos += 2
            count = (w >> 12) + 3
            dist = w & 0x0fff
            if dist == 0 or dist > len(out):
                raise ValueError('bad distance %d at output %d'
                                 % (dist, len(out)))
            start = len(out) - dist
            for i in range(count):
                out.append(out[start + i])

    return bytes(out[:size]), pos


def main():
    src = sys.argv[1]
    dst = sys.argv[2] if len(sys.argv) > 2 else None
    data = open(src, 'rb').read()
    out, used = unpack(data)
    name = os.path.basename(src).upper()
    at = LOAD.get(name)
    print('%s  %d -> %d bytes (%d of %d source bytes used)%s' %
          (name, len(data), len(out), used, len(data),
           '' if at is None else
           '\n  loads at 0x%04x, so it occupies DS:%04x..DS:%04x'
           % (at, at, at + len(out) - 1)))
    if dst:
        os.makedirs(os.path.dirname(dst) or '.', exist_ok=True)
        open(dst, 'wb').write(out)
        print('  -> %s' % dst)


if __name__ == '__main__':
    main()
