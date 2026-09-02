#include "app.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The window WAKU leaves for the map, measured off the frame itself: the black
 * rectangle runs x 96..479 and y 8..391, which is 24 by 24 squares of 16.  The
 * dim copies of the panel icons sit inside it at x 96..168 - the game keeps the
 * "not selected" artwork in the one place it knows will be painted over on the
 * first frame, rather than spending memory on a second bank. */
#define VIEW_X 96
#define VIEW_Y 8
#define VIEW_W 384
#define VIEW_H 384

#define MAP_COUNT 52

/* The panel down the left of WAKU: two columns of 32x32 icons, seven rows.
 *
 * The original stores no rectangles at all.  sub_4db2 keeps a single index in
 * [0x3bee] and moves it with index +- 2 for up and down and bit 0 for left and
 * right, which is only correct for a 2 x 7 grid; the pixel positions are baked
 * into the WAKU artwork.  So the geometry here is measured off WAKU (columns at
 * x 8 and 40, rows at the y below) and the order is the game's own: the table
 * of fourteen handlers at DS:0x202d, which sub_1aa6 calls as
 * "call word ptr [bx + 0x202d]".
 *
 * The identifications come from the code each handler runs, not from the
 * pictures:
 *   GO     leaves the panel and lets the world run (it also loads the chosen
 *          map through sub_6033 the first time)
 *   VIEW   sub_1b5f prints DS:0x10f1, which is the string "ＶＩＥＷモード"
 *   TAX    sub_4e9f reads [side + 0x12], the rate that game_develop taxes at
 *   INFO   sub_4f76 lays out four rows, one per country
 *   SPEED  writes [0x3c02], which the cell and unit ticks use as a shift count
 *   ZOOM   writes [0x3c04] and then reloads the graphics: the tile size
 *   ALLY   sub_1cb0; the messages are "@Sと@Sは盟約を交わしました｡"
 *   EDIT   sub_2368, the map editor, whose own panel is WAKU2
 * and the bottom block is the disk menu, whose artwork reads LOAD, MAP, SAVE,
 * FORM, CRT/LCD, DRIVE. */
#define ICON_SIZE 32
enum {
    ICON_GO, ICON_VIEW, ICON_TAX, ICON_INFO, ICON_SPEED, ICON_ZOOM,
    ICON_ALLY, ICON_EDIT, ICON_LOAD, ICON_MAP, ICON_SAVE, ICON_FORM,
    ICON_CRT, ICON_DRIVE, ICON_COUNT
};
static const short iconCol[2] = {8, 40};
static const short iconRow[7] = {24, 56, 120, 184, 248, 280, 312};

/* Which of the fourteen this port actually does something with.  The rest are
 * drawn dim, the way the original draws a command you cannot use. */
static const unsigned char iconLive[ICON_COUNT] = {
    1, 1, 1, 1, 1, 1, 0, 0,        /* GO VIEW TAX INFO SPEED ZOOM ALLY EDIT */
    0, 1, 0, 0, 0, 0               /* LOAD MAP SAVE FORM CRT DRIVE */
};

/* The "not selected" artwork for the eight game icons, which WAKU carries at
 * x 96 and 128 on the same rows - inside the map window, so it survives exactly
 * until the first map is drawn over it.  Snapshotting it in app_init is the
 * port's version of the original reading it out of VRAM before it goes. */
#define DIM_ICONS 8
static unsigned char dimIcon[DIM_ICONS][ICON_SIZE * ICON_SIZE];
static int haveDim;

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

static void snapshot_dim_icons(void);
static int screen_to_icon(int x, int y);

static Screen scr;
/* The backdrop - the title image, or the frame - is decompressed once per mode
 * change rather than per frame: WAKU is three or four BZ streams of 32000 bytes
 * and redoing that every frame would be the whole frame budget. */
static Screen bg;
static Disk *disk;
static Bank bank;
static Map map;
static Game game;
static Map live;                /* the map as the simulation has it now */
static int showCastles;
static int running;
static long ticks;
static int hoverX = -1, hoverY = -1;      /* in cells */
static int hoverIcon = -1;                /* a panel index, 0..13 */
static int viewMode;                      /* the VIEW icon: scroll, do not pick */
static int selected = -1;                 /* a unit slot */
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
    snapshot_dim_icons();
    mode = APP_MODE_MAP;
    mapNumber = number;
    tileSize = size;
    scrollX = scrollY = 0;
    game_init(&game, &map);
    selected = -1;
    game.human = 0;
    live = map;
    running = 0;
    ticks = 0;
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

/* Take the dim artwork out of the map window before anything is drawn over it.
 * WAKU keeps it at x 96 and 128 on the same four rows as the game icons. */
static void snapshot_dim_icons(void)
{
    int i;
    for (i = 0; i < DIM_ICONS; i++) {
        int sx = 96 + (i % 2) * 32, sy = iconRow[i / 2], y;
        for (y = 0; y < ICON_SIZE; y++)
            memcpy(dimIcon[i] + (size_t)y * ICON_SIZE,
                   bg.px + (size_t)(sy + y) * SCR_W + sx, ICON_SIZE);
    }
    haveDim = 1;
}

/* Which icon a screen point is on, or -1. */
static int screen_to_icon(int x, int y)
{
    int c, r;
    for (r = 0; r < 7; r++)
        for (c = 0; c < 2; c++)
            if (x >= iconCol[c] && x < iconCol[c] + ICON_SIZE &&
                y >= iconRow[r] && y < iconRow[r] + ICON_SIZE)
                return r * 2 + c;
    return -1;
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

/* Press one of the panel's fourteen.  The ones this port cannot do say so
 * rather than doing nothing, because a button that silently ignores you is
 * indistinguishable from a broken hit test. */
static void icon_press(int idx)
{
    if (mode != APP_MODE_MAP) return;
    switch (idx) {
    case ICON_GO:
        /* The original's GO leaves the panel and the world starts moving. */
        running = !running;
        snprintf(status, sizeof status, "GO: %s",
                 running ? "running" : "paused");
        break;
    case ICON_VIEW:
        viewMode = !viewMode;
        snprintf(status, sizeof status, "VIEW mode %s (%s)",
                 viewMode ? "on" : "off",
                 viewMode ? "the arrows scroll, clicks do not select"
                          : "clicks select again");
        break;
    case ICON_TAX: {
        /* [side + 0x12].  It drifts on its own towards 18 - funds/256 once the
         * treasury is full, so a setting here is a nudge, not a lock. */
        Side *me = &game.side[game.human < 0 ? 0 : game.human];
        me->rate = (unsigned char)(me->rate >= 17 ? 1 : me->rate + 1);
        snprintf(status, sizeof status, "tax rate %d/256 per square",
                 me->rate);
        break;
    }
    case ICON_INFO: {
        /* The four rows sub_4f76 lays out. */
        int i, n = 0;
        n += snprintf(status + n, sizeof status - n, "INFO ");
        for (i = 0; i < PLAYERS; i++) {
            int plain, claimed;
            game_land_count(&game, i, &plain, &claimed);
            n += snprintf(status + n, sizeof status - n,
                          " %d:%d/%lu%s", i, plain + claimed,
                          game.side[i].funds, game.side[i].alive ? "" : "*");
        }
        break;
    }
    case ICON_SPEED:
        game.speed = (game.speed + 1) % 3;
        snprintf(status, sizeof status, "speed %s",
                 game.speed == 0 ? "fast" :
                 game.speed == 1 ? "normal" : "slow");
        break;
    case ICON_ZOOM:
        app_show_map(mapNumber,
                     tileSize == 8 ? 16 : tileSize == 16 ? 32 : 8);
        break;
    case ICON_MAP:
        app_show_map(mapNumber + 1 >= MAP_COUNT ? 0 : mapNumber + 1, tileSize);
        break;
    default:
        snprintf(status, sizeof status,
                 "%s is in the original but not in this port yet",
                 idx == ICON_ALLY  ? "ALLY"  : idx == ICON_EDIT ? "EDIT" :
                 idx == ICON_LOAD  ? "LOAD"  : idx == ICON_SAVE ? "SAVE" :
                 idx == ICON_FORM  ? "FORM"  : idx == ICON_CRT  ? "CRT/LCD" :
                 "DRIVE");
        break;
    }
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
    case APP_KEY_RUN:       running = !running; break;
    case APP_KEY_STEP:      running = 0; app_tick(); break;
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

/* One turn of the world: the cell sweep and the unit sweep, then the castles
 * take their cut.  The original drives both from its main loop at 0x1a4d. */
void app_tick(void)
{
    int i;
    if (mode != APP_MODE_MAP) return;
    /* The castles collect from inside the cell sweep, when the cursor lands on
     * one - not once a tick.  0x3332 dispatches on the tile. */
    game_tick_cells(&game);
    game_step(&game);
    for (i = 0; i < MAP_W * MAP_H; i++) live.cell[i] = game.cell[i].tile;
    ticks++;
    {
        int p[PLAYERS], c[PLAYERS];
        for (i = 0; i < PLAYERS; i++)
            game_land_count(&game, i, &p[i], &c[i]);
        snprintf(status, sizeof status,
                 "B_%03d.MAP tick %ld  units %d (wild %d)  "
                 "land %d+%d %d+%d %d+%d %d+%d  funds %lu %lu %lu %lu",
                 mapNumber, ticks, game_unit_count(&game, -1),
                 game_unit_count(&game, 4),
                 p[0], c[0], p[1], c[1], p[2], c[2], p[3], c[3],
                 game.side[0].funds, game.side[1].funds,
                 game.side[2].funds, game.side[3].funds);
    }
}

/* Screen pixel -> map cell, or 0 if the point is outside the view. */
static int screen_to_cell(int x, int y, int *cx, int *cy)
{
    if (mode != APP_MODE_MAP || bank.size <= 0) return 0;
    if (x < VIEW_X || y < VIEW_Y || x >= VIEW_X + VIEW_W ||
        y >= VIEW_Y + VIEW_H) return 0;
    *cx = scrollX + (x - VIEW_X) / bank.size;
    *cy = scrollY + (y - VIEW_Y) / bank.size;
    return *cx >= 0 && *cx < MAP_W && *cy >= 0 && *cy < MAP_H;
}

void app_hover(int x, int y)
{
    int cx, cy;
    if (screen_to_cell(x, y, &cx, &cy)) {
        hoverX = cx;
        hoverY = cy;
    } else {
        hoverX = hoverY = -1;
    }
    hoverIcon = mode == APP_MODE_MAP ? screen_to_icon(x, y) : -1;
}

int app_selected(void) { return selected; }

void app_click(int x, int y)
{
    int cx, cy, index, icon;

    icon = mode == APP_MODE_MAP ? screen_to_icon(x, y) : -1;
    if (icon >= 0) {
        icon_press(icon);
        return;
    }
    if (mode == APP_MODE_TITLE) {
        app_show_map(0, tileSize);
        return;
    }
    if (!screen_to_cell(x, y, &cx, &cy)) return;
    if (viewMode) {
        /* VIEW mode: the click centres the window instead of selecting. */
        scrollX = cx - VIEW_W / bank.size / 2;
        scrollY = cy - VIEW_H / bank.size / 2;
        scroll_by(0, 0);
        return;
    }
    index = game_cell_index(cx, cy);

    if (selected < 0) {
        int who = game_cell_occupant(&game, index);
        if (who >= 0 && game_unit_side(&game, who) == game.human)
            selected = who;
        return;
    }
    /* Send it there.  A square that asks for work rather than a walk - water
     * or a rock to fill in, woodland to clear, a bridge to break, a nest to
     * pull down - becomes that order; everything else is a walk.  If it cannot
     * get there the selection just clears. */
    {
        int order = game_job_for(&game, cx, cy);
        if (order) {
            int len = game_order_job(&game, selected, cx, cy);
            snprintf(status, sizeof status, len
                     ? "%s %d,%d: %d squares to walk first"
                     : "%s %d,%d: no way to reach it",
                     order == UNIT_STATE_BRIDGE ? "bridge" :
                     order == UNIT_STATE_FELL   ? "clear the wood at" :
                     order == UNIT_STATE_BREAK  ? "break the bridge at" :
                                                  "pull the nest down at",
                     cx, cy, len);
        } else {
            game_order_move(&game, selected, cx, cy);
        }
    }
    selected = -1;
}

/* Copy the dim artwork over an icon, and outline one. */
static void draw_dim_icon(int idx)
{
    int x = iconCol[idx % 2], y = iconRow[idx / 2], row;
    if (!haveDim || idx >= DIM_ICONS) return;
    for (row = 0; row < ICON_SIZE; row++)
        memcpy(scr.px + (size_t)(y + row) * SCR_W + x,
               dimIcon[idx] + (size_t)row * ICON_SIZE, ICON_SIZE);
}

static void outline_icon(int idx, int colour)
{
    int x = iconCol[idx % 2], y = iconRow[idx / 2], i;
    for (i = 0; i < ICON_SIZE; i++) {
        scr.px[(size_t)y * SCR_W + x + i] = (unsigned char)colour;
        scr.px[(size_t)(y + ICON_SIZE - 1) * SCR_W + x + i] =
            (unsigned char)colour;
        scr.px[(size_t)(y + i) * SCR_W + x] = (unsigned char)colour;
        scr.px[(size_t)(y + i) * SCR_W + x + ICON_SIZE - 1] =
            (unsigned char)colour;
    }
}

void app_render(void)
{
    memcpy(scr.px, bg.px, sizeof scr.px);
    if (mode != APP_MODE_MAP) return;
    if (running) app_tick();
    gfx_draw_map(&scr, &live, &bank, VIEW_X, VIEW_Y, scrollX, scrollY,
                 VIEW_W / bank.size + 1, VIEW_H / bank.size + 1);
    if (hoverX >= 0)
        outline_cell(hoverX, hoverY, 6);
    if (selected >= 0 && !game_unit_free(&game, selected)) {
        int sx, sy;
        game_unit_pos(&game, selected, &sx, &sy);
        outline_cell(sx, sy, 7);
    } else if (selected >= 0) {
        selected = -1;
    }
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
    /* The panel last, so nothing can be drawn over it. */
    {
        int i;
        for (i = 0; i < DIM_ICONS; i++)
            if (!iconLive[i]) draw_dim_icon(i);
        if (running) outline_icon(ICON_GO, 6);
        if (viewMode) outline_icon(ICON_VIEW, 6);
        if (hoverIcon >= 0) outline_icon(hoverIcon, iconLive[hoverIcon] ? 7 : 2);
    }
}
