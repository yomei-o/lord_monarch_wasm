#include "lmz.h"

/* The format, straight off the boot sector at 0x1bb:
 *
 *     uint16  decompressed size
 *     uint16  first flag word, then more as needed
 *     ...     blocks
 *
 * Flag words are consumed MSB first, sixteen bits to a word.
 *
 *     bit 0   a literal block: one count byte n
 *               n & 1 == 0  ->  copy n >> 1 bytes verbatim
 *               n & 1 == 1  ->  one byte follows, written n >> 1 times
 *     bit 1   a match: one uint16 w
 *               length   = (w >> 12) + 3          (3..18)
 *               distance = w & 0x0fff             back into the output
 *
 * The match copy has to be byte at a time: the distance may be shorter than the
 * length, which is how the format spreads a short pattern.
 *
 * The refill happens on the sixteenth shift, *before* that item's own operand
 * bytes are read - in the original, `dec dl / jne / lodsw` sits between the
 * `shl bx,1` and the `jb`.  Refilling after the operand instead decodes fifteen
 * items correctly and then desynchronises, which is a remarkably convincing way
 * to be wrong.
 */

unsigned lmz_size(const unsigned char *src, unsigned srcSize)
{
    if (srcSize < 4) return 0;
    return (unsigned)src[0] | ((unsigned)src[1] << 8);
}

unsigned lmz_unpack(const unsigned char *src, unsigned srcSize,
                    unsigned char *dst, unsigned dstCapacity)
{
    unsigned size = lmz_size(src, srcSize);
    unsigned pos = 2, out = 0, flags, left;

    if (size == 0 || size > dstCapacity) return 0;
    if (pos + 2 > srcSize) return 0;
    flags = (unsigned)src[pos] | ((unsigned)src[pos + 1] << 8);
    pos += 2;
    left = 16;

    while (out < size) {
        int bit = (flags >> 15) & 1;
        flags = (flags << 1) & 0xffff;
        if (--left == 0) {
            if (pos + 2 > srcSize) return 0;
            flags = (unsigned)src[pos] | ((unsigned)src[pos + 1] << 8);
            pos += 2;
            left = 16;
        }

        if (!bit) {
            unsigned n, count;
            if (pos >= srcSize) return 0;
            n = src[pos++];
            count = n >> 1;
            if (count > size - out) return 0;
            if (n & 1) {
                unsigned char v;
                if (pos >= srcSize) return 0;
                v = src[pos++];
                while (count--) dst[out++] = v;
            } else {
                if (pos + count > srcSize) return 0;
                while (count--) dst[out++] = src[pos++];
            }
        } else {
            unsigned w, count, dist, from;
            if (pos + 2 > srcSize) return 0;
            w = (unsigned)src[pos] | ((unsigned)src[pos + 1] << 8);
            pos += 2;
            count = (w >> 12) + 3;
            dist = w & 0x0fff;
            if (dist == 0 || dist > out || count > size - out) return 0;
            from = out - dist;
            while (count--) dst[out++] = dst[from++];
        }
    }
    return out;
}
