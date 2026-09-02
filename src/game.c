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

static int place(Game *g, int index, int side, unsigned char state,
                 unsigned short carrying);

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

/* ------------------------------------------------------------------ paths */

/* The flood fill at 0xc050 is a scanline fill that writes a distance one
 * greater than its neighbour's and stops where a cell already holds something
 * smaller.  For a uniform cost that is a breadth-first search, so this is one -
 * the distances come out the same and the code says what it means.
 *
 * The source cell gets 1, which is why the builder does `dec ax` on the target
 * to get the number of steps and stops descending when it reaches 1.
 */
#define DIST_WALL 0xffffu
#define DIST_OPEN 0u

static unsigned short *fill_distances(Game *g, int from)
{
    static unsigned short dist[MAP_W * MAP_H];
    static int queue[MAP_W * MAP_H];
    int head = 0, tail = 0, i;

    for (i = 0; i < MAP_W * MAP_H; i++)
        dist[i] = g->cell[i].tile >= CELL_IMPASSABLE ? DIST_WALL : DIST_OPEN;
    dist[from] = 1;
    queue[tail++] = from;
    while (head < tail) {
        int c = queue[head++];
        int x = c % MAP_W, y = c / MAP_W, k;
        static const int dx[4] = {0, 1, 0, -1};
        static const int dy[4] = {1, 0, -1, 0};
        for (k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k], n;
            if (nx < MAP_MIN || nx > MAP_MAX || ny < MAP_MIN || ny > MAP_MAX)
                continue;
            n = ny * MAP_W + nx;
            if (dist[n] != DIST_OPEN) continue;      /* wall, or already seen */
            dist[n] = (unsigned short)(dist[c] + 1);
            queue[tail++] = n;
        }
    }
    return dist;
}

static void put_step(Path *p, int index, int code)
{
    int byte = index >> 2, shift = (index & 3) * 2;
    p->step[byte] = (unsigned char)((p->step[byte] & ~(3 << shift)) |
                                    ((code & 3) << shift));
}

static int get_step(const Path *p, int index)
{
    return (p->step[index >> 2] >> ((index & 3) * 2)) & 3;
}

int game_path_to(Game *g, int slot, int x, int y)
{
    Unit *u = &g->unit[slot];
    Path *p = &g->path[slot];
    unsigned short *dist;
    int from = game_cell_index(u->pos & 0xff, u->pos >> 8);
    int to = game_cell_index(x, y);
    int len, at, i;

    u->link = 0xff;
    if (x < MAP_MIN || x > MAP_MAX || y < MAP_MIN || y > MAP_MAX) return 0;
    dist = fill_distances(g, from);
    if (dist[to] == DIST_WALL || dist[to] == DIST_OPEN) return 0;
    len = dist[to] - 1;                         /* 0xc0e9: dec ax */
    if (len <= 0 || len >= PATH_STEPS) return 0;   /* 0xc0ef: cmp ax,0x1f0 */

    memset(p->step, 0, sizeof p->step);
    p->len = (unsigned short)len;
    p->cursor = 0;

    /* Walk back from the target, always to the smaller neighbour, writing the
     * steps from the end so that reading forwards starts at the source. */
    at = to;
    for (i = len - 1; i >= 0; i--) {
        static const int off[4] = {MAP_W, 1, -MAP_W, -1};   /* below, right, above, left */
        int best = -1, bestCode = 0, k;
        for (k = 0; k < 4; k++) {
            int n = at + off[k];
            int nx = n % MAP_W, ny = n / MAP_W;
            if (n < 0 || n >= MAP_W * MAP_H) continue;
            if (nx < MAP_MIN || nx > MAP_MAX || ny < MAP_MIN || ny > MAP_MAX)
                continue;
            if (dist[n] == DIST_WALL || dist[n] == DIST_OPEN) continue;
            if (best < 0 || dist[n] < (unsigned short)best) {
                best = dist[n];
                bestCode = k;
            }
        }
        if (best < 0) return 0;
        put_step(p, i, bestCode);
        at += off[bestCode];
    }
    u->link = (unsigned char)slot;
    return len;
}

int game_path_dir(const Game *g, int slot)
{
    const Unit *u = &g->unit[slot];
    const Path *p = &g->path[slot];

    if (u->link == 0xff || p->cursor >= p->len) return -1;
    /* sub_c291: the two-bit code doubled, which lands on up / left / down /
     * right in the eight-direction table. */
    return get_step(p, p->cursor) * 2;
}

void game_path_advance(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    Path *p = &g->path[slot];

    if (u->link == 0xff) return;
    p->cursor++;
    if (p->cursor >= p->len) u->link = 0xff;     /* 0xc2df */
}

/* --------------------------------------------------------------- the world */

void game_neighbours(const Game *g, int index, unsigned char tile,
                     int *same, int *empty, int *lastEmpty)
{
    /* sub_adeb walks the eight neighbours by byte offset: +98, +94, -94, -98
     * for the diagonals and +/-96, +/-2 for the sides.  In cells that is the
     * ordinary eight-way ring. */
    static const int dx[8] = { 1, -1,  1, -1, 0,  0, 1, -1 };
    static const int dy[8] = { 1,  1, -1, -1, 1, -1, 0,  0 };
    int x = index % MAP_W, y = index / MAP_W, k;

    *same = *empty = 0;
    *lastEmpty = -1;
    for (k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k], n;
        if (nx < 0 || nx >= MAP_W || ny < 0 || ny >= MAP_H) continue;
        n = ny * MAP_W + nx;
        if (g->cell[n].tile == 0) {
            (*empty)++;
            *lastEmpty = n;
        } else if (g->cell[n].tile == tile) {
            (*same)++;
        }
    }
}

/* Tile 5: the amount climbs by ten and, when it would pass 255, turns into a
 * neutral unit standing on a cleared square.  0x3533. */
static void tick_nest(Game *g, int index)
{
    int v = g->cell[index].amount + 10;

    if (v <= 0xff) {
        g->cell[index].amount = (unsigned char)v;
        return;
    }
    if (g->occupant[index] >= 0) return;
    if (place(g, index, 4, UNIT_STATE_NEUTRAL, CELL_FULL_AMOUNT) < 0) return;
    g->cell[index].amount = 0;
}

/* Tiles 0x08..0x0b: developed land.  0x33d1. */
static void tick_land(Game *g, int index, int side)
{
    int same, empty, last, gain, v;

    game_neighbours(g, index, (unsigned char)(CELL_TERRITORY0 + side),
                    &same, &empty, &last);
    gain = same + 1;                        /* `inc dh`, then it is used twice */
    if (side != g->human && g->aiBonus) gain *= 2;
    v = g->cell[index].amount + gain;
    g->cell[index].amount = (unsigned char)(v > 0xff ? 0xff : v);
}

void game_tick_cells(Game *g)
{
    int todo = (0x90 >> (g->speed & 7)) - 1;
    int at = g->cellCursor;

    if (todo < 1) todo = 1;
    while (todo--) {
        unsigned char tile = g->cell[at].tile;
        if (tile == 5)
            tick_nest(g, at);
        else if (tile >= CELL_TERRITORY0 && tile < CELL_TERRITORY0 + PLAYERS)
            tick_land(g, at, tile - CELL_TERRITORY0);
        /* castles (0x14..0x17) go through 0x3581, which is not ported yet */
        at += 23;                            /* 46 bytes */
        if (at >= MAP_W * MAP_H) at -= MAP_W * MAP_H;
    }
    g->cellCursor = at;
}
