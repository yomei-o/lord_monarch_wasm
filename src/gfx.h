/* The PC-98 screen, as the game sees it: 640x400 palette indices.
 *
 * The real machine keeps four 1bpp planes at A800/B000/B800/E000 and forms the
 * index as (E<<3)|(G<<2)|(R<<1)|B.  Everything here works on the assembled
 * index instead, because the port draws to one byte per pixel and hands that to
 * a DIB (native) or putImageData (WASM); the plane layout only matters when
 * reading the disk's own images, which is what gfx_load_screen does.
 */
#ifndef GFX_H
#define GFX_H

#include "disk.h"

#define SCR_W 640
#define SCR_H 400

#define MAP_W 48
#define MAP_H 48

typedef struct {
    unsigned char px[SCR_W * SCR_H];        /* palette indices */
    unsigned char pal[16][3];               /* 0..15 per channel, as stored */
} Screen;

/* A bank of square tiles, indices already assembled. */
typedef struct {
    int size;                   /* 8, 16 or 32 */
    int count;
    unsigned char *px;          /* count * size * size indices */
} Bank;

typedef struct {
    unsigned char cell[MAP_W * MAP_H];
    int terrain;                /* 10, 20, 30, 40 or 50 - the map's own set */
} Map;

/* The game's own font: C_MOJI.DAT decompresses to 4096 bytes, which is 256
 * glyphs of 8 x 16 one bit per pixel, indexed by the character code - 0x30 is
 * "0", 0x41 is "A".  The kanji in the messages come from the PC-98's own font
 * ROM and are not on the disk at all, so this is the whole of the text the
 * disk can draw. */
typedef struct {
    unsigned char glyph[256][16];
    int loaded;
} Font;

/* A PC-98 font ROM, if one has been supplied.  The kanji in the original's
 * messages live in the machine's font ROM, not on the floppy, so without one
 * only the disk's own ASCII can be drawn.  The layout was measured from a
 * 288768-byte image rather than looked up:
 *
 *   0x0000 + code * 16      8 x 8 ANK
 *   0x0800 + code * 16      8 x 16 ANK   (0x41 is a clean "A")
 *   0x1800 + n * 32         16 x 16, sixteen bytes of the left half then
 *                           sixteen of the right, where
 *                             n = (jisHi - 0x21) * 96 + (jisLo - 0x21) + 1
 *
 * 96 rather than 94 to the row, and the extra +1, were pinned down from the
 * blank runs: "0".."9" is a run of exactly ten at index 208, "A".."Z" twenty-six
 * at 225, hiragana eighty-three at 289 and NEC's row 13 thirty at 1153.  All
 * four fall out of that one formula and no other.
 *
 * The ROM is the machine's, not the game's, so it is never shipped with this:
 * it is loaded at runtime if the person running it has one. */
typedef struct {
    unsigned char *rom;
    unsigned size;
    int loaded;
} FontRom;

int gfx_font_rom(FontRom *f, const unsigned char *data, unsigned n);
void gfx_font_rom_free(FontRom *f);

/* Draws Shift-JIS.  Single bytes come from the ROM's 8 x 16 ANK when there is a
 * ROM and from the disk's own font otherwise; double bytes need the ROM and are
 * skipped without one. */
void gfx_text_sjis(Screen *s, const Font *ank, const FontRom *rom,
                   int x, int y, const char *text, unsigned char colour);
int gfx_text_sjis_width(const FontRom *rom, const char *text);

int gfx_load_font(Font *f, Disk *d);
void gfx_text(Screen *s, const Font *f, int x, int y, const char *t,
              unsigned char colour);
int gfx_text_width(const char *t);

/* The graphic charger, as the title screen uses it.  Two numbers travel
 * together in one word through sub_724a: `mask` says which planes the write
 * reaches - bit 0 is B, 1 is R, 2 is G, 3 is E - and `colour` supplies one bit
 * per plane, so a pixel comes out as
 *
 *     new = (old & ~mask) | (colour & mask)
 *
 * on the assembled index.  The title asks for mask 7 throughout, which is
 * every plane but E: E belongs to the starfield, and leaving it alone is why a
 * star still shows over the panel.  Both take inclusive corners, the way the
 * original's register pairs do.
 *
 * The panel at 0xc9b5 is a fill with colour 6 and the two diagonals at 0xc9c7
 * and 0xc9d9 are lines with colour 1. */
void gfx_grcg_fill(Screen *s, int x0, int y0, int x1, int y1,
                   int mask, int colour);
void gfx_grcg_line(Screen *s, int x0, int y0, int x1, int y1,
                   int mask, int colour);

/* A filled rectangle with a one-pixel edge, which is all a dialog needs. */
void gfx_box(Screen *s, int x, int y, int w, int h, unsigned char fill,
             unsigned char edge);

void gfx_clear(Screen *s, unsigned char index);

/* Sets the palette from a 48-byte table in the disk's own layout: three bytes
 * per index, in B, R, G order, only the low nibble of each significant.  That
 * is exactly what the routine at PROG.BIN 0x5db7 pushes to ports 0xae/0xac/0xaa
 * with `and al,0x0f`. */
void gfx_set_palette(Screen *s, const unsigned char *table48);

/* Copies in a palette already held as 16 x (r, g, b), 0..15 each. */
void gfx_set_palette_rgb(Screen *s, const unsigned char rgb[16][3]);

/* Expands one index to 8-bit RGB for the host. */
void gfx_rgb(const Screen *s, int index, unsigned char *r, unsigned char *g,
             unsigned char *b);

/* Loads NAME.B1/.R1/.G1/.E1 as a full-screen image.  A missing plane reads as
 * zero, which is how the title (no .E1) is stored. */
int gfx_load_screen(Screen *s, Disk *d, const char *name);

/* The same, but index 0 is transparent and the screen is filled with `under`
 * first.  The title is drawn this way: DS7TTL's background is index 0, and the
 * palette it runs with (PROG.DAT DS:24fb) has 0 = a blue that never appears on
 * screen while 1 is the black you actually see behind the logo. */
int gfx_load_screen_over(Screen *s, Disk *d, const char *name,
                         unsigned char under);

/* Loads a .CH4 tile bank.  `size` picks how the bytes are cut up; the S/M/L
 * files hold 8x8, 16x16 and 32x32 of the same terrain set. */
int gfx_load_bank(Bank *b, Disk *d, const char *name, int size);
void gfx_free_bank(Bank *b);

/* Loads a .MAP: 48x48 one-byte cells plus a uint16 terrain-set number.  The
 * file is column-major and is transposed on the way in - see gfx.c. */
int gfx_load_map(Map *m, Disk *d, const char *name);

/* The tile bank a map asks for, e.g. terrain 30 and size 8 -> "B_030S.CH4". */
void gfx_bank_name(const Map *m, int size, char *out, int outSize);

void gfx_blit_tile(Screen *s, const Bank *b, int tile, int x, int y);
void gfx_draw_map(Screen *s, const Map *m, const Bank *b, int originX,
                  int originY, int cellX, int cellY, int cellsW, int cellsH);

#endif
