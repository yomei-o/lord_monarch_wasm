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

/* Loads a .MAP: 48x48 one-byte cells plus a uint16 terrain-set number. */
int gfx_load_map(Map *m, Disk *d, const char *name);

/* The tile bank a map asks for, e.g. terrain 30 and size 8 -> "B_030S.CH4". */
void gfx_bank_name(const Map *m, int size, char *out, int outSize);

void gfx_blit_tile(Screen *s, const Bank *b, int tile, int x, int y);
void gfx_draw_map(Screen *s, const Map *m, const Bank *b, int originX,
                  int originY, int cellX, int cellY, int cellsW, int cellsH);

#endif
