/* The boot sector's own LZSS, which PROG.BIN and PROG.DAT are packed with.
 *
 * Every directory entry on the disk has `time & 0x1f == 0x1f`, and the boot
 * loader tests exactly that before choosing between a plain copy and this - so
 * the plain path is dead and both program files arrive packed.  The port only
 * needs PROG.DAT, which holds the palettes, the message strings and the
 * filename table; reading them from the original rather than hardcoding them
 * keeps the port honest.
 */
#ifndef LMZ_H
#define LMZ_H

/* Unpacks into a buffer the caller sizes from the two-byte header (see
 * lmz_size).  Returns the byte count, or 0 if the stream is malformed. */
unsigned lmz_unpack(const unsigned char *src, unsigned srcSize,
                    unsigned char *dst, unsigned dstCapacity);

/* The decompressed size, taken from the header. */
unsigned lmz_size(const unsigned char *src, unsigned srcSize);

#endif
