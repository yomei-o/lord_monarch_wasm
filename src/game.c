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
    if (g->cell[to].tile >= CELL_IMPASSABLE) {      /* 0x37b6 */
        if (u->retry) u->retry--;       /* 0x37ec counts down and gives up */
        return 0;
    }
    if (game_bump(g, slot, to)) return 0;           /* 0x37bd */
    if (u->flags & 0x80) return 0;                  /* it died trading blows */
    if (game_merge(g, slot, to)) return 0;          /* 0x37c3 */
    if (u->flags & 0x80) return 0;
    if (g->occupant[to] >= 0) {                     /* 0x37c9 */
        if (u->retry) u->retry--;
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
    g->stamp++;
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

/* sub_4814 remembers the position it last flooded from in [0x32bb] and skips
 * the work when it is asked again for the same one.  Without that cache every
 * unit's decision costs a sweep of the whole board, which is most of the
 * program's time. */
static int fillFrom = -1;
static long fillStamp = -1;

void game_forget_distances(void) { fillFrom = -1; }

static unsigned short *fill_distances(Game *g, int from)
{
    static unsigned short dist[MAP_W * MAP_H];
    static int queue[MAP_W * MAP_H];
    int head = 0, tail = 0, i;

    if (from == fillFrom && fillStamp == g->stamp) return dist;
    fillFrom = from;
    fillStamp = g->stamp;

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

    /* 0x34b0: if one of that side's own units is standing here it takes what
     * the square holds, leaving 1 - which is how a unit builds up the thousand
     * it needs before it will march on a lord. */
    {
        int who = g->occupant[index];
        if (who >= 0 && g->unit[who].side == side &&
            !(g->unit[who].flags & 0x82)) {
            game_pick_up(g, who);
            return;                             /* 0x34cc, nothing else */
        }
    }

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
    g->stamp++;
        g->cell[last].amount = CELL_START_AMOUNT;
    }
    if (g->cell[index].amount >= CELL_FULL_AMOUNT)       /* 0x3460 */
        land_produces(g, index, side);
}

/* The first half of sub_3332, over the four sides.  A side's collection rate
 * drifts one step a turn towards `18 - funds / 256`, never below 1 - so a rich
 * side taxes its ground gently and a poor one hard.  The human's side is left
 * alone (0x3352 compares against [0x3c00]).
 */
static void tick_sides(Game *g)
{
    int side;

    for (side = 0; side < PLAYERS; side++) {
        Side *s = &g->side[side];
        int want;

        if (s->flag & 8) continue;              /* 0x334c, out of play */
        if (side == g->human) continue;         /* 0x3352 */
        if (s->funds > 0xffff) {                /* 0x3356, the high word */
            want = 1;
        } else {
            want = 0x12 - (int)((s->funds >> 8) & 0xff);
            if (want < 1) want = 1;             /* 0x3365 */
        }
        if (s->rate > want) s->rate--;          /* 0x336e */
        else if (s->rate < want) s->rate++;     /* 0x3373 */
    }
}

void game_tick_cells(Game *g)
{
    int todo = (0x90 >> (g->speed & 7)) - 1;
    int at = g->cellCursor;

    tick_sides(g);

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
    game_land_totals(g);
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

/* sub_ae9e says whether any of the eight neighbours is this side's productive
 * land or its ally's - and it sets the carry when one **is**, which the callers
 * treat as a refusal (`jb` to the failure exit in sub_3ec7, `jae` to accept in
 * sub_b876).  So a square can only be developed when none of its neighbours is
 * already the side's own productive land: the ground spreads out with gaps
 * rather than filling in solidly.  That is exactly the `08 0c 08` pattern the
 * maps start with, and it is why the twenty-four maps holding no 0x08 at all
 * still work.
 */
static int neighbour_is_ours(const Game *g, int index, int side)
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

/* The test the callers actually make: a square is open to development only
 * while none of its neighbours is the side's own ground. */
static int can_develop_here(const Game *g, int index, int side)
{
    return !neighbour_is_ours(g, index, side);
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
static void unit_spent(Game *g, int slot);

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
    if (!can_develop_here(g, index, u->side)) return 0;   /* sub_ae9e */
    if (!spend(g, u->side, DEVELOP_COST)) return 0;

    take = u->carrying;
    if (take > CELL_FULL_AMOUNT) take = CELL_FULL_AMOUNT;   /* 0x3ef7 */
    g->cell[index].tile = (unsigned char)(CELL_TERRITORY0 + u->side);
    g->stamp++;
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
/* Is this square one this side could develop?  Plain ground or anybody's
 * claimed land, and joined on to our own - which is what sub_3ec7 and sub_ae9e
 * between them require. */
static int allied(const Game *g, int a, int b);
static int pick_job(Game *g, int slot);
static void tick_dying(Game *g, int slot);
static void unit_lord(Game *g, int slot);

/* sub_41b5: a unit standing on somebody else's claimed land wipes it back to
 * plain ground.  Its own and its ally's are left alone. */
static void wipe_foreign_land(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    int c = g->cell[index].tile - (CELL_TERRITORY0 + 4);

    if (c < 0 || c >= PLAYERS) return;              /* not claimed land */
    if (c == u->side) return;
    if (g->side[u->side].ally == c) return;
    g->cell[index].tile = 0;
    g->cell[index].amount = CELL_START_AMOUNT;      /* 0x6400 */
}

/* Is this square a job for this side?  sub_b876 accepts, in its own order:
 *
 *   tile 0, or 0x0c..0x0f (anybody's claimed land), provided one of the eight
 *   neighbours is already this side's or its ally's productive land - that is
 *   sub_ae9e, the same test developing itself makes
 *   tile 1..4 - the auto-tiled ground
 *   tile 0x08..0x0b belonging to somebody else - which is how a side comes to
 *   walk into its neighbours; there is no separate decision to attack
 *
 * Its own and its ally's productive land are skipped: there is nothing to do
 * there.
 */
static int job_here(const Game *g, int index, int side)
{
    unsigned char t = g->cell[index].tile;
    unsigned char ally = g->side[side].ally;
    int x = index % MAP_W, y = index / MAP_W;

    if (x < MAP_MIN || x > MAP_MAX || y < MAP_MIN || y > MAP_MAX) return 0;
    if (t == CELL_TERRITORY0 + side) return 0;                  /* 0xb8bc */
    if (ally < PLAYERS && t == CELL_TERRITORY0 + ally) return 0;/* 0xb8c0 */
    if (t == 0 || (t >= CELL_TERRITORY0 + 4 && t < CELL_TERRITORY0 + 8))
        return can_develop_here(g, index, side);                /* 0xb8d3 */
    if (t >= 1 && t < 5) return 1;                              /* 0xb8da */
    if (t >= CELL_TERRITORY0 && t < CELL_TERRITORY0 + PLAYERS) return 1;
    return 0;
}

/* The state a job asks for, from the tile, at 0x443d.  0 if the tile is not a
 * job at all. */
static int job_state(unsigned char tile)
{
    if (tile == 0) return 5;
    if (tile >= CELL_TERRITORY0 + 4 && tile < CELL_TERRITORY0 + 8) return 5;
    if (tile >= CELL_TERRITORY0 && tile < CELL_TERRITORY0 + 4) return 4;
    if (tile >= 1 && tile < 5) return 8;
    if (tile == 5) return 11;
    return 0;
}

/* sub_4420 with sub_b876 inside it: flood the distances out from the unit, then
 * take the nearest job - the original scores each candidate as its distance
 * plus eight and keeps the smallest under 512.  The unit must be carrying at
 * least twice the distance for the trip to be worth making (0x4438).
 *
 * Returns 1 if the unit came away with a job and a path.
 */
static int pick_job(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int here = game_cell_index(u->pos & 0xff, u->pos >> 8);
    unsigned short *dist = fill_distances(g, here);
    int best = -1, bestCost = 0x200, i, state, len;

    for (i = 0; i < MAP_W * MAP_H; i++) {
        int cost;
        if (dist[i] == DIST_WALL || dist[i] == DIST_OPEN) continue;
        cost = dist[i] + 8;                         /* 0xb8af */
        if (cost >= bestCost) continue;             /* 0xb8b4 */
        if (!job_here(g, i, u->side)) continue;
        best = i;
        bestCost = cost;
    }
    if (best < 0) return 0;
    if (dist[best] - 1 >= PATH_STEPS) return 0;     /* 0x4431 */
    if (u->carrying < (unsigned short)((dist[best] - 1) * 2)) return 0;
    state = job_state(g->cell[best].tile);
    if (!state) return 0;

    len = game_path_to(g, slot, best % MAP_W, best / MAP_W);
    u->state = (unsigned char)((u->state & 0xd0) | state);      /* 0x446f */
    u->home = (unsigned short)(((best / MAP_W) << 8) | (best % MAP_W));
    u->retry = 4;                                               /* 0x4475 */
    if (len <= 0) u->link = 0xff;
    return 1;
}

/* State 8, sub_3f2a: rough ground (tiles 1..4) is chipped away with half of
 * what the unit carries - which it does not spend - and becomes plain ground
 * holding 100 once its own amount runs out.  A unit carrying 512 or more
 * clears it in one go, because the original tests the high byte of carried / 2.
 *
 * Returns 1 while there is still work in the square.
 */
int game_clear(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    unsigned char t = g->cell[index].tile;
    int power = u->carrying >> 1;

    if (t < 1 || t >= 5) return 0;                  /* 0x3f30 */
    if (power < 256 && g->cell[index].amount > (power & 0xff)) {
        g->cell[index].amount =
            (unsigned char)(g->cell[index].amount - (power & 0xff));
        return 1;                                   /* 0x3f57 */
    }
    g->cell[index].tile = 0;                        /* 0x3f45 */
    g->stamp++;
    g->cell[index].amount = CELL_START_AMOUNT;
    return 0;
}

/* State 4, 0x38eb by way of sub_b037: look up, down, left and right for a
 * square that is passable and is **not** this side's or its ally's ground, and
 * step that way.  It is what pushes a unit off its own land and into whatever
 * is next to it - and since walking into somebody is a fight, it is also how
 * two sides come to blows.  There is no decision to attack anywhere in the
 * game; this is it.
 *
 * Returns 1 if it found somewhere to go.
 */
static int state_outward(Game *g, int slot)
{
    static const int dir[4] = {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};
    Unit *u = &g->unit[slot];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    int x = index % MAP_W, y = index / MAP_W, k;
    unsigned char mine = (unsigned char)(CELL_TERRITORY0 + u->side);
    unsigned char ally = g->side[u->side].ally;

    for (k = 0; k < 4; k++) {
        int nx = x + GAME_DX[dir[k]], ny = y + GAME_DY[dir[k]], n;
        unsigned char t;
        if (nx < MAP_MIN || nx > MAP_MAX || ny < MAP_MIN || ny > MAP_MAX)
            continue;
        n = ny * MAP_W + nx;
        t = g->cell[n].tile;
        if (t >= CELL_IMPASSABLE) continue;         /* 0xb03e */
        if (t == mine) continue;                    /* 0xb042 */
        if (ally < PLAYERS && t == CELL_TERRITORY0 + ally) continue;
        game_move(g, slot, dir[k]);
        return 1;
    }
    return 0;
}

/* A very small pseudo-random source, standing in for sub_9a36 / sub_9a24.  The
 * original seeds itself from the clock at startup and stirs the state once per
 * tick; the sequence itself is not what matters here, only that the choices in
 * sub_4881 come up in roughly the documented proportions.
 */
static unsigned long rngState = 1;

static int roll(int range)
{
    rngState = rngState * 1103515245u + 12345u;
    return (int)((rngState >> 16) % (unsigned)range);
}

/* sub_46d3: a unit carrying a thousand or more goes for the nearest enemy
 * lord.  This is checked before the random choice below, so a rich unit always
 * marches - there is no decision to attack anywhere, just this rule.
 *
 *   the lord has to be within 496 squares and the unit must carry twice that
 *   on its castle, the unit needs more than three times what the lord carries
 *   off it, more than the lord carries
 */
static int pick_assault(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    unsigned short *dist;
    int here = game_cell_index(u->pos & 0xff, u->pos >> 8);
    int best = -1, bestD = 0x1f0, i;

    if (u->carrying < 0x3e8) return 0;              /* 0x4889 */
    dist = fill_distances(g, here);
    for (i = 0; i < UNIT_SLOTS; i++) {
        Unit *v = &g->unit[i];
        int cell, d;
        if (v->flags & 0x80) continue;
        if (!(v->state & 0x20)) continue;           /* 0x46ef, lords only */
        if (allied(g, u->side, v->side)) continue;
        cell = game_cell_index(v->pos & 0xff, v->pos >> 8);
        if (dist[cell] == DIST_WALL || dist[cell] == DIST_OPEN) continue;
        d = dist[cell] - 1;
        if (d >= bestD) continue;
        best = i;
        bestD = d;
    }
    if (best < 0) return 0;
    if (u->carrying < (unsigned short)(bestD * 2)) return 0;    /* 0x4720 */
    {
        Unit *v = &g->unit[best];
        int cell = game_cell_index(v->pos & 0xff, v->pos >> 8);
        int onCastle = g->cell[cell].tile == CELL_CASTLE0 + v->side;
        unsigned long need = onCastle ? (unsigned long)v->carrying * 3
                                      : (unsigned long)v->carrying;
        if (u->carrying <= need) return 0;          /* 0x474d, 0x4769 */
        if (game_path_to(g, slot, v->pos & 0xff, v->pos >> 8) <= 0) return 0;
        u->home = v->pos;
        u->state = (unsigned char)((u->state & 0xd0) | 2);
        u->retry = 4;
        return 1;
    }
}

/* sub_4658: ten per cent of the time a unit picks a square at random, and goes
 * to develop it if it is empty and it can afford the trip.  This is what takes
 * a side's ground away from where it already is. */
static int pick_random_target(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int x, y, index, len;

    if (g->side[u->side].funds < DEVELOP_COST) return 0;    /* sub_b4d8(100) */
    x = MAP_MIN + roll(MAP_MAX - MAP_MIN + 1);
    y = MAP_MIN + roll(MAP_MAX - MAP_MIN + 1);
    index = game_cell_index(x, y);
    if (g->cell[index].tile != 0) return 0;                 /* 0x4682 */
    if (g->occupant[index] >= 0) return 0;
    len = game_path_to(g, slot, x, y);
    if (len <= 0) return 0;
    if (u->carrying < (unsigned short)(len * 2)) return 0;  /* 0x468e */
    u->home = (unsigned short)((y << 8) | x);
    u->state = (unsigned char)((u->state & 0xd0) | 5);
    u->retry = 4;
    return 1;
}

/* sub_4881: what a unit does when it has nothing in hand.  A rich one marches
 * on a lord; otherwise the roll is 80% the nearest job, 10% a random square,
 * 10% the nearest job again (the original also weighs a rock in that branch).
 */
static int decide(Game *g, int slot)
{
    int r;

    if (pick_assault(g, slot)) return 1;
    r = roll(100);                                  /* 0x4897, sub_9a24(100) */
    if (r >= 90) return pick_job(g, slot);          /* 0x48a9 */
    if (r >= 80) {                                  /* 0x48a2 */
        if (pick_random_target(g, slot)) return 1;
        return pick_job(g, slot);
    }
    return pick_job(g, slot);                       /* 0x48cf */
}

/* Following a path, at 0x39c2 by way of sub_c291: take the next step, and when
 * the walk is done drop the path so the state handler gets a turn. */
static void follow_path(Game *g, int slot)
{
    int dir = game_path_dir(g, slot);

    if (dir < 0) {
        g->unit[slot].link = 0xff;
        return;
    }
    if (game_move(g, slot, dir)) game_path_advance(g, slot);
}

/* States 1, 3 and 5 all end up here: develop where you stand, and if you
 * cannot, look for something else to do.  0x3998 and 0x38c1. */
static void state_develop(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    int index, dir;

    if (game_develop(g, slot)) return;
    if (u->flags & 0x80) return;                /* it spent itself developing */
    if (decide(g, slot)) return;

    /* Nothing to be had: step towards your own land, as 0x39a6 does when the
     * action budget has run out. */
    index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    dir = direction_towards(g, index,
                            (unsigned char)(CELL_TERRITORY0 + u->side));
    if (dir >= 0) game_move(g, slot, dir);
    else u->state = (unsigned char)((u->state & 0xd0) | 1);
}

/* The default handler at 0x383e: wipe any foreign ground underfoot, then either
 * carry on along the path or, when there is none left, let the state handler
 * have its turn. */
void game_unit_step(Game *g, int slot)
{
    Unit *u = &g->unit[slot];

    if (u->flags & 0x80) return;
    if (u->flags & 2) {                         /* 0x32f4 -> 0x493a */
        tick_dying(g, slot);
        return;
    }
    if (u->state & 0x20) {                      /* the lord, 0x3a67 */
        unit_lord(g, slot);
        return;
    }
    if (u->side >= PLAYERS) return;             /* the wild ones, 0x3b86 */

    wipe_foreign_land(g, slot);                 /* 0x3847 */

    if (u->link != 0xff) {                      /* 0x384a */
        follow_path(g, slot);
        return;
    }

    switch (u->state & 0x0f) {
    case 1: case 3: case 5:
        state_develop(g, slot);
        break;
    case 8:
        if (game_clear(g, slot)) break;         /* still chipping away */
        if (!decide(g, slot))
            u->state = (unsigned char)((u->state & 0xd0) | 1);
        break;
    case 4:
        if (!state_outward(g, slot))
            u->state = (unsigned char)((u->state & 0xd0) | 1);
        break;
    case 2: case 11:
        /* Jobs at the target square: walking your own ground, chipping rock,
         * clearing a nest.  Only developing is ported, so these fall back to
         * looking for a fresh job. */
        if (!game_develop(g, slot) && !(u->flags & 0x80))
            if (!decide(g, slot))
                u->state = (unsigned char)((u->state & 0xd0) | 1);
        break;
    default:
        if (!decide(g, slot))
            u->state = (unsigned char)((u->state & 0xd0) | 1);
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

void game_land_totals(Game *g)
{
    int i;
    for (i = 0; i < SIDES; i++) g->side[i].landTotal = 0;
    for (i = 0; i < MAP_W * MAP_H; i++) {
        unsigned char t = g->cell[i].tile;
        int side;
        if (t == 5) side = 4;                       /* a nest, for the wild */
        else if (t >= CELL_TERRITORY0 && t < CELL_TERRITORY0 + PLAYERS)
            side = t - CELL_TERRITORY0;
        else continue;
        g->side[side].landTotal += g->cell[i].amount;
    }
}

/* The lord, at 0x3a67 by way of sub_3c7f.  Standing on its own castle it either
 * pushes a worker out of the gate or tops itself up:
 *
 *   carried / 2 > the side's land total   ->  a worker appears on the square to
 *                                             the right carrying a quarter of
 *                                             what the lord holds, which the
 *                                             lord gives up
 *   otherwise                             ->  carried climbs a quarter of the
 *                                             way towards the land total, plus
 *                                             one, and stops when it gets there
 *
 * So the lord's reserve tracks how much the side's ground is holding, and a
 * worker goes out when the ground has been drained relative to it.
 */
static void unit_lord(Game *g, int slot)
{
    Unit *u = &g->unit[slot];
    Side *s = &g->side[u->side];
    int index = game_cell_index(u->pos & 0xff, u->pos >> 8);
    unsigned long cap;

    if (g->cell[index].tile != CELL_CASTLE0 + u->side) return;  /* 0x3cd9 */

    if ((unsigned long)(u->carrying >> 1) > s->landTotal) {      /* 0x3ca0 */
        int gate = index + 1;
        int give, slot2;
        if (index % MAP_W + 1 >= MAP_W) return;
        if (g->occupant[gate] >= 0) return;                      /* 0x3ce2 */
        give = u->carrying >> 2;                                 /* 0x3cf3 */
        if (give == 0) return;
        slot2 = place(g, gate, u->side, UNIT_STATE_FOLLOW,
                      (unsigned short)give);
        if (slot2 < 0) return;
        u->carrying = (unsigned short)(u->carrying - give);
        return;
    }

    cap = s->landTotal > 0xffff ? 0xffff : s->landTotal;          /* 0x3cb5 */
    if (cap <= u->carrying) return;                               /* 0x3cc1 */
    {
        unsigned long room = cap - u->carrying;
        unsigned long v = u->carrying + (room >> 2) + 1;
        u->carrying = (unsigned short)(v > 0xffff ? 0xffff : v);
    }
}

/* ---------------------------------------------------------------- fighting */

void game_kill(Game *g, int slot, int killerSide)
{
    Unit *u = &g->unit[slot];

    if (!(u->flags & 2)) {              /* sub_4924 */
        u->flags |= 2;
        u->retry = (unsigned char)killerSide;   /* +0x0f */
        u->want = 0;                            /* +0x0e, the death counter */
    }
    u->carrying = 0;
}

/* 0x493a: four ticks of dying, then off the board. */
static void tick_dying(Game *g, int slot)
{
    Unit *u = &g->unit[slot];

    u->want++;
    if (u->want < 4) return;
    unit_spent(g, slot);
}

static int allied(const Game *g, int a, int b)
{
    if (a == b) return 1;
    if (a < SIDES && g->side[a].ally == b) return 1;
    return 0;
}

int game_bump(Game *g, int slot, int toIndex)
{
    Unit *u = &g->unit[slot];
    int other = g->occupant[toIndex];
    Unit *v;
    int here, onCastle, targetCastle, hit, back;

    if (other < 0) return 0;                    /* 0x3d75 */
    v = &g->unit[other];
    if (allied(g, u->side, v->side)) return 0;  /* 0x3d81, 0x3d88 */

    /* The defender turns to face the blow if it has nothing else to do. */
    if (v->link == 0xff)                        /* 0x3d8f */
        v->facing = (unsigned char)((u->facing + 4) & 6);

    here = game_cell_index(u->pos & 0xff, u->pos >> 8);
    onCastle = g->cell[here].tile >= CELL_CASTLE0 &&
               g->cell[here].tile < CELL_CASTLE0 + PLAYERS;
    targetCastle = g->cell[toIndex].tile >= CELL_CASTLE0 &&
                   g->cell[toIndex].tile < CELL_CASTLE0 + PLAYERS;

    if (onCastle) {                             /* 0x3ddc */
        hit = (u->carrying >> 2) + 1;
        if (v->carrying > hit) v->carrying = (unsigned short)(v->carrying - hit);
        else game_kill(g, other, u->side);
        return 1;
    }
    if (targetCastle) {                         /* 0x3df3 */
        hit = (u->carrying >> 3) + 1;
        back = (v->carrying >> 3) + 1;
        if (v->carrying > hit) v->carrying = (unsigned short)(v->carrying - hit);
        else game_kill(g, other, u->side);
        if (u->carrying > back) u->carrying = (unsigned short)(u->carrying - back);
        else game_kill(g, slot, v->side);
        return 1;
    }
    hit = (u->carrying >> 3) + 1;               /* 0x3daf */
    if (v->carrying > hit) {
        v->carrying = (unsigned short)(v->carrying - hit);
        back = (v->carrying >> 4) + 1;          /* 0x3dc5, four shifts */
        if (u->carrying > back)
            u->carrying = (unsigned short)(u->carrying - back);
        else
            game_kill(g, slot, v->side);
    } else {
        game_kill(g, other, u->side);
    }
    return 1;
}

/* sub_3e21.  Two units of the same side, neither dying, whose loads add up
 * without overflowing, combine.  Which of the two takes the load is decided in
 * this order (0x3e41-0x3e7b):
 *
 *   the mover is the lord (0x20)              the mover takes it
 *   the other is the lord                     the other takes it
 *   exactly one has the 0x10 bit              that one takes it
 *   both are in state 3                       whichever carries more
 *   the mover is in state 3                   the other takes it
 *   the other is in state 3                   the mover takes it
 *   otherwise                                 whichever carries more
 *
 * Returns 1 only when the *other* took it, because then the mover is finished
 * and its turn is over.  When the mover took it the original sets CF and the
 * caller walks on to the square it just cleared, so this returns 0.
 */
int game_merge(Game *g, int slot, int toIndex)
{
    Unit *u = &g->unit[slot];
    int other = g->occupant[toIndex];
    Unit *v;
    unsigned long sum;
    int moverTakes;

    if (other < 0) return 0;                    /* 0x3e2a */
    v = &g->unit[other];
    if (v->side != u->side) return 0;           /* 0x3e2f */
    if (v->flags & 2) return 0;                 /* 0x3e34, already dying */
    sum = (unsigned long)u->carrying + v->carrying;
    if (sum > 0xffff) return 0;                 /* 0x3e3f */

    if (u->state & 0x20)            moverTakes = 1;
    else if (v->state & 0x20)       moverTakes = 0;
    else if (((u->state | v->state) & 0x10) &&
             !((u->state & v->state) & 0x10))
        moverTakes = (u->state & 0x10) ? 1 : 0;
    else if ((u->state & 0x0f) == 3 && (v->state & 0x0f) == 3)
        moverTakes = u->carrying >= v->carrying;
    else if ((u->state & 0x0f) == 3) moverTakes = 0;
    else if ((v->state & 0x0f) == 3) moverTakes = 1;
    else moverTakes = u->carrying >= v->carrying;

    if (moverTakes) {
        u->carrying = (unsigned short)sum;
        unit_spent(g, other);
        return 0;
    }
    v->carrying = (unsigned short)sum;
    unit_spent(g, slot);
    return 1;
}
