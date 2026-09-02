#include "gfx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gfx_clear(Screen *s, unsigned char index)
{
    memset(s->px, index, sizeof s->px);
}

void gfx_set_palette(Screen *s, const unsigned char *t)
{
    int i;
    for (i = 0; i < 16; i++) {
        s->pal[i][0] = t[i * 3 + 1] & 0x0f;      /* R, from port 0xac */
        s->pal[i][1] = t[i * 3 + 2] & 0x0f;      /* G, from port 0xaa */
        s->pal[i][2] = t[i * 3 + 0] & 0x0f;      /* B, from port 0xae */
    }
}

void gfx_set_palette_rgb(Screen *s, const unsigned char rgb[16][3])
{
    memcpy(s->pal, rgb, sizeof s->pal);
}

void gfx_rgb(const Screen *s, int index, unsigned char *r, unsigned char *g,
             unsigned char *b)
{
    /* The hardware is 4 bits a channel; 17 spreads 0..15 over the full 0..255
     * rather than leaving white at 240. */
    *r = (unsigned char)(s->pal[index & 15][0] * 17);
    *g = (unsigned char)(s->pal[index & 15][1] * 17);
    *b = (unsigned char)(s->pal[index & 15][2] * 17);
}

/* Assembles four 1bpp planes into indices.  The plane order is the file
 * extension order - B, R, G, E - because the index is (E<<3)|(G<<2)|(R<<1)|B. */
static void planes_to_indices(unsigned char *out, const unsigned char *pl[4],
                              int w, int h)
{
    int bit, y, xb, k;
    const int stride = w / 8;
    memset(out, 0, (size_t)w * h);
    for (bit = 0; bit < 4; bit++) {
        if (!pl[bit]) continue;
        for (y = 0; y < h; y++) {
            const unsigned char *src = pl[bit] + (size_t)y * stride;
            unsigned char *dst = out + (size_t)y * w;
            for (xb = 0; xb < stride; xb++) {
                unsigned char v = src[xb];
                for (k = 0; k < 8; k++)
                    if (v & (0x80 >> k)) dst[xb * 8 + k] |= 1 << bit;
            }
        }
    }
}

static int load_screen(Screen *s, Disk *d, const char *name, int under)
{
    static const char *ext[4] = {"B1", "R1", "G1", "E1"};
    unsigned char *own[4] = {0, 0, 0, 0};
    const unsigned char *pl[4];
    char buf[32];
    int i, ok = 0;

    for (i = 0; i < 4; i++) {
        unsigned n = 0;
        snprintf(buf, sizeof buf, "%s.%s", name, ext[i]);
        own[i] = disk_read_bz(d, buf, &n);
        /* The title has no .E1; a missing plane simply reads as zero. */
        if (own[i] && n < (unsigned)(SCR_W / 8) * SCR_H) {
            free(own[i]);
            own[i] = 0;
        }
        pl[i] = own[i];
        if (own[i]) ok = 1;
    }
    if (ok) {
        if (under < 0) {
            planes_to_indices(s->px, pl, SCR_W, SCR_H);
        } else {
            static unsigned char tmp[SCR_W * SCR_H];
            size_t n;
            planes_to_indices(tmp, pl, SCR_W, SCR_H);
            for (n = 0; n < (size_t)SCR_W * SCR_H; n++)
                s->px[n] = tmp[n] ? tmp[n] : (unsigned char)under;
        }
    }
    for (i = 0; i < 4; i++) free(own[i]);
    return ok;
}

int gfx_load_screen(Screen *s, Disk *d, const char *name)
{
    return load_screen(s, d, name, -1);
}

int gfx_load_screen_over(Screen *s, Disk *d, const char *name,
                         unsigned char under)
{
    return load_screen(s, d, name, under);
}

int gfx_load_bank(Bank *b, Disk *d, const char *name, int size)
{
    unsigned n = 0;
    unsigned char *data = disk_read_bz(d, name, &n);
    const int stride = size / 8, per = stride * size * 4;
    int i;

    b->size = size;
    b->count = 0;
    b->px = 0;
    if (!data) return 0;
    b->count = (int)(n / (unsigned)per);
    b->px = (unsigned char *)malloc((size_t)b->count * size * size);
    for (i = 0; i < b->count; i++) {
        const unsigned char *base = data + (size_t)i * per;
        const unsigned char *pl[4];
        int p;
        for (p = 0; p < 4; p++) pl[p] = base + (size_t)p * stride * size;
        planes_to_indices(b->px + (size_t)i * size * size, pl, size, size);
    }
    free(data);
    return b->count > 0;
}

void gfx_free_bank(Bank *b)
{
    free(b->px);
    b->px = 0;
    b->count = 0;
}

int gfx_load_map(Map *m, Disk *d, const char *name)
{
    unsigned n = 0;
    unsigned char *data = disk_read_bz(d, name, &n);

    if (!data) return 0;
    if (n < MAP_W * MAP_H + 2) {
        free(data);
        return 0;
    }
    memcpy(m->cell, data, MAP_W * MAP_H);
    m->terrain = data[MAP_W * MAP_H] | (data[MAP_W * MAP_H + 1] << 8);
    free(data);
    return 1;
}

void gfx_bank_name(const Map *m, int size, char *out, int outSize)
{
    const char c = size == 8 ? 'S' : size == 16 ? 'M' : 'L';
    snprintf(out, (size_t)outSize, "B_%03d%c.CH4", m->terrain, c);
}

void gfx_blit_tile(Screen *s, const Bank *b, int tile, int x, int y)
{
    const unsigned char *src;
    int ty, tx;

    if (tile < 0 || tile >= b->count) return;
    src = b->px + (size_t)tile * b->size * b->size;
    for (ty = 0; ty < b->size; ty++) {
        int dy = y + ty;
        if (dy < 0 || dy >= SCR_H) continue;
        for (tx = 0; tx < b->size; tx++) {
            int dx = x + tx;
            if (dx < 0 || dx >= SCR_W) continue;
            s->px[(size_t)dy * SCR_W + dx] = src[ty * b->size + tx];
        }
    }
}

void gfx_draw_map(Screen *s, const Map *m, const Bank *b, int originX,
                  int originY, int cellX, int cellY, int cellsW, int cellsH)
{
    int cy, cx;
    for (cy = 0; cy < cellsH; cy++) {
        int my = cellY + cy;
        if (my < 0 || my >= MAP_H) continue;
        for (cx = 0; cx < cellsW; cx++) {
            int mx = cellX + cx;
            if (mx < 0 || mx >= MAP_W) continue;
            gfx_blit_tile(s, b, m->cell[my * MAP_W + mx],
                          originX + cx * b->size, originY + cy * b->size);
        }
    }
}
