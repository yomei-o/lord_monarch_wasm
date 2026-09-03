#include "app.h"
#include "game.h"
#include "jp.h"
#include "sound.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
/* The palette the machine boots with: 0x0085 and 0x0149 both copy forty-eight
 * bytes of DS:0x249b into the working table, and that is what is up while no
 * stage is loaded. */
#define PAL_BOOT_AT 0x249b
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
static void app_palette(const unsigned char *t48);
static void dlg_say_table(unsigned tableAddr);
static void dlg_choices_table(unsigned tableAddr);
static void dlg_clean(const char *in, char *out, int max);
static void device_lines(void);
static void dlg_cancel(void);
static void dlg_confirm(void);
static void dlg_open_order2(void);
static void dlg_open_force(unsigned tableAddr);
static void dlg_open_drive(void);
static void dlg_open_slots(int what);
static void slot_lines(void);
static void dlg_open_order(int cx, int cy);
static void order_chosen(void);
static void order_apply(int after);
static void order_name(int k, char *out, int max);
static void cursor_move(int dx, int dy);
static void dlg_follow(void);
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
/* C_ICON.DAT, the sheet the windows' own furniture comes off.
 *
 * sub_8789 draws one 16x16 from segment 0x3000 + piece * 8, which is 128 bytes
 * a piece - sixteen rows of two bytes in each of four planes, and its own reads
 * take the planes at +0, +0x20, +0x40 and +0x60, which is exactly the order
 * gfx_load_bank unpacks a .CH4 in.  0x5cef reads the file to 0x7000:5000, so
 * piece 0x8a0 is its first: 0x30000 + 0x8a0 * 128 is 0x70000 + 0x5000.
 *
 * 3956 bytes of BZ come out as 8704, which is 68 pieces.  What is on it:
 * 0..3 are odds and ends, 4..7 the slider's rail and knob, then the panel's
 * own icons as 2x2 groups, then the editor's key caps and four kanji. */
#define ICON_PIECE_BASE 0x8a0
static Bank icons;
static int iconsOk;
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
/* Long enough for the widest of the game's own templates.  DS:0x1a54 is
 * "@5w    @10l@10w@o@10l" - five, four spaces, and three fields of ten, which
 * is thirty-nine characters - and DS:0x1a74 comes to forty.  At 34 both lines
 * lost their tail, which showed up as the purse running straight into the
 * villages' total with none of the six spaces between them. */
#define DLG_TEXT 48
enum {
    DLG_NONE, DLG_INFO, DLG_TAX, DLG_SPEED, DLG_ZOOM, DLG_ALLY, DLG_ORDER,
    DLG_FELL, DLG_OVER, DLG_REFUSED, DLG_VIEW, DLG_MAPSEL, DLG_ORDER2,
    DLG_FORCE, DLG_DRIVE, DLG_SAVE, DLG_LOAD, DLG_DEVICE
};
static struct {
    int what;                       /* DLG_* , DLG_NONE when closed */
    int lines;
    int first;                      /* the first choosable line */
    int count;                      /* how many are choosable */
    int pick;                       /* 0..count-1 */
    int value[DLG_LINES];           /* what each choice means */
    char line[DLG_LINES][DLG_TEXT];
    /* A window on to a longer list, which sub_49bb and sub_4ca1 keep between
     * them: [di] is the selection and [di+1] the first line shown, with cl the
     * lines the box can hold less one and ch the whole list less one.  0x4cc4
     * scrolls up when the selection lands on the top of the box and 0x4ccd down
     * when it lands on the bottom.  `window` of nought means the list is short
     * enough to show whole, which is every window but the stage list. */
    int top;                        /* [di+1] */
    int window;                     /* cl + 1 */
    int total;                      /* ch + 1, when it is longer than `count` */
    char item[GFX_MAPS][DLG_TEXT];  /* the whole list, when there is one */
    /* The colour of each line.  The original carries it in the text itself:
     * bytes 0x10..0x1f are a control that sub_759b turns into "[0x32a9] = byte
     * - 0x10", and the order menu picks between DS:0x1306 and DS:0x1308 - a
     * lone 0x16 and a lone 0x17 - to say whether a line is available.  Here the
     * colour is kept beside the text instead, because dlg_clean has already
     * thrown the controls away by the time the line is drawn. */
    unsigned char colour[DLG_LINES];
} dlg;

static void dlg_close(void)
{
    dlg.what = DLG_NONE;
    dlg.lines = dlg.count = dlg.pick = 0;
    dlg.window = dlg.top = dlg.total = 0;
}

static void dlg_say(const char *t)
{
    if (dlg.lines >= DLG_LINES) return;
    snprintf(dlg.line[dlg.lines], DLG_TEXT, "%s", t);
    dlg.colour[dlg.lines] = 7;
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
/* The twelve bytes a stage keeps once it has been cleared, which SAVE writes
 * out: 0x6495 hands sub_694f 0x274 bytes from DS:0xcc00, and the win path fills
 * them at 0xb3f5 onwards with bx = stage * 12 -
 *
 *   [bx - 0x3400] = [0x3bcc]   the days it took
 *   [bx - 0x33fe] = [0xc53c]   the share of the land
 *   [bx - 0x33fc] = [0x3bca]   the days left
 *
 * and reads [bx - 0x33fa] and [bx - 0x3406] back as the previous best.  Only
 * a stage below 52 is recorded (0xb398) and only when the score beat the one
 * already there and is not nought (0xb3d1, 0xb3d7).
 *
 * Kept here as fields rather than as the original's byte layout, because a
 * browser has no floppy to be byte-compatible with; what matters is that the
 * same facts survive. */
typedef struct {
    unsigned short days;        /* [0x3bcc] when it was cleared */
    unsigned short share;       /* [0xc53c], whole per cent in the low byte */
    unsigned short daysLeft;    /* [0x3bca] */
    unsigned short score;       /* [0xc4f0] */
} StageRecord;

static StageRecord record[GFX_MAPS];

/* The save slots.  DS:0xf67e holds eighty records of twelve bytes and 0x1f39
 * reads the first word of one to see whether it holds anything:
 *
 *   +0   non-zero when the slot is used
 *   +2   the day the stage was on, nought meaning it was saved at the start
 *   +4   the stage number, nought meaning the slot is only a cursor position
 *   +6   year, +7 month, +8 day, +9 hour, +10 minute
 *
 * and DS:0x170c draws a line of the list out of them - see the note on
 * dlg_open_slots.  What goes in the file is another matter: sub_6473 writes 628
 * bytes of progress from DS:0xcc00 and 87 bytes of globals from DS:0x3bc2, and
 * then the board on top when a stage is under way.  A browser has no floppy to
 * be byte-compatible with, so the port keeps the same facts in its own shape
 * and leaves the directory looking exactly like the game's. */
#define SAVE_SLOTS 80
#define SAVE_DIR_AT 0xf67eu
#define SAVE_LIST_AT 0x10bd         /* the descriptor, ten of eighty visible */
#define SAVE_TITLE_AT 0x1189        /* ゲームセーブ */
#define LOAD_TITLE_AT 0x1183        /* ゲーム・ロード */
#define SAVE_MAGIC 0x314d4cadu      /* "LM" and a format number */

typedef struct {
    unsigned short used, days, map;
    unsigned char yy, mm, dd, hh, mi;
    unsigned char *blob;
    unsigned blobLen;
} SaveSlot;

static SaveSlot slotDir[SAVE_SLOTS];
/* Bumped whenever a slot changes, so a host that keeps them somewhere can tell
 * without copying eighty of them every frame. */
static int slotStamp;

typedef struct {
    unsigned magic;
    /* The directory fields travel with the payload so that one byte array is a
     * whole slot: the page hands it to localStorage and back without knowing
     * anything about what is in it. */
    unsigned short used, days, map;
    unsigned char yy, mm, dd, hh, mi, pad;
    unsigned short mapNumber, tileSize, reached, hasGame;
    unsigned short day, daysLeft, spare[2];
    StageRecord record[GFX_MAPS];
    Game game;
} SaveBlob;
/* 0xb3d1 and 0xb3d7: the record is only replaced, and [0xce70] only moved,
 * when the score beats the one already stored AND is not nought.  So clearing
 * a stage with nothing left to your name does not open the next one. */
static int overImproved;

/* [0x3bc2] = 0xffff means no stage is loaded, and that is how the game starts.
 * 0x4ce0 reads it as the GO icon's own picture, and sub_1afa's 0x1b21 arm is the
 * ONLY thing in the program that loads a map: it takes the stage from [0xce70],
 * calls sub_6033 and then falls into 0x1b37, which sets [0x3bd4] and does
 * "add sp, 2 / ret" to throw the panel loop's return address away.  So the
 * screen the game opens on is the frame and the panel with the map window
 * empty, and GO is what fills it.  This port went straight to stage 0 with the
 * world already drawn. */
/* [0x3286], which display is attached.  0x0090 reads bit 4 of the 8255's port
 * B for the machine's own answer and 0x0096 sets the byte from it; sub_06e7 then
 * lets the player override it, and the CRT/LCD icon at 0x206c does the same
 * later.  What it changes is which arm of sub_736c uploads the palette:
 *
 *   0x7374  the analogue RGB one, four bits a channel straight out of DS:0x3e20
 *   0x739f  the eight-gradation one.  sub_73d4 adds the entry up as
 *           4*green + 2*red + blue - green weighted most, which is a
 *           luminance - scales it by the brightness in [0x34d6] over fifteen,
 *           complements it, and 0x739f then uses bits 0, 1 and 2 of that as
 *           blue, red and green, each fully on or fully off.  Black comes back
 *           as 7, which is white: an LCD of the period showed dark pixels on a
 *           light ground, so the ramp is inverted.
 */
static int lcd;

static int stageLoaded;

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
    /* 0x00b5 asks this before anything is drawn, so the port does too. */
    return app_show_device();
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
    app_palette(b + n - 48);
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

/* The game screen with no stage on it, which is where the original goes after
 * its opening: everything is loaded but [0x3bc2] is still 0xffff, so the map
 * window keeps the frame's own artwork and the panel has the keys.  The stage
 * whose art is preloaded is the one GO will pick, which is what [0xce70] names.
 */
int app_show_ready(void)
{
    const unsigned char *t;

    if (!app_show_map(reached, tileSize > 0 ? tileSize : 16)) return 0;
    stageLoaded = 0;
    running = 0;
    underWay = 0;
    nameShow = 0;                       /* no stage, so no stage name */
    panelIcon = ICON_GO;
    t = dat_at(PAL_BOOT_AT, 48);
    if (t) app_palette(t);
    snprintf(status, sizeof status, "panel: GO");
    return 1;
}

/* Every palette upload goes through here so that the display setting applies to
 * all of them and not just whichever one was written last. */
static void app_palette(const unsigned char *t48)
{
    unsigned char out[48];
    int i;

    if (!t48) return;
    if (!lcd) {
        gfx_set_palette(&scr, t48);
        return;
    }
    for (i = 0; i < 16; i++) {
        int b = t48[i * 3 + 0] & 0x0f;          /* port 0xae */
        int r = t48[i * 3 + 1] & 0x0f;          /* port 0xac */
        int g = t48[i * 3 + 2] & 0x0f;          /* port 0xaa */
        int sum = 4 * g + 2 * r + b, v;

        if (sum == 0) {
            v = 7;                              /* 0x73f5 */
        } else {
            v = ((sum + 15) * 0xff) >> 8;       /* [0x34d6] at full */
            v = v / 15;
            v = (~v) & 0xff;
        }
        /* 0x739f writes bits 0, 1 and 2 of that to the blue, red and green
         * registers, each fully on or fully off - eight corners of the colour
         * cube.  On the machine this was for, an eight-gradation LCD panel, the
         * panel itself turned those eight into eight GREYS, which is what the
         * menu means by 階調 and what the player actually saw.  Writing the
         * bits out as colours here gives a magenta-and-yellow mess instead, so
         * the level is mapped to a grey ramp: the "not al" at 0x73f0 is why it
         * runs the other way, and it lands black on black and white on white.
         */
        {
            int level = v & 7;
            int grey = (7 - level) * 15 / 7;

            out[i * 3 + 0] = (unsigned char)grey;
            out[i * 3 + 1] = (unsigned char)grey;
            out[i * 3 + 2] = (unsigned char)grey;
        }
    }
    gfx_set_palette(&scr, out);
}

/* The message and the two choices, which is all sub_06e7 puts on the screen.
 *
 * The message is not a descriptor: 0x070e hands the raw string at DS:0x1026 -
 * "表示装置を選択してください。" - straight to sub_759b.  The menu IS one, at
 * DS:0x101c, and it is a sub_49bb descriptor so its header is six bytes:
 * 0a 06 02 0e 02 00, which is (10,6) in cells, two lines, two in all, with the
 * pointers at DS:0x1022 naming "アナログＢＧＢディスプレイ" and
 * "８階調表示液晶ディスプレイ".
 *
 * Reading DS:0x1022 as the message was a false start - those two bytes are the
 * first pointer, and decoding from there gave "C^表示装置を..." with the
 * pointer bytes on the front. */
static void device_lines(void)
{
    const unsigned char *t = dat_at(0x1026, 1);

    dlg_close();
    dlg.what = DLG_DEVICE;
    if (t) {
        char clean[DLG_TEXT];
        dlg_clean((const char *)t, clean, sizeof clean);
        dlg_say(clean);
    }
    if (dlg.lines == 0) dlg_say("select the display");
    dlg_say("");
    dlg_choices_table(0x101c);
    if (dlg.count == 0) {
        dlg_choice("ANALOGUE RGB", 0);
        dlg_choice("8-LEVEL LCD", 1);
    }
    dlg.pick = lcd ? 1 : 0;
}

/* sub_06e7, the first thing the game does after the hardware is up: it draws
 * DS:0x1026 - "表示装置を選択してください。" - and then puts the two-line menu
 * DS:0x101c up into [0x3286].  It asks sub_4be9 for 0x23, which is up, down and
 * confirm and NO cancel, so the question has to be answered. */
int app_show_device(void)
{
    mode = APP_MODE_DEVICE;
    dlg_close();
    dlg.what = DLG_DEVICE;
    device_lines();
    /* 0x0085 copies DS:0x249b into the working table before any of this, so
     * that is the palette the question is drawn under.  Without it every index
     * is black and the screen comes up empty, which is what happened. */
    app_palette(dat_at(PAL_BOOT_AT, 48));
    snprintf(status, sizeof status, "select the display device");
    return 1;
}

int app_show_title(void)
{
    const unsigned char *t = dat_at(PAL_TITLE_AT, 48);

    dlg_close();
    mode = APP_MODE_TITLE;
    if (!t) {
        snprintf(status, sizeof status, "no title palette in PROG.DAT");
        return 0;
    }
    app_palette(t);
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

    /* A stage replaces the screen, so whatever window was up goes with it -
     * the display question at boot among them. */
    dlg_close();

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
    stageLoaded = 1;
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
    /* The window furniture, which does not depend on the tileset. */
    if (!iconsOk) iconsOk = gfx_load_bank(&icons, disk, "C_ICON.DAT", 16);

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

/* A window's line as text, with what is not text taken out.
 *
 * sub_759b treats a byte under 0x20 as an instruction rather than a character -
 * 0x10..0x1f set the colour, which is what panel_line above does with them -
 * and an "@" opens a format code whose operand comes from a stack the caller
 * built.  A title like the map load's is <0x16>@?マップ・ロード<0x17>, so
 * copying it verbatim put "@?" and two stray glyphs on the screen, which is
 * what "the windows do not display properly" looked like.  Here there is no
 * operand stack to draw from, so a code contributes nothing and is dropped.
 *
 * A code is "@", an optional ".", optional digits, then one letter.
 */
static void dlg_clean(const char *in, char *out, int max)
{
    const unsigned char *p = (const unsigned char *)in;
    int n = 0;

    while (*p && n < max - 1) {
        if (*p < 0x20) {                /* colour and the like, not text */
            p++;
            continue;
        }
        if (*p == '@') {
            p++;
            if (*p == '.') p++;
            while (*p >= '0' && *p <= '9') p++;
            if (*p) p++;                /* the letter that ends it */
            continue;
        }
        /* Shift-JIS lead bytes take their trail byte with them. */
        if ((*p >= 0x81 && *p <= 0x9f) || (*p >= 0xe0 && *p <= 0xef)) {
            if (n + 2 >= max - 1) break;
            out[n++] = (char)*p++;
            if (*p) out[n++] = (char)*p++;
            continue;
        }
        out[n++] = (char)*p++;
    }
    out[n] = 0;
}

/* The one format code the port fills in so far.
 *
 * sub_759b reads the words sitting immediately after a string's terminator as
 * its arguments - a repne scasb at 0x75c4 finds them - and "@S" means "the next
 * argument is the address of a pointer to a string; draw that string".  The
 * game uses it for names it works out at run time: the alliance messages at
 * DS:0x11c7, DS:0x11d5 and DS:0x11dd all put the country names into 0xc52e,
 * 0xc530, 0xc532 and 0xc534 first and then let "@S" pick them up.
 *
 * `slot` and `text` are the port's answers for those addresses.  Every other
 * code is still dropped the way dlg_clean drops it, and the argument stream is
 * walked past so that later codes on the same line keep their place: a code
 * that is not understood costs one word, "@?" three and "@Nt" two, which is
 * what sub_759b's own handlers consume.
 */
/* One answer for one argument address.  A string slot fills "@s" and "@S"; a
 * number slot fills "@b", "@w" and "@l", whose default widths are the digits
 * their sizes need - three, five and ten - and whose padding is the space or
 * the zero that "@." chose.  An address the port has no answer for is drawn as
 * that many pad characters, so the columns stay where the original put them
 * rather than the rest of the line sliding left.
 *
 * "@o" sets a base that every later argument is an offset from, and the port
 * cannot hand out real addresses for its own structures, so a slot wanted after
 * an "@o" is keyed as FMT_BASED + the offset. */
#define FMT_BASED 0x10000u

typedef struct {
    unsigned addr;
    const char *text;
    long value;
    int isNum;
} FmtSlot;

static int fmt_render(unsigned strAddr, const FmtSlot *slot, int slots,
                      char *out, int max, int depth, int line, unsigned inBase)
{
    const unsigned char *str;
    unsigned at, based = inBase, pending = 0;
    int n = 0, len = 0, havePending = 0;

    if (max <= 1 || depth > 4) return 0;
    if (!dat_at(strAddr, 1)) return 0;
    while (dat_at(strAddr + len, 1) && *dat_at(strAddr + len, 1)) len++;
    at = strAddr + len + 1;             /* 0x75c4's repne scasb lands here */
    str = dat_at(strAddr, 1);
    while (*str && n < max - 1) {
        if (*str < 0x20) { str++; continue; }   /* a colour, not text */
        if (*str == '@') {
            int eats = 1, width = 0, i, found = -1;
            char pad = ' ', letter;
            unsigned arg = 0, key;
            const unsigned char *w;

            str++;
            if (*str == '.') { pad = '0'; str++; }
            while (*str >= '0' && *str <= '9') width = width * 10 + (*str++ - '0');
            letter = (char)*str;
            if (*str) str++;
            if (letter == '?') eats = 3;
            else if (letter == 't') eats = pad == '0' ? 1 : 2;
            /* "@O" is the one code that reads no argument: 0x7754 takes the
             * caller's base off the stack and never touches bx.  Letting it
             * eat a word put every field of the save list one along, which
             * showed up as a date that read 9/03/11 50 instead of 26/09/03
             * 11:50 and a missing MAP-No. */
            else if (letter == 'O') eats = 0;
            if (havePending) {
                arg = pending;
                havePending = 0;
            } else {
                w = dat_at(at, 2);
                if (w) arg = (unsigned)(w[0] | (w[1] << 8));
            }
            at += (unsigned)(eats * 2);
            /* "@Nt" indexes a table: 0x779f reads the word at the first
             * argument, multiplies it by N and adds the second, then writes the
             * answer into the slot after them - so the next code reads what it
             * worked out, not the nought sitting in the file.  ("@.Nt" is the
             * same with the line number in [0xc54c]; the one window that uses
             * that form - the order menu - the port builds itself.) */
            if (letter == 't') {
                const unsigned char *w2;
                unsigned base;
                long idx = 0;
                int j;

                /* "@.Nt" is the same sum with [0xc54c] - the line being drawn -
                 * in place of the first argument, and it takes one word rather
                 * than two (0x77b4).  That is how one template becomes eighty
                 * lines of a save list. */
                if (pad == '0') {
                    pending = (unsigned)((long)(line - 1) * width + (long)arg);
                    havePending = 1;
                    continue;
                }
                w2 = dat_at(at - 2, 2);
                base = w2 ? (unsigned)(w2[0] | (w2[1] << 8)) : 0;
                for (j = 0; j < slots; j++)
                    if (slot[j].addr == arg && slot[j].isNum) {
                        idx = slot[j].value;
                        break;
                    }
                pending = (unsigned)(idx * width + (long)base);
                havePending = 1;
                continue;
            }
            /* "@o" is not drawn: it says where the arguments after it are
             * measured from, and the three forms differ.
             *
             *   "@o"   0x7735 with ch = 0x20: si = [bx], then the base is the
             *          WORD AT that address - an address of the original's own
             *          memory, which this port has no equivalent of, so the
             *          base becomes FMT_BASED and the slots are keyed by the
             *          offset alone.  DS:0x1a54's side record is one of these.
             *   "@.o"  0x7746: the base is the argument itself, which "@Nt"
             *          has usually just filled in - a real address the port can
             *          answer for, so it is used as it stands.
             *   "@O"   0x7754: the caller's base, inherited.
             */
            if (letter == 'o') {
                based = pad == '0' ? arg : FMT_BASED;
                continue;
            }
            if (letter == 'O') { based = inBase; continue; }
            /* An offset from whatever "@o" last named.  `based` is nought
             * outside one, a real address after "@.o", and FMT_BASED when the
             * base was a word of the original's memory the port cannot hand
             * out - so the slots are keyed the same way either way. */
            key = based + arg;
            /* "@?" picks one of two strings on a word being zero - 0x7763's
             * "cmp word ptr [si], 0 / je +5" takes [bx+4] for nought and
             * [bx+2] otherwise - and then draws it through sub_75ad, so the
             * chosen string gets its own codes and its own arguments.  Drawing
             * it as plain text instead left "繰越日数 @5w日(@?@5w)" as
             * "繰越日数 日()". */
            if (letter == '?') {
                const unsigned char *w2 = dat_at(at - 4, 4);
                unsigned pick;
                long flag = 0;
                int j;

                if (!w2) continue;
                for (j = 0; j < slots; j++)
                    if (slot[j].addr == key && slot[j].isNum) {
                        flag = slot[j].value;
                        break;
                    }
                pick = flag ? (unsigned)(w2[0] | (w2[1] << 8))
                            : (unsigned)(w2[2] | (w2[3] << 8));
                n += fmt_render(pick, slot, slots, out + n, max - n, depth + 1,
                                line, based);
                continue;
            }
            if (letter != 'S' && letter != 's' && letter != 'b' &&
                letter != 'w' && letter != 'l')
                continue;
            for (i = 0; i < slots; i++)
                if (slot[i].addr == key) { found = i; break; }
            if (letter == 'S' || letter == 's') {
                if (found >= 0 && slot[found].text) {
                    int k = 0;
                    while (slot[found].text[k] && n < max - 1)
                        out[n++] = slot[found].text[k++];
                }
                continue;
            }
            /* A number.  sub_c455, sub_c492 and sub_c52d fill a buffer that
             * ends at DS:0x32ba with the pad byte and write the digits into its
             * tail, so the value is right-aligned in `width`; their defaults
             * when cl is nought are the digits a byte, a word and a long need.
             * An address with no answer is drawn as that many spaces, so the
             * columns stay where the original put them. */
            if (width <= 0) width = letter == 'b' ? 3 : letter == 'w' ? 5 : 10;
            if (width > max - 1 - n) width = max - 1 - n;
            if (found >= 0 && slot[found].isNum) {
                char num[24];
                long v = slot[found].value;
                int k;

                if (letter == 'b') v &= 0xff;
                else if (letter == 'w') v &= 0xffff;
                snprintf(num, sizeof num, "%ld", v);
                for (k = (int)strlen(num); k < width; k++) out[n++] = pad;
                for (k = 0; num[k] && n < max - 1; k++) out[n++] = num[k];
            } else {
                int k;
                for (k = 0; k < width; k++) out[n++] = ' ';
            }
            continue;
        }
        if ((*str >= 0x81 && *str <= 0x9f) || (*str >= 0xe0 && *str <= 0xef)) {
            if (n + 2 >= max - 1) break;
            out[n++] = (char)*str++;
            if (*str) out[n++] = (char)*str++;
            continue;
        }
        out[n++] = (char)*str++;
    }
    out[n] = 0;
    return n;
}

static void dlg_say_fmt(unsigned strAddr, const FmtSlot *slot, int slots)
{
    char out[DLG_TEXT];

    if (!dat_at(strAddr, 1)) return;
    fmt_render(strAddr, slot, slots, out, (int)sizeof out, 0, 1, 0);
    dlg_say(out);
}

/* Every line of one of sub_4a4d's tables, with "@S" filled in. */
static void dlg_say_table_fmt(unsigned tableAddr, const FmtSlot *slot,
                              int slots)
{
    const unsigned char *t = dat_at(tableAddr, 4);
    int lines, i;

    if (!t) return;
    lines = t[2] & 0x7f;
    if (lines > DLG_LINES - 2) lines = DLG_LINES - 2;
    for (i = 0; i < lines; i++) {
        const unsigned char *p = dat_at(tableAddr + 4 + i * 2, 2);
        unsigned addr;

        if (!p) break;
        addr = (unsigned)(p[0] | (p[1] << 8));
        dlg_say_fmt(addr, slot, slots);
    }
}

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
            if (text) {
                char clean[DLG_TEXT];
                dlg_clean((const char *)text, clean, sizeof clean);
                dlg_say(clean);
            }
        }
    }
}

/* The same table, but every line is choosable: that is the difference between
 * sub_4a4d and sub_49bb, and DS:0x10e7 is one of these - two lines, 強行 at
 * DS:0x1de0 and 再選択 at DS:0x1de7.
 *
 * The two descriptors are not the same shape, which cost a false start here.
 * sub_4a4d reads four bytes and then the pointers; sub_49bb does "add si, 6"
 * at 0x49e6, so its header is six - x, y, how many lines are visible with 0x80
 * meaning "one template indexed by line number", a width, the whole list's
 * length, and a spare.  Reading DS:0x10e7 as a four-byte header gave 0x0002 as
 * the first pointer and the window came up with no choices in it at all. */
static void dlg_choices_table(unsigned tableAddr)
{
    const unsigned char *t = dat_at(tableAddr, 6);
    int lines, i;

    if (!t) return;
    lines = t[2] & 0x7f;
    if (lines > DLG_LINES - dlg.lines) lines = DLG_LINES - dlg.lines;
    for (i = 0; i < lines; i++) {
        const unsigned char *p = dat_at(tableAddr + 6 + i * 2, 2);
        unsigned at;
        const unsigned char *text;
        char clean[DLG_TEXT];

        if (!p) break;
        at = p[0] | (p[1] << 8);
        text = dat_at(at, 1);
        if (!text) break;
        dlg_clean((const char *)text, clean, sizeof clean);
        dlg_choice(clean, i);
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

/* 0x1e0f, the map load.  It puts up the window DS:0x117d names and then a menu
 * of what is on the disk (the descriptor at DS:0x1079, selected into [0x3bf0]).
 * Fifty-two stages will not fit in a box, which is what the scroll window is
 * for.  This port used to advance to the next stage instead, which is not what
 * the icon does at all.
 */
static void dlg_open_mapsel(void)
{
    int i;

    dlg_close();
    dlg.what = DLG_MAPSEL;
    dlg_say_table(0x117d);
    if (dlg.lines == 0) dlg_say("MAP");
    dlg_say("");

    dlg.total = MAP_COUNT;
    for (i = 0; i < MAP_COUNT && i < GFX_MAPS; i++)
        snprintf(dlg.item[i], DLG_TEXT, "%2d %s", i,
                 mapNames[i][0] ? mapNames[i] : "");
    dlg.window = DLG_LINES - dlg.lines - 1;
    if (dlg.window > 8) dlg.window = 8;
    dlg.first = dlg.lines;
    dlg.count = dlg.window;
    for (i = 0; i < dlg.window; i++) dlg_say("");
    dlg.pick = mapNumber;
    if (dlg.pick >= dlg.total) dlg.pick = 0;
    /* pick is an index into the whole list here, so the box is placed round it
     * and then the selection is expressed inside the box. */
    dlg.top = dlg.pick - dlg.window / 2;
    dlg_follow();
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
/* The end of a stage, and this one is the game's own table too.
 *
 * 0xb410 puts up DS:0x1105 on a win and 0xb413 DS:0x112f on a loss, and the
 * win table's eight lines are
 *
 *     @Sの勝利です。              c538
 *     ------------------------
 *     経過日数          @5w       3bcc
 *     残り日数          @5w       3bca
 *     国の面積      @4w/@4w       c53a c53e
 *     国の率            @3b.@1b%  c53c c53d
 *     ------------------------
 *     @?                          c4f0 1509 152a
 *
 * where the last line is 開拓点は @5w点(@?@5w) when there is a score and
 * "もう一度挑戦してください" when there is none.  0xb34f onwards works the
 * numbers out:
 *
 *   [0xc538]  the surviving country's name, DS:0x12ad indexed by side
 *   [0xc53e]  sub_bc99, every country's land added up
 *   [0xc53a]  sub_bcce, this one's
 *   [0xc53c]  the share.  land * 1000 / total, then "div cl" by ten, so al is
 *             the whole per cent and ah - which the template reads as
 *             [0xc53d] - is the tenth
 *   [0xc4f0]  the score: days left times the share in per mille, over a
 *             thousand (0xb37d)
 *   [0xc540]  set at 0xb3b9 when the score came out below the stage's best
 *   [0xc542]  how far off it was, always positive (0xb3bf negates it)
 *   [0xc544]  the same for the rate, which DS:0x1129 announces
 *
 * The port used to write its own lines here with a cell count for the area,
 * which is a different number from the side records' own totals.
 */
static void dlg_open_over(int won)
{
    int mine = game.human < 0 ? 0 : game.human;
    unsigned long total = 0, held;
    long permille = 0, whole = 0, tenth = 0, score = 0;
    long best = 0, diff = 0, fell = 0;
    FmtSlot slot[10];
    char nm[DLG_TEXT];
    int i;

    dlg_close();
    dlg.what = DLG_OVER;
    for (i = 0; i < PLAYERS; i++) total += game.side[i].landTotal;
    held = game.side[mine].landTotal;
    if (total) {
        permille = (long)(held * 1000UL / total);
        whole = permille / 10;
        tenth = permille % 10;
        score = (long)game.daysLeft * permille / 1000;
    }
    if (mapNumber >= 0 && mapNumber < MAP_COUNT) {
        best = record[mapNumber].score;
        diff = score - best;
        if (diff < 0) { fell = 1; diff = -diff; }
    }
    /* 0xb3d1 onwards, in the original's order: the difference is worked out
     * against the stored score first and the record replaced afterwards, so
     * the window says what the improvement was. */
    overImproved = 0;
    if (won && mapNumber >= 0 && mapNumber < MAP_COUNT &&
        score > best && score != 0) {
        overImproved = 1;
        record[mapNumber].days = (unsigned short)game.day;
        record[mapNumber].share = (unsigned short)whole;
        record[mapNumber].daysLeft = (unsigned short)game.daysLeft;
        record[mapNumber].score = (unsigned short)score;
    }

    country_name(mine, nm, sizeof nm);
    slot[0].addr = 0xc538; slot[0].text = nm;   slot[0].isNum = 0;
    slot[0].value = 0;
    slot[1].addr = 0x3bcc; slot[1].value = game.day;         slot[1].isNum = 1;
    slot[2].addr = 0x3bca; slot[2].value = game.daysLeft;    slot[2].isNum = 1;
    slot[3].addr = 0xc53a; slot[3].value = (long)held;       slot[3].isNum = 1;
    slot[4].addr = 0xc53e; slot[4].value = (long)total;      slot[4].isNum = 1;
    slot[5].addr = 0xc53c; slot[5].value = whole;            slot[5].isNum = 1;
    slot[6].addr = 0xc53d; slot[6].value = tenth;            slot[6].isNum = 1;
    slot[7].addr = 0xc4f0; slot[7].value = score;            slot[7].isNum = 1;
    slot[8].addr = 0xc540; slot[8].value = fell;             slot[8].isNum = 1;
    slot[9].addr = 0xc542; slot[9].value = diff;             slot[9].isNum = 1;
    for (i = 1; i < 10; i++) slot[i].text = 0;

    dlg_say_table_fmt(won ? 0x1105 : 0x112f, slot, 10);
    /* 0xb416: the extra line goes up only when [bp-2] is set, and 0xb3f0
     * clears it again when the stage was the furthest one - so it says
     * "improved" for a stage played again, not for a new one. */
    if (won && overImproved && mapNumber < reached) {
        slot[9].addr = 0xc544;
        slot[9].value = diff;
        slot[9].isNum = 1;
        slot[9].text = 0;
        dlg_say_table_fmt(0x1129, slot, 10);
    }
    if (dlg.lines == 0) dlg_say(won ? "won" : "lost");
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
}

/* The country readout, and both of its lines are the game's own templates.
 *
 * sub_4f76 walks the four side records from DS:0xc792, sixteen bytes apart,
 * and calls sub_4faf for each; sub_4faf skips a country whose flag word has
 * bit 3 set (0x4fb2 - one that has fallen), draws its frame and its flag art,
 * works out six numbers into a run of variables at DS:0x1a9b, and then hands
 * DS:0x1a54 and DS:0x1a74 to sub_759b:
 *
 *     "@5w    @10l@10w@o@10l"
 *        args 1a9b 1a9d 1aa1 1aa3 000e
 *     "@3b.@1b%   @10b@10w@o@10b%"
 *        args 1aa9 1aaa 1aa5 1aa7 1aa3 0012
 *
 * so, reading them off:
 *
 *   [0x1a9b]  the lord's carry            - 0x4ff4, the unit with bit 0x20
 *   [0x1a9d]  everyone else's carry, 32   - 0x4ffb, summed with adc
 *   [0x1aa1]  the villages' amount        - 0x5026, cells whose tile is side+8
 *   [0x1aa3]  the side record, which "@o" then takes as a base, so 0x0e is
 *             the purse and 0x12 the rate
 *   [0x1aa5]  how many units, not counting the lord
 *   [0x1aa7]  how many villages
 *   [0x1aa9]  the share of the land: sub_bcce over sub_bc99, times 1000, then
 *             "div cl" by ten - so al is the whole percent and ah the tenth,
 *             which is why the line reads "@3b.@1b%" with the second argument
 *             one byte further on.
 *
 * The original gives each country its own little box with its flag drawn
 * beside it; here the four boxes are four pairs of lines in one window, with
 * the country's own name above each pair, because this port has one window
 * shape and the flag art is not what says which country a row is.
 */
static void dlg_open_info(void)
{
    unsigned long total = 0;
    int i;

    dlg_close();
    dlg.what = DLG_INFO;
    for (i = 0; i < PLAYERS; i++) total += game.side[i].landTotal;

    for (i = 0; i < PLAYERS; i++) {
        FmtSlot slot[8];
        char nm[DLG_TEXT];
        const Side *sd = &game.side[i];
        long lordCarry = 0, othersCarry = 0, others = 0;
        long villageAmount = 0, villages = 0;
        long pct = 0, tenth = 0;
        int u, c;

        /* 0x4fb2: a fallen country has no row at all. */
        if (!sd->alive || (sd->flag & 8)) continue;

        for (u = 0; u < UNIT_SLOTS; u++) {
            if (game_unit_free(&game, u)) continue;
            if (game.unit[u].side != i) continue;
            if (game.unit[u].state & 0x20) lordCarry = game.unit[u].carrying;
            else { others++; othersCarry += game.unit[u].carrying; }
        }
        for (c = 0; c < MAP_W * MAP_H; c++)
            if (game.cell[c].tile == (unsigned char)(i + 8)) {
                villages++;
                villageAmount += game.cell[c].amount;
            }
        if (total) {
            long thousandths = (long)(sd->landTotal * 1000UL / total);
            pct = thousandths / 10;
            tenth = thousandths % 10;
        }

        country_name(i, nm, sizeof nm);
        dlg_say(nm);

        slot[0].addr = 0x1a9b; slot[0].value = lordCarry;    slot[0].isNum = 1;
        slot[1].addr = 0x1a9d; slot[1].value = othersCarry;  slot[1].isNum = 1;
        slot[2].addr = 0x1aa1; slot[2].value = villageAmount; slot[2].isNum = 1;
        slot[3].addr = FMT_BASED + 0x0e; slot[3].value = (long)sd->funds;
        slot[3].isNum = 1;
        slot[0].text = slot[1].text = slot[2].text = slot[3].text = 0;
        dlg_say_fmt(0x1a54, slot, 4);

        slot[0].addr = 0x1aa9; slot[0].value = pct;          slot[0].isNum = 1;
        slot[1].addr = 0x1aaa; slot[1].value = tenth;        slot[1].isNum = 1;
        slot[2].addr = 0x1aa5; slot[2].value = others;       slot[2].isNum = 1;
        slot[3].addr = 0x1aa7; slot[3].value = villages;     slot[3].isNum = 1;
        slot[4].addr = FMT_BASED + 0x12; slot[4].value = sd->rate;
        slot[4].isNum = 1;
        slot[0].text = slot[1].text = slot[2].text = slot[3].text =
            slot[4].text = 0;
        dlg_say_fmt(0x1a74, slot, 5);
    }
    if (dlg.lines == 0) dlg_say("no countries left");
    /* 0x1c47 waits at sub_c90f, so any key closes it and there is nothing to
     * choose.  dlg_confirm and dlg_cancel both close a window with no menu. */
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
/* The three windows that are knobs on a bar rather than menus, and they follow
 * their own rules.  sub_4f08 (tax), sub_539f (speed) and sub_52b7 (zoom) are
 * the same loop three times over:
 *
 *   the keys      tax takes "and al, 0x6c" - left and right - while speed and
 *                 zoom take "and al, 0x63", up and down.  Either way only two
 *                 directions, confirm and cancel get through.
 *   a move        writes the new value straight into the game's own byte and
 *                 goes back to waiting.  There is NO sound: 0x53e2 jumps to
 *                 0x53b3 and 0x4f56 to 0x4f1a, neither of which touches the
 *                 driver.  A menu plays 0x0500 on a move; a knob is silent.
 *   at either end 0x4f45, 0x53d3 and 0x52eb all jump back to the wait without
 *                 doing anything, so pressing on past the end is silent too.
 *   confirm       sound 0x601, carry clear.
 *   cancel        sound 0x601 as well - unlike a menu, whose cancel at 0x4c94
 *                 is a bare "stc" with no sound at all.
 *
 * And they do not agree about what cancel means, which is worth writing down
 * because it looks like an oversight and is consistent across two of the three:
 *
 *   speed  0x53a1 saves [di] in bh and 0x53f1 puts it back  -> cancel reverts
 *   zoom   0x52b9 and 0x5309 do the same                    -> cancel reverts
 *   tax    0x4f66 restores nothing                          -> cancel KEEPS it
 *
 * Since every move has already been written to the live byte, tax cancelled is
 * tax set.  This port used to apply all three only on confirm, so the world
 * never sped up while the knob was moving and a cancelled tax went back.
 */
/* [0x3c02] as it was when the speed window opened, which 0x53a1 keeps in bh so
 * that 0x53f1 can put it back on a cancel.  A named place rather than a spare
 * slot in dlg.value, where the next person to add a line would tread on it. */
static int speedWas;

static int slider_is(int what)
{
    return what == DLG_TAX || what == DLG_SPEED || what == DLG_ZOOM;
}

/* Push the live value into the game, which is what the loops do on every move
 * rather than at the end.  Zoom is the exception: 0x52fa stores the byte but
 * the display is only rebuilt at 0x1c6a, after the confirm. */
static void slider_apply(void)
{
    int mine = game.human < 0 ? 0 : game.human;

    switch (dlg.what) {
    case DLG_TAX:
        game.side[mine].rate = (unsigned char)dlg.value[0];
        break;
    case DLG_SPEED:
        game.speed = dlg.pick;          /* [0x3c02] */
        break;
    default:
        break;
    }
}

static int tax_step(int by)
{
    int rate = dlg.value[0] + by;

    if (dlg.what != DLG_TAX) return 0;
    /* 0x4f45 and 0x4f4d both jump straight back to the wait. */
    if (rate < 0 || rate > TAX_MAX) return 1;
    dlg.value[0] = rate;
    slider_apply();                     /* 0x4f56, on every move */
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
    /* 0x53a1: bh keeps [0x3c02] so the cancel can put it back, and the knob
     * opens where the setting already is. */
    dlg.pick = game.speed >= 0 && game.speed < dlg.count ? game.speed : 0;
    speedWas = game.speed;
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

/* 0x1cb0.  The window lists the countries by their own names - the five
 * records at 0xc642 that gfx_load_names reads, which is what DS:0x12ad points
 * at - and 0x1cc2 nudges the selection off your own country before it opens,
 * because 0x1d0c sends a choice of yourself straight back to the menu.  So does
 * a country whose flag word is not zero (0x1d18), which is one that has
 * fallen. */
static void dlg_open_ally(void)
{
    int i, mine = game.human < 0 ? 0 : game.human;

    dlg_close();
    dlg.what = DLG_ALLY;
    dlg_say(JP_ALLY_TITLE);
    dlg_say("");
    for (i = 0; i < PLAYERS; i++) {
        char buf[DLG_TEXT], nm[DLG_TEXT];

        country_name(i, nm, sizeof nm);
        snprintf(buf, sizeof buf, "%s%s", nm,
                 game.side[mine].ally == i ? JP_ALLY_NOW : "");
        dlg_choice(buf, i);
        /* Your own country and a fallen one are refused, so they are drawn the
         * way the order menu draws a choice that means nothing. */
        if (i == mine || !game.side[i].alive || game.side[i].flag)
            dlg.colour[dlg.lines - 1] = 2;
    }
    if (mine >= 0 && mine < PLAYERS && dlg.count > 0) {
        dlg.pick = mine + 1 < PLAYERS ? mine + 1 : 0;   /* 0x1ccb */
    }
}

/* 0x1d61: the alliance is struck, and it is not one pair but two.  sub_1de2
 * finds the two countries that are neither you nor your new ally - "cl = 0;
 * while (cl is one of al, ah, dh) cl++", twice - and sub_1df5 then writes
 * side[cl].ally = ch for all four, so you pair with your choice and the other
 * two pair with each other.  The message at DS:0x11c7 names both pairs, which
 * is how it was noticed: it has two "@Sと@Sの" lines, not one.
 */
static void ally_strike(int with)
{
    int mine = game.human < 0 ? 0 : game.human;
    int other[2], n = 0, i;
    FmtSlot slot[4];
    char nm[4][DLG_TEXT];

    for (i = 0; i < PLAYERS && n < 2; i++)
        if (i != mine && i != with) other[n++] = i;

    game.side[mine].ally = (unsigned char)with;
    game.side[with].ally = (unsigned char)mine;
    if (n == 2) {
        game.side[other[0]].ally = (unsigned char)other[1];
        game.side[other[1]].ally = (unsigned char)other[0];
    }

    /* The four name slots the message reads through "@S", in the order
     * 0x1d83 onwards fills them. */
    country_name(mine, nm[0], DLG_TEXT);
    country_name(with, nm[1], DLG_TEXT);
    country_name(n == 2 ? other[1] : mine, nm[2], DLG_TEXT);
    country_name(n == 2 ? other[0] : mine, nm[3], DLG_TEXT);
    slot[0].addr = 0xc52e; slot[0].text = nm[0];
    slot[1].addr = 0xc530; slot[1].text = nm[1];
    slot[2].addr = 0xc532; slot[2].text = nm[2];
    slot[3].addr = 0xc534; slot[3].text = nm[3];

    dlg_close();
    dlg.what = DLG_REFUSED;             /* a message with one way out */
    dlg_say_table_fmt(0x11c7, slot, 4);
    if (dlg.lines == 0) dlg_say("allied");
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
    app_sound(0x0302);                  /* 0x1d6b */
    snprintf(status, sizeof status, "allied with %s", nm[1]);
}

/* 0x1d2d: the other side refuses if it holds more land than you do.  sub_ab2b
 * reads the 32-bit total at +8 of each side record and the comparison is
 * "sub ax, bx / sbb cx, dx / jae accept", so equal is accepted and only
 * strictly more is refused.  DS:0x11dd is "@Sは同盟を拒否しました。" */
static void ally_refuse(int with)
{
    FmtSlot slot[1];
    char nm[DLG_TEXT];

    country_name(with, nm, sizeof nm);
    slot[0].addr = 0xc52e;
    slot[0].text = nm;
    dlg_close();
    dlg.what = DLG_REFUSED;
    dlg_say_table_fmt(0x11dd, slot, 1);
    if (dlg.lines == 0) dlg_say("refused");
    dlg_say("");
    dlg_choice(JP_CLOSE, 0);
    app_sound(APP_SND_FAILED);          /* 0x702 at 0x1d3f */
    snprintf(status, sizeof status, "%s refused the alliance", nm);
}

/* The order menu, which is what sub_20f0 puts up once a destination has been
 * named: the choices are the ones the square allows. */
/* The order menu, and every line of it is the game's own.
 *
 * sub_20f0 does not work the choices out from the terrain, which is what this
 * port used to do.  It puts up the descriptor at DS:0x1093, which is a
 * twelve-line window whose single template lives at DS:0x15a5:
 *
 *     "@.2t" "@?" "@.2t" "@?" "@.2t" "@S" 0x17
 *
 * with the words c4f8 0000 1308 1306 c512 0000 12f9 12fe 12b7 0000 after its
 * terminator.  sub_759b keeps the line number in [0xc54c], and "@.2t" means
 * "take that line number, multiply by two, add the next argument and write the
 * answer into the argument after it" - so line k indexes three parallel
 * tables.  "@?" then reads the word it just addressed and draws one of two
 * strings depending on whether it is zero, and "@S" draws the string a pointer
 * points at.  Written out, line k is
 *
 *     colour   [0xc4f8 + k*2] ? DS:0x1308 (0x17) : DS:0x1306 (0x16)
 *     colour   [0xc512 + k*2] ? nothing          : DS:0x12fe (0x12)
 *     the name *(word *)(DS:0x12b7 + k*2), which is 0xc692 + k*16
 *
 * and 0xc692 is record six of the twenty-two that gfx_load_names already
 * pulls out of the tail of B_0n0L.CH4.  So the twelve names are on the floppy,
 * different for every tileset, and the demo disk reads:
 *
 *     0 待機      1 オート    2 拠点防衛  3 援軍
 *     4 村を壊す  5 村を作る  6 柵を作る  7 橋を作る
 *     8 開墾      9 柵を壊す 10 橋を壊す 11 洞窟封鎖
 *
 * The two masks come from sub_ab3e, which is called with the destination at
 * 0x2215 just before the window goes up.  It reads the destination's terrain
 * byte, sorts it into one of eleven buckets by a ladder of ranges, and expands
 * two twelve-bit masks out of the four bytes at DS:0x22f5 + bucket * 4 - one
 * word a line, 0xffff or 0.  The buckets say what the terrain bytes mean:
 *
 *     0x08..0x0b  a village   - 村を壊す and 村を作る
 *     0x01..0x04  waste       - 開墾 only
 *     0x7b        a fence     - 柵を作る and 柵を壊す
 *     0x7a        rock        - 橋を作る and 橋を壊す
 *     0x20..0x2f  a bridge    - 橋を壊す
 *     0x30..0x5f  water       - 橋を作る, and nothing else at all
 *     0x05        a cave      - 洞窟封鎖
 *     0x14..0x17  a castle    - 村を作る
 *
 * The low nibble of the state byte is the choice itself, which is how the five
 * job handlers this port already had line up: 6 is sub_3f62, 7 sub_4040, 9
 * sub_41dc, 10 sub_4247 and 11 sub_4304.
 */
#define ORDER_MASKS 0x22f5

static int order_bucket(unsigned char t)
{
    /* sub_ab3e, 0xab4a onwards.  The ladder tests in this order and the first
     * range that matches wins, so it is written out the same way. */
    if (t == 0) return 0;
    if (t >= 8 && t < 0x0c) return 1;
    if (t >= 0x0c && t < 0x10) return 2;
    if (t >= 1 && t < 5) return 3;
    if (t == 0x7b) return 4;
    if (t >= 0x20 && t < 0x30) return 5;
    if (t == 5) return 6;
    if (t == 0x7a) return 7;
    if (t >= 0x30 && t < 0x60) return 8;
    if (t >= 0x14 && t < 0x18) return 9;
    return 10;
}

/* The pair of masks for a square, straight out of PROG.DAT so they stay the
 * game's numbers.  Returns 0 if the table cannot be read, and then everything
 * is treated as allowed. */
static int order_masks(unsigned char t, unsigned *m1, unsigned *m2)
{
    const unsigned char *p = dat_at(ORDER_MASKS + order_bucket(t) * 4, 4);

    if (!p) { *m1 = 0xfff; *m2 = 0xfff; return 0; }
    *m1 = (unsigned)(p[0] | (p[1] << 8)) & 0xfff;
    *m2 = (unsigned)(p[2] | (p[3] << 8)) & 0xfff;
    return 1;
}

/* One of the twelve names, cleaned of its controls and its padding. */
static void order_name(int k, char *out, int max)
{
    if (!namesOk || k < 0 || k >= 12) {
        snprintf(out, max, "order %d", k);
        return;
    }
    dlg_clean((const char *)names[6 + k], out, max);
}

/* Which choice the first window took, kept while the second is up.  The
 * original keeps it in [0x3bf4] and reads it back at 0x227b, which is why the
 * second window can name it: DS:0x1dee is "@16t@sを行う" with 0x3bf4 and
 * 0xc692 as its arguments. */
static int orderK;
static int orderAt;                     /* [0x3ea4], the destination */

/* The follow-up window at 0x2241: what to do once the job is finished.  Three
 * lines from DS:0x109b, or two from DS:0x10a7 when the job is 橋を作る, and
 * "ror ah, 2" folds the answer into the top two bits of the state. */
static void dlg_open_order2(void)
{
    char nm[DLG_TEXT], line[DLG_TEXT];

    order_name(orderK, nm, sizeof nm);
    dlg_close();
    dlg.what = DLG_ORDER2;
    snprintf(line, sizeof line, "%s%s", nm, JP_ORDER_DO);
    dlg_say(line);
    dlg_say("");
    order_name(1, nm, sizeof nm);       /* オート */
    snprintf(line, sizeof line, "%s%s", nm, JP_ORDER_THEN);
    dlg_choice(line, 0);
    order_name(0, nm, sizeof nm);       /* 待機 */
    snprintf(line, sizeof line, "%s%s", nm, JP_ORDER_THEN);
    dlg_choice(line, 1);
    /* 0x225a: the third line is missing for choice seven, and the table it
     * switches to - DS:0x10a7 - is two lines rather than three. */
    if (orderK != 7) {
        order_name(orderK, nm, sizeof nm);
        snprintf(line, sizeof line, "%s%s", nm, JP_ORDER_KEEP);
        dlg_choice(line, 2);
    }
}

/* 0x227b onwards: build the state byte and hand it to the engine.
 *
 *     al = the first window's choice
 *     if al != 1 then al |= 0x10           ; 0x227e
 *     ror ah, 2                            ; the follow-up, into bits 6 and 7
 *     al |= ah
 *     [si+0xa] = al                        ; the unit's state
 *     [si+8]   = the destination
 *     [si+0xb] = 0xff
 *
 * so choice one - オート - is state 1 and every other choice carries 0x10.
 * That is why the low nibble lines up with the sixteen handlers at CS:0x3a47.
 */
static void order_apply(int after)
{
    int cx = orderAt & 0xff, cy = (orderAt >> 8) & 0xff;
    int who = selected, k = orderK, state, len;
    char nm[DLG_TEXT];

    dlg_close();
    selected = -1;
    if (who < 0 || game_unit_free(&game, who)) {
        app_sound(APP_SND_FAILED);
        snprintf(status, sizeof status, "the unit is gone");
        return;
    }
    state = k == 1 ? 1 : (k | 0x10);
    state |= (after & 3) << 6;
    order_name(k, nm, sizeof nm);
    len = game_order(&game, who, cx, cy, state);
    app_sound(len ? APP_SND_OK : APP_SND_FAILED);
    if (len)
        snprintf(status, sizeof status, "%s at %d,%d - state %02x, %d to walk",
                 nm, cx, cy, state, len);
    else
        snprintf(status, sizeof status, "cannot reach %d,%d for %s",
                 cx, cy, nm);
}

/* The warning at 0x2191 and 0x21c3, and the two-line menu at DS:0x10e7 that
 * follows both of them.  0x21ba and 0x21ec read the answer the same way: nought
 * - 強行 - falls through to 0x21f5 and the order stands, and anything else goes
 * back to 0x211a, which is the destination loop again.  A cancel does the same,
 * so the unit stays in your hand either way.
 *
 *   DS:0x1147  目標までの経路に危険な敵がいます
 *   DS:0x113f  目標までの経路が仲間によってふさがれています
 */
#define GUARD_ENEMY_ON_WAY 0x1147
#define GUARD_FRIENDS_ON_WAY 0x113f

static void dlg_open_force(unsigned tableAddr)
{
    dlg_close();
    dlg.what = DLG_FORCE;
    dlg_say_table(tableAddr);
    if (dlg.lines == 0) dlg_say("the way is not clear");
    dlg_say("");
    dlg_choices_table(0x10e7);
    if (dlg.count == 0) { dlg_choice(JP_CLOSE, 1); }
    app_sound(APP_SND_FAILED);          /* 0x402 at 0x2193 and 0x21c5 */
}

/* 0x21f5: the destination is settled.  The confirm sound goes here rather than
 * with the pick-up, because this is where the original plays 0x602, and then
 * the lord skips the menu - 0x2208 tests bit 0x20 and stores 0x2d - while
 * everyone else is asked. */
static void order_chosen(void)
{
    int cx = orderAt & 0xff, cy = (orderAt >> 8) & 0xff;

    app_sound(APP_SND_OK);                      /* 0x2201 */
    if (selected >= 0 && (game.unit[selected].state & 0x20)) {
        int len = game_order(&game, selected, cx, cy, UNIT_STATE_LORD);
        snprintf(status, sizeof status, len
                 ? "the lord is walking to %d,%d, %d squares"
                 : "no way for the lord to reach %d,%d",
                 cx, cy, len);
        if (!len) app_sound(APP_SND_FAILED);
        selected = -1;
        return;
    }
    dlg_open_order(cx, cy);
}

/* 0x203e, and it needs no guard at all - it goes straight to sub_727a.
 *
 * The menu is DS:0x10c5, four lines that read
 *
 *     グラフィック    ドライブ@3t@s
 *     ＢＧＭデーター  ドライブ@3t@s
 *     マップデーター  ドライブ@3t@s
 *     ゲームデーター  ドライブ@3t@s
 *
 * with the words 3476+i*2 and 1854 after each terminator.  "@3t" works out
 * "the word at the first argument, times three, plus the second" and writes it
 * into the argument after, which "@s" then draws: DS:0x1854 is four three-byte
 * strings, the full-width １ ２ ３ ４.  So each line says which drive that kind
 * of data is read from.
 *
 * Confirming does not leave: 0x205e xors [bx + 0x3476] with 1 and jumps back to
 * the top, so a confirm toggles the drive between one and two and the window
 * stays.  It is the CANCEL that leaves, and 0x2055 plays 0x602 - the "taken"
 * sound - on the way out, which is the other way round from every other window.
 *
 * A browser has no drives, so the setting cannot mean anything here; the window
 * is still worth having, because showing the game's own four lines says what the
 * icon is for, where a refusal said only that this port had not got to it.
 */
static unsigned char driveOf[4] = {0, 0, 0, 0};     /* [0x3476..0x347c] */

static void dlg_open_drive(void)
{
    int i;

    dlg_close();
    dlg.what = DLG_DRIVE;
    for (i = 0; i < 4; i++) {
        const unsigned char *p = dat_at(0x10c5 + 6 + i * 2, 2);
        unsigned at, numAt;
        FmtSlot slot[2];
        char letter[8];
        const unsigned char *num;
        int before = dlg.lines;

        if (!p) break;
        at = (unsigned)(p[0] | (p[1] << 8));
        numAt = 0x1854 + (unsigned)driveOf[i] * 3;
        num = dat_at(numAt, 3);
        letter[0] = 0;
        if (num) {
            letter[0] = (char)num[0];
            letter[1] = (char)num[1];
            letter[2] = 0;
        }
        /* The flag "@3t" reads, and then the string "@s" draws at the address
         * it works out.  Written this way round the port does the original's
         * arithmetic rather than short-circuiting it. */
        slot[0].addr = 0x3476 + (unsigned)i * 2;
        slot[0].text = 0;
        slot[0].value = driveOf[i];
        slot[0].isNum = 1;
        slot[1].addr = numAt;
        slot[1].text = letter;
        slot[1].value = 0;
        slot[1].isNum = 0;
        dlg_say_fmt(at, slot, 2);
        if (dlg.lines > before) {
            if (!dlg.count) dlg.first = before;
            dlg.value[before] = i;
            dlg.count++;
        }
    }
    if (dlg.count == 0) {
        dlg_say("DRIVE");
        dlg_say("");
        dlg_choice(JP_CLOSE, -1);
    }
}

/* The save and load lists, which are one descriptor used twice: 0x1efc and
 * 0x2007 both hand sub_49bb DS:0x10bd, whose header is 04 01 8a 15 50 00 -
 * position (4,1), ten lines visible with bit 7 set, height 21, eighty in all -
 * and put the answer in [0x3bf6].  Bit 7 means the count is not a list of
 * pointers but one template indexed by the line number, and the template is
 * DS:0x170c:
 *
 *     "@2b : @.12t@.o@?"   with c54c f67e 0000 0000 174d 1729
 *
 *   @2b     [0xc54c], the line being drawn, so each line numbers itself
 *   @.12t   0xf67e + (line - 1) * 12, written into the argument after it
 *   @.o     take that as the base
 *   @?      base+0 is nought -> DS:0x1729, a row of dashes; otherwise
 *           DS:0x174d, "@O@? @2b/@.2b/@.2b @2b:@.2b" - the date out of +6..+10
 *           with base+4 choosing DS:0x1779 "@OMAP-No.@.3w @?" or DS:0x1792
 *           "@OOnly cursor position", and base+2 inside that choosing
 *           DS:0x17a9 "@O@5w DAYS" or DS:0x17b8 "beginning".
 *
 * Cancel leaves with the 0x602 sound, which is the same the other way round as
 * the drive window (0x1f27 and 0x202c).
 */
static void dlg_open_slots(int what)
{
    int i;

    dlg_close();
    dlg.what = what;
    dlg_say_table(what == DLG_SAVE ? SAVE_TITLE_AT : LOAD_TITLE_AT);
    if (dlg.lines == 0) dlg_say(what == DLG_SAVE ? "SAVE" : "LOAD");
    dlg_say("");

    dlg.total = SAVE_SLOTS;
    dlg.window = 10;                    /* the descriptor's own count */
    dlg.first = dlg.lines;
    dlg.count = dlg.window;
    for (i = 0; i < dlg.window; i++) dlg_say("");
    dlg.pick = 0;
    dlg.top = 0;
    slot_lines();
}

/* Writing a slot and reading it back.  What goes in is the port's own shape:
 * the stage records, the reached counter, and - when a stage is under way - the
 * whole board, because being byte-compatible with a floppy the browser has not
 * got would buy nothing.  The directory entry is the game's, so the list reads
 * the way the original's does.
 *
 * 0x64e8: the day is only recorded when [0x3bd4] says the stage is under way
 * and [0x3bd6] says no loss is pending; otherwise it is nought, which is what
 * makes the list say "beginning".
 */
static int slot_write(int at)
{
    SaveSlot *sl;
    SaveBlob *b;
    time_t now;
    struct tm *t;

    if (at < 0 || at >= SAVE_SLOTS) return 0;
    sl = &slotDir[at];
    b = (SaveBlob *)calloc(1, sizeof *b);
    if (!b) return 0;
    b->magic = SAVE_MAGIC;
    b->mapNumber = (unsigned short)mapNumber;
    b->tileSize = (unsigned short)tileSize;
    b->reached = (unsigned short)reached;
    b->hasGame = (unsigned short)(mode == APP_MODE_MAP);
    b->day = (unsigned short)game.day;
    b->daysLeft = (unsigned short)game.daysLeft;
    memcpy(b->record, record, sizeof record);
    b->game = game;

    free(sl->blob);
    sl->blob = (unsigned char *)b;
    sl->blobLen = (unsigned)sizeof *b;
    sl->used = 1;
    /* 0x64ff and 0x6502 put the day and the stage in the entry, the day only
     * when the stage is under way (0x64e8), which is what makes the list say
     * "beginning".  The stage is stored one along, because the original writes
     * [0x3bc2] as it stands and DS:0x174d reads nought as "Only cursor
     * position" - so a save on the very first stage would read as an empty
     * one, which is worth not copying. */
    sl->map = (unsigned short)(mode == APP_MODE_MAP ? mapNumber + 1 : 0);
    sl->days = (unsigned short)(underWay ? game.day : 0);
    now = time(0);
    t = localtime(&now);
    if (t) {
        sl->yy = (unsigned char)(t->tm_year % 100);
        sl->mm = (unsigned char)(t->tm_mon + 1);
        sl->dd = (unsigned char)t->tm_mday;
        sl->hh = (unsigned char)t->tm_hour;
        sl->mi = (unsigned char)t->tm_min;
    }
    b->used = sl->used;
    b->days = sl->days;
    b->map = sl->map;
    b->yy = sl->yy;
    b->mm = sl->mm;
    b->dd = sl->dd;
    b->hh = sl->hh;
    b->mi = sl->mi;
    slotStamp++;
    return 1;
}

static int slot_read(int at)
{
    const SaveSlot *sl;
    const SaveBlob *b;

    if (at < 0 || at >= SAVE_SLOTS) return 0;
    sl = &slotDir[at];
    if (!sl->used || !sl->blob || sl->blobLen < sizeof *b) return 0;
    b = (const SaveBlob *)sl->blob;
    if (b->magic != SAVE_MAGIC) return 0;
    memcpy(record, b->record, sizeof record);
    reached = b->reached;
    if (b->hasGame) {
        if (!app_show_map(b->mapNumber, b->tileSize)) return 0;
        game = b->game;
        game.day = b->day;
        game.daysLeft = b->daysLeft;
        game_forget_distances();
        live = map;
        {
            int i;
            for (i = 0; i < MAP_W * MAP_H; i++) live.cell[i] = game.cell[i].tile;
        }
    }
    return 1;
}

static void dlg_open_order(int cx, int cy)
{
    unsigned char t = game.cell[game_cell_index(cx, cy)].tile;
    unsigned m1, m2;
    int k;

    order_masks(t, &m1, &m2);
    dlg_close();
    dlg.what = DLG_ORDER;
    orderAt = (cy << 8) | cx;
    dlg.value[0] = orderAt;
    for (k = 0; k < 12; k++) {
        char nm[DLG_TEXT];

        order_name(k, nm, sizeof nm);
        dlg_choice(nm, k);
        /* 0x1308 is white and 0x1306 dark; then a clear bit in the second mask
         * overrides both with DS:0x12fe, which is red.  Read together: white is
         * what this square is for, dark is possible but not the point, and red
         * is a square the order means nothing on. */
        dlg.colour[dlg.lines - 1] =
            (unsigned char)(!((m2 >> k) & 1) ? 2 : ((m1 >> k) & 1) ? 7 : 6);
    }
    /* The selection is remembered between windows, which is what [0x3bf4]
     * being a static is for. */
    if (orderK >= 0 && orderK < dlg.count) dlg.pick = orderK;
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
        /* 0x1b21: with no stage loaded, GO takes the one [0xce70] names and
         * loads it - this is the only place in the program that does. */
        if (!stageLoaded && !app_show_map(reached, tileSize)) break;
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
    /* The guards are not all the same, which is worth reading off each handler
     * rather than assuming:
     *
     *   0x1c06  TAX    sub_b509 AND sub_b571 - it changes your own rate, so it
     *                  needs a country as well as a stage
     *   0x1c36  INFO   sub_b509
     *   0x1c4d  ZOOM   sub_b509
     *   0x1c21  SPEED  nothing at all.  It goes straight to sub_727a, so the
     *                  speed can be set on the title screen before a stage is
     *                  even loaded, and this port refusing it was its own idea.
     *   0x1cb0  ALLY   all three
     */
    case ICON_TAX:
        if (!guard_stage()) break;
        if (!guard_has_land()) break;
        app_sound(APP_SND_OK); dlg_open_tax();   break;
    case ICON_INFO:
        if (!guard_stage()) break;
        app_sound(APP_SND_OK); dlg_open_info();  break;
    case ICON_SPEED:
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
        if (!guard_stage()) break;
        app_sound(APP_SND_OK);
        dlg_open_mapsel();
        break;
    /* 0x1ee5 and 0x1ff3 both open with sub_6591, which picks the game-data
     * drive and reads the eighty-entry directory into DS:0xf67e before the
     * window goes up.  There is no drive here, so the directory is whatever
     * this session and the page's own store have put in it. */
    case ICON_LOAD:
        app_sound(APP_SND_OK);
        dlg_open_slots(DLG_LOAD);
        break;
    case ICON_SAVE:
        app_sound(APP_SND_OK);
        dlg_open_slots(DLG_SAVE);
        break;
    /* 0x206c has no guard either, and it is the same question sub_06e7 asks at
     * boot - a knob on [0x3286] rather than a menu, but two positions either
     * way. */
    case ICON_CRT:
        app_sound(APP_SND_OK);
        dlg_close();
        dlg.what = DLG_DEVICE;
        device_lines();
        break;
    /* 0x203e has no guard - straight to sub_727a. */
    case ICON_DRIVE:
        app_sound(APP_SND_OK);
        dlg_open_drive();
        break;
    default:
        app_sound(APP_SND_NO);          /* not a refusal by the game: by me */
        snprintf(status, sizeof status,
                 "%s is in the original but not in this port yet",
                 idx == ICON_EDIT ? "EDIT" : "FORM");
        break;
    }
}

/* Fill the ten visible lines of the slot list from the game's own template.
 * The slots the format engine is given are rebuilt for each line, because the
 * base - 0xf67e + (line - 1) * 12 - is different on every one. */
static void slot_lines(void)
{
    int i;

    if (dlg.what != DLG_SAVE && dlg.what != DLG_LOAD) return;
    if (dlg.top < 0) dlg.top = 0;
    if (dlg.top > dlg.total - dlg.window) dlg.top = dlg.total - dlg.window;
    for (i = 0; i < dlg.window; i++) {
        int at = dlg.top + i;
        int line = at + 1;              /* [0xc54c] counts from one */
        unsigned base = SAVE_DIR_AT + (unsigned)at * 12;
        const SaveSlot *sl = &slotDir[at];
        FmtSlot fs[9];
        char out[DLG_TEXT];
        int k;

        fs[0].addr = 0xc54c; fs[0].value = line;        /* "@2b" */
        fs[1].addr = base + 0; fs[1].value = sl->used;
        fs[2].addr = base + 2; fs[2].value = sl->days;
        fs[3].addr = base + 4; fs[3].value = sl->map;
        fs[4].addr = base + 6; fs[4].value = sl->yy;
        fs[5].addr = base + 7; fs[5].value = sl->mm;
        fs[6].addr = base + 8; fs[6].value = sl->dd;
        fs[7].addr = base + 9; fs[7].value = sl->hh;
        fs[8].addr = base + 10; fs[8].value = sl->mi;
        for (k = 0; k < 9; k++) { fs[k].text = 0; fs[k].isNum = 1; }
        out[0] = 0;
        fmt_render(0x170c, fs, 9, out, (int)sizeof out, 0, line, 0);
        snprintf(dlg.line[dlg.first + i], DLG_TEXT, "%s", out);
        dlg.colour[dlg.first + i] = 7;
        dlg.value[dlg.first + i] = at;
    }
}

/* 0x4cc4 and 0x4ccd: the box follows the selection when it reaches an edge. */
static void dlg_follow(void)
{
    int i;

    if (dlg.window <= 0) return;
    if (dlg.pick < dlg.top) dlg.top = dlg.pick;
    if (dlg.pick >= dlg.top + dlg.window) dlg.top = dlg.pick - dlg.window + 1;
    if (dlg.top < 0) dlg.top = 0;
    if (dlg.top > dlg.total - dlg.window) dlg.top = dlg.total - dlg.window;
    if (dlg.what == DLG_SAVE || dlg.what == DLG_LOAD) {
        slot_lines();
        return;
    }
    for (i = 0; i < dlg.window; i++) {
        int at = dlg.top + i;
        snprintf(dlg.line[dlg.first + i], DLG_TEXT, "%s",
                 at < dlg.total ? dlg.item[at] : "");
        dlg.value[dlg.first + i] = at;
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
    /* 0x2236 sends a cancel to 0x22ce, which is the same place the
     * destination loop's cancel goes: it plays 0x0702 and drops the whole
     * thing.  An earlier note here said the unit stayed in your hand, which
     * came from misreading "jae 0x223b" as the cancel arm rather than the
     * confirm one. */
    case DLG_ORDER:
    case DLG_ORDER2:
        dlg_close();
        selected = -1;
        app_sound(APP_SND_FAILED);          /* 0x0702 at 0x22d3 */
        snprintf(status, sizeof status, "cancelled");
        break;
    /* sub_06e7 does not take a cancel, so there is nothing to do with one. */
    case DLG_DEVICE:
        break;
    /* 0x1f27 and 0x202c: the same as the drive window, the cancel is what
     * leaves and it plays 0x602 doing it. */
    case DLG_SAVE:
    case DLG_LOAD:
        dlg_close();
        app_sound(APP_SND_OK);
        snprintf(status, sizeof status, "back from the slot list");
        break;
    /* 0x2052 takes the cancel out of the drive window, and 0x2055 plays 0x602
     * on the way - the only window where leaving sounds like accepting. */
    case DLG_DRIVE:
        dlg_close();
        app_sound(APP_SND_OK);
        snprintf(status, sizeof status, "drives set");
        break;
    /* 0x21b7 sends the warning's cancel back to 0x211a, not to 0x22ce: the
     * unit stays in your hand and you pick a different square. */
    case DLG_FORCE:
        dlg_close();
        snprintf(status, sizeof status,
                 "pick another square - the unit is still yours");
        break;
    case DLG_FELL:
    case DLG_OVER:
    case DLG_REFUSED:
        dlg_confirm();              /* these only wait for a key */
        break;
    /* 0x53f1 and 0x5309 put the byte they saved on the way in back before they
     * leave, and both play 0x601 doing it.  The tax window does not restore
     * anything, so what the knob was left on is what the country pays. */
    case DLG_SPEED:
        game.speed = speedWas;
        dlg_close();
        app_sound(APP_SND_CONFIRM);
        snprintf(status, sizeof status, "speed left at %d", game.speed);
        break;
    case DLG_ZOOM:
        dlg_close();
        app_sound(APP_SND_CONFIRM);
        snprintf(status, sizeof status, "square size unchanged");
        break;
    case DLG_TAX:
        dlg_close();
        app_sound(APP_SND_CONFIRM);
        snprintf(status, sizeof status, "tax rate %d of %d",
                 game.side[game.human < 0 ? 0 : game.human].rate, TAX_MAX);
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
    /* With a scroll window the selection is an index into the whole list and
     * the line it is drawn on is the one the box shows it at, which is what
     * the drawing works out too.  Reading dlg.value at first + pick was right
     * only while the box was at the top of the list. */
    int line = dlg.first + (dlg.window > 0 ? dlg.pick - dlg.top : dlg.pick);
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
            /* 0xb3e3: the counter only moves when this stage was the
             * furthest one AND the score was worth recording (0xb3d1 and
             * 0xb3d7 guard the whole block), and then 0x6315 starts whatever
             * [0xce70] now names. */
            if (overImproved && mapNumber >= reached && reached + 1 < MAP_COUNT)
                reached++;
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
    /* 0x4f5b only sounds and clears the carry: the rate has been in the side
     * record since the knob last moved. */
    case DLG_TAX:
        game.side[game.human < 0 ? 0 : game.human].rate =
            (unsigned char)dlg.value[0];
        snprintf(status, sizeof status, "tax rate %d of %d", dlg.value[0],
                 TAX_MAX);
        dlg_close();
        break;
    case DLG_SPEED:
        game.speed = value;             /* already set, but say so plainly */
        snprintf(status, sizeof status, "speed %s",
                 value == 0 ? "fast" : value == 1 ? "normal" : "slow");
        dlg_close();
        break;
    case DLG_ZOOM:
        dlg_close();
        app_show_map(mapNumber, value);
        break;
    case DLG_MAPSEL: {
        int want = dlg.pick;            /* the index into the whole list */
        dlg_close();
        if (want >= 0 && want < MAP_COUNT) app_show_map(want, tileSize);
        break;
    }
    case DLG_ALLY: {
        int mine = game.human < 0 ? 0 : game.human;

        /* 0x1d0c and 0x1d18: your own country and a fallen one send the menu
         * straight back to waiting, with no sound and no message. */
        if (value == mine || value < 0 || value >= PLAYERS ||
            !game.side[value].alive || game.side[value].flag)
            break;                      /* the window stays up */
        if (game.side[value].landTotal > game.side[mine].landTotal)
            ally_refuse(value);
        else
            ally_strike(value);
        break;
    }
    case DLG_ORDER: {
        /* 0x223b: choices nought to three go straight through, and anything
         * above opens the follow-up window before the order is stored. */
        orderK = value;
        if (value > 3) {
            app_sound(APP_SND_OK);
            dlg_open_order2();
            break;
        }
        order_apply(0);
        break;
    }
    case DLG_ORDER2:
        order_apply(value);
        break;
    /* 0x205e: a confirm toggles the drive and jumps back to the top of
     * 0x203e, so the window is rebuilt and stays up. */
    case DLG_DRIVE: {
        int which = value, pick = dlg.pick;

        if (which >= 0 && which < 4) driveOf[which] ^= 1;
        dlg_open_drive();
        dlg.pick = pick;
        snprintf(status, sizeof status, "drive %d for kind %d",
                 which >= 0 && which < 4 ? driveOf[which] + 1 : 0, which);
        break;
    }
    /* 0x1f39: a slot with nothing in it sends the load list back to waiting,
     * so an empty slot cannot be chosen.  A save slot can, used or not. */
    case DLG_LOAD:
        if (value < 0 || value >= SAVE_SLOTS || !slotDir[value].used) {
            app_sound(APP_SND_NO);
            return;                     /* the window stays up */
        }
        dlg_close();
        if (slot_read(value)) {
            app_sound(APP_SND_OK);
            snprintf(status, sizeof status, "loaded slot %d", value + 1);
        } else {
            app_sound(APP_SND_FAILED);
            snprintf(status, sizeof status, "slot %d would not read",
                     value + 1);
        }
        break;
    case DLG_SAVE:
        if (slot_write(value)) {
            app_sound(APP_SND_OK);
            slot_lines();               /* the list shows it at once */
            snprintf(status, sizeof status, "saved to slot %d", value + 1);
        } else {
            app_sound(APP_SND_FAILED);
            snprintf(status, sizeof status, "slot %d would not write",
                     value + 1);
        }
        break;
    /* sub_06e7 asks for 0x23 - no cancel - so this is the only way out. */
    case DLG_DEVICE:
        lcd = value ? 1 : 0;
        dlg_close();
        app_show_title();
        break;
    case DLG_FORCE:
        /* 0x21ba and 0x21ec: nought is 強行 and goes on, anything else goes
         * back to choosing a destination with the unit still held. */
        dlg_close();
        if (value == 0) {
            order_chosen();
        } else {
            snprintf(status, sizeof status,
                     "pick another square - the unit is still yours");
        }
        break;
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
        /* Off the title and on to the game screen, which has no stage on it
         * yet: GO is what loads one. */
        if (key == APP_KEY_START) app_show_ready();
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
                dlg_follow();
                /* A knob is silent; only a menu clicks. */
                if (!slider_is(dlg.what)) app_sound(APP_SND_MOVE);  /* 0x4c2e */
                slider_apply();
            }
            return;                             /* 0x4cab: no wrap, no sound */
        case APP_KEY_DOWN:
            if (tax_step(1)) return;
            if (dlg.pick + 1 < (dlg.window > 0 ? dlg.total : dlg.count)) {
                dlg.pick++;
                dlg_follow();
                if (!slider_is(dlg.what)) app_sound(APP_SND_MOVE);
                slider_apply();
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
    if (mode != APP_MODE_MAP || !stageLoaded) return;
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
    /* 0x00fe puts 4 in [0x3bc6] at boot and 0x017e loads it, and sub_06e7's
     * question comes before either - so the display screen and the title share
     * the same song. */
    if (mode == APP_MODE_TITLE || mode == APP_MODE_DEVICE) return 4;
    if (mode == APP_MODE_MAP) {                 /* 0x1945 */
        int set = map.terrain / 10;

        /* sub_b2f2 puts 1 in [0x3bc6] when the game is won and sub_b28d puts
         * 2 there when it is lost, before loading and starting it. */
        if (game.over == 1) return 1;
        if (game.over == 2) return 2;
        /* Before GO the screen is the panel with no stage on it, and 0x1927
         * has just put 5 in [0x3bc6] - the setting-up song - which is what the
         * main loop plays until a map is loaded. */
        if (!stageLoaded) return 5;
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
/* What the page needs to keep the slots between visits.  A slot is one opaque
 * byte array - the directory entry and the payload together - so the store need
 * not know the shape of anything. */
int app_save_slots(void) { return SAVE_SLOTS; }

int app_slot_used(int at)
{
    return at >= 0 && at < SAVE_SLOTS && slotDir[at].used ? 1 : 0;
}

const unsigned char *app_slot_bytes(int at, unsigned *len)
{
    if (len) *len = 0;
    if (at < 0 || at >= SAVE_SLOTS || !slotDir[at].used || !slotDir[at].blob)
        return 0;
    if (len) *len = slotDir[at].blobLen;
    return slotDir[at].blob;
}

int app_slot_put(int at, const unsigned char *bytes, unsigned len)
{
    const SaveBlob *b = (const SaveBlob *)bytes;
    SaveSlot *sl;

    if (at < 0 || at >= SAVE_SLOTS || !bytes || len != sizeof *b) return 0;
    if (b->magic != SAVE_MAGIC) return 0;
    sl = &slotDir[at];
    free(sl->blob);
    sl->blob = (unsigned char *)malloc(len);
    if (!sl->blob) { sl->blobLen = 0; sl->used = 0; return 0; }
    memcpy(sl->blob, bytes, len);
    sl->blobLen = len;
    sl->used = b->used ? b->used : 1;
    sl->days = b->days;
    sl->map = b->map;
    sl->yy = b->yy;
    sl->mm = b->mm;
    sl->dd = b->dd;
    sl->hh = b->hh;
    sl->mi = b->mi;
    slotStamp++;
    return 1;
}

int app_slot_stamp(void) { return slotStamp; }

int app_day(void) { return game.day; }

int app_tax(void)
{
    return game.side[game.human < 0 ? 0 : game.human].rate;
}

int app_speed(void) { return game.speed; }

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
        /* 0x210e: "test byte ptr [si], 2" and a dying unit is refused with
         * the same 0x402 as an empty square.  Nothing in this port stopped
         * you picking one up, and then the order was stored on a unit that
         * was about to be freed. */
        if (game.unit[who].flags & 2) {
            app_sound(APP_SND_NO);
            snprintf(status, sizeof status,
                     "%d,%d: that one is dying", cx, cy);
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
    /* A destination has been named.  Before anything else 0x2136 asks how
     * clear the way is, three times over, and only the careful answer goes
     * straight through - see game_route_tier.  A route that needs walking past
     * a dangerous enemy or through our own allies puts up the warning and the
     * 強行 / 再選択 menu; no route at all just plays 0x402 and leaves the unit
     * in your hand to be sent somewhere else. */
    orderAt = (cy << 8) | cx;
    switch (game_route_tier(&game, selected, cx, cy)) {
    case 2:
        break;
    case 1:
        dlg_open_force(GUARD_ENEMY_ON_WAY);
        return;
    case 0:
        dlg_open_force(GUARD_FRIENDS_ON_WAY);
        return;
    default:
        app_sound(APP_SND_FAILED);              /* 0x2188, then back to 0x211a */
        snprintf(status, sizeof status, "no way to %d,%d at all - pick another",
                 cx, cy);
        return;
    }
    order_chosen();
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
            dlg.pick = row - dlg.first + (dlg.window > 0 ? dlg.top : 0);
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
        app_show_ready();
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
    /* The display question comes before anything has been read off the disk -
     * sub_06e7 is called at 0x00b5, long before WAKU - so there is no frame
     * artwork to put it in.  The original draws it on the text screen with its
     * own box; here it is plain text on black, which is what that looks like.
     * The position is the descriptor's own: DS:0x101a puts the message at
     * (2,12) in cells and DS:0x101c the menu at (2,14). */
    if (mode == APP_MODE_DEVICE) {
        int i;

        memset(scr.px, 0, sizeof scr.px);
        for (i = 0; i < dlg.lines; i++) {
            int chosen = dlg.count && i == dlg.first + dlg.pick;
            int y = 12 * 16 + i * 16;

            if (chosen) {
                int j, k;
                for (j = 0; j < 16; j++)
                    for (k = 0; k < 34 * 8; k++)
                        scr.px[(size_t)(y + j) * SCR_W + 2 * 16 + k] = 2;
            }
            gfx_text_sjis(&scr, &font, &fontRom, 2 * 16, y, dlg.line[i], 7);
        }
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
    /* No stage, no world.  [0x3bc2] is 0xffff until GO loads one, and until
     * then the map window keeps the frame's own artwork - so everything below
     * this, which is the board and the readouts beside it, has nothing to draw
     * from.  Only the panel is live. */
    if (!stageLoaded) {
        int i, y;

        /* The map window is cleared rather than left as it is, because WAKU
         * keeps a second copy of the panel's icons at x 96 and 128 - the dim
         * ones snapshot_dim_icons takes - and with no map over them they show
         * as a stray column of artwork inside the frame. */
        for (y = 0; y < VIEW_H; y++)
            memset(scr.px + (size_t)(VIEW_Y + y) * SCR_W + VIEW_X, 0, VIEW_W);
        for (i = 0; i < DIM_ICONS; i++)
            if (!iconLive[i]) draw_dim_icon(i);
        if (panelIcon >= 0)
            outline_icon(panelIcon, iconLive[panelIcon] ? 7 : 2);
        return;
    }
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
    /* The tax window is not a box of text: sub_4e49 builds a bar out of the
     * icon sheet and puts two knobs on it.
     *
     *   0x4b61   the frame, bx = 0x0101 and cx = 0x1302 - cell (1,1) off the
     *            map frame's corner at (96,8), so (112,24), nineteen cells
     *            wide and two lines deep
     *   0x4e53   the rail at VRAM 0xc8f, which is row 40 byte 15 = (120,40):
     *            piece 0x8a4, then fifteen of 0x8a5, then one 0x8a6
     *   0x4e94   a knob, piece 0x8a7, at 0xc90 + (0x14 - (purse >> 8)) - the
     *            purse, clamped at nought, not the rate
     *   0x4eca   the rate's knob, same piece, at 0xc90 + [bx+0x12]
     *   0x4ed3   DS:0x1ae4 - "@2t@o@2b%" - at 0xcb1, which is (392,40)
     *
     * 0xc90 is row 40 byte 16, so a step of the rate is eight pixels and the
     * rate's thirty-one positions cover 128..368 inside a rail that runs
     * 120..392.
     */
    if (dlg.what == DLG_TAX && frameOk && iconsOk) {
        int mine = game.human < 0 ? 0 : game.human;
        unsigned long purse = game.side[mine].funds;
        int rate = game.side[mine].rate;
        long knob = purse >> 16 ? 0 : 0x14 - (long)((purse >> 8) & 0xff);
        char buf[16];
        int i;

        if (knob < 0) knob = 0;
        gfx_window(&scr, frameArt, 112, 24, 19, 2);
        gfx_blit_tile(&scr, &icons, 0x8a4 - ICON_PIECE_BASE, 120, 40);
        for (i = 0; i < 15; i++)
            gfx_blit_tile(&scr, &icons, 0x8a5 - ICON_PIECE_BASE,
                          120 + 16 + i * 16, 40);
        gfx_blit_tile(&scr, &icons, 0x8a6 - ICON_PIECE_BASE, 120 + 16 * 16, 40);
        gfx_blit_tile(&scr, &icons, 0x8a7 - ICON_PIECE_BASE,
                      128 + (int)knob * 8, 40);
        gfx_blit_tile(&scr, &icons, 0x8a7 - ICON_PIECE_BASE, 128 + rate * 8, 40);
        snprintf(buf, sizeof buf, "%2d%%", rate);
        gfx_text_sjis(&scr, &font, &fontRom, 392, 40, buf, 7);
    } else if (dlg.what != DLG_NONE && frameOk) {
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
            int chosen = dlg.count &&
                         i == dlg.first + (dlg.window > 0 ? dlg.pick - dlg.top
                                                          : dlg.pick);

            if (chosen) {
                int j, k;

                for (j = 0; j < 16; j++)
                    for (k = 0; k < cellsW * 16 - 8; k++)
                        scr.px[(size_t)(ly + j) * SCR_W + x + 16 + k] = 2;
            }
            gfx_text_sjis(&scr, &font, &fontRom, x + 16, ly, dlg.line[i],
                          dlg.colour[i] ? dlg.colour[i] : 7);
        }
    }
}
