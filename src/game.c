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
        s->funds = 5000;                /* 0x1388 across +0x0e and +0x10 */
        s->rate = 0x0a;                 /* 10 */
        s->b13 = 0;
        s->ally = 0x80;
        s->heir = 0x80;

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
    g->side[4].ally = 0x80;
}

void game_step(Game *g)
{
    /* 0x40 >> speed, less one: the original loads 0x40, shifts by [0x3c02] and
     * decrements before using it as the loop count. */
    int todo = (0x40 >> (g->speed & 7)) - 1;
    int slot = g->cursor;

    if (todo < 1) todo = 1;
    while (todo--) {
        int i = slot & (UNIT_SLOTS - 1);
        Unit *u = &g->unit[i];
        if (!(u->flags & 0x80)) {
            u->flags &= (unsigned char)~1u;
            game_unit_step(g, i);
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

/* A square of developed land that has filled up turns into a unit: the unit
 * carries what the square held less one, and the square is left with 1.
 * 0x346a. */
static void land_produces(Game *g, int index, int side)
{
    int slot, carried;

    if (g->occupant[index] >= 0) return;            /* 0x346e */
    carried = g->cell[index].amount - 1;            /* xchg 1, then dec */
    if (carried < 0) carried = 0;
    slot = place(g, index, side, UNIT_STATE_FOLLOW,
                 (unsigned short)carried);
    if (slot < 0) return;
    g->cell[index].amount = 1;
}

/* Tiles 0x08..0x0b: developed land.  0x33d1.
 *
 * It grows by one for every neighbour of the same land plus one - twice that
 * for an AI side while [0x347e] is set - and saturates.  Then, only if what it
 * holds is more than (neighbours + 1) * 16:
 *
 *   - with eight neighbours of its own kind it produces a unit outright
 *   - otherwise it spreads into an empty neighbour, which becomes 0x0c + side
 *     holding 100, and produces a unit if it is at 200 or more
 *
 * The one branch not pinned down is sub_b7cf, which the original consults when
 * there is no empty neighbour; here that case just falls through to the same
 * "produce if full" test.
 */
static void tick_land(Game *g, int index, int side)
{
    int same, empty, last, gain, v, n;

    game_neighbours(g, index, (unsigned char)(CELL_TERRITORY0 + side),
                    &same, &empty, &last);
    gain = same + 1;                        /* `inc dh`, then it is used twice */
    if (side != g->human && g->aiBonus) gain *= 2;
    v = g->cell[index].amount + gain;
    g->cell[index].amount = (unsigned char)(v > 0xff ? 0xff : v);

    n = same + 1;
    if (g->cell[index].amount <= n * 16) return;        /* 0x3439 */
    if (n >= 9) {                                       /* 0x3440 */
        land_produces(g, index, side);
        return;
    }
    if (empty > 0 && last >= 0) {                       /* 0x3454 */
        g->cell[last].tile = (unsigned char)(CELL_TERRITORY0 + 4 + side);
        g->cell[last].amount = CELL_START_AMOUNT;
    }
    if (g->cell[index].amount >= CELL_FULL_AMOUNT)       /* 0x3460 */
        land_produces(g, index, side);
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
        else if (tile >= CELL_CASTLE0 && tile < CELL_CASTLE0 + PLAYERS)
            game_collect(g, tile - CELL_CASTLE0);   /* 0x3581 */
        at += 23;                            /* 46 bytes */
        if (at >= MAP_W * MAP_H) at -= MAP_W * MAP_H;
    }
    g->cellCursor = at;
}

/* The castle collects, at 0x3581.  It only happens when the side's own lord is
 * standing on the castle in a 0x20 mode, and when the square two to the right -
 * the one past the castle gate - is not somebody else's land.  Then every
 * square of the side's own 0x08 + side land that the flood fill can reach hands
 * over `(rate * amount) >> 8`, and loses it.
 *
 * Returns what was collected.
 */
int game_collect(Game *g, int side);

int game_collect(Game *g, int side)
{
    Side *s = &g->side[side];
    int castle, gate, got = 0, i;
    unsigned short *dist;
    unsigned char mine = (unsigned char)(CELL_TERRITORY0 + side);
    int lord;

    if (!s->alive) return 0;
    castle = game_cell_index(s->pos & 0xff, s->pos >> 8);
    lord = g->occupant[castle];
    if (lord < 0) return 0;                          /* 0x3588 */
    if (g->unit[lord].side != side) return 0;        /* 0x358c */
    if (!(g->unit[lord].state & 0x20)) return 0;     /* 0x3591 */

    /* [di + 4]: two cells to the right. */
    if (castle % MAP_W + 2 < MAP_W) {
        int t = g->cell[castle + 2].tile - 8;
        if (t >= 0 && t < 8 && (t & 3) != side) return 0;   /* 0x35a6 */
    }

    dist = fill_distances(g, castle);
    for (i = 0; i < MAP_W * MAP_H; i++) {
        int take;
        if (g->cell[i].tile != mine) continue;
        if (dist[i] == DIST_WALL || dist[i] == DIST_OPEN) continue;
        if (dist[i] >= 0x4000) continue;             /* 0x35e1 */
        take = (s->rate * g->cell[i].amount) >> 8;   /* mul, keep the high byte */
        if (take == 0) continue;
        g->cell[i].amount = (unsigned char)(g->cell[i].amount - take);
        s->funds += (unsigned long)take;
        got += take;
    }
    (void)gate;
    return got;
}

/* ------------------------------------------------------------ what units do */

/* sub_ae9e: is one of the eight neighbours this side's productive land, or its
 * ally's?  Developing needs the ground to stay joined up. */
static int joined_up(const Game *g, int index, int side)
{
    static const int dx[8] = { 0,  1, 1, 1, 0, -1, -1, -1 };
    static const int dy[8] = {-1, -1, 0, 1, 1,  1,  0, -1 };
    unsigned char mine = (unsigned char)(CELL_TERRITORY0 + side);
    unsigned char ally = g->side[side].ally;
    int x = index % MAP_W, y = index / MAP_W, k;

    for (k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k], n;
        unsigned char t;
        if (nx < 0 || nx >= MAP_W || ny < 0 || ny >= MAP_H) continue;
        n = ny * MAP_W + nx;
        t = g->cell[n].tile;
        if (t == mine) return 1;
        if (ally < PLAYERS && t == CELL_TERRITORY0 + ally) return 1;
    }
    return 0;
}

/* sub_abc7: take from the side's purse, or fail. */
static int spend(Game *g, int side, unsigned long cost)
{
    if (g->side[side].funds < cost) return 0;
    g->side[side].funds -= cost;
    return 1;
}

/* sub_a9ca, for an ordinary unit: it is finished with.  The lord's death does a
 * great deal more - it hands the side's land to whoever killed it - and is not
 * ported yet. */
static void unit_spent(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);

    u->carrying = 0;
    u->link = 0xff;
    if (u->state & 0x20) return;        /* the lord; left alone for now */
    if (g->occupant[index] == slot) g->occupant[index] = -1;
    u->flags = 0x80;                    /* back to a free slot */
}

int game_develop(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    unsigned char tile = g->cell[index].tile;
    int take;

    if (u->side >= PLAYERS) return 0;
    if (tile != 0) {                            /* 0x3ece */
        int c = tile - (CELL_TERRITORY0 + 4);
        if (c < 0 || c >= PLAYERS) return 0;
    }
    if (!joined_up(g, index, u->side)) return 0;
    if (!spend(g, u->side, DEVELOP_COST)) return 0;

    take = u->carrying;
    if (take > CELL_FULL_AMOUNT) take = CELL_FULL_AMOUNT;   /* 0x3ef7 */
    g->cell[index].tile = (unsigned char)(CELL_TERRITORY0 + u->side);
    g->cell[index].amount = (unsigned char)((take >> 1) + 1);
    u->carrying = (unsigned short)(u->carrying - take);
    if (u->carrying == 0) unit_spent(g, slot);
    return 1;
}

int game_pick_up(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    int got;

    if (g->cell[index].tile != CELL_TERRITORY0 + u->side) return 0;
    got = g->cell[index].amount;
    g->cell[index].amount = 1;                  /* xchg with 1 */
    if (u->carrying + got > 0xffff) u->carrying = 0xffff;   /* 0x34c7 */
    else u->carrying = (unsigned short)(u->carrying + got);
    return got;
}

/* sub_af42: the first of the four orthogonal neighbours whose tile is `tile`,
 * looked at up, down, left, right - which the original turns into 0, 4, 2, 6 of
 * the eight-direction table.  Returns -1 if none of them is. */
static int direction_towards(const Game *g, int index, unsigned char tile)
{
    static const int off[4] = {-MAP_W, MAP_W, -1, 1};
    static const int dir[4] = {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};
    int x = index % MAP_W, y = index / MAP_W, k;

    for (k = 0; k < 4; k++) {
        int n = index + off[k];
        int nx = (k >= 2) ? x + off[k] : x;
        int ny = (k < 2) ? y + (off[k] > 0 ? 1 : -1) : y;
        if (nx < 0 || nx >= MAP_W || ny < 0 || ny >= MAP_H) continue;
        if (n < 0 || n >= MAP_W * MAP_H) continue;
        if (g->cell[n].tile == tile) return dir[k];
    }
    return -1;
}

/* Somewhere worth walking to: a square this side could develop - plain ground
 * or claimed land - that already touches its own productive land.
 *
 * **This part is ours.**  The original picks its target through sub_4814 and
 * sub_bc56, which run its own flood fill over the pathfinding grid and choose
 * the nearest square of the side's own land, with the AI and the human taking
 * different branches (sub_bd3b against sub_bd84).  Those are not decoded yet.
 * What is decoded is everything the worker then does with the answer, so this
 * stands in for the choice and nothing else.
 */
static int worker_target(const Game *g, int slot)
{
    const Unit *u = &g->unit[slot];
    int here = game_cell_index(u->pos & 0xff, u->pos >> 8);
    int hx = here % MAP_W, hy = here / MAP_W;
    int best = -1, bestD = 0, i;

    for (i = 0; i < MAP_W * MAP_H; i++) {
        int x = i % MAP_W, y = i / MAP_W, d, c;
        unsigned char t = g->cell[i].tile;
        if (x < MAP_MIN || x > MAP_MAX || y < MAP_MIN || y > MAP_MAX) continue;
        if (g->occupant[i] >= 0) continue;
        if (t != 0) {
            c = t - (CELL_TERRITORY0 + 4);
            if (c < 0 || c >= PLAYERS) continue;
        }
        if (!joined_up(g, i, u->side)) continue;
        d = (x - hx) * (x - hx) + (y - hy) * (y - hy);
        if (best < 0 || d < bestD) {
            best = i;
            bestD = d;
        }
    }
    return best;
}

/* State 1, at 0x3998: develop the square you stand on.  Failing that the
 * original spends its action budget on sub_4881, which picks a target, checks
 * the unit carries at least twice the distance, paths to it and moves the unit
 * to state 2; when the budget is gone it just steps towards its own land with
 * sub_af42.  Both of those are here, with the target choice standing in for
 * sub_4814 / sub_bc56.
 */
static void unit_worker(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index, dir, target;

    if (game_develop(g, slot)) return;
    if (u->flags & 0x80) return;                /* it spent itself developing */
    index = game_cell_index(u->pos & 0xff, u->pos >> 8);

    /* Already walking somewhere: keep going. */
    dir = game_path_dir(g, slot);
    if (dir >= 0) {
        if (game_move(g, slot, dir)) game_path_advance(g, slot);
        return;
    }

    target = worker_target(g, slot);
    if (target >= 0) {
        int len = game_path_to(g, slot, target % MAP_W, target / MAP_W);
        /* 0x45af: it has to carry at least twice the distance to be worth it. */
        if (len > 0 && u->carrying >= (unsigned short)(len * 2)) {
            u->state = 2;
            return;
        }
        u->link = 0xff;
    }
    /* The budget-exhausted path: step towards your own land. */
    dir = direction_towards(g, index,
                            (unsigned char)(CELL_TERRITORY0 + u->side));
    if (dir >= 0) game_move(g, slot, dir);
}

void game_unit_step(Game *g, int slot)
{
    Unit *u = &g->unit[slot];

    if (u->flags & 0x80) return;
    if (u->side >= PLAYERS) return;             /* the neutral ones idle */
    if (u->state & 0x20) return;                /* the lord; 0x3a67, not ported */
    switch (u->state & 0x0f) {
    case 1: case 3:                 /* the worker, 0x3998 */
    case 2:                         /* walking to a target, 0x386c */
        unit_worker(g, slot);
        break;
    default:
        break;
    }
}

void game_land_count(const Game *g, int side, int *productive, int *claimed)
{
    int i, p = 0, c = 0;
    for (i = 0; i < MAP_W * MAP_H; i++) {
        unsigned char t = g->cell[i].tile;
        if (t == CELL_TERRITORY0 + side) p++;
        else if (t == CELL_TERRITORY0 + 4 + side) c++;
    }
    if (productive) *productive = p;
    if (claimed) *claimed = c;
}
