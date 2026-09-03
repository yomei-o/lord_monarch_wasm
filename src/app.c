#include "app.h"
#include "game.h"
#include "jp.h"
#include "sound.h"

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
/* Measured, not eyeballed.  The staged dim copies are the same artwork, so
 * correlating one against the panel finds where its lit twin is: icon 0 lands
 * at 16,24 with 967 of 1024 pixels agreeing against 781 for the next best
 * offset, every other icon agrees on the same two columns, and cropping
 * (16,24) out of WAKU shows the GO character squarely inside its plate.  An
 * earlier cut had 8 and 40 from lining a grid up by eye, which put every
 * highlight eight pixels to the left of the icon it was meant to be on.
 *
 * The game does keep its own table: sub_4d4a, which draws the blinking cursor
 * on the panel, reads a VRAM offset from DS:0x2055 + index * 4.  Its relative
 * geometry agrees exactly - four bytes (32 pixels) between the columns, 0xa00
 * (32 rows) and 0x1400 (64 rows) between the blocks - but its origin comes out
 * as x 8, y 40 for icon 0, a constant eight pixels left and sixteen rows down
 * from where the artwork actually is once WAKU is assembled.  The offset is the
 * same for all fourteen, so it is a base address of some kind rather than a
 * misreading of the table, and until that is pinned down the artwork's own
 * position is the one to trust: it is where the icons are on the screen. */
static const short iconCol[2] = {16, 48};
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
#define PANEL_TABLE_AT 0x3b4f      /* the three lines across the title's foot */

static unsigned char *progDat;
static unsigned progDatSize;

/* Load a font image from a file, if one is there.  Two candidates, in order:
 * whatever the host handed over already, and then the free font shipped with
 * this - Shinonome, which is public domain and whose licence says in as many
 * words that converting it to another format and embedding it are fine.  The
 * PC-98's own ROM is NEC's and is never shipped, but --fontrom will take one. */
static int font_rom_from_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    long n;
    unsigned char *buf;
    int ok = 0;

    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (n > 0 && (buf = (unsigned char *)malloc((size_t)n)) != 0) {
        if (fread(buf, 1, (size_t)n, f) == (size_t)n)
            ok = app_font_rom(buf, (unsigned)n);
        free(buf);
    }
    fclose(f);
    return ok;
}

/* A pointer to a DS: address inside PROG.DAT, or 0 if it is outside. */
static const unsigned char *dat_at(unsigned addr, unsigned need)
{
    unsigned off = addr - DAT_BASE;
    if (!progDat || addr < DAT_BASE || off + need > progDatSize) return 0;
    return progDat + off;
}

static void snapshot_dim_icons(void);
static int screen_to_icon(int x, int y);
static void confirm_at(int cx, int cy);
static void dlg_cancel(void);
static void dlg_confirm(void);
static void cursor_move(int dx, int dy);
static void follow_cursor(void);
static void panel_move(int dx, int dy);
static const char *icon_name(int idx);
static void stars_init(void);
static void stars_tick(void);

static Screen scr;
/* The backdrop - the title image, or the frame - is decompressed once per mode
 * change rather than per frame: WAKU is three or four BZ streams of 32000 bytes
 * and redoing that every frame would be the whole frame budget. */
static Screen bg;
static Disk *disk;
static Bank bank;
/* The characters.  C_0n0M.CH4 is 256 tiles of 16x16 and holds all four
 * countries; the first 32 are something else, then it runs kind-major and
 * side-minor in blocks of eight frames:
 *
 *   32 + kind * 32 + side * 8 + facing
 *
 * The side order is the one the terrain bank uses for the castle middles
 * 0x14..0x17 - green, red, white, blue - which is how it was pinned down rather
 * than by eye.  Index 15 is the sheet's own background and gfx_blit_tile
 * already treats it as transparent.
 *
 * At 32x32 each country has its own file, C_0n0L1..L4, whose layout has not
 * been worked out yet; at 8x8 there is no character art at all.  Both fall back
 * to a square in the country's colour, which at least says where a unit is. */
static Bank chars;
static int charsOk;
static Font font;
/* The machine's font ROM, if one has been handed over.  With it the dialogs say
 * what the original says; without it they fall back to English, because the
 * kanji simply are not on the floppy.  See src/jp.h. */
static FontRom fontRom;

/* An on-screen dialog, which is where the game's own answers belong: the
 * original draws its windows and menus on the 640 x 400 screen (sub_4a4d lays
 * out a table of lines, sub_49bb the same with one line choosable), and a port
 * that answers in the host's chrome instead does not feel like the game.
 *
 * The text is what the disk's own font can draw, which is ASCII: the kanji in
 * the original's messages come from the PC-98 font ROM and are not on the
 * floppy. */
#define DLG_LINES 14
#define DLG_TEXT 34
enum {
    DLG_NONE, DLG_INFO, DLG_TAX, DLG_SPEED, DLG_ZOOM, DLG_ALLY, DLG_ORDER,
    DLG_FELL, DLG_OVER, DLG_REFUSED, DLG_VIEW
};
static struct {
    int what;                       /* DLG_* , DLG_NONE when closed */
    int lines;
    int first;                      /* the first choosable line */
    int count;                      /* how many are choosable */
    int pick;                       /* 0..count-1 */
    int value[DLG_LINES];           /* what each choice means */
    char line[DLG_LINES][DLG_TEXT];
} dlg;

static void dlg_close(void)
{
    dlg.what = DLG_NONE;
    dlg.lines = dlg.count = dlg.pick = 0;
}

static void dlg_say(const char *t)
{
    if (dlg.lines >= DLG_LINES) return;
    snprintf(dlg.line[dlg.lines], DLG_TEXT, "%s", t);
    dlg.lines++;
}

static void dlg_sayf(const char *fmt, int a, int b, int c)
{
    if (dlg.lines >= DLG_LINES) return;
    snprintf(dlg.line[dlg.lines], DLG_TEXT, fmt, a, b, c);
    dlg.lines++;
}

/* Add a choosable line.  The first one marks where the menu starts. */
static void dlg_choice(const char *t, int value)
{
    if (dlg.lines >= DLG_LINES) return;
    if (!dlg.count) dlg.first = dlg.lines;
    dlg.value[dlg.lines] = value;
    dlg.count++;
    dlg_say(t);
}

static Map map;
static Game game;
static Map live;                /* the map as the simulation has it now */
static int showCastles;
static int running;
static long ticks;
static int hoverX = -1, hoverY = -1;      /* in cells */
static int hoverIcon = -1;                /* a panel index, 0..13 */
/* The original is played on the keyboard, and these are the two things it moves
 * about: a cursor over the map at [0x3be4] and, when the cursor is pushed off
 * the left of the map, an index into the panel at [0x3bee].  sub_4db2 moves the
 * panel one with index +- 2 for up and down and bit 0 for left and right. */
static int curX = MAP_MIN, curY = MAP_MIN;
static int panelIcon = -1;                /* -1 while the cursor is on the map */
static int viewMode;                      /* the VIEW icon: scroll, do not pick */
static int selected = -1;                 /* a unit slot */
static int mode = APP_MODE_TITLE;
static int mapNumber, tileSize = 16, scrollX, scrollY;

/* So the end is announced once rather than every turn. */
static int overSaid;
/* [0xce70], the furthest stage reached.  sub_1afa - the GO icon - starts at it
 * whenever no stage has been chosen (0x1b21 loads [0x3bc2] from it), and the win
 * path increments it only when the stage just cleared is at least as far
 * (0xb3e3).  So clearing stage 5 having already reached 10 puts you back on 10,
 * not on 6, and this port advancing with mapNumber + 1 was wrong for that. */
static int reached;
/* [0x3bd4], the stage is under way.  sub_1afa sets it and sub_b52e refuses a
 * command while it stands: the alliance is one of those, so it can only be
 * arranged before the stage starts. */
static int underWay;

/* 0 = the LOGiN three, 1 = the game's own fifty-two.  mapNumber is the index
 * within whichever is in force, not the file's number. */
/* The names out of NAME.TXT, and how
 * many more frames to show the one just loaded.  The original puts it in the
 * window at DS:0x123f - fifteen cells at (112, 24) - while a
 * map is being chosen; here it goes up for a couple of seconds whenever one
 * is loaded, which is the only time this port chooses. */
static char mapNames[GFX_MAPS][17];
static int nameShow;

/* The tileset's own names - see gfx_load_names.  [1..5] are the countries and
 * [6..21] the sixteen unit states, so a state number indexes from 6. */
static unsigned char names[GFX_NAMES][16];
static int namesOk;

/* What colour each country's bar is.  DS:0x3484 holds five ten-byte records
 * of (plane mask, colour) and PROG.DAT ships them as 0f 04, 0f 02, 0f 07,
 * 0f 00, 0f 0f - green, red, white, black and the monsters' white.  0x6197
 * then overwrites the colour from the first byte of each country's name in
 * the tileset's tail, less 0x10, because those names open with the same
 * colour control. */
#define GRAPH_COLOURS_AT 0x3484
static unsigned char sideColour[5] = { 4, 2, 7, 0, 15 };

/* The window frame, taken off the screen the way sub_977e takes it: three
 * bytes a row for sixteen rows from (96, 8), which is the corner of the frame
 * WAKU already draws round the map.  Every dialog is built out of this. */
static unsigned char frameArt[16][24];
static int frameOk;

/* For the thumbnail of the square under the cursor: the tileset's own 32x32
 * composition table and the 16x16 bank its pieces come from. */
static unsigned char compose[GFX_TILES][4];
static int composeOk;
static Bank pieces;

/* The four character banks the unit box's portrait comes out of.  They hold
 * 16x16 pieces, not 32x32 tiles: sub_8789 reads 128 bytes - four planes of
 * sixteen rows of two - from segment 0x3000 + piece * 8, and sub_8738 puts
 * four of them together as n, n+1 across the top and n+2, n+3 below.  (That
 * is not the order sub_8756 uses for the terrain thumbnail, which goes down
 * the left column first; the two routines walk di differently.)
 *
 * 0x6201, 0x6228, 0x624f and the one after read C_0n0L1..L4 to 0x5000:0000,
 * 0x5000:8000, 0x6000:0000 and 0x6000:8000, and a piece number of 0x400 is
 * exactly 0x50000 - so the four files are characters 0..63, 64..127, 128..191
 * and 192..255 of one run. */
static Bank portraits[4];
static int portraitsOk;

/* 0x7d0e: when the cursor is over nothing, the box keeps whatever it showed
 * last, in [0x32bf]. */
static int boxUnit = -1;
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
    /* The disk's own 8x16 ASCII, and then a font image if one is to be found -
     * with which the dialogs come out in the original's Japanese. */
    gfx_load_font(&font, disk);
    if (!fontRom.loaded) {
        if (!font_rom_from_file("/shinonome.fnt"))
            if (!font_rom_from_file("font/shinonome.fnt"))
                font_rom_from_file("shinonome.fnt");
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

/* ---------------------------------------------------------- the starfield */

/* The title's stars are not in DS7TTL - the disk's three planes hold the logo
 * and nothing else, all of it inside the top eight rows of a 20x10 grid.  They
 * are drawn by the interrupt the title installs at INT 0Ah, which on a PC-98 is
 * IRQ2, the vertical retrace: sub_c6ad (0xc6ad) writes 0x0949 into [0x28], and
 * the loop is at 0x098c.
 *
 * FUN_1000_c946 builds the table.  DS:0x3bb4 holds a count that comes from the
 * machine's speed setting at DS:0x3c1e - 0x80 at level 3, halved for each level
 * below - and DS:0x3bb6 marks the end at base + count*8.  Eight bytes a count
 * means the table is count*2 entries of four:
 *
 *     uint16 position   a byte offset into one 32000-byte plane
 *     uint16 step       0x50, 0xa0 or 0xf0 - one, two or three rows a frame
 *
 * so at level 3 there are 256 stars.  The interrupt walks only [0x3bb4] = 128
 * of them per retrace and remembers where it stopped in DS:0x3bb2, so each star
 * moves every other frame.
 *
 * The dot is four rows of one byte - 0x18, 0x3c, 0x3c, 0x18, a round four-pixel
 * blob - ORed into the E plane on its own: the interrupt sets DS to 0xe000 and
 * touches no other segment.  Over the background, index 0, that reads as index
 * 8, and index 8 is #ddddff, which is what the stars measure in ss0.jpg.
 *
 * A star that steps past the end of the plane is respawned at a random byte
 * column in the top row with a fresh step. */
#define STAR_MAX   256
#define STAR_PLANE 32000
#define STAR_ROW   80              /* bytes across, 640/8 */

static unsigned short starPos[STAR_MAX];
static unsigned short starStep[STAR_MAX];
static int starCount;              /* DS:0x3bb4 * 2 */
static int starWalk;               /* DS:0x3bb4, how many move per frame */
static int starAt;                 /* DS:0x3bb2 */
static unsigned short starRnd;     /* DS:0x3c06, the seed sub_9a36 turns */
static unsigned short starLcg;     /* DS:0x3bb8, the one sub_0a38 turns */

/* sub_9a36: a 16-bit shift register, taps at 15 and 1. */
static unsigned short star_rand(void)
{
    unsigned bit = ((starRnd >> 14) ^ starRnd) & 1;

    starRnd = (unsigned short)((starRnd << 1) | bit);
    return starRnd;
}

/* One of the three steps, chosen the way both the fill loop at 0xc993 and the
 * respawn at 0xa0c do it: one eighth each for the two slow ones. */
static unsigned short star_step_for(unsigned char r)
{
    r &= 7;
    if (r == 0) return 0x50;
    if (r < 2) return 0xa0;
    return 0xf0;
}

/* sub_0a38, the respawn's own generator.  It returns the old high byte in ah
 * and a fresh 7-bit value in al; the caller takes the step from ah and the
 * column from al. */
static unsigned short star_lcg(void)
{
    unsigned short old = starLcg;
    unsigned short next = (unsigned short)(old * 3 + 1);
    unsigned char al = (unsigned char)((old & 0xff) + (next >> 8)) & 0x7f;

    starLcg = (unsigned short)((next & 0x00ff) | ((unsigned)al << 8));
    return (unsigned short)((old & 0xff00) | al);
}

static void stars_init(void)
{
    int i;

    /* DS:0x3c1e is the speed setting the boot menu picks; the shipped default
     * is 3, which is also what ss0.jpg was taken at ("CPU Power Level 3"). */
    starWalk = 0x80;
    starCount = starWalk * 2;
    starAt = 0;
    starRnd = 1;
    starLcg = 1;
    for (i = 0; i < starCount; i++)
        starPos[i] = (unsigned short)(star_rand() & 0x7fff);
    for (i = 0; i < starCount; i++)
        starStep[i] = star_step_for((unsigned char)star_rand());
}

/* Draw one star's four rows into the E plane, which here means setting bit 3
 * of the index.  The original ORs the same bytes into both display pages. */
static void star_draw(unsigned pos)
{
    static const unsigned char row[4] = { 0x18, 0x3c, 0x3c, 0x18 };
    int i;

    for (i = 0; i < 4; i++) {
        unsigned o = pos + (unsigned)i * STAR_ROW;
        int y, x0, b;

        if (o >= STAR_PLANE) return;
        y = (int)(o / STAR_ROW);
        x0 = (int)(o % STAR_ROW) * 8;
        for (b = 0; b < 8; b++)
            if (row[i] >> (7 - b) & 1)
                scr.px[(long)y * SCR_W + x0 + b] |= 8;
    }
}

static void stars_tick(void)
{
    int n;

    for (n = 0; n < starWalk; n++) {
        unsigned pos = starPos[starAt] + starStep[starAt];

        if (pos >= STAR_PLANE) {
            /* Off the bottom: back to the top row, at a fresh column.  The
             * original's `mul 0xa0` on a 7-bit value lands in 0..79. */
            unsigned short r = star_lcg();

            starStep[starAt] = star_step_for((unsigned char)(r >> 8));
            starPos[starAt] = (unsigned short)((r & 0x7f) * 0xa0 >> 8);
        } else {
            starPos[starAt] = (unsigned short)pos;
        }
        star_draw(starPos[starAt]);
        if (++starAt >= starCount) starAt = 0;
    }
    /* The half that is not moving this frame still has to be drawn: the
     * original leaves them standing in VRAM, and this port repaints the
     * backdrop every frame. */
    for (n = 0; n < starCount; n++) star_draw(starPos[n]);
}

/* The panel across the foot of the title, which sub_c946 draws in four steps:
 *
 *   0xc9b5  sub_7c1c  ax=0x0607  x 0..639, y 326..399     the band
 *   0xc9c7  sub_7ad3  ax=0x0107  (73,326) to (0,399)      the left diagonal
 *   0xc9d9  sub_7ad3  ax=0x0107  (566,326) to (639,399)   the right one
 *   0xc9eb            si=0x3b4f                           three lines of text
 *
 * The low byte of each ax is the plane mask and the high byte the colour, so
 * the band is colour 6 and the diagonals colour 1, both through B, R and G
 * with E left to the stars.  Every one of those numbers is confirmed against
 * ss0.jpg to the pixel: the diagonals leave row 326 at x 73 and x 566 and
 * reach row 398 at x 1 and x 638, the band runs the full width, and the text
 * starts at x 240 on rows 336, 356 and 376.
 *
 * One thing does not agree, and it is the colour.  Index 6 is fff in the
 * table at DS:0x24fb and the photo's logo outline - which the picture stores
 * as index 6 - measures #fefefc, so index 6 really is white.  The band, forty
 * thousand pixels of one flat value, measures #abaabc.  It is not a dither
 * (the fill writes 0xff through a solid tile), not the fade (the per-channel
 * fractions disagree), not a global brightness (the loop at 0x7374 scales
 * every entry by the same [0x34d6], and no value fits both fff and 088), and
 * not a second table (nothing on the disk holds aab at index 6).  So the band
 * is drawn here as the code says, index 6, and the photograph is left
 * disagreeing until something explains it.
 */
/* Three of the panel's numbers are written after the boot menu runs, so what
 * PROG.DAT carries for them is the state before anything was detected - and
 * two of the three live above the end of PROG.DAT altogether.  This port
 * answers for itself:
 *
 *   DS:0x3c1e  the speed the boot menu picks.  3 is the shipped default and
 *              what ss0.jpg was taken at.
 *   DS:0x3b3a  which sound driver started.  Nought means the beeper, and
 *              nought is what the file holds because nothing had looked for a
 *              board yet; this port renders an OPN, so it says so.
 *   DS:0xc4e8  the kilobytes the cache driver took.  There is no cache here.
 */
static int panel_runtime(unsigned addr, int *answered)
{
    *answered = 1;
    switch (addr) {
    case 0x3c1e: return 3;
    case 0x3b3a: return 1;
    case 0xc4e8: return 0;
    default: break;
    }
    *answered = 0;
    return 0;
}

/* One line of the panel.  `at` is the byte after the two that gave the screen
 * offset; the return is where the next entry starts.
 *
 * sub_759b finds the string's terminator first (0x75c4: repne scasb, and bx
 * keeps what it found), so the format codes take their operands from just past
 * the NUL, one word each in the order they appear.  A byte below 0x20 is not
 * text: 0x7633 subtracts 0x10 and drops the result in [0x32a9], the colour, so
 * the 0x11 that opens the first line is what makes all three black. */
static unsigned panel_line(unsigned di, unsigned at, int *colour)
{
    char out[128];
    int n = 0, x = (int)(di % 0x50) * 8, y = (int)(di / 0x50);
    unsigned end = at, op;
    const unsigned char *p;

    while ((p = dat_at(end, 1)) != 0 && *p) end++;
    if (!p) return 0;
    op = end + 1;                       /* bx, in the original */

    while ((p = dat_at(at, 1)) != 0 && *p && n < (int)sizeof out - 12) {
        unsigned char c = *p++;

        at++;
        if (c < 0x20) {
            /* The colour applies from here on, so what is already gathered
             * goes out first.  Getting that backwards painted the last line
             * in the colour its own trailing 0x17 leaves for the next one. */
            if (c >= 0x10) {
                out[n] = 0;
                if (n) {
                    gfx_text_sjis(&bg, &font, &fontRom, x, y, out,
                                  (unsigned char)*colour);
                    x += n * 8;
                    n = 0;
                }
                *colour = c - 0x10;
            }
            continue;
        }
        if (c != '@') { out[n++] = (char)c; continue; }

        /* Digits set the width, then one letter says what to print.  Only the
         * three this table uses are here; the other twenty-five characters at
         * DS:0x2847 are for the message strings and are not read yet. */
        {
            int width = 0;
            const unsigned char *q;

            while ((q = dat_at(at, 1)) != 0 && *q >= '0' && *q <= '9') {
                width = width * 10 + (*q - '0');
                at++;
            }
            if (!q) break;
            at++;
            if (*q == 'w' || *q == 'W' || *q == 'b' || *q == 'B') {
                const unsigned char *v = dat_at(op, 2);
                unsigned addr = v ? (unsigned)(v[0] | (v[1] << 8)) : 0;
                const unsigned char *cell = dat_at(addr, 2);
                int value = cell ? (cell[0] | (cell[1] << 8)) : 0;

                int answered = 0;
                int mine = panel_runtime(addr, &answered);

                op += 2;
                if (answered || !cell) value = answered ? mine : 0;
                n += snprintf(out + n, sizeof out - n, "%*d",
                              width ? width : 1, value);
            } else if (*q == '?') {
                /* 0x7763: three words - a selector and the two strings.  The
                 * word at the selector's address decides, and nought picks
                 * the *second* of the two (0x776c jumps to [bx+4] when it is
                 * zero and falls into [bx+2] when it is not).  This had the
                 * branch the other way round and still printed "FM", because
                 * the byte it was reading happened to be zero. */
                const unsigned char *sel = dat_at(op, 6);
                unsigned addr, at2;
                const unsigned char *val, *str;
                int zero = 1;

                if (!sel) break;
                addr = (unsigned)(sel[0] | (sel[1] << 8));
                val = dat_at(addr, 2);
                if (val) zero = !(val[0] | val[1]);
                {
                    int answered = 0;
                    int mine = panel_runtime(addr, &answered);

                    if (answered) zero = !mine;
                }
                at2 = zero ? 4 : 2;
                addr = (unsigned)(sel[at2] | (sel[at2 + 1] << 8));
                op += 6;
                for (str = dat_at(addr, 1); str && *str; str++)
                    if (n < (int)sizeof out - 1) out[n++] = (char)*str;
            }
        }
    }
    out[n] = 0;
    if (n) gfx_text_sjis(&bg, &font, &fontRom, x, y, out,
                         (unsigned char)*colour);
    return op;
}

static void title_panel(void)
{
    unsigned at = PANEL_TABLE_AT;
    /* Nothing is drawn before the first line's 0x11 sets this, and the last
     * line's 0x17 leaves 7 behind for whatever draws next. */
    int colour = 7;

    gfx_grcg_fill(&bg, 0, 326, 639, 399, 7, 6);
    gfx_grcg_line(&bg, 73, 326, 0, 399, 7, 1);
    gfx_grcg_line(&bg, 566, 326, 639, 399, 7, 1);

    for (;;) {
        const unsigned char *p = dat_at(at, 2);
        unsigned di;

        if (!p) return;
        di = (unsigned)(p[0] | (p[1] << 8));
        at += 2;
        if (di == 0xffff) return;
        at = panel_line(di, at, &colour);
        if (!at) return;
    }
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
    /* The background is index 0, and it is black on screen even though the
     * stored table gives index 0 as 06A, a blue.  Three measurements off
     * ss0.jpg agree on that and leave no other reading:
     *
     *   - 74.5% of the picture above the panel is black, and index 0 is 72.4%
     *     of those rows in DS7TTL.  Index 1 is 6,630 pixels, 3%.
     *   - the stars measure #ddddff, which is index 8 exactly - and a star is
     *     the E plane on its own (the interrupt at 0x098c writes 0xe000 and
     *     nothing else), so what it lands on has to be index 0.  Over index 1
     *     it would be index 9, which the table gives as black.
     *   - the logo measures #008888, index 3, exactly.
     *
     * Where the game blanks index 0 has not been found: the palette loop at
     * 0x7374 writes all sixteen entries out of DS:0x3e20, and the crossfade
     * at 0xc630 ends by copying all forty-eight bytes of DS:0x24fb into it.
     * So this is measured, not read, and it is the one thing on this screen
     * that is. */
    scr.pal[0][0] = scr.pal[0][1] = scr.pal[0][2] = 0;
    gfx_clear(&bg, 0);
    if (!gfx_load_screen(&bg, disk, "DS7TTL")) {
        snprintf(status, sizeof status, "DS7TTL: %s", disk_error());
        return 0;
    }
    title_panel();
    stars_init();
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
    gfx_load_map_names(disk, mapNames);
    overSaid = 0;
    underWay = 0;               /* sub_6033 loads it; GO is what starts it */
    nameShow = 120;
    namesOk = gfx_load_names(disk, map.terrain, names);
    composeOk = gfx_load_compose(disk, map.terrain, compose);
    gfx_free_bank(&pieces);
    {
        char pname[32];

        snprintf(pname, sizeof pname, "B_%03dM.CH4", map.terrain);
        if (!gfx_load_bank(&pieces, disk, pname, 16)) composeOk = 0;
    }
    {
        int b;

        portraitsOk = 1;
        for (b = 0; b < 4; b++) {
            char pname[32];

            gfx_free_bank(&portraits[b]);
            snprintf(pname, sizeof pname, "C_%03dL%d.CH4", map.terrain, b + 1);
            if (!gfx_load_bank(&portraits[b], disk, pname, 16)) portraitsOk = 0;
        }
    }
    boxUnit = -1;
    {
        const unsigned char *t = dat_at(GRAPH_COLOURS_AT, 50);
        int k;

        for (k = 0; k < 5; k++) {
            if (t) sideColour[k] = t[k * 10 + 1] & 15;
            if (namesOk && names[1 + k][0] >= 0x10)
                sideColour[k] = (unsigned char)(names[1 + k][0] - 0x10);
        }
    }
    gfx_bank_name(&map, size, bankName, sizeof bankName);
    gfx_free_bank(&bank);
    if (!gfx_load_bank(&bank, disk, bankName, size)) {
        snprintf(status, sizeof status, "%s: %s", bankName, disk_error());
        return 0;
    }
    /* The character bank, when there is one for this size. */
    gfx_free_bank(&chars);
    charsOk = 0;
    if (size == 16) {
        char cname[32];
        snprintf(cname, sizeof cname, "C_%03dM.CH4", map.terrain);
        charsOk = gfx_load_bank(&chars, disk, cname, 16);
    }

    gfx_clear(&bg, 0);
    if (!gfx_load_screen(&bg, disk, "WAKU"))
        snprintf(status, sizeof status, "WAKU: %s", disk_error());
    {
        int r, k;

        for (r = 0; r < 16; r++)
            for (k = 0; k < 24; k++)
                frameArt[r][k] = bg.px[(size_t)(8 + r) * SCR_W + 96 + k];
        frameOk = 1;
    }
    snapshot_dim_icons();
    mode = APP_MODE_MAP;
    mapNumber = number;
    tileSize = size;
    scrollX = scrollY = 0;
    game_init(&game, &map);
    selected = -1;
    game.human = 0;
    /* Start on the gate below your own castle, which is where your one spare
     * unit is standing. */
    curX = game.side[0].pos & 0xff;
    curY = (game.side[0].pos >> 8) + 1;
    if (curY > MAP_MAX) curY = MAP_MAX;
    panelIcon = -1;
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

static const char *icon_name(int idx)
{
    static const char *name[ICON_COUNT] = {
        "GO", "VIEW", "TAX", "INFO", "SPEED", "ZOOM", "ALLY", "EDIT",
        "LOAD", "MAP", "SAVE", "FORM", "CRT/LCD", "DRIVE"
    };
    return idx >= 0 && idx < ICON_COUNT ? name[idx] : "?";
}

/* A country's name out of the tileset's tail, without the colour controls it
 * is wrapped in: the records read <colour>ＧＲＥＥＮ国<colour>, and sub_759b
 * acts on those bytes rather than drawing them.  Falls back to a number. */
static const char *country_name(int side, char *buf, int n)
{
    int k = 0, i;

    if (namesOk && side >= 0 && side < 5) {
        for (i = 0; i < 16 && names[1 + side][i] && k < n - 1; i++)
            if (names[1 + side][i] >= 0x20)
                buf[k++] = (char)names[1 + side][i];
    }
    /* And the wide spaces they are padded with. */
    while (k >= 2 && (unsigned char)buf[k - 2] == 0x81 &&
           (unsigned char)buf[k - 1] == 0x40)
        k -= 2;
    buf[k] = 0;
    if (!k) snprintf(buf, (size_t)n, JP_COUNTRY, side);
    return buf;
}

/* 0xb197, when a country goes: a window and the 0x302 sound. */
static void dlg_open_fell(int side)
{
    char buf[64], who[24];

    dlg_close();
    dlg.what = DLG_FELL;
    snprintf(buf, sizeof buf, JP_DESTROYED, country_name(side, who, sizeof who));
    dlg_say(buf);
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
}

/* The refusals, and their words are the game's rather than mine: sub_4a4d is
 * handed the address of a little table - a word of position, a byte of how many
 * lines with 0x80 as a flag, a byte of height, then that many pointers - and
 * every one of the three guards passes one of these:
 *
 *   DS:0x1153   sub_b509, no stage is loaded or a loss is pending
 *   DS:0x1159   sub_b52e, the stage has started, so this cannot change
 *   DS:0x115f   sub_b571, the player has no country
 *
 * All three then play 0x0702 and wait for a key at sub_c90f.
 */
#define GUARD_NO_STAGE  0x1153
#define GUARD_UNDER_WAY 0x1159
#define GUARD_NO_LAND   0x115f

/* Says every line of one of sub_4a4d's tables. */
static void dlg_say_table(unsigned tableAddr)
{
    const unsigned char *t = dat_at(tableAddr, 4);
    int lines, i;

    if (t) {
        lines = t[2] & 0x7f;
        if (lines > DLG_LINES - 2) lines = DLG_LINES - 2;
        for (i = 0; i < lines; i++) {
            const unsigned char *p = dat_at(tableAddr + 4 + i * 2, 2);
            unsigned at;
            const unsigned char *text;
            if (!p) break;
            at = p[0] | (p[1] << 8);
            text = dat_at(at, 1);
            if (text) dlg_say((const char *)text);
        }
    }
}

static void dlg_open_refused(unsigned tableAddr)
{
    dlg_close();
    dlg.what = DLG_REFUSED;
    dlg_say_table(tableAddr);
    if (dlg.lines == 0) dlg_say("refused");
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
    app_sound(APP_SND_FAILED);          /* 0x0702 at every one of the three */
}

/* The look-around at 0x1b5f.  Its window is the table at DS:0x10f1, which is
 * one line, and while it is up the arrows walk the cursor and either button
 * closes it. */
#define VIEW_TABLE 0x10f1

static void dlg_open_view(void)
{
    dlg_close();
    dlg.what = DLG_VIEW;
    dlg_say_table(VIEW_TABLE);
    if (dlg.lines == 0) dlg_say("VIEW");
}

/* The three guards themselves.  Each answers 1 when the command may go ahead. */
static int guard_stage(void)            /* sub_b509 */
{
    if (mode == APP_MODE_MAP) return 1;
    dlg_open_refused(GUARD_NO_STAGE);
    return 0;
}

static int guard_has_land(void)         /* sub_b571 */
{
    if (game.human >= 0 && game.human < PLAYERS) return 1;
    dlg_open_refused(GUARD_NO_LAND);
    return 0;
}

static int guard_not_started(void)      /* sub_b52e */
{
    if (!underWay) return 1;
    dlg_open_refused(GUARD_UNDER_WAY);
    return 0;
}

/* sub_b2f2 and sub_b28d, and the table DS:0x1105 puts under the first. */
static void dlg_open_over(int won)
{
    char buf[64];
    int p, c, total = 0, i;

    dlg_close();
    dlg.what = DLG_OVER;
    if (won) {
        char who[24];

        snprintf(buf, sizeof buf, JP_WON,
                 country_name(game.human, who, sizeof who));
        dlg_say(buf);
    } else {
        dlg_say(JP_LOST1);
        dlg_say(JP_LOST2);
    }
    dlg_say("");
    snprintf(buf, sizeof buf, JP_DAYS_GONE, game.day);
    dlg_say(buf);
    snprintf(buf, sizeof buf, JP_DAYS_LEFT, game.daysLeft);
    dlg_say(buf);
    game_land_count(&game, game.human & 3, &p, &c);
    for (i = 0; i < MAP_W * MAP_H; i++)
        if (live.cell[i] < CELL_IMPASSABLE) total++;
    snprintf(buf, sizeof buf, JP_HELD_AREA, p + c, total);
    dlg_say(buf);
    snprintf(buf, sizeof buf, JP_HELD_RATE,
             total ? (p + c) * 100 / total : 0);
    dlg_say(buf);
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
}

static void dlg_open_info(void)
{
    int i;
    dlg_close();
    dlg.what = DLG_INFO;
    dlg_say(JP_INFO_TITLE);
    dlg_say("");
    dlg_say(JP_INFO_HEAD);
    for (i = 0; i < PLAYERS; i++) {
        int plain, claimed;
        char buf[DLG_TEXT];
        game_land_count(&game, i, &plain, &claimed);
        snprintf(buf, sizeof buf, " %s%d  %4d  %4d  %6lu%s",
                 i == game.human ? ">" : " ", i, plain, claimed,
                 game.side[i].funds, game.side[i].alive ? "" : JP_GONE);
        dlg_say(buf);
    }
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
}

/* The tax window, as 0x4e49 and 0x4f08 have it.  It is not a menu of rates:
 * it is a bar with a knob, and the arrows walk the knob one notch at a time.
 *
 *   0x4e49   draws tile 0x8a4, fifteen of 0x8a5 and one 0x8a6 at (120,40) -
 *            the bar - and puts the knob 0x8a7 on it
 *   0x4f08   the loop.  sub_c8b0 gives the keys, `and al, 0x6c` keeps four of
 *            them, and bits 2 and 3 are the two directions:
 *              4f45  and ah,ah / je   - nought is as low as it goes
 *              4f4d  cmp ah,0x1e / jae - thirty is as high
 *            each step writes [side + 0x12], which is Side.rate here, and
 *            0x4f5b / 0x4f66 leave with 0x601 either way
 *
 * So every value from 0 to 30 is reachable, nought included - which is what
 * the map is winnable with.  The port used to offer six fixed rates out of a
 * table of its own invention, and the lowest of them was 1.
 */
#define TAX_MAX 30                      /* 0x4f4d */

static void tax_lines(void)
{
    char buf[DLG_TEXT];
    int rate = dlg.value[0], i, n = 0;

    dlg.lines = dlg.count = dlg.pick = 0;
    dlg_say(JP_TAX_TITLE);
    dlg_say("");
    /* The bar, one cell per notch, with the knob where 0x4e49 puts 0x8a7. */
    for (i = 0; i <= TAX_MAX && n < DLG_TEXT - 2; i++)
        buf[n++] = i == rate ? '#' : '-';
    buf[n] = 0;
    dlg_say(buf);
    snprintf(buf, sizeof buf, JP_TAX_ITEM, rate);
    dlg_say(buf);
    dlg_say("");
    dlg_choice(JP_TAX_SET, rate);
}

static void dlg_open_tax(void)
{
    dlg_close();
    dlg.what = DLG_TAX;
    dlg.value[0] = game.side[game.human < 0 ? 0 : game.human].rate;
    if (dlg.value[0] > TAX_MAX) dlg.value[0] = TAX_MAX;
    tax_lines();
}

/* One notch of the knob.  Returns whether the window took the key. */
static int tax_step(int by)
{
    int rate = dlg.value[0] + by;

    if (dlg.what != DLG_TAX) return 0;
    if (rate < 0 || rate > TAX_MAX) {   /* 0x4f45 and 0x4f4d both just wait */
        app_sound(APP_SND_NO);
        return 1;
    }
    dlg.value[0] = rate;
    tax_lines();
    return 1;
}

static void dlg_open_speed(void)
{
    dlg_close();
    dlg.what = DLG_SPEED;
    dlg_say(JP_SPEED_TITLE);
    dlg_say("");
    dlg_choice(JP_FAST, 0);
    dlg_choice(JP_NORMAL, 1);
    dlg_choice(JP_SLOW, 2);
}

static void dlg_open_zoom(void)
{
    dlg_close();
    dlg.what = DLG_ZOOM;
    dlg_say(JP_ZOOM_TITLE);
    dlg_say("");
    dlg_choice(JP_ZOOM16, 16);
    dlg_choice(JP_ZOOM32, 32);
    dlg_choice(JP_ZOOM8, 8);
}

static void dlg_open_ally(void)
{
    int i;
    dlg_close();
    dlg.what = DLG_ALLY;
    dlg_say(JP_ALLY_TITLE);
    dlg_say("");
    for (i = 0; i < PLAYERS; i++) {
        char buf[DLG_TEXT];
        if (i == game.human || !game.side[i].alive) continue;
        {
            char head[DLG_TEXT];
            snprintf(head, sizeof head, JP_ALLY_ITEM, i);
            snprintf(buf, sizeof buf, "%s%s", head,
                     game.side[game.human].ally == i ? JP_ALLY_NOW : "");
        }
        dlg_choice(buf, i);
    }
    dlg_choice(JP_ALLY_NONE, 0x80);
}

/* The order menu, which is what sub_20f0 puts up once a destination has been
 * named: the choices are the ones the square allows. */
static void dlg_open_order(int cx, int cy)
{
    unsigned char t = game.cell[game_cell_index(cx, cy)].tile;
    int mine = game.human;

    dlg_close();
    dlg.what = DLG_ORDER;
    dlg.value[0] = (cy << 8) | cx;              /* remembered in value[0] */
    dlg_sayf(JP_ORDER_TITLE, cx, cy, t);
    dlg_say("");
    dlg_choice(JP_WALK, 2);
    if (t == CELL_ROCK || (t >= CELL_IMPASSABLE && t < CELL_WATER_END))
        dlg_choice(JP_BRIDGE, UNIT_STATE_BRIDGE);
    if (t == CELL_WOOD) {
        dlg_choice(JP_FELL, UNIT_STATE_FELL);
        dlg_choice(JP_THICKEN, UNIT_STATE_PLANT);
    }
    if (t == 0 || (t >= CELL_TERRITORY0 + 4 && t < CELL_TERRITORY0 + 8))
        dlg_choice(JP_PLANT, UNIT_STATE_PLANT);
    if (t >= CELL_TERRITORY0 && t < CELL_TERRITORY0 + PLAYERS &&
        t - CELL_TERRITORY0 != mine)
        dlg_choice(JP_ATTACK, UNIT_STATE_PLANT);
    if (t >= CELL_BRIDGE && t < CELL_BRIDGE_END)
        dlg_choice(JP_BREAK, UNIT_STATE_BREAK);
    if (t == CELL_NEST)
        dlg_choice(JP_NEST, UNIT_STATE_NEST);
    dlg_choice(JP_NOTHING, 0);
}

/* Press one of the panel's fourteen.  The ones this port cannot do say so
 * rather than doing nothing, because a button that silently ignores you is
 * indistinguishable from a broken hit test. */
static void icon_press(int idx)
{
    if (mode != APP_MODE_MAP) return;
    switch (idx) {
    case ICON_GO:
        /* sub_1afa, and it is not a toggle.  It sets [0x3bd4] - the stage is
         * under way - and then does "add sp, 2; ret" at 0x1b52 to throw away
         * the return address and escape the panel loop.  There is no way for it
         * to stop anything: the only refusal is at 0x1b10, when the stage is
         * already under way AND a loss is pending, and that says so with a
         * message and the 0x0702 sound.  Pausing is done by opening the panel,
         * which is why pressing GO twice used to stop the world here and does
         * not in the game. */
        app_sound(APP_SND_OK);
        running = 1;
        underWay = 1;                   /* 0x1b37: [0x3bd4] = 0xffff */
        panelIcon = -1;
        snprintf(status, sizeof status, "GO");
        break;
    /* Every one of these is a panel command that was accepted, and the
     * original says so: 0x1a78 checks that the player has a side and then
     * plays 0x602 before doing the work, and 0x1e5b, 0x202c, 0x2055 and
     * 0x2201 do the same at their own commands.  The comment that used to
     * stand here said they fell through to a sound at the end of the switch.
     * There was no sound at the end of the switch, so opening a dialog made
     * no noise at all. */
    case ICON_VIEW:
        /* 0x1b5f is a loop of its own, not a mode that stays on: it puts up the
         * window DS:0x10f1 names, walks [0x3be4] about with the move sound at
         * 0x1baa, and leaves on either button (0x1b85 confirm, 0x1b89 cancel).
         * A toggle that persisted was this port's invention. */
        if (!guard_stage()) break;
        app_sound(APP_SND_OK);
        dlg_open_view();
        break;
    /* Each of these opens with sub_b509 and nothing else - 0x1c06, 0x1c36,
     * 0x1c21 and 0x1c4d all call it and return on the carry. */
    case ICON_TAX:
        if (!guard_stage()) break;
        app_sound(APP_SND_OK); dlg_open_tax();   break;
    case ICON_INFO:
        if (!guard_stage()) break;
        app_sound(APP_SND_OK); dlg_open_info();  break;
    case ICON_SPEED:
        if (!guard_stage()) break;
        app_sound(APP_SND_OK); dlg_open_speed(); break;
    case ICON_ZOOM:
        if (!guard_stage()) break;
        app_sound(APP_SND_OK); dlg_open_zoom();  break;
    /* 0x1cb0 opens with all three, which is why an alliance can only be
     * arranged before the stage is under way. */
    case ICON_ALLY:
        if (!guard_stage()) break;
        if (!guard_has_land()) break;
        if (!guard_not_started()) break;
        app_sound(APP_SND_OK); dlg_open_ally();  break;
    case ICON_MAP:
        app_sound(APP_SND_OK);
        app_show_map(mapNumber + 1 >= MAP_COUNT ? 0 : mapNumber + 1,
                     tileSize);
        break;
    default:
        app_sound(APP_SND_NO);          /* not a refusal by the game: by me */
        snprintf(status, sizeof status,
                 "%s is in the original but not in this port yet",
                 idx == ICON_EDIT ? "EDIT" :
                 idx == ICON_LOAD  ? "LOAD"  : idx == ICON_SAVE ? "SAVE" :
                 idx == ICON_FORM  ? "FORM"  : idx == ICON_CRT  ? "CRT/LCD" :
                 "DRIVE");
        break;
    }
}

/* Cancel.  sub_4be9 hands the carry back and the caller decides; the order menu
 * at 0x2238 puts the unit back in your hand to be sent somewhere else, and
 * everything else simply closes.  The window that announces a fall or the end of
 * a stage has no cancel at all - sub_c90f and sub_c921 wait for any key and
 * carry on - so cancel there does what confirm does. */
static void dlg_cancel(void)
{
    switch (dlg.what) {
    case DLG_ORDER:
        dlg_close();
        snprintf(status, sizeof status,
                 "still holding the unit - say where it should go");
        break;                      /* selected is left alone: choose again */
    case DLG_FELL:
    case DLG_OVER:
    case DLG_REFUSED:
        dlg_confirm();              /* these only wait for a key */
        break;
    default:
        dlg_close();
        snprintf(status, sizeof status, "cancelled");
        break;
    }
}

/* Confirm inside a dialog. */
static void dlg_confirm(void)
{
    int line = dlg.first + dlg.pick;
    int value = dlg.value[line];
    int what = dlg.what;

    switch (what) {
    case DLG_INFO:
    case DLG_REFUSED:
    case DLG_VIEW:
        dlg_close();
        break;
    case DLG_OVER:
        dlg_close();
        /* 0xb433 onwards.  A win: the last of the fifty-two goes to the ending
         * (0xb446 sub_b661), and anything else falls into sub_b58f and then
         * sub_6315, which is the whole of the stage advance -
         *
         *     [0x3bc2] = [0xce70]      the stage just reached
         *     [0x3bd6] = 0             this one is not finished
         *     sub_6033                 load its map
         *
         * and note what it does NOT clear: [0x3bd4], the flag that says the
         * stage is under way.  0x1afa (GO) reads it, so the next map arrives
         * already running rather than waiting to be started.
         *
         * A loss is sub_b28d, which sets [0x3bd6] to -1 and calls sub_6033
         * with [0x3bc2] untouched: the same stage again.  It leaves [0x3bd6]
         * set, so its GO refuses at 0x1b10 until the stage is entered afresh -
         * here that reads as the map coming back up paused. */
        if (overSaid == 1) {
            /* 0xb3e3: the counter only moves when this stage was the furthest
             * one, and then 0x6315 starts whatever [0xce70] now names. */
            if (mapNumber >= reached && reached + 1 < MAP_COUNT) reached++;
            if (reached < MAP_COUNT) {
                app_show_map(reached, tileSize);
                running = 1;
            } else {
                app_show_title();       /* sub_b661, which is not ported */
                snprintf(status, sizeof status, "all %d stages cleared",
                         MAP_COUNT);
            }
        } else {
            /* sub_b28d leaves [0x3bc2] alone: the same stage, and paused. */
            app_show_map(mapNumber, tileSize);
        }
        break;
    case DLG_TAX:
        game.side[game.human < 0 ? 0 : game.human].rate = (unsigned char)value;
        snprintf(status, sizeof status, "tax rate %d of %d", value, TAX_MAX);
        dlg_close();
        break;
    case DLG_SPEED:
        game.speed = value;
        snprintf(status, sizeof status, "speed %s",
                 value == 0 ? "fast" : value == 1 ? "normal" : "slow");
        dlg_close();
        break;
    case DLG_ZOOM:
        dlg_close();
        app_show_map(mapNumber, value);
        break;
    case DLG_ALLY: {
        /* An alliance holds from both ends, and sub_b102 breaks it from both
         * ends when a country falls, so it is set the same way. */
        Side *me = &game.side[game.human < 0 ? 0 : game.human];
        if (me->ally < PLAYERS) game.side[me->ally].ally = 0x80;
        if (value < PLAYERS) {
            me->ally = (unsigned char)value;
            game.side[value].ally = (unsigned char)game.human;
            snprintf(status, sizeof status, "allied with country %d", value);
        } else {
            me->ally = 0x80;
            snprintf(status, sizeof status, "no alliance");
        }
        dlg_close();
        break;
    }
    case DLG_ORDER: {
        int cx = dlg.value[0] & 0xff, cy = dlg.value[0] >> 8;
        int who = selected, len = 0;
        dlg_close();
        selected = -1;
        if (who < 0 || game_unit_free(&game, who)) {
            snprintf(status, sizeof status, "the unit is gone");
            break;
        }
        if (value == 0) {
            app_sound(APP_SND_NO);
            snprintf(status, sizeof status, "no order given");
            break;
        }
        if (value == 2) {
            len = game_order_move(&game, who, cx, cy);
            app_sound(len ? APP_SND_OK : APP_SND_FAILED);
            snprintf(status, sizeof status, len ? "walking to %d,%d, %d squares"
                                                : "no way to %d,%d",
                     cx, cy, len);
        } else {
            static const char *what[16] = {
                0, 0, 0, 0, 0, 0, "plant", "bridge", 0, "clear",
                "break", "nest", 0, 0, 0, 0
            };
            const char *name = what[value & 15] ? what[value & 15] : "order";
            len = game_order(&game, who, cx, cy, value);
            app_sound(len ? APP_SND_OK : APP_SND_FAILED);
            if (len)
                snprintf(status, sizeof status,
                         "%s %d,%d - %d squares to walk first", name, cx, cy,
                         len);
            else
                snprintf(status, sizeof status, "cannot reach %d,%d for %s",
                         cx, cy, name);
        }
        break;
    }
    default:
        dlg_close();
        break;
    }
}

/* Move the cursor one square, and step into the panel when it is pushed off the
 * left of the map - which is what the original does: sub_269e watches for the
 * cursor leaving at column 0 and hands over to the panel. */
static void cursor_move(int dx, int dy)
{
    int nx = curX + dx, ny = curY + dy;

    if (nx < MAP_MIN) {
        /* Off the left: into the panel, on the row nearest the cursor. */
        int row = (curY - MAP_MIN) * 7 / (MAP_MAX - MAP_MIN + 1);
        if (row > 6) row = 6;
        panelIcon = row * 2;
        snprintf(status, sizeof status, "panel: %s", icon_name(panelIcon));
        return;
    }
    if (nx > MAP_MAX) nx = MAP_MAX;
    if (ny < MAP_MIN) ny = MAP_MIN;
    if (ny > MAP_MAX) ny = MAP_MAX;
    curX = nx;
    curY = ny;
    follow_cursor();
    {
        int index = game_cell_index(curX, curY);
        int who = game_cell_occupant(&game, index);
        snprintf(status, sizeof status,
                 "%d,%d  tile %02x amount %d%s%s", curX, curY,
                 game.cell[index].tile, game.cell[index].amount,
                 who >= 0 ? "  unit of side " : "",
                 who >= 0 ? (game_unit_side(&game, who) == 0 ? "0 (yours)" :
                             game_unit_side(&game, who) == 1 ? "1" :
                             game_unit_side(&game, who) == 2 ? "2" :
                             game_unit_side(&game, who) == 3 ? "3" : "nobody")
                          : "");
    }
}

void app_key(int key)
{
    if (mode == APP_MODE_TITLE) {
        if (key == APP_KEY_START) app_show_map(0, tileSize);
        return;
    }
    /* A dialog takes the keys while it is up, which is what the original does:
     * sub_4be9 sits on the input until the menu is answered. */
    /* A window has the keys while it is up, and sub_4be9 is exact about what
     * happens to each one:
     *
     *   sub_4ca1   moves the selection by one and REFUSES at either end - it
     *              returns with the carry set and 0x4c2c goes straight back to
     *              waiting, so pressing up at the top does nothing at all, not
     *              even a click.  There is no wrapping.
     *   0x4c2e     a move that did happen plays 0x0500
     *   0x4c89     confirm plays 0x0601 and returns with the carry clear
     *   0x4c94     cancel returns with the carry SET, and it is the caller that
     *              decides what that means - for the order menu at 0x2238 it is
     *              "choose again", not "forget it"
     *   0x4c10     "and al, bh" - only the buttons the caller asked for get
     *              through, and every caller passes 0x63: up, down, confirm and
     *              cancel.  Left and right are not among them, so in a menu
     *              they do nothing.  The tax window is not a menu but the
     *              slider at sub_531d, which is why it alone takes them.
     */
    /* The look-around is its own loop in the original (0x1b7e), and while it is
     * up the arrows are the cursor's rather than the window's. */
    if (dlg.what == DLG_VIEW) {
        switch (key) {
        case APP_KEY_LEFT:  cursor_move(-1, 0); return;
        case APP_KEY_RIGHT: cursor_move(1, 0);  return;
        case APP_KEY_UP:    cursor_move(0, -1); return;
        case APP_KEY_DOWN:  cursor_move(0, 1);  return;
        case APP_KEY_START:                     /* 0x1b85 */
        case APP_KEY_BACK:                      /* 0x1b89 - either one */
            dlg_close();
            snprintf(status, sizeof status, "back from VIEW");
            return;
        default:
            return;
        }
    }

    if (dlg.what != DLG_NONE) {
        switch (key) {
        case APP_KEY_LEFT:
            tax_step(-1);           /* the slider, sub_539f, takes these */
            return;
        case APP_KEY_RIGHT:
            tax_step(1);
            return;
        case APP_KEY_UP:
            if (tax_step(-1)) return;
            if (dlg.pick > 0) {
                dlg.pick--;
                app_sound(APP_SND_MOVE);        /* 0x4c2e */
            }
            return;                             /* 0x4cab: no wrap, no sound */
        case APP_KEY_DOWN:
            if (tax_step(1)) return;
            if (dlg.pick + 1 < dlg.count) {
                dlg.pick++;
                app_sound(APP_SND_MOVE);
            }
            return;                             /* 0x4cb3: no wrap, no sound */
        case APP_KEY_START:
            app_sound(APP_SND_CONFIRM);         /* 0x4c8a */
            dlg_confirm();
            return;
        case APP_KEY_BACK:
            dlg_cancel();
            return;
        default:
            return;                 /* 0x4c10 lets nothing else through */
        }
    }

    /* In the panel the arrows walk the icons and confirm presses one; cancel
     * comes back to the map.  On the map the arrows move the cursor, confirm is
     * the two-step order, and cancel opens the panel - the original does the
     * same, 0x1a9b jumping back into the panel loop at 0x193f. */
    if (panelIcon >= 0) {
        switch (key) {
        case APP_KEY_LEFT:  panel_move(-1, 0); break;
        case APP_KEY_RIGHT: panel_move(1, 0); break;
        case APP_KEY_UP:    panel_move(0, -1); break;
        case APP_KEY_DOWN:  panel_move(0, 1); break;
        case APP_KEY_START: icon_press(panelIcon); return;
        case APP_KEY_BACK:
            panelIcon = -1;
            snprintf(status, sizeof status, "back to the map");
            return;
        default: break;
        }
        if (key == APP_KEY_LEFT || key == APP_KEY_RIGHT ||
            key == APP_KEY_UP || key == APP_KEY_DOWN) {
            snprintf(status, sizeof status, "panel: %s", icon_name(panelIcon));
            return;
        }
    } else {
        switch (key) {
        case APP_KEY_LEFT:  cursor_move(-1, 0); return;
        case APP_KEY_RIGHT: cursor_move(1, 0); return;
        case APP_KEY_UP:    cursor_move(0, -1); return;
        case APP_KEY_DOWN:  cursor_move(0, 1); return;
        case APP_KEY_START: confirm_at(curX, curY); return;
        case APP_KEY_BACK:
            if (selected >= 0) {
                selected = -1;
                snprintf(status, sizeof status, "put it down again");
                return;
            }
            panelIcon = 0;
            snprintf(status, sizeof status, "panel: %s", icon_name(0));
            return;
        default: break;
        }
    }
    switch (key) {
    case APP_KEY_PREV_MAP:  app_show_map(mapNumber - 1, tileSize); break;
    case APP_KEY_NEXT_MAP:  app_show_map(mapNumber + 1, tileSize); break;
    case APP_KEY_TILE8:     app_show_map(mapNumber, 8); break;
    case APP_KEY_TILE16:    app_show_map(mapNumber, 16); break;
    case APP_KEY_TILE32:    app_show_map(mapNumber, 32); break;
    case APP_KEY_CASTLES:   showCastles = !showCastles; break;
    case APP_KEY_RUN:       running = !running; break;
    case APP_KEY_STEP:      running = 0; app_tick(); break;
    case APP_KEY_TITLE:     app_show_title(); break;
    case APP_KEY_MONEY:
        if (mode == APP_MODE_MAP && game.human >= 0 && game.human < PLAYERS) {
            game.side[game.human].funds = APP_MONEY_MAX;
            game.purseMoved = 1;
            snprintf(status, sizeof status,
                     "cheat: side %d has %lu now", game.human,
                     game.side[game.human].funds);
        }
        break;
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

/* A square of colour, for when there is no character art at this size. */
static void fill_cell(int cx, int cy, unsigned char colour, int inset)
{
    const int n = bank.size;
    int x0 = VIEW_X + (cx - scrollX) * n, y0 = VIEW_Y + (cy - scrollY) * n;
    int x, y;

    if (x0 < VIEW_X || y0 < VIEW_Y ||
        x0 + n > VIEW_X + VIEW_W || y0 + n > VIEW_Y + VIEW_H) return;
    for (y = inset; y < n - inset; y++)
        for (x = inset; x < n - inset; x++)
            scr.px[(size_t)(y0 + y) * SCR_W + x0 + x] = colour;
}

/* The colour each country is drawn in, taken from its own castle middle in the
 * terrain bank rather than chosen: 0x14 + side. */
static unsigned char side_colour(int side)
{
    static const unsigned char c[SIDES] = {12, 2, 7, 13, 6};
    return side >= 0 && side < SIDES ? c[side] : 6;
}

/* Every unit inside the window.  The original draws these from its own display
 * list; here it is a straight sweep, which comes to the same picture. */
static void draw_units(void)
{
    int i;
    for (i = 0; i < UNIT_SLOTS; i++) {
        const Unit *u = &game.unit[i];
        int x, y, sprite;
        if (u->flags & 0x80) continue;
        x = u->pos & 0xff;
        y = u->pos >> 8;
        if (x < scrollX || y < scrollY) continue;
        if (x >= scrollX + VIEW_W / bank.size) continue;
        if (y >= scrollY + VIEW_H / bank.size) continue;

        if (!charsOk) {
            fill_cell(x, y, side_colour(u->side), bank.size / 4);
            continue;
        }
        if (u->side >= PLAYERS) {
            sprite = 176 + (u->facing & 7);      /* the wild ones */
        } else {
            sprite = 32 + (u->side & 3) * 8 + (u->facing & 7);
        }
        if (sprite < chars.count)
            gfx_blit_tile(&scr, &chars, (unsigned char)sprite,
                          VIEW_X + (x - scrollX) * bank.size,
                          VIEW_Y + (y - scrollY) * bank.size);
        else
            fill_cell(x, y, side_colour(u->side), bank.size / 4);
    }
}

/* sub_ac00: which of the 256 character tiles a unit shows as.  The pieces of
 * it are the side (times eight), the way it is facing (bits 1 and 2 of +0x01),
 * one bit of the turn counter so it walks, and a rank taken from what it is
 * carrying - unless bit 5 of its state says it is the lord, which outranks
 * everything.  A unit with no move left this turn (flags bit 0), one that is
 * dying (bit 1) and the wild ones (side 4) each have their own block. */
static int portrait_tile(const Unit *u, int turn)
{
    int anim = (turn >> 1) & 1;
    int dl;

    if (u->side == 4) {                             /* 0xac50 */
        if (u->flags & 2) return (0xc8 | u->want) & 0xff;
        return 0xc0 | anim | (u->facing & 6);
    }
    if (u->flags & 2) {                             /* 0xaca3 */
        dl = (u->state & 0x20) ? 0xa4 : 0xa0;
        return (dl | (u->side << 3) | u->want) & 0xff;
    }
    if (u->flags & 1) {                             /* 0xac71 */
        dl = (u->state & 0x20) ? 0x86
           : u->carrying >= 10000 ? 0x84
           : u->carrying >= 1000 ? 0x82 : 0x80;
        return (dl | (u->side << 3) | anim) & 0xff;
    }
    dl = (u->state & 0x20) ? 0x60                   /* 0xac16 */
       : u->carrying >= 10000 ? 0x40
       : u->carrying >= 1000 ? 0x20 : 0;
    return (dl | (u->side << 3) | anim | (u->facing & 6)) & 0xff;
}

/* One turn of the world: the cell sweep and the unit sweep, then the castles
 * take their cut.  The original drives both from its main loop at 0x1a4d. */
void app_tick(void)
{
    int i;
    if (mode != APP_MODE_MAP) return;
    /* The castles collect from inside the cell sweep, when the cursor lands on
     * one - not once a tick.  0x3332 dispatches on the tile. */
    /* 0x1a43 bumps the turn counter before the sweeps and 0x1a56 reads it
     * after them, so the order here is the interrupt's. */
    {
        unsigned long was = game.human >= 0 && game.human < PLAYERS
                            ? game.side[game.human].funds : 0;

        game.turn = (game.turn + 1) & 0xff;
        game_tick_cells(&game);
        game_step(&game);
        game_day(&game);
        game.purseMoved = game.human >= 0 && game.human < PLAYERS &&
                          game.side[game.human].funds != was;
        game_endgame(&game);
    }

    /* What the world did that the screen has to say.  Neither of these touches
     * the run flag, and neither does the original: 0xb197 opens its window,
     * plays 0x302, waits at sub_72ad and closes at sub_c921, and the code
     * after that just carries on.  A window stops the world only because the
     * wait is blocking, which is what app_frame does now - so closing one puts
     * the game back exactly as it was, without a press of GO. */
    if (game.fellSide >= 0) {
        int who = game.fellSide;

        game.fellSide = -1;
        app_sound(APP_SND_FALLEN);              /* 0xb19e */
        dlg_open_fell(who);
    } else if (game.over && !overSaid) {
        overSaid = game.over;
        app_sound(game.over == 1 ? APP_SND_OK : APP_SND_FALLEN);
        dlg_open_over(game.over == 1);
    }
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
    (void)hoverIcon;
}

int app_selected(void) { return selected; }

/* Which dialog is up, 0 for none, so a headless run can see the same thing a
 * player sees.  The values are the DLG_* order: INFO TAX SPEED ZOOM ALLY
 * ORDER. */
/* sub_0d12, and the read that empties it. */
static int pendingSound;

void app_sound(int idAndPriority)
{
    if ((idAndPriority & 0xff) >= (pendingSound & 0xff))
        pendingSound = idAndPriority;
}

int app_sound_take(void)
{
    int s = pendingSound;
    pendingSound = 0;
    return s;
}

/* Whether the world is advancing.  The host has to ask rather than keep its own
 * flag: GO on the panel and the R key both toggle this, and a host that only
 * watched its own key handling would sit still after GO was pressed - which is
 * exactly what happened, and it looked like the game had stopped producing
 * soldiers rather than like the clock had stopped. */
int app_running(void) { return running; }

/* [0xce70].  A host or a test can ask how far the player has got. */
int app_reached(void) { return reached; }
int app_map_number(void) { return mapNumber; }

int app_effect_pcm(int id, short *out, int maxSamples, int rate)
{
    if (!progDat) return 0;
    return snd_render_effect(progDat, progDatSize, id, out, maxSamples, rate);
}

/* See app.h. */
static SndSong song;
static unsigned char *songData;
static int songOn;

int app_song_wanted(void)
{
    if (mode == APP_MODE_TITLE) return 4;       /* 0x00fe */
    if (mode == APP_MODE_MAP) {                 /* 0x1945 */
        int set = map.terrain / 10;

        /* sub_b2f2 puts 1 in [0x3bc6] when the game is won and sub_b28d puts
         * 2 there when it is lost, before loading and starting it. */
        if (game.over == 1) return 1;
        if (game.over == 2) return 2;
        if (set < 1) return 0;
        /* 0x1979: the low bit picks the second of the terrain's pair, and
         * sub_a75d is what sets it - see Game.songHot. */
        return (16 + 2 * (set - 1)) | (game.songHot ? 1 : 0);
    }
    return 0;
}

int app_song_start(int number, int rate)
{
    char name[32];
    unsigned n = 0;

    songOn = 0;
    free(songData);
    songData = 0;
    if (!disk || !progDat || number <= 0) return 0;
    snprintf(name, sizeof name, "FM%03d.DAT", number);
    songData = disk_read_bz(disk, name, &n);
    if (!songData) return 0;
    songOn = snd_song_open(&song, progDat, progDatSize, songData, n, rate);
    if (!songOn) { free(songData); songData = 0; }
    return songOn;
}

int app_song_fill(short *out, int frames)
{
    if (!songOn) return 0;
    return snd_song_fill(&song, out, frames);
}

int app_song_playing(void) { return songOn; }

int app_song_effect(int id)
{
    if (!songOn) return 0;
    return snd_song_effect(&song, id);
}

int app_japanese(void) { return fontRom.loaded; }

int app_font_rom(const unsigned char *data, unsigned n)
{
    return gfx_font_rom(&fontRom, data, n);
}

int app_dialog(void) { return dlg.what; }
int app_dialog_lines(void) { return dlg.lines; }
const char *app_dialog_line(int i)
{
    return i >= 0 && i < dlg.lines ? dlg.line[i] : "";
}
int app_dialog_pick(void) { return dlg.count ? dlg.pick : -1; }

/* Confirm on a square: sub_20f0.  The first press picks up one of your units,
 * the second says where it should go and what it should do there. */
static void confirm_at(int cx, int cy)
{
    int index = game_cell_index(cx, cy);

    if (selected < 0) {
        int who = game_cell_occupant(&game, index);
        if (who < 0 || game_unit_side(&game, who) != game.human) {
            app_sound(APP_SND_NO);              /* 0x22c5 */
            snprintf(status, sizeof status,
                     "%d,%d: none of yours there", cx, cy);
            return;
        }
        app_sound(APP_SND_OK);                  /* 0x2201 */
        selected = who;
        snprintf(status, sizeof status,
                 "picked up the unit on %d,%d carrying %d - now say where "
                 "it should go",
                 cx, cy, game.unit[who].carrying);
        return;
    }
    /* A destination has been named, so the order menu goes up - which is what
     * sub_20f0 does, rather than deciding for the player from the terrain.  The
     * one exception is the lord, for which sub_20f0 skips the menu (0x2208
     * tests bit 0x20 and jumps straight to storing the destination): it has one
     * thing it can do, which is walk. */
    if (game.unit[selected].state & 0x20) {
        int len = game_order_move(&game, selected, cx, cy);
        app_sound(len ? APP_SND_OK : APP_SND_FAILED);
        snprintf(status, sizeof status, len
                 ? "the lord is walking to %d,%d, %d squares"
                 : "no way for the lord to reach %d,%d",
                 cx, cy, len);
        selected = -1;
        return;
    }
    dlg_open_order(cx, cy);
}

/* Where the dialog is drawn, so a click can be turned back into a line. */
#define DLG_X (VIEW_X + 24)
#define DLG_Y (VIEW_Y + 40)
#define DLG_W (DLG_TEXT * 8 + 16)
#define DLG_LINE 16

void app_click(int x, int y)
{
    int cx, cy, icon;

    if (dlg.what != DLG_NONE) {
        int row = (y - DLG_Y - 8) / DLG_LINE;
        if (x >= DLG_X && x < DLG_X + DLG_W &&
            row >= dlg.first && row < dlg.first + dlg.count) {
            dlg.pick = row - dlg.first;
            dlg_confirm();
        } else {
            dlg_close();
        }
        return;
    }

    icon = mode == APP_MODE_MAP ? screen_to_icon(x, y) : -1;
    if (icon >= 0) {
        /* Press it, but leave the keyboard where it was: a mouse click is not
         * the same as walking the cursor into the panel, and moving the focus
         * here meant the arrows silently stopped moving the map cursor and
         * cancel closed the panel instead of opening it. */
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
    panelIcon = -1;
    curX = cx;
    curY = cy;
    confirm_at(cx, cy);
}

/* sub_a656: the window is centred on the cursor and then clamped - scroll =
 * cursor - half the window - rather than nudged along when the cursor reaches
 * an edge.  It reads quite differently in the hand: the map moves under a
 * cursor that stays in the middle. */
static void follow_cursor(void)
{
    int wide, high;
    if (bank.size <= 0) return;
    wide = VIEW_W / bank.size;
    high = VIEW_H / bank.size;
    scrollX = curX - wide / 2;
    scrollY = curY - high / 2;
    scroll_by(0, 0);                    /* clamps to 0..MAP - window */
}

/* sub_4db2: two columns and seven rows, walked as one index. */
static void panel_move(int dx, int dy)
{
    int n = panelIcon;
    if (dy) {
        n += dy * 2;
        if (n < 0 || n >= ICON_COUNT) return;
        panelIcon = n;
        return;
    }
    if (dx < 0) {
        if (!(n & 1)) return;           /* already the left column */
        panelIcon = n & ~1;
    } else if (dx > 0) {
        if (n & 1) return;
        panelIcon = n | 1;
    }
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
    if (mode == APP_MODE_TITLE) {
        stars_tick();
        return;
    }
    if (mode != APP_MODE_MAP) return;
    /* A window is modal.  sub_4a4d puts it up and sub_72ad sits there until it
     * is answered, so nothing in the world moves while one is open - the port
     * used to keep ticking behind them, which is why the day count and the
     * fighting ran on under the tax and info windows. */
    /* And so is the panel, for the same reason: sub_1aa6 is a loop that sits on
     * the input, so nothing in the world moves while the panel is up.  GO is
     * what leaves it (0x1b52 discards the return address to escape the loop),
     * and that is the only way the world starts again.  The original has no
     * pause command because it does not need one - opening the panel IS the
     * pause. */
    if (running && dlg.what == DLG_NONE && panelIcon < 0) app_tick();
    /* Exactly as many squares as the window holds, and not one more: gfx_draw_map
     * does not clip, and the extra row and column this used to ask for spilled a
     * whole tile over the right and bottom edges of WAKU's frame - which reads
     * as the frame being in the wrong place rather than as the map being too
     * big.  Scrolling is by whole squares, so there is never a part-tile edge
     * to cover. */
    gfx_draw_map(&scr, &live, &bank, VIEW_X, VIEW_Y, scrollX, scrollY,
                 VIEW_W / bank.size, VIEW_H / bank.size);
    /* No marker under the pointer.  The original has no mouse at all - there is
     * not one mouse port in the whole binary - so a box following the cursor is
     * an invention of this port, and drawing over the terrain to show where the
     * cursor is caused more trouble than it was worth.  Nothing is drawn for
     * the picked-up unit either: the original draws no such marker, so the
     * status line says which unit is in hand instead of the port painting over
     * the terrain to show it. */
    if (selected >= 0 && game_unit_free(&game, selected)) selected = -1;
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
    draw_units();

    /* The keyboard cursor.  This one the original does draw - it is the only
     * thing it has, being played on the keyboard - so unlike a box following a
     * mouse it belongs on the screen. */
    if (panelIcon < 0) outline_cell(curX, curY, selected >= 0 ? 7 : 6);

    /* The calendar on the right, over WAKU's own "days" and "Left".
     *
     * 0x7ccf clears five cells at VRAM 0x1e3d and draws DS:0x131a - "@5w"
     * against [0x3bcc] - and 0x7cde does the same at 0x1e46 with DS:0x1320,
     * whose "@?" picks a word and then prints [0x3bca].  0x1e3d is row 96 byte
     * 61 and 0x1e46 is row 96 byte 70, so x 488 and x 560, five columns each.
     * ss3.jpg has "293" in the last three of the first five and "2907" in the
     * last four of the second, in white, which is index 7 in the tileset's own
     * table - so five columns, right-aligned, and not zero-padded. */
    {
        char buf[16];

        snprintf(buf, sizeof buf, "%5d", game.day > 99999 ? 99999 : game.day);
        gfx_text_sjis(&scr, &font, &fontRom, 488, 96, buf, 7);
        snprintf(buf, sizeof buf, "%5d",
                 game.daysLeft > 99999 ? 99999 : game.daysLeft);
        gfx_text_sjis(&scr, &font, &fontRom, 560, 96, buf, 7);
    }

    /* The land graph, from sub_9355 and sub_93c5.
     *
     * sub_93c5 finds the largest of the five sides' land totals - the 32-bit
     * value at +8 of each record at DS:0xc792, which game_land_totals keeps -
     * counts the bits in its high word and adds one; that shift, plus the
     * eight the code takes by reading a high byte, is what every total is
     * divided by, so the tallest bar just fits.  Anything left over rounds the
     * height up (0x9440), and 127 is the cap (0x9443).
     *
     * Then sub_9355 draws.  Each bar is one byte wide - eight pixels - at
     * VRAM 0x666f, which is row 327 x 504, and the next is three bytes on, so
     * 24 apart.  It goes up a row at a time (0x9389 adds -0x50) writing 0x5a,
     * which is a half dither, through the graphic charger in the country's
     * own colour with every plane enabled. */
    {
        unsigned long best = 0;
        int k, shift = 0;
        unsigned hi;

        for (k = 0; k < SIDES && k < 5; k++)
            if (game.side[k].landTotal > best) best = game.side[k].landTotal;
        hi = (unsigned)((best >> 16) & 0xffff);
        while (hi) { shift++; hi >>= 1; }
        shift++;                                /* 0x93f4 */

        for (k = 0; k < SIDES && k < 5; k++) {
            /* Two bars a country, eight pixels each and side by side: the
             * land at VRAM 0x666f, x 504, and at 0x6670, x 512, what its lord
             * is carrying - 0x94ae follows the side record's +6 to the lord
             * and reads that unit's own +6.  The pair repeats every three
             * bytes, so 24 pixels. */
            int lord = game.side[k].lord;
            unsigned long bar[2];
            int b;

            bar[0] = game.side[k].landTotal;
            bar[1] = (lord >= 0 && lord < UNIT_SLOTS &&
                      !(game.unit[lord].flags & 0x80))
                     ? game.unit[lord].carrying : 0;
            for (b = 0; b < 2; b++) {
                unsigned long v = bar[b] >> shift;
                int h = (int)((v >> 8) & 0xff);
                int x0 = 504 + k * 24 + b * 8, row;

                if (((bar[b] & 0xffff) & ((1UL << shift) - 1)) || (v & 0xff))
                    h++;
                if (h > 127) h = 127;
                for (row = 0; row < h; row++) {
                    int y = 327 - row, bit;

                    if (y < 200) break;
                    for (bit = 0; bit < 8; bit++)
                        if (0x5a >> (7 - bit) & 1)
                            gfx_grcg_fill(&scr, x0 + bit, y, x0 + bit, y,
                                          0x0f, sideColour[k]);
                }
            }
        }
    }

    /* The unit standing there, in the box above.  0x7cff takes the cursor
     * through sub_9b34 and reads [bx + 0xe47e], the occupant array, keeping
     * the last one it had (0x32bf) when there is nothing there.
     *
     *   0x7d33  VRAM 0x25c2 = row 120 x 528, DS:0x1bb6 "@5w  @2b,@2b" with
     *           34b8 | 34bf | 34be - sub_c5bb puts [si+6] in 0x34b8 and
     *           [si+2] in 0x34be, so that is what the unit carries and then
     *           its position, high byte first: y, then x.
     *   0x7d3c  VRAM 0x2ac2 = row 136 x 528, DS:0x1bc9 "@S@16t@s" with
     *           34bc | 34ba | c692 - "@16t" works out [0x34ba] * 16 + 0xc692
     *           and "@s" prints the string there, which is the state's name;
     *           "@S" ahead of it prints the string [0x34bc] points at, which
     *           sub_c5bb sets to DS:0x1306 or DS:0x1308 - colour 6 or 7 - on
     *           bit 4 of [si+0xa].
     */
    {
        int at = game_cell_index(curX, curY);
        int slot = at >= 0 ? game.occupant[at] : -1;

        if (slot >= 0) boxUnit = slot;
        if (boxUnit >= 0 && !(game.unit[boxUnit].flags & 0x80)) {
            const Unit *u = &game.unit[boxUnit];
            int state = u->state & 0x0f;
            unsigned char colour = (u->state & 0x10) ? 6 : 7;
            char buf[24];

            /* 0x7d2a: the portrait at VRAM 0x25be, row 120 x 496. */
            if (portraitsOk) {
                int t = portrait_tile(u, game.turn);
                Bank *b = &portraits[(t >> 6) & 3];
                int base = (t & 63) * 4, k;

                for (k = 0; k < 4; k++)
                    if (base + k < b->count)
                        gfx_blit_tile(&scr, b, (unsigned char)(base + k),
                                      496 + (k & 1) * 16, 120 + (k >> 1) * 16);
            }
            snprintf(buf, sizeof buf, "%5d", u->carrying);
            gfx_text_sjis(&scr, &font, &fontRom, 528, 120, buf, 7);
            snprintf(buf, sizeof buf, "%2d", (u->pos >> 8) & 0xff);
            /* Five columns from 528 and then the string's own two spaces put
             * the coordinates at 584 - the same place the line below has
             * them, since 528 + 5*8 + 2*8 and 544 + 3*8 + 2*8 both come to
             * 584. */
            gfx_text_sjis(&scr, &font, &fontRom, 584, 120, buf, 7);
            gfx_text_sjis(&scr, &font, &fontRom, 600, 120, ",", 7);
            snprintf(buf, sizeof buf, "%2d", u->pos & 0xff);
            gfx_text_sjis(&scr, &font, &fontRom, 608, 120, buf, 7);
            if (namesOk) {
                char nm[17];

                memcpy(nm, names[6 + state], 16);
                nm[16] = 0;
                gfx_text_sjis(&scr, &font, &fontRom, 528, 136, nm, colour);
            }
        }
    }

    /* And a picture of it, at VRAM 0x323e - row 160, x 496.  0x7d45 hands
     * sub_8756 the tile byte, which indexes the composition table four bytes
     * at a time and draws the four 16x16 pieces as a 32x32. */
    if (composeOk) {
        int at2 = game_cell_index(curX, curY);
        int tile = at2 >= 0 ? game.cell[at2].tile & 0x7f : 0;
        int k;

        for (k = 0; k < 4; k++) {
            int piece = compose[tile][k];
            int ox = (k >= 2) ? 16 : 0, oy = (k & 1) ? 16 : 0;

            if (piece < pieces.count)
                gfx_blit_tile(&scr, &pieces, (unsigned char)piece,
                              496 + ox, 160 + oy);
        }
    }

    /* What the cursor is standing on.  0x7d4f clears ten cells at VRAM 0x34c4
     * - row 168, byte 68, so x 544 - and 0x7d67 draws DS:0x1bdb into them:
     *
     *     "@3b  @2b,@2b"   with 34c2 | 34c5 | 34c4 after the terminator
     *
     * 0x7d5e puts [bx + 0xd27f] in 0x34c2, which is the amount byte of the
     * cell the cursor is over (DS:0xD27E is the cell array, two bytes each),
     * and 0x7d61 puts the cursor itself in 0x34c4 - so the two "@2b" print
     * its high byte and then its low, which is y and then x.
     *
     * ss3.jpg has "100" across x 544..567, "10" at 584..599, the comma at 600
     * and "30" at 608..623, which is exactly three columns, two spaces, two,
     * one and two.  Its cursor was on a full square at 30 across and 10 down.
     *
     * The two lines above this one - VRAM 0x25c2 and 0x2ac2, rows 120 and 136
     * at x 528 - are the unit standing there rather than the ground, and they
     * are empty in that photograph because nothing was.  They want the state
     * names at DS:0xc642, which are loaded from somewhere this port has not
     * followed yet, so they are not drawn. */
    {
        char buf[24];
        int at = game_cell_index(curX, curY);
        int amount = at >= 0 ? game.cell[at].amount : 0;

        snprintf(buf, sizeof buf, "%3d", amount);
        gfx_text_sjis(&scr, &font, &fontRom, 544, 168, buf, 7);
        snprintf(buf, sizeof buf, "%2d", curY);
        gfx_text_sjis(&scr, &font, &fontRom, 584, 168, buf, 7);
        gfx_text_sjis(&scr, &font, &fontRom, 600, 168, ",", 7);
        snprintf(buf, sizeof buf, "%2d", curX);
        gfx_text_sjis(&scr, &font, &fontRom, 608, 168, buf, 7);
    }

    /* The purse and the rate along the bottom.  0x7d70 clears sixteen cells at
     * VRAM 0x6e3e - row 352, byte 62, so x 496 - and draws DS:0x1ac0, which is
     *
     *     " @?@2t@o@10l\x17@3b\x14%\x17"
     *
     * with the words c52c 12fe 1308 | 3c00 12ef | 0000 | 000e | 0012 after its
     * terminator.  "@2t" works out [0x3c00] * 2 + 0x12ef - the human's slot in
     * the table of five side-record pointers - and writes it into the 0000
     * that follows, which "@o" then takes as the base; so 000e and 0012 are
     * offsets into that record, the purse and the rate.  The "@?" picks a
     * colour rather than a word: DS:0x1308 is "\x17" and DS:0x12fe is "\x12",
     * so the money is white while it is moving and dark red when it is not.
     *
     * Every column of that is measured off ss3.jpg: "64" sits in x 568..583,
     * the last two of the ten from 504; the "0" of the rate in 600..607, the
     * last of three from 584; and the "%" in 608..615, green, which is what
     * the \x14 before it asks for. */
    {
        char buf[24];
        unsigned long purse = game.side[game.human & 3].funds;
        int rate = game.side[game.human & 3].rate;

        /* A 32-bit purse is at most ten digits, which is the field. */
        snprintf(buf, sizeof buf, "%10lu", purse & 0xffffffffUL);
        gfx_text_sjis(&scr, &font, &fontRom, 504, 352, buf,
                      (unsigned char)(game.purseMoved ? 7 : 2));
        snprintf(buf, sizeof buf, "%3d", rate > 999 ? 999 : rate);
        gfx_text_sjis(&scr, &font, &fontRom, 584, 352, buf, 7);
        gfx_text_sjis(&scr, &font, &fontRom, 608, 352, "%", 4);
    }

    /* The panel last, so nothing can be drawn over it. */
    {
        int i;
        for (i = 0; i < DIM_ICONS; i++)
            if (!iconLive[i]) draw_dim_icon(i);
        if (running) outline_icon(ICON_GO, 6);
        if (viewMode) outline_icon(ICON_VIEW, 6);
        if (panelIcon >= 0)
            outline_icon(panelIcon, iconLive[panelIcon] ? 7 : 2);
    }

    /* The map's name, in the window the original shows it in. */
    if (nameShow > 0 && frameOk && mapNumber >= 0 && mapNumber < GFX_MAPS &&
        mapNames[mapNumber][0]) {
        char line[40];

        nameShow--;
        snprintf(line, sizeof line, "%s%s", JP_MAP_NAME, mapNames[mapNumber]);
        gfx_window(&scr, frameArt, 112, 24, 15, 1);
        gfx_text_sjis(&scr, &font, &fontRom, 128, 32, line, 7);
    }

    /* The dialog, in the game's own window rather than a box of this port's
     * invention.  sub_4a4d takes a descriptor of (position, size) in sixteen
     * pixel cells off the map frame's corner at (96, 8), hands it to sub_4b61
     * which builds the frame with sub_9167, and then draws its lines sixteen
     * pixels in and eight rows down, one every sixteen rows.  DS:0x1189 and
     * DS:0x11ef are two real ones: eleven cells by one line at (112, 24) and
     * fifteen by one at (160, 296).
     *
     * The width here is taken from the longest line rather than fixed, which
     * is what those descriptors do by carrying their own. */
    if (dlg.what != DLG_NONE && frameOk) {
        int i, longest = 0, cellsW, x, y;

        for (i = 0; i < dlg.lines; i++) {
            int n = gfx_text_sjis_width(&fontRom, dlg.line[i]);

            if (n > longest) longest = n;
        }
        /* The text starts sixteen pixels in and the right border is eight
         * wide, so a window of cellsW cells has cellsW * 16 - 8 pixels to
         * write in. */
        cellsW = (longest + 8 + 15) / 16;
        if (cellsW < 4) cellsW = 4;
        if (cellsW > 33) cellsW = 33;
        x = DLG_X & ~7;
        y = DLG_Y;
        if (x + cellsW * 16 + 16 > SCR_W - 8) x = SCR_W - 8 - cellsW * 16 - 16;
        if (y + dlg.lines * 16 + 16 > SCR_H - 8) y = SCR_H - 8 - dlg.lines * 16 - 16;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        gfx_window(&scr, frameArt, x, y, cellsW, dlg.lines);
        for (i = 0; i < dlg.lines; i++) {
            int ly = y + 8 + i * 16;
            int chosen = dlg.count && i == dlg.first + dlg.pick;

            if (chosen) {
                int j, k;

                for (j = 0; j < 16; j++)
                    for (k = 0; k < cellsW * 16 - 8; k++)
                        scr.px[(size_t)(ly + j) * SCR_W + x + 16 + k] = 2;
            }
            gfx_text_sjis(&scr, &font, &fontRom, x + 16, ly, dlg.line[i],
                          (unsigned char)(chosen ? 7 : 7));
        }
    }
}
