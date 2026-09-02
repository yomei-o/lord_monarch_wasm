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

/* The eight directions, from the table at DS:2827, and the deltas it holds.
 * Direction 0 is up and they run anticlockwise; the initialiser faces new units
 * 6, which is right, and puts the second unit on the square to the right. */
enum { DIR_UP, DIR_UPLEFT, DIR_LEFT, DIR_DOWNLEFT,
       DIR_DOWN, DIR_DOWNRIGHT, DIR_RIGHT, DIR_UPRIGHT };
extern const signed char GAME_DX[8], GAME_DY[8];

/* sub_ad80 rejects anything outside 1..0x2e in either axis, so the outermost
 * ring of the map is off limits - the "外周部当り" of the message table. */
#define MAP_MIN 1
#define MAP_MAX 0x2e

typedef struct {
    unsigned char flags;        /* +0x00, bit 7 = the slot is free */
    unsigned char facing;       /* +0x01, a direction; new units get 6 */
    unsigned short pos;         /* +0x02, (y << 8) | x */
    unsigned short at;          /* +0x04, the cell as a byte offset (index * 2) */
    unsigned short carrying;    /* +0x06 */
    unsigned short home;        /* +0x08, the lord gets its own position here */
    unsigned char state;        /* +0x0a */
    unsigned char link;         /* +0x0b, a unit slot, 0xff for none */
    unsigned char side;         /* +0x0c, 0..4 */
    unsigned char want;         /* +0x0e, the direction it turned towards */
    unsigned char retry;        /* +0x0f, counts down while blocked */
} Unit;

/* A unit's path.  The original keeps these in their own segment: 2000:0000 is a
 * 48 x 48 grid of words the flood fill writes distances into, 2000:1200 a second
 * grid, 2000:2400 the 64 path buffers of 128 bytes, and 2000:4400 the fill's own
 * stack.  A buffer is 124 bytes of **two-bit steps** - 496 of them, which is the
 * 0x1f0 the builder refuses to exceed - then a word length and a word cursor.
 *
 * The steps are written walking *back* from the target down the distance field,
 * so the code says which neighbour was smaller: 0 below, 1 right, 2 above,
 * 3 left.  Read forwards they are the direction to walk, and sub_c291 doubles
 * them into the eight-direction table - 0 up, 2 left, 4 down, 6 right - which
 * is exactly the reverse, as it must be. */
#define PATH_STEPS 496
#define PATH_BYTES 124

typedef struct {
    unsigned char step[PATH_BYTES];
    unsigned short len;         /* +0x7c */
    unsigned short cursor;      /* +0x7e */
} Path;

/* 0x16 bytes.  The initialiser at 0x0326 writes every one of these. */
typedef struct {
    unsigned short flag;        /* +0x00 */
    unsigned short pos;         /* +0x02, (y << 8) | x of the castle */
    unsigned short at;          /* +0x04, the castle cell as a byte offset */
    short lord;                 /* +0x06, the side's first unit (a slot here) */
    unsigned short full;        /* +0x0c, set to 200 */
    /* +0x0e and +0x10 are one 32-bit purse: sub_abc7 does
     * `sub cx,ax / sbb di,dx` across the pair. */
    unsigned long funds;        /* starts at 5000 */
    unsigned char rate;         /* +0x12, set to 10 */
    unsigned char b13;          /* +0x13, set to 0 */
    unsigned char ally;         /* +0x14, another side, or 0x80 for none */
    unsigned char heir;         /* +0x15, who takes the land if this side falls */
    int alive;                  /* the castle was found on this map */
} Side;

typedef struct {
    Cell cell[MAP_W * MAP_H];
    Path path[UNIT_SLOTS];
    short occupant[MAP_W * MAP_H];      /* DS:E47E - a unit slot, or -1 */
    Unit unit[UNIT_SLOTS];
    Side side[SIDES];
    int terrain;                        /* the map's own tile set */
    int cursor;                         /* DS:3BEC, the rolling unit cursor */
    int cellCursor;                     /* DS:3BEA, the rolling cell cursor */
    int speed;                          /* DS:3C02, 0 = fastest */
    int human;                          /* DS:3C00, the side the player has */
    int aiBonus;                        /* DS:347E, doubles AI land growth */
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

/* One unit's turn.  Only the worker state (1 and 3) is ported so far; the
 * lord's 0x20 branch and the rest of the sixteen handlers are not. */
void game_unit_step(Game *g, int slot);

/* One pass of the unit updater: `0x40 >> speed` slots, stepping 31 at a time. */
void game_step(Game *g);

/* One pass of the world tick, following sub_3332.  It walks `(144 >> speed) - 1`
 * cells, stepping the cursor 23 cells at a time (46 bytes) and wrapping at 2304,
 * which is coprime with 2304 and so visits every square.  What it does depends
 * on the tile:
 *
 *   5             the amount grows by 10; when that would pass 255 and nobody is
 *                 standing there, a neutral unit appears and the amount resets
 *                 to 0 - this is where the wild ones come from
 *   0x08 + side   developed land: the amount grows by one for each of the eight
 *                 neighbours that is the same side's land, plus one, and the AI
 *                 sides get that twice over while [0x347e] is set
 *   0x14 + side   the castle; not ported yet
 */
void game_tick_cells(Game *g);

/* What developing a square costs, from `mov ax,0x64` before sub_abc7. */
#define DEVELOP_COST 100

/* A unit turns the square it stands on into its side's productive land, at
 * sub_3ec7:
 *
 *   - the square has to be plain ground or claimed land (0x0c + any side)
 *   - one of the eight neighbours has to already be 0x08 + this side or
 *     0x08 + its ally, so the land stays connected (sub_ae9e)
 *   - it costs the side 100 from its purse (sub_abc7)
 *   - the square becomes 0x08 + side holding `min(carried, 200) / 2 + 1`, and
 *     the unit spends that much of what it carries
 *   - a unit that spends its last is finished (sub_a9ca)
 *
 * Returns 1 if the square was developed.
 */
int game_develop(Game *g, int slot);

/* A unit standing on its own productive land picks up what the square holds and
 * leaves 1 behind, at 0x34bb. */
int game_pick_up(Game *g, int slot);

/* The castle's collection, at 0x3581: with the side's lord standing on the
 * castle in a 0x20 mode and the square past its gate not held by anybody else,
 * every reachable square of the side's own land hands over
 * `(rate * amount) >> 8` and loses it.  Returns the total. */
int game_collect(Game *g, int side);

/* The eight neighbours of a cell: how many are `tile`, how many are plain
 * ground, and where the last plain one was.  sub_adeb. */
void game_neighbours(const Game *g, int index, unsigned char tile,
                     int *same, int *empty, int *lastEmpty);

/* One step, following the sequence at 0x3793:
 *
 *   - if the unit is not already facing `dir`, turn and take no step
 *   - otherwise work out the square, reject it if it leaves 1..46 in either
 *     axis, if its tile is 0x30 or above, or if another unit is standing there
 *   - on success move the occupancy word, [si+4] and [si+2] together
 *
 * Returns 1 if the unit moved, 0 if it turned or was blocked.
 */
int game_move(Game *g, int slot, int dir);

/* Fills the unit's path buffer with a route from where it stands to (x, y),
 * following sub_c0bd: flood the distances out from the unit four-connected over
 * anything below 0x30, then walk back from the target always stepping to the
 * smaller neighbour.  Returns the number of steps, or 0 if there is no route or
 * it needs more than 496 steps.  On success the unit's link is set to its own
 * slot, which is how the original addresses the buffer. */
int game_path_to(Game *g, int slot, int x, int y);

/* The direction the path wants next (0..7), or -1 when there is none left.
 * game_move consumes it; game_path_advance moves the cursor on and drops the
 * path when it runs out, the way 0xc2c0 does. */
int game_path_dir(const Game *g, int slot);
void game_path_advance(Game *g, int slot);

/* Handy for the viewer and for tests. */
int game_unit_count(const Game *g, int side);

/* How many squares a side holds: `productive` counts 0x08 + side, `claimed`
 * counts 0x0c + side. */
void game_land_count(const Game *g, int side, int *productive, int *claimed);
int game_cell_index(int x, int y);

#endif
