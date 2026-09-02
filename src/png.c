/* A PNG writer with no dependencies, for checking renders without opening a
 * window.  Deflate "stored" blocks only - the files are a little fat, but
 * nothing has to be linked and there is no compressor to get wrong. */
#include "png.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned crc_table[256];
static int crc_ready;

static void crc_init(void)
{
    unsigned n, k, c;
    for (n = 0; n < 256; n++) {
        c = n;
        for (k = 0; k < 8; k++) c = (c & 1) ? 0xedb88320u ^ (c >> 1) : c >> 1;
        crc_table[n] = c;
    }
    crc_ready = 1;
}

static unsigned crc32_of(const unsigned char *p, size_t n, unsigned c)
{
    size_t i;
    if (!crc_ready) crc_init();
    c ^= 0xffffffffu;
    for (i = 0; i < n; i++) c = crc_table[(c ^ p[i]) & 0xff] ^ (c >> 8);
    return c ^ 0xffffffffu;
}

static void put32(FILE *f, unsigned v)
{
    fputc((int)(v >> 24) & 0xff, f);
    fputc((int)(v >> 16) & 0xff, f);
    fputc((int)(v >> 8) & 0xff, f);
    fputc((int)v & 0xff, f);
}

static void chunk(FILE *f, const char *tag, const unsigned char *data,
                  size_t n)
{
    unsigned c;
    put32(f, (unsigned)n);
    fwrite(tag, 1, 4, f);
    if (n) fwrite(data, 1, n, f);
    c = crc32_of((const unsigned char *)tag, 4, 0);
    if (n) c = crc32_of(data, n, c);
    put32(f, c);
}

int png_write_indexed(const char *path, int w, int h,
                      const unsigned char *px, int stride,
                      const unsigned char pal[][3], int palCount)
{
    FILE *f;
    unsigned char ihdr[13], plte[768];
    unsigned char *raw, *z;
    size_t rawLen, zLen = 0, i, pos;
    unsigned a = 1, b = 0;
    int y;

    f = fopen(path, "wb");
    if (!f) return 0;
    fwrite("\x89PNG\r\n\x1a\n", 1, 8, f);

    ihdr[0] = (unsigned char)(w >> 24); ihdr[1] = (unsigned char)(w >> 16);
    ihdr[2] = (unsigned char)(w >> 8);  ihdr[3] = (unsigned char)w;
    ihdr[4] = (unsigned char)(h >> 24); ihdr[5] = (unsigned char)(h >> 16);
    ihdr[6] = (unsigned char)(h >> 8);  ihdr[7] = (unsigned char)h;
    ihdr[8] = 8;            /* bit depth */
    ihdr[9] = 3;            /* colour type: palette */
    ihdr[10] = ihdr[11] = ihdr[12] = 0;
    chunk(f, "IHDR", ihdr, sizeof ihdr);

    for (i = 0; i < (size_t)palCount; i++) {
        plte[i * 3 + 0] = pal[i][0];
        plte[i * 3 + 1] = pal[i][1];
        plte[i * 3 + 2] = pal[i][2];
    }
    chunk(f, "PLTE", plte, (size_t)palCount * 3);

    /* One filter byte (0 = none) per row, then the row. */
    rawLen = (size_t)(w + 1) * h;
    raw = (unsigned char *)malloc(rawLen);
    for (y = 0; y < h; y++) {
        raw[(size_t)y * (w + 1)] = 0;
        memcpy(raw + (size_t)y * (w + 1) + 1, px + (size_t)y * stride,
               (size_t)w);
    }

    /* zlib: 2-byte header, stored deflate blocks, adler32. */
    z = (unsigned char *)malloc(rawLen + rawLen / 65535 * 5 + 64);
    z[zLen++] = 0x78;
    z[zLen++] = 0x01;
    for (pos = 0; pos < rawLen; ) {
        size_t n = rawLen - pos;
        int last;
        if (n > 65535) n = 65535;
        last = (pos + n == rawLen);
        z[zLen++] = (unsigned char)(last ? 1 : 0);
        z[zLen++] = (unsigned char)(n & 0xff);
        z[zLen++] = (unsigned char)(n >> 8);
        z[zLen++] = (unsigned char)(~n & 0xff);
        z[zLen++] = (unsigned char)((~n >> 8) & 0xff);
        memcpy(z + zLen, raw + pos, n);
        zLen += n;
        pos += n;
    }
    for (i = 0; i < rawLen; i++) {
        a = (a + raw[i]) % 65521;
        b = (b + a) % 65521;
    }
    z[zLen++] = (unsigned char)(b >> 8);
    z[zLen++] = (unsigned char)b;
    z[zLen++] = (unsigned char)(a >> 8);
    z[zLen++] = (unsigned char)a;

    chunk(f, "IDAT", z, zLen);
    chunk(f, "IEND", 0, 0);
    fclose(f);
    free(raw);
    free(z);
    return 1;
}
