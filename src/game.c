#include "game.h"

#include <string.h>

/* DS:2827, eight words of (dy << 8) | dx. */
const signed char GAME_DX[8] = { 0, -1, -1, -1,  0,  1,  1,  1 };
const signed char GAME_DY[8] = {-1, -1,  0,  1,  1,  1,  0, -1 };

int game_cell_index(int x, int y) { return y * MAP_W + x; }

int game_move(Game *g, int slot, int dir)
{
    Unit *u = &g->unit[slot];
    int x, y, nx, ny, from, to;

    dir &= 7;
    if (u->facing != dir) {             /* turning costs the step */
        u->want = (unsigned char)dir;
        u->facing = (unsigned char)dir;
        return 0;
    }
    x = u->pos & 0xff;
    y = u->pos >> 8;
    nx = x + GAME_DX[dir];
    ny = y + GAME_DY[dir];
    if (nx < MAP_MIN || nx > MAP_MAX || ny < MAP_MIN || ny > MAP_MAX) {
        u->state = UNIT_STATE_FOLLOW;   /* 0x37fe writes 1 and clears the link */
        u->link = 0xff;
        return 0;
    }
    from = game_cell_index(x, y);
    to = game_cell_index(nx, ny);
    if (g->cell[to].tile >= CELL_IMPASSABLE || g->occupant[to] >= 0) {
        if (u->retry) u->retry--;       /* 0x37ec counts down and gives up */
        return 0;
    }
    g->occupant[to] = (short)slot;
    g->occupant[from] = -1;
    u->at = (unsigned short)(to * 2);
    u->pos = (unsigned short)((ny << 8) | nx);
    return 1;
}

/* sub_add0: the first slot whose byte 0 has bit 7 set, scanning from the front.
 * Returns -1 when the field is full, which the original signals with CF. */
static int alloc_unit(Game *g)
{
    int i;
    for (i = 0; i < UNIT_SLOTS; i++)
        if (g->unit[i].flags & 0x80) return i;
    return -1;
}

/* The initialiser computes x and y from the cell offset with
 * `ax = di >> 1 / div 0x30`, so y is the quotient and x the remainder, then
 * `xchg al,ah` packs them as (y << 8) | x. */
static unsigned short pack_pos(int index)
{
    return (unsigned short)(((index / MAP_W) << 8) | (index % MAP_W));
}

static int place(Game *g, int index, int side, unsigned char state,
                 unsigned short carrying)
{
    int slot = alloc_unit(g);
    Unit *u;

    if (slot < 0) return -1;
    u = &g->unit[slot];
    memset(u, 0, sizeof *u);
    u->flags = 0;                       /* [si] = 0 clears the free bit */
    u->facing = DIR_RIGHT;              /* [si+1] = 6 */
    u->pos = pack_pos(index);
    u->at = (unsigned short)(index * 2);
    u->carrying = carrying;
    u->state = state;
    u->side = (unsigned char)side;
    u->link = 0xff;
    g->occupant[index] = (short)slot;   /* [di+0xe47e] = si */
    return slot;
}

void game_init(Game *g, const Map *m)
{
    int i, side;

    memset(g, 0, sizeof *g);
    g->terrain = m->terrain;

    /* The loader's in-place expansion: every cell becomes (tile, 100). */
    for (i = 0; i < MAP_W * MAP_H; i++) {
        g->cell[i].tile = m->cell[i];
        g->cell[i].amount = CELL_START_AMOUNT;
        g->occupant[i] = -1;
    }
    for (i = 0; i < UNIT_SLOTS; i++) g->unit[i].flags = 0x80;

    for (side = 0; side < PLAYERS; side++) {
        Side *s = &g->side[side];
        int found = -1, lord;

        s->flag = 1;
        /* `repne scasw` for the word (0x64, 0x14 + side): the castle square,
         * still at its starting amount. */
        for (i = 0; i < MAP_W * MAP_H; i++)
            if (g->cell[i].tile == CELL_CASTLE0 + side &&
                g->cell[i].amount == CELL_START_AMOUNT) {
                found = i;
                break;
            }
        if (found < 0) continue;        /* the original just skips the side */

        s->alive = 1;
        s->flag = 0;
        s->pos = pack_pos(found);
        s->at = (unsigned short)(found * 2);
        s->full = CELL_FULL_AMOUNT;     /* 0xc8 */
        s->funds = 0x1388;              /* 5000 */
        s->spent = 0;
        s->rate = 0x0a;                 /* 10 */
        s->b13 = 0;
        s->b14 = 0x80;

        lord = place(g, found, side, UNIT_STATE_LORD, 0x3e8);
        if (lord >= 0) {
            g->unit[lord].home = g->unit[lord].pos;   /* [si+8] = ax */
            s->lord = (short)lord;
        } else {
            s->lord = -1;
        }
        /* And one on the next square along, which is the castle's right-hand
         * cell (tile 0x1d). */
        if (found % MAP_W + 1 < MAP_W)
            place(g, found + 1, side, UNIT_STATE_FOLLOW, CELL_FULL_AMOUNT);
    }

    /* Then the sweep at 0x03d2: a cell whose tile is 6 turns into plain ground
     * and gets a neutral unit. */
    for (i = 0; i < MAP_W * MAP_H; i++) {
        if (g->cell[i].tile != CELL_NEUTRAL) continue;
        g->cell[i].tile = 0;
        g->cell[i].amount = CELL_START_AMOUNT;
        place(g, i, 4, UNIT_STATE_NEUTRAL, CELL_FULL_AMOUNT);
    }
    g->side[4].b14 = 0x80;
}

void game_step(Game *g)
{
    /* 0x40 >> speed, less one: the original loads 0x40, shifts by [0x3c02] and
     * decrements before using it as the loop count. */
    int todo = (0x40 >> (g->speed & 7)) - 1;
    int slot = g->cursor;

    if (todo < 1) todo = 1;
    while (todo--) {
        Unit *u = &g->unit[slot & (UNIT_SLOTS - 1)];
        if (!(u->flags & 0x80)) {
            u->flags &= (unsigned char)~1u;
            /* The sixteen order handlers behind CS:3A47 are not ported yet.
             * Keeping the visiting order right now means nothing else has to
             * move when they are. */
        }
        slot = (slot + 31) & (UNIT_SLOTS - 1);
    }
    g->cursor = slot;
}

int game_unit_count(const Game *g, int side)
{
    int i, n = 0;
    for (i = 0; i < UNIT_SLOTS; i++)
        if (!(g->unit[i].flags & 0x80) &&
            (side < 0 || g->unit[i].side == side)) n++;
    return n;
}
