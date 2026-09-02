#include "gfx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gfx_font_rom(FontRom *f, const unsigned char *data, unsigned n)
{
    gfx_font_rom_free(f);
    if (!data || n < 0x1800 + 32) return 0;
    f->rom = (unsigned char *)malloc(n);
    if (!f->rom) return 0;
    memcpy(f->rom, data, n);
    f->size = n;
    f->loaded = 1;
    return 1;
}

void gfx_font_rom_free(FontRom *f)
{
    free(f->rom);
    f->rom = 0;
    f->size = 0;
    f->loaded = 0;
}

/* Shift-JIS to JIS, the usual two-step: undo the row pairing and the gap the
 * second byte leaves around 0x7f. */
static void sjis_to_jis(unsigned char hi, unsigned char lo,
                        unsigned char *jhi, unsigned char *jlo)
{
    int c1 = hi, c2 = lo;

    c1 -= c1 <= 0x9f ? 0x71 : 0xb1;
    c1 = c1 * 2 + 1;
    if (c2 > 0x7f) c2--;
    if (c2 >= 0x9e) {
        c2 -= 0x7d;
        c1++;
    } else {
        c2 -= 0x1f;
    }
    *jhi = (unsigned char)c1;
    *jlo = (unsigned char)c2;
}

static int is_sjis_lead(unsigned char c)
{
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xef);
}

/* One 8-wide, 16-tall column of bits. */
static void blit_column(Screen *s, const unsigned char *rows, int x, int y,
                        unsigned char colour)
{
    int r, bit;
    for (r = 0; r < 16; r++) {
        int gy = y + r;
        if (gy < 0 || gy >= SCR_H) continue;
        for (bit = 0; bit < 8; bit++) {
            int gx = x + bit;
            if (gx < 0 || gx >= SCR_W) continue;
            if (rows[r] & (0x80 >> bit))
                s->px[(size_t)gy * SCR_W + gx] = colour;
        }
    }
}

void gfx_text_sjis(Screen *s, const Font *ank, const FontRom *rom,
                   int x, int y, const char *text, unsigned char colour)
{
    const unsigned char *t = (const unsigned char *)text;
    int i = 0;

    while (t[i]) {
        if (is_sjis_lead(t[i]) && t[i + 1]) {
            unsigned char jhi, jlo;
            unsigned long n, off;
            if (!rom->loaded) {                 /* nothing to draw it with */
                i += 2;
                x += 16;
                continue;
            }
            sjis_to_jis(t[i], t[i + 1], &jhi, &jlo);
            n = (unsigned long)(jhi - 0x21) * 96 + (jlo - 0x21) + 1;
            off = 0x1800 + n * 32;
            if (off + 32 <= rom->size) {
                blit_column(s, rom->rom + off, x, y, colour);
                blit_column(s, rom->rom + off + 16, x + 8, y, colour);
            }
            i += 2;
            x += 16;
            continue;
        }
        if (rom->loaded) {
            unsigned long off = 0x0800 + (unsigned long)t[i] * 16;
            if (off + 16 <= rom->size)
                blit_column(s, rom->rom + off, x, y, colour);
        } else if (ank->loaded) {
            blit_column(s, ank->glyph[t[i]], x, y, colour);
        }
        i++;
        x += 8;
    }
}

int gfx_text_sjis_width(const FontRom *rom, const char *text)
{
    const unsigned char *t = (const unsigned char *)text;
    int i = 0, w = 0;
    (void)rom;
    while (t[i]) {
        if (is_sjis_lead(t[i]) && t[i + 1]) {
            w += 16;
            i += 2;
        } else {
            w += 8;
            i++;
        }
    }
    return w;
}

int gfx_load_font(Font *f, Disk *d)
{
    unsigned n = 0;
    unsigned char *b = disk_read_bz(d, "C_MOJI.DAT", &n);

    f->loaded = 0;
    if (!b) return 0;
    if (n >= sizeof f->glyph) {
        memcpy(f->glyph, b, sizeof f->glyph);
        f->loaded = 1;
    }
    free(b);
    return f->loaded;
}

int gfx_text_width(const char *t)
{
    int n = 0;
    while (t[n]) n++;
    return n * 8;
}

void gfx_text(Screen *s, const Font *f, int x, int y, const char *t,
              unsigned char colour)
{
    int i;
    if (!f->loaded) return;
    for (i = 0; t[i]; i++) {
        const unsigned char *g = f->glyph[(unsigned char)t[i]];
        int gx = x + i * 8, row;
        if (gx + 8 > SCR_W) break;
        for (row = 0; row < 16; row++) {
            int gy = y + row, bit;
            if (gy < 0 || gy >= SCR_H) continue;
            for (bit = 0; bit < 8; bit++)
                if (g[row] & (0x80 >> bit))
                    s->px[(size_t)gy * SCR_W + gx + bit] = colour;
        }
    }
}

void gfx_box(Screen *s, int x, int y, int w, int h, unsigned char fill,
             unsigned char edge)
{
    int i, j;
    if (x < 0 || y < 0 || x + w > SCR_W || y + h > SCR_H) return;
    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++) {
            int onEdge = i == 0 || j == 0 || i == w - 1 || j == h - 1;
            s->px[(size_t)(y + j) * SCR_W + x + i] = onEdge ? edge : fill;
        }
}

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
    /* The file is **column-major**: the byte for the square at (x, y) is at
     * x * 48 + y.  Transposing it here is what makes the picture come out the
     * way the game draws it - checked against org45.gif, which is B_044 and
     * matches the transpose on 85% of its squares against 46% for anything
     * else.  Everything downstream then uses the ordinary y * 48 + x.
     *
     * The game itself does not transpose: its own `y * 0x30 + x` over the
     * stored array simply means its x runs down the screen.  Since that is
     * consistent throughout, relabelling it here changes nothing but the
     * direction names. */
    {
        int x, y;
        for (y = 0; y < MAP_H; y++)
            for (x = 0; x < MAP_W; x++)
                m->cell[y * MAP_W + x] = data[x * MAP_W + y];
    }
    m->terrain = data[MAP_W * MAP_H] | (data[MAP_W * MAP_H + 1] << 8);
    free(data);
    return 1;
}

void gfx_bank_name(const Map *m, int size, char *out, int outSize)
{
    const char c = size == 8 ? 'S' : size == 16 ? 'M' : 'L';
    snprintf(out, (size_t)outSize, "B_%03d%c.CH4", m->terrain, c);
}

/* Index 15 is the transparent colour, and that comes straight out of the
 * original's blitter (sub_8789): it builds `~(B & R & G & E)` as a mask and
 * hands the four plane bytes to the GRCG, so a pixel with all four planes set -
 * index 15 - leaves the screen alone.  The terrain banks bear this out: the
 * 16x16 sets contain **exactly no** index 15, while the character banks are
 * 18-27% of it, which is their sprite background. */
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
            unsigned char v = src[ty * b->size + tx];
            if (dx < 0 || dx >= SCR_W || v == 15) continue;
            s->px[(size_t)dy * SCR_W + dx] = v;
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
