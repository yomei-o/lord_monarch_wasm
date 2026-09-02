// Falcom's .BZ codec, read out of DS7E_WIN.EXE.
//
// The container is row-oriented: each row starts with a uint16 giving that
// row's compressed length, and the byte after it selects the codec - zero
// picks the bit-packed variant at 00420240, anything else the byte-opcode
// variant at 0041fef0.  Both are LZ77 over the output written so far, so a
// back-reference may overlap what it is still producing and the copy has to
// stay byte at a time.
//
// Names here are ours; the structure is the executable's.
#include "bz.h"

#include <string.h>

typedef struct {
    unsigned char *dst;         // where the next output byte goes
    unsigned char *dstStart;    // for bounds checks the original omits
    unsigned char *dstEnd;
    const unsigned char *src;
    const unsigned char *srcEnd;
    unsigned short bits;        // the bit-codec's 16-bit window
    int bitCount;
    int consumed;               // source bytes taken for the current row
    int failed;
} BzState;

static unsigned char take(BzState *s) {
    if (s->src >= s->srcEnd) { s->failed = 1; return 0; }
    s->consumed++;
    return *s->src++;
}

static void emit(BzState *s, unsigned char v) {
    if (s->dst >= s->dstEnd) { s->failed = 1; return; }
    *s->dst++ = v;
}

// A back-reference into what has already been produced.  Overlapping is
// deliberate: it is how the original spreads a short pattern.
static void copyBack(BzState *s, unsigned distance, unsigned count) {
    if (distance == 0 || (size_t)(s->dst - s->dstStart) < distance) {
        s->failed = 1;
        return;
    }
    const unsigned char *from = s->dst - distance;
    while (count-- && !s->failed) emit(s, *from++);
}

/* ------------------------------------------------- the byte-opcode codec */

static void rowByteOpcodes(BzState *s, unsigned rowLen) {
    s->consumed = 2;                     // the length word itself
    if (rowLen == 2) return;             // an empty row
    while (s->consumed != (int)rowLen && !s->failed) {
        const unsigned char op = take(s);
        if (op & 0x80) {
            // Match: five distance bits here, eight in the next byte, and a
            // length of four to seven.
            const unsigned lo = take(s);
            const unsigned distance = ((op & 0x1f) << 8) | lo;
            unsigned count = ((op & 0x60) >> 5) + 4;
            if (distance == 0 || (size_t)(s->dst - s->dstStart) < distance) {
                s->failed = 1;
                return;
            }
            const unsigned char *from = s->dst - distance;
            while (count-- && !s->failed) emit(s, *from++);
            // 0x60-0x7f continues the same match rather than starting a new
            // opcode - the one context-dependent encoding in the format.
            while (!s->failed && s->consumed != (int)rowLen &&
                   s->src < s->srcEnd && (*s->src & 0xe0) == 0x60) {
                unsigned more = *s->src & 0x1f;
                s->src++;
                s->consumed++;
                while (more-- && !s->failed) emit(s, *from++);
            }
        } else if (op & 0x40) {
            // Run of one repeated byte, four bits of count or twelve.
            unsigned count;
            if (op & 0x10) {
                const unsigned hi = op & 0x0f;
                const unsigned lo = take(s);
                count = ((hi << 8) | lo) + 4;
            } else {
                count = (op & 0x0f) + 4;
            }
            const unsigned char v = take(s);
            while (count-- && !s->failed) emit(s, v);
        } else if (op & 0x20) {
            // Literal run, twelve bits of length.
            const unsigned lo = take(s);
            unsigned count = ((op & 0x1f) << 8) | lo;
            while (count-- && !s->failed) emit(s, take(s));
        } else {
            // Literal run, five bits of length.
            unsigned count = op & 0x1f;
            while (count-- && !s->failed) emit(s, take(s));
        }
    }
}

/* --------------------------------------------------- the bit-packed codec */

static int bit(BzState *s) {
    if (s->bitCount == 0) {
        if (s->src + 1 >= s->srcEnd) { s->failed = 1; return 0; }
        s->bits = (unsigned short)(s->src[0] | (s->src[1] << 8));
        s->src += 2;
        s->consumed += 2;
        s->bitCount = 16;
    }
    const int b = s->bits & 1;
    s->bits >>= 1;
    s->bitCount--;
    return b;
}

// 004204c0 accumulates most significant bit first: v = v * 2 + bit.
static unsigned bitsOf(BzState *s, int n) {
    unsigned v = 0;
    while (n-- > 0) v = v * 2 + (unsigned)bit(s);
    return v;
}

static void rowBitPacked(BzState *s, unsigned rowLen) {
    (void)rowLen;
    s->consumed = 4;                     // length word plus the first bits
    if (s->src + 1 >= s->srcEnd) { s->failed = 1; return; }
    s->bits = s->src[1];
    s->bitCount = 8;
    s->src += 2;

    for (;;) {
        if (s->failed) return;
        // A zero bit means one literal byte; keep taking them.
        while (!bit(s) && !s->failed) emit(s, take(s));
        if (s->failed) return;

        unsigned distance;
        if (!bit(s)) {
            distance = take(s);
        } else {
            const unsigned hi = bitsOf(s, 5);
            distance = (hi << 8) | take(s);
            if (distance == 0) return;             // end of row
            if (distance == 1) {
                // The long run escape.  Both branches fill raw + 0x0e bytes;
                // the 0x0f and 0x10 the original also computes go into its
                // consumed-bytes bookkeeping, not into the count.
                unsigned raw;
                if (!bit(s)) {
                    raw = bitsOf(s, 4);
                } else {
                    const unsigned hi2 = bitsOf(s, 4);
                    raw = (hi2 << 8) | take(s);
                }
                unsigned count = raw + 0x0e;
                const unsigned char v = take(s);
                while (count-- && !s->failed) emit(s, v);
                continue;
            }
        }

        // The match length, unary-ish: 2, 3, 4, 5, 6..13, or a byte + 14.
        unsigned count;
        if (bit(s)) count = 2;
        else if (bit(s)) count = 3;
        else if (bit(s)) count = 4;
        else if (bit(s)) count = 5;
        else if (bit(s)) count = bitsOf(s, 3) + 6;
        else count = take(s) + 14u;
        copyBack(s, distance, count);
    }
}

/* -------------------------------------------------------------- the whole */

int bzDecompress(const void *srcData, unsigned srcSize, void *dstData,
                 unsigned dstCapacity, unsigned *producedOut) {
    BzState s;
    memset(&s, 0, sizeof s);
    s.dst = s.dstStart = (unsigned char *)dstData;
    s.dstEnd = s.dst + dstCapacity;
    s.src = (const unsigned char *)srcData;
    s.srcEnd = s.src + srcSize;

    unsigned taken = 0;
    while (taken < srcSize && !s.failed) {
        if (s.src + 1 >= s.srcEnd) break;
        const unsigned rowLen = (unsigned)(s.src[0] | (s.src[1] << 8));
        if (rowLen < 2) break;
        const unsigned char *rowStart = s.src;
        taken += rowLen;
        if (taken > srcSize) break;
        s.src += 2;
        if (s.src < s.srcEnd && *s.src == 0) rowBitPacked(&s, rowLen);
        else rowByteOpcodes(&s, rowLen);
        // Each row's length is authoritative: resynchronise on it rather
        // than trusting where a codec happened to stop.  The extra byte is
        // the separator the original reads and rejects when it is zero.
        s.src = rowStart + rowLen;
        taken += 1;
        if (s.src < s.srcEnd) s.src++;
    }
    if (producedOut) *producedOut = (unsigned)(s.dst - s.dstStart);
    return !s.failed;
}
