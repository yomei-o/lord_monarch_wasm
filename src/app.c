#include "app.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The map window inside WAKU.  Found by measurement rather than guessed: in the
 * assembled WAKU image the columns that are index 0 for essentially the whole
 * height run x = 160..479, and the rows likewise y = 8..391.  320 x 384 is
 * 20 x 24 cells at 16x16, so the view scrolls over the 48 x 48 map - which is
 * what a real-time strategy game wants.  A whole-map overview needs 384 px and
 * does not fit, so that must be its own screen (the MAP button on the panel). */
#define VIEW_X 160
#define VIEW_Y 8
#define VIEW_W 320
#define VIEW_H 384

#define MAP_COUNT 52

/* PROG.DAT, unpacked, as the game has it at DS:1000.  It holds the palette
 * tables, the message strings and the filename table, so the port reads them
 * from the original rather than carrying copies. */
#define DAT_BASE 0x1000
#define PAL_TITLE_AT 0x24fb        /* the table the title fades to */

static unsigned char *progDat;
static unsigned progDatSize;

/* A pointer to a DS: address inside PROG.DAT, or 0 if it is outside. */
static const unsigned char *dat_at(unsigned addr, unsigned need)
{
    unsigned off = addr - DAT_BASE;
    if (!progDat || addr < DAT_BASE || off + need > progDatSize) return 0;
    return progDat + off;
}

static Screen scr;
/* The backdrop - the title image, or the frame - is decompressed once per mode
 * change rather than per frame: WAKU is three or four BZ streams of 32000 bytes
 * and redoing that every frame would be the whole frame budget. */
static Screen bg;
static Disk *disk;
static Bank bank;
static Map map;
static Game game;
static int showCastles;
static int mode = APP_MODE_TITLE;
static int mapNumber, tileSize = 16, scrollX, scrollY;
static char status[256];

const Screen *app_screen(void) { return &scr; }
int app_mode(void) { return mode; }
const char *app_status(void) { return status; }

int app_init(const char *imagePath)
{
    disk = disk_open(imagePath);
    if (!disk) {
        snprintf(status, sizeof status, "%s", disk_error());
        return 0;
    }
    progDat = disk_read_lz(disk, "PROG.DAT", &progDatSize);
    if (!progDat) {
        snprintf(status, sizeof status, "PROG.DAT: %s", disk_error());
        return 0;
    }
    return app_show_title();
}

void app_shutdown(void)
{
    gfx_free_bank(&bank);
    free(progDat);
    progDat = 0;
    disk_close(disk);
    disk = 0;
}

/* The palette travels with the tileset: the 48 bytes appended to B_0n0L.CH4,
 * three per index in B, R, G order.  See gfx_set_palette. */
static int palette_from_terrain(int terrain)
{
    char name[32];
    unsigned n = 0;
    unsigned char *b;

    snprintf(name, sizeof name, "B_%03dL.CH4", terrain);
    b = disk_read_bz(disk, name, &n);
    if (!b || n < 48) {
        free(b);
        snprintf(status, sizeof status, "%s: no palette", name);
        return 0;
    }
    gfx_set_palette(&scr, b + n - 48);
    free(b);
    return 1;
}

int app_show_title(void)
{
    const unsigned char *t = dat_at(PAL_TITLE_AT, 48);

    mode = APP_MODE_TITLE;
    if (!t) {
        snprintf(status, sizeof status, "no title palette in PROG.DAT");
        return 0;
    }
    gfx_set_palette(&scr, t);
    /* Index 0 is transparent here.  The stored table has 0 = a blue that never
     * shows: the game clears the screen first and lays DS7TTL over it, so what
     * you see behind the logo is index 1, black.  Checked against ss0.jpg -
     * index 1 and index 3 come out exactly right that way. */
    gfx_clear(&bg, 1);
    if (!gfx_load_screen_over(&bg, disk, "DS7TTL", 1)) {
        snprintf(status, sizeof status, "DS7TTL: %s", disk_error());
        return 0;
    }
    snprintf(status, sizeof status, "title");
    return 1;
}

int app_show_map(int number, int size)
{
    char name[32], bankName[32];

    if (number < 0) number = MAP_COUNT - 1;
    if (number >= MAP_COUNT) number = 0;
    snprintf(name, sizeof name, "B_%03d.MAP", number);
    if (!gfx_load_map(&map, disk, name)) {
        snprintf(status, sizeof status, "%s: %s", name, disk_error());
        return 0;
    }
    if (!palette_from_terrain(map.terrain)) return 0;
    gfx_bank_name(&map, size, bankName, sizeof bankName);
    gfx_free_bank(&bank);
    if (!gfx_load_bank(&bank, disk, bankName, size)) {
        snprintf(status, sizeof status, "%s: %s", bankName, disk_error());
        return 0;
    }
    gfx_clear(&bg, 0);
    if (!gfx_load_screen(&bg, disk, "WAKU"))
        snprintf(status, sizeof status, "WAKU: %s", disk_error());
    mode = APP_MODE_MAP;
    mapNumber = number;
    tileSize = size;
    scrollX = scrollY = 0;
    game_init(&game, &map);
    snprintf(status, sizeof status,
             "%s  terrain %d  %s  %dx%d  castles %d,%d %d,%d %d,%d %d,%d  "
             "units %d (neutral %d)",
             name, map.terrain, bankName, size, size,
             game.side[0].pos & 0xff, game.side[0].pos >> 8,
             game.side[1].pos & 0xff, game.side[1].pos >> 8,
             game.side[2].pos & 0xff, game.side[2].pos >> 8,
             game.side[3].pos & 0xff, game.side[3].pos >> 8,
             game_unit_count(&game, -1), game_unit_count(&game, 4));
    return 1;
}

static void scroll_by(int dx, int dy)
{
    int maxX = MAP_W - VIEW_W / bank.size;
    int maxY = MAP_H - VIEW_H / bank.size;

    if (maxX < 0) maxX = 0;
    if (maxY < 0) maxY = 0;
    scrollX += dx;
    scrollY += dy;
    if (scrollX < 0) scrollX = 0;
    if (scrollY < 0) scrollY = 0;
    if (scrollX > maxX) scrollX = maxX;
    if (scrollY > maxY) scrollY = maxY;
}

void app_key(int key)
{
    if (mode == APP_MODE_TITLE) {
        if (key == APP_KEY_START) app_show_map(0, tileSize);
        return;
    }
    switch (key) {
    case APP_KEY_BACK:      app_show_title(); break;
    case APP_KEY_PREV_MAP:  app_show_map(mapNumber - 1, tileSize); break;
    case APP_KEY_NEXT_MAP:  app_show_map(mapNumber + 1, tileSize); break;
    case APP_KEY_LEFT:      scroll_by(-1, 0); break;
    case APP_KEY_RIGHT:     scroll_by(1, 0); break;
    case APP_KEY_UP:        scroll_by(0, -1); break;
    case APP_KEY_DOWN:      scroll_by(0, 1); break;
    case APP_KEY_TILE8:     app_show_map(mapNumber, 8); break;
    case APP_KEY_TILE16:    app_show_map(mapNumber, 16); break;
    case APP_KEY_TILE32:    app_show_map(mapNumber, 32); break;
    case APP_KEY_CASTLES:   showCastles = !showCastles; break;
    default: break;
    }
}

/* A one-pixel box round a cell, in the view.  Purely an aid for reading the
 * map while the simulation is being worked out - the original draws no such
 * thing.  The positions themselves are the game's: cell values 0x14..0x17 mark
 * the four sides' castles, and every one of the 52 maps has exactly one of
 * each. */
static void outline_cell(int cx, int cy, unsigned char colour)
{
    const int n = bank.size;
    int x0 = VIEW_X + (cx - scrollX) * n, y0 = VIEW_Y + (cy - scrollY) * n;
    int i;

    if (x0 < VIEW_X || y0 < VIEW_Y ||
        x0 + n > VIEW_X + VIEW_W || y0 + n > VIEW_Y + VIEW_H) return;
    for (i = 0; i < n; i++) {
        scr.px[(size_t)y0 * SCR_W + x0 + i] = colour;
        scr.px[(size_t)(y0 + n - 1) * SCR_W + x0 + i] = colour;
        scr.px[(size_t)(y0 + i) * SCR_W + x0] = colour;
        scr.px[(size_t)(y0 + i) * SCR_W + x0 + n - 1] = colour;
    }
}

void app_render(void)
{
    memcpy(scr.px, bg.px, sizeof scr.px);
    if (mode != APP_MODE_MAP) return;
    gfx_draw_map(&scr, &map, &bank, VIEW_X, VIEW_Y, scrollX, scrollY,
                 VIEW_W / bank.size + 1, VIEW_H / bank.size + 1);
    if (showCastles) {
        /* The starting state, as the original builds it.  These marks are ours;
         * the game draws no such thing.  Index 6 is the interface yellow and 2
         * its red, neither of which the terrain uses. */
        int i;
        for (i = 0; i < UNIT_SLOTS; i++) {
            const Unit *u = &game.unit[i];
            if (u->flags & 0x80) continue;
            outline_cell(u->pos & 0xff, u->pos >> 8,
                         u->side >= PLAYERS ? 2 : 6);
        }
        for (i = 0; i < PLAYERS; i++)
            if (game.side[i].alive)
                outline_cell(game.side[i].pos & 0xff, game.side[i].pos >> 8, 7);
    }
}
