/* The game's own state, laid out the way the original lays it out.
 *
 * Everything here was read off PROG.BIN rather than invented, so the field
 * names carry the address they came from.  The two big ones:
 *
 *   DS:C800  64 unit records of 16 bytes.  The updater at 0x32cc walks them
 *            with a stride of 0x1f0 (31 records) wrapping at 0x400, which is
 *            coprime with 64 and so visits every slot while spreading the work
 *            across frames.  How many it does per call is `0x40 >> [0x3c02]`,
 *            and [0x3c02] is the speed setting - the 速い / 普通 / 遅い menu.
 *
 *   DS:D27E  48 x 48 cells of **two** bytes.  The .MAP file holds one byte a
 *            cell; the loader expands it in place, backwards, at 0x60c3:
 *
 *                si = 0xdb7d / di = 0xe47c / cx = 0x900 / ah = 0x64
 *                std / lodsb / stosw / loop
 *
 *            so every cell becomes (tile, 100).  The high byte is the amount
 *            the square holds - it grows by 10 a tick, saturates at 255, has a
 *            threshold at 200, and a unit standing on a square takes it with
 *            `xchg` and carries it in its own +6 field.  That is the game's
 *            economy.
 *
 *   DS:E47E  one word a cell, right after the cells: the unit standing there,
 *            or 0.  The original writes it as `mov [di+0xe47e], si` with SI the
 *            unit record.
 *
 * The four castles come from the map itself: cell values 0x14..0x17 are the
 * four sides' castles, and every one of the 52 maps has **exactly one of each**.
 */
#ifndef GAME_H
#define GAME_H

#include "gfx.h"

#define UNIT_SLOTS 64
#define SIDES 4

/* Cell values that mark a side's castle.  0x14 + side. */
#define CELL_CASTLE0 0x14

typedef struct {
    unsigned char tile;         /* the .MAP byte: which terrain tile */
    unsigned char amount;       /* the high byte: starts at 100, caps at 255 */
} Cell;

typedef struct {
    unsigned char flags;        /* +0x00, bit 7 = the slot is not in play */
    unsigned char timer;        /* +0x01 */
    unsigned short at;          /* +0x04, the cell, as a byte offset (index*2) */
    unsigned short carrying;    /* +0x06 */
    unsigned char state;        /* +0x0a, low nibble = order, 0x10/0x20 = mode */
    unsigned char side;         /* +0x0c, 0..3 */
} Unit;

typedef struct {
    Cell cell[MAP_W * MAP_H];
    short occupant[MAP_W * MAP_H];      /* DS:E47E - a unit slot, or -1 */
    Unit unit[UNIT_SLOTS];
    int castleX[SIDES], castleY[SIDES]; /* -1 if the map has none */
    int terrain;                        /* the map's own tile set */
    int cursor;                         /* DS:3BEC, the rolling update cursor */
    int speed;                          /* DS:3C02, 0 = fastest */
} Game;

/* Builds the starting state from a loaded map: every cell at 100, no units,
 * and the four castles located. */
void game_init(Game *g, const Map *m);

/* One pass of the unit updater: `0x40 >> speed` slots, stepping 31 at a time.
 * The stepping is the original's, so a port that later fills in the handlers
 * gets the same visiting order. */
void game_step(Game *g);

#endif
