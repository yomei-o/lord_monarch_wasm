/* The game's own state, laid out the way the original lays it out.
 *
 * Everything here was read off PROG.BIN rather than invented, so the comments
 * carry the address the fact came from.  Three arrays sit next to each other in
 * the original's low memory:
 *
 *   DS:C792  five side records of 0x16 bytes.  Sides 0..3 are the players;
 *            side 4 is the neutral one.  The last of them ends at 0xc800,
 *            exactly where the units begin.
 *   DS:C800  64 unit records of 0x10 bytes.  The allocator (sub_add0) scans
 *            them for one whose byte 0 has bit 7 set, so bit 7 means "free".
 *   DS:D27E  48 x 48 cells of **two** bytes: (tile, amount).  DS:E47E, right
 *            after them, is one word a cell holding the unit standing there.
 *
 * The updater at 0x32cc walks the units with a stride of 0x1f0 (31 records)
 * wrapping at 0x400, which is coprime with 64 and so visits every slot while
 * spreading the work across frames.  How many it does per call is
 * `0x40 >> [0x3c02]`, and [0x3c02] is the 速い / 普通 / 遅い setting.
 *
 * The cell amount is the economy.  The loader expands the one-byte-a-cell .MAP
 * in place, backwards, at 0x60c3, writing (tile, 100) into every cell; from
 * there it grows by 10 a tick, saturates at 255, has a threshold at 200, and a
 * unit standing on a square takes it with `xchg` and carries it in its own +6.
 */
#ifndef GAME_H
#define GAME_H

#include "gfx.h"

#define UNIT_SLOTS 64
#define SIDES 5                 /* 0..3 play, 4 is neutral */
#define PLAYERS 4

/* Cell tiles that mean something to the rules rather than to the eye. */
#define CELL_NEUTRAL   0x06     /* becomes a neutral unit at startup */
#define CELL_CASTLE0   0x14     /* + side: the middle of a side's castle */
#define CELL_TERRITORY0 0x08    /* + side: ground that side holds */
#define CELL_IMPASSABLE 0x30    /* this and above is water and the like */

#define CELL_START_AMOUNT 0x64  /* 100 */
#define CELL_MAX_AMOUNT   0xff
#define CELL_FULL_AMOUNT  0xc8  /* 200, the threshold the code tests */

/* Unit states seen being written by the initialiser.  The low nibble of the
 * state picks one of sixteen order handlers through the table at CS:3A47; the
 * 0x10 and 0x20 bits pick a different branch in the dispatcher first. */
#define UNIT_STATE_LORD    0x2d /* the side's monarch */
#define UNIT_STATE_FOLLOW  0x01
#define UNIT_STATE_NEUTRAL 0x0f

typedef struct {
    unsigned char tile;         /* the .MAP byte: which terrain tile */
    unsigned char amount;       /* starts at 100, caps at 255 */
} Cell;

typedef struct {
    unsigned char flags;        /* +0x00, bit 7 = the slot is free */
    unsigned char timer;        /* +0x01, the initialiser writes 6 */
    unsigned short pos;         /* +0x02, (y << 8) | x */
    unsigned short at;          /* +0x04, the cell as a byte offset (index * 2) */
    unsigned short carrying;    /* +0x06 */
    unsigned short home;        /* +0x08, the lord gets its own position here */
    unsigned char state;        /* +0x0a */
    unsigned char link;         /* +0x0b, a unit slot, 0xff for none */
    unsigned char side;         /* +0x0c, 0..4 */
} Unit;

/* 0x16 bytes.  The initialiser at 0x0326 writes every one of these. */
typedef struct {
    unsigned short flag;        /* +0x00 */
    unsigned short pos;         /* +0x02, (y << 8) | x of the castle */
    unsigned short at;          /* +0x04, the castle cell as a byte offset */
    short lord;                 /* +0x06, the side's first unit (a slot here) */
    unsigned short full;        /* +0x0c, set to 200 */
    unsigned short funds;       /* +0x0e, set to 5000 */
    unsigned short spent;       /* +0x10, set to 0 */
    unsigned char rate;         /* +0x12, set to 10 */
    unsigned char b13;          /* +0x13, set to 0 */
    unsigned char b14;          /* +0x14, set to 0x80; sub_a61d returns it */
    int alive;                  /* the castle was found on this map */
} Side;

typedef struct {
    Cell cell[MAP_W * MAP_H];
    short occupant[MAP_W * MAP_H];      /* DS:E47E - a unit slot, or -1 */
    Unit unit[UNIT_SLOTS];
    Side side[SIDES];
    int terrain;                        /* the map's own tile set */
    int cursor;                         /* DS:3BEC, the rolling update cursor */
    int speed;                          /* DS:3C02, 0 = fastest */
} Game;

/* Builds the starting state from a loaded map, following sub_0311:
 *
 *   - every cell becomes (tile, 100)
 *   - for each of the four sides, find the cell holding (100, 0x14 + side) with
 *     `repne scasw`, fill in the side record, and put two units there: the lord
 *     on the castle with 1000 carried, and one on the square to its right with
 *     200
 *   - every cell whose tile is 6 becomes plain ground and gets a neutral unit
 *     (side 4) with 200 carried
 */
void game_init(Game *g, const Map *m);

/* One pass of the unit updater: `0x40 >> speed` slots, stepping 31 at a time. */
void game_step(Game *g);

/* Handy for the viewer and for tests. */
int game_unit_count(const Game *g, int side);
int game_cell_index(int x, int y);

#endif
