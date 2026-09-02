// Falcom's .BZ codec.  See bz.c for the format.
#ifndef BZ_H
#define BZ_H

// Decompresses srcSize bytes into dstData, writing at most dstCapacity.
// Returns non-zero on success; *producedOut receives the byte count.
int bzDecompress(const void *srcData, unsigned srcSize, void *dstData,
                 unsigned dstCapacity, unsigned *producedOut);

#endif
