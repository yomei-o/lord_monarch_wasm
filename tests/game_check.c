/* Checks the ported rules against what the disk and the disassembly say.
 *
 *   tmp/game_check.exe tmp/monarch.fim
 *
 * Everything asserted here is something the original does, with the address it
 * was read from in the message, so a failure says which reading was wrong
 * rather than just that a number moved.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "game.h"
#include "gfx.h"

static int failures;

static void check(int ok, const char *what, ...)
{
    if (!ok) {
        printf("FAIL  %s\n", what);
        failures++;
    }
}

static void checkf(int ok, const char *fmt, int a, int b, int c)
{
    if (!ok) {
        printf("FAIL  ");
        printf(fmt, a, b, c);
        printf("\n");
        failures++;
    }
}

/* The castle is a fixed 3x3 in every map.  The file holds it as
 *
 *     70 72 78
 *     7x 1x 1d      1x = 0x14 + side, 7x = 0x74 + side
 *     71 73 79
 *
 * and the file is column-major, so on screen that is the transpose:
 *
 *     70 7x 71
 *     72 1x 73
 *     78 1d 79
 *
 * which puts the castle's one way in, the 0x1d, directly below its middle.
 */
static void check_castle_shape(const Map *m, int side, int x, int y)
{
    static const unsigned char want[3][3] = {
        {0x70, 0x00, 0x71},         /* the middle of the top row is the side's */
        {0x72, 0x00, 0x73},
        {0x78, 0x1d, 0x79},
    };
    int dx, dy;
    for (dy = -1; dy <= 1; dy++)
        for (dx = -1; dx <= 1; dx++) {
            int cx = x + dx, cy = y + dy;
            unsigned char got, expect;
            if (cx < 0 || cx >= MAP_W || cy < 0 || cy >= MAP_H) continue;
            got = m->cell[cy * MAP_W + cx];
            if (dy == -1 && dx == 0) expect = (unsigned char)(0x74 + side);
            else if (dy == 0 && dx == 0) expect = (unsigned char)(0x14 + side);
            else expect = want[dy + 1][dx + 1];
            checkf(got == expect,
                   "castle %d at %d,%d: wrong tile in the 3x3", side, x, y);
        }
}

int main(int argc, char **argv)
{
    Disk *d = disk_open(argc > 1 ? argv[1] : "tmp/monarch.fim");
    Game *g = (Game *)malloc(sizeof *g);
    int n, maps = 0, totalNeutral = 0;

    if (!d) {
        fprintf(stderr, "%s\n", disk_error());
        return 1;
    }

    for (n = 0; n < 52; n++) {
        char name[32];
        Map m;
        int side, i, tile6 = 0;

        snprintf(name, sizeof name, "B_%03d.MAP", n);
        if (!gfx_load_map(&m, d, name)) {
            printf("FAIL  %s: %s\n", name, disk_error());
            failures++;
            continue;
        }
        maps++;
        checkf(m.terrain == 10 || m.terrain == 20 || m.terrain == 30 ||
               m.terrain == 40 || m.terrain == 50,
               "B_%03d.MAP: terrain set %d is not one of 10/20/30/40/50", n,
               m.terrain, 0);

        for (i = 0; i < MAP_W * MAP_H; i++)
            if (m.cell[i] == CELL_NEUTRAL) tile6++;

        game_init(g, &m);

        for (side = 0; side < PLAYERS; side++) {
            int x = g->side[side].pos & 0xff, y = g->side[side].pos >> 8;
            checkf(g->side[side].alive, "B_%03d.MAP: side %d has no castle", n, side, 0);
            if (!g->side[side].alive) continue;
            checkf(m.cell[y * MAP_W + x] == CELL_CASTLE0 + side,
                   "B_%03d.MAP: side %d castle at %d is not its own tile", n, side,
                   y * MAP_W + x);
            check_castle_shape(&m, side, x, y);
            checkf(g->side[side].funds == 0x1388,
                   "B_%03d.MAP: side %d funds %d, expected 5000", n, side,
                   g->side[side].funds);
            checkf(g->side[side].lord >= 0 &&
                   g->unit[g->side[side].lord].state == UNIT_STATE_LORD,
                   "B_%03d.MAP: side %d has no lord in state 0x2d", n, side, 0);
            checkf(g->unit[g->side[side].lord].carrying == 1000,
                   "B_%03d.MAP: side %d lord carries %d, expected 1000", n, side,
                   g->unit[g->side[side].lord].carrying);
        }

        /* The field holds 64 units and the four sides take eight of them, so a
         * map with more tile-6 cells than that simply runs out - sub_add0
         * returns CF and the sweep carries on without placing one.  B_028 and
         * B_036 are the two that hit it. */
        {
            int room = UNIT_SLOTS - PLAYERS * 2;
            int want = tile6 < room ? tile6 : room;
            checkf(game_unit_count(g, 4) == want,
                   "B_%03d.MAP: %d neutral units, expected %d", n,
                   game_unit_count(g, 4), want);
            checkf(game_unit_count(g, -1) == PLAYERS * 2 + want,
                   "B_%03d.MAP: %d units, expected %d", n,
                   game_unit_count(g, -1), PLAYERS * 2 + want);
            totalNeutral += want;
        }

        /* No cell of tile 6 survives: the sweep at 0x03d2 turns each into
         * plain ground whether or not a unit could be placed on it. */
        for (i = 0; i < MAP_W * MAP_H; i++)
            checkf(g->cell[i].tile != CELL_NEUTRAL,
                   "B_%03d.MAP: a tile 6 cell survived at %d", n, i, 0);

        /* Every cell starts at 100. */
        for (i = 0; i < MAP_W * MAP_H; i++)
            checkf(g->cell[i].amount == CELL_START_AMOUNT,
                   "B_%03d.MAP: cell %d starts at %d, expected 100", n, i,
                   g->cell[i].amount);
    }

    check(maps == 52, "all 52 maps loaded");
    printf("%d maps, %d neutral units in total\n", maps, totalNeutral);

    /* Movement.  The geometry is taken from the map rather than written down,
     * because the file is column-major and the castle's gate sits below its
     * middle. */
    {
        Map m;
        int lord, mate, cx, cy, castle, gate;
        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        lord = g->side[0].lord;
        cx = g->side[0].pos & 0xff;
        cy = g->side[0].pos >> 8;
        castle = game_cell_index(cx, cy);
        gate = game_cell_index(cx, cy + 1);
        mate = g->occupant[gate];

        check(g->side[0].alive, "B_000 side 0 has a castle");
        check(g->occupant[castle] == lord,
              "the lord owns its cell in the occupancy array");
        check(mate >= 0 && g->unit[mate].side == 0,
              "the side's second unit is in the gate below the castle");
        checkf(g->cell[gate].tile == 0x1d,
               "the gate square holds tile %02x, expected 0x1d",
               g->cell[gate].tile, 0, 0);

        /* Every other neighbour of the middle is castle masonry, 0x30 or above,
         * so the gate is the only way in or out. */
        {
            int dx, dy, walls = 0;
            for (dy = -1; dy <= 1; dy++)
                for (dx = -1; dx <= 1; dx++) {
                    int n;
                    if (!dx && !dy) continue;
                    if (dx == 0 && dy == 1) continue;   /* the gate */
                    n = game_cell_index(cx + dx, cy + dy);
                    if (g->cell[n].tile >= CELL_IMPASSABLE) walls++;
                }
            checkf(walls == 7, "%d of the 7 masonry squares are impassable",
                   walls, 0, 0);
        }

        /* The lord faces right; turning costs the step and the wall refuses it
         * anyway. */
        check(g->unit[lord].facing == DIR_RIGHT, "new units face right");
        check(!game_move(g, lord, DIR_RIGHT), "the wall refuses it");

        /* The unit in the gate can leave downwards if that square is clear. */
        {
            int below = game_cell_index(cx, cy + 2);
            if (g->cell[below].tile < CELL_IMPASSABLE &&
                g->occupant[below] < 0) {
                check(!game_move(g, mate, DIR_DOWN), "turning takes the step");
                check(game_move(g, mate, DIR_DOWN), "then it steps out");
                check(g->occupant[gate] == -1, "the gate is free");
                check(g->occupant[below] == mate, "and the square below taken");
            }
        }

        /* Walking into one of your own merges them, and the lord always takes
         * the load - so it can step on through. */
        game_init(g, &m);
        lord = g->side[0].lord;
        mate = g->occupant[gate];
        {
            int had = g->unit[lord].carrying + g->unit[mate].carrying;
            check(!game_move(g, lord, DIR_DOWN), "the lord turns to the gate");
            check(game_move(g, lord, DIR_DOWN),
                  "then absorbs its own worker and steps in");
            checkf(g->unit[lord].carrying == had,
                   "it now carries %d, expected %d",
                   g->unit[lord].carrying, had, 0);
            check(g->unit[mate].flags & 0x80, "and the worker is gone");
        }

        /* Walking into an enemy trades blows. */
        game_init(g, &m);
        lord = g->side[0].lord;
        {
            int foe = -1, k, hp;
            for (k = 0; k < UNIT_SLOTS; k++)
                if (!(g->unit[k].flags & 0x80) && g->unit[k].side == 1) {
                    foe = k;
                    break;
                }
            check(foe >= 0, "side 1 has a unit to borrow");
            g->occupant[game_cell_index(g->unit[foe].pos & 0xff,
                                        g->unit[foe].pos >> 8)] = -1;
            g->unit[g->occupant[gate]].flags = 0x80;
            g->occupant[gate] = (short)foe;
            g->unit[foe].pos = (unsigned short)(((cy + 1) << 8) | cx);
            g->unit[foe].at = (unsigned short)(gate * 2);
            g->unit[lord].facing = DIR_DOWN;

            hp = g->unit[foe].carrying;
            check(!game_move(g, lord, DIR_DOWN),
                  "a step into an enemy is a blow, not a move");
            checkf(g->unit[foe].carrying < hp || (g->unit[foe].flags & 2),
                   "the enemy went from %d to %d", hp,
                   g->unit[foe].carrying, 0);
            checkf(g->unit[lord].carrying == 1000,
                   "the lord took %d damage defending its castle",
                   1000 - g->unit[lord].carrying, 0, 0);
        }
    }

    /* Pathfinding: walk a unit somewhere and see that it arrives. */
    {
        Map m;
        int who, len, steps, tx, ty, guard;
        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        who = g->occupant[game_cell_index(g->side[0].pos & 0xff,
                                          (g->side[0].pos >> 8) + 1)];
        check(who >= 0, "there is a unit in the gate to walk");

        /* Somewhere reachable and a fair distance off. */
        tx = 20; ty = 20;
        len = game_path_to(g, who, tx, ty);
        checkf(len > 0, "no path from the gate to 20,20 (%d)", len, 0, 0);
        check(g->unit[who].link == who, "the unit points at its own path");

        steps = 0;
        guard = 0;
        while (game_path_dir(g, who) >= 0 && guard++ < 4000) {
            int dir = game_path_dir(g, who);
            if (game_move(g, who, dir)) {
                game_path_advance(g, who);
                steps++;
            }
            /* turning does not consume a step, so the loop just goes round */
        }
        checkf(steps == len, "walked %d steps of a %d step path", steps, len, 0);
        checkf((g->unit[who].pos & 0xff) == tx &&
               (g->unit[who].pos >> 8) == ty,
               "ended at %d,%d instead of 20,20",
               g->unit[who].pos & 0xff, g->unit[who].pos >> 8, 0);
        check(g->occupant[game_cell_index(tx, ty)] == who,
              "and the occupancy array agrees");

        /* Water has no route across it. */
        for (tx = 0; tx < MAP_W; tx++) {
            for (ty = 0; ty < MAP_H; ty++)
                if (g->cell[game_cell_index(tx, ty)].tile >= CELL_IMPASSABLE)
                    break;
            if (ty < MAP_H) break;
        }
        check(tx < MAP_W, "B_000 has impassable cells");
        check(game_path_to(g, who, tx, ty) == 0,
              "no path onto an impassable cell");
        check(g->unit[who].link == 0xff, "and the unit has no path");
    }

    /* The world tick. */
    {
        Map m;
        int i, seen, before, same, empty, last, c;
        static unsigned char visited[MAP_W * MAP_H];

        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);

        /* The cell cursor steps 23 cells at a time and 23 is coprime with 2304,
         * so 2304 steps touch every square exactly once. */
        memset(visited, 0, sizeof visited);
        for (i = 0; i < MAP_W * MAP_H; i++) {
            visited[g->cellCursor] = 1;
            g->cellCursor += 23;
            if (g->cellCursor >= MAP_W * MAP_H) g->cellCursor -= MAP_W * MAP_H;
        }
        seen = 0;
        for (i = 0; i < MAP_W * MAP_H; i++) seen += visited[i];
        checkf(seen == MAP_W * MAP_H,
               "the cell cursor reached %d of %d squares", seen,
               MAP_W * MAP_H, 0);
        check(g->cellCursor == 0, "and came back to where it started");

        /* A nest square climbs by ten and eventually breeds. */
        game_init(g, &m);
        for (i = 0; i < MAP_W * MAP_H; i++)
            if (g->cell[i].tile == 5 && g->occupant[i] < 0) break;
        if (i < MAP_W * MAP_H) {
            int before5 = game_unit_count(g, 4), rounds = 0;
            g->cellCursor = i;
            g->speed = 7;                    /* one cell a tick */
            before = g->cell[i].amount;
            game_tick_cells(g);
            checkf(g->cell[i].amount == before + 10,
                   "a nest square went from %d to %d, expected +10", before,
                   g->cell[i].amount, 0);
            while (g->cell[i].amount != 0 && rounds++ < 64) {
                g->cellCursor = i;
                game_tick_cells(g);
            }
            check(g->cell[i].amount == 0, "it eventually resets");
            checkf(game_unit_count(g, 4) == before5 + 1,
                   "and breeds one neutral unit (%d -> %d)", before5,
                   game_unit_count(g, 4), 0);
        }

        /* Productive land grows by one for each of its side's CLAIMED
         * neighbours plus one - 0x33fb and 0x341a add 0x0c to the side number
         * before counting, so it is 0x0c + side that is looked for and not
         * 0x08 + side. */
        game_init(g, &m);
        for (i = 0; i < MAP_W * MAP_H; i++)
            if (g->cell[i].tile >= CELL_TERRITORY0 &&
                g->cell[i].tile < CELL_TERRITORY0 + PLAYERS) break;
        check(i < MAP_W * MAP_H, "B_000 has developed land at the start");
        if (i < MAP_W * MAP_H) {
            c = g->cell[i].tile - CELL_TERRITORY0;
            game_neighbours(g, i, (unsigned char)(CELL_TERRITORY0 + 4 + c),
                            &same, &empty, &last);
            g->cellCursor = i;
            g->speed = 7;
            g->human = c;                    /* no AI bonus for this one */
            before = g->cell[i].amount;
            game_tick_cells(g);
            checkf(g->cell[i].amount == before + same + 1,
                   "land grew by %d, expected %d",
                   g->cell[i].amount - before, same + 1, 0);
        }
    }

    /* The castle's collection. */
    {
        Map m;
        int side = 0, got, i, owned = 0, castle;
        unsigned long before;

        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        castle = game_cell_index(g->side[side].pos & 0xff,
                                 g->side[side].pos >> 8);

        for (i = 0; i < MAP_W * MAP_H; i++)
            if (g->cell[i].tile == CELL_TERRITORY0 + side) owned++;
        checkf(owned > 0, "side 0 starts with %d squares of its own land",
               owned, 0, 0);

        before = g->side[side].funds;
        got = game_collect(g, side);
        checkf(got > 0, "the castle collected %d", got, 0, 0);
        checkf(g->side[side].funds == before + got,
               "funds went %d -> %d", before, g->side[side].funds, 0);

        /* Every square it took from is its own land and is now poorer. */
        check(g->cell[castle].tile == CELL_CASTLE0 + side,
              "the castle square is unchanged");

        /* Without its lord on the castle nothing is collected. */
        game_init(g, &m);
        g->occupant[castle] = -1;
        check(game_collect(g, side) == 0,
              "no lord on the castle, no collection");

        /* Nor if the lord is not in a 0x20 mode. */
        game_init(g, &m);
        g->unit[g->side[side].lord].state = UNIT_STATE_FOLLOW;
        check(game_collect(g, side) == 0,
              "the lord has to be in a 0x20 mode");
    }

    /* Let the world run for a while and see the land behave. */
    {
        Map m;
        int i, t, ownedBefore = 0, ownedAfter = 0, unitsBefore, unitsAfter;
        int grownBefore = 0, grownAfter = 0;

        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        g->speed = 0;
        g->human = 0;

        for (i = 0; i < MAP_W * MAP_H; i++) {
            unsigned char c = g->cell[i].tile;
            if (c >= CELL_TERRITORY0 && c < CELL_TERRITORY0 + PLAYERS)
                ownedBefore++;
            if (c >= CELL_TERRITORY0 + 4 && c < CELL_TERRITORY0 + 8)
                grownBefore++;
        }
        unitsBefore = game_unit_count(g, -1);

        for (t = 0; t < 2000; t++) game_tick_cells(g);

        for (i = 0; i < MAP_W * MAP_H; i++) {
            unsigned char c = g->cell[i].tile;
            if (c >= CELL_TERRITORY0 && c < CELL_TERRITORY0 + PLAYERS)
                ownedAfter++;
            if (c >= CELL_TERRITORY0 + 4 && c < CELL_TERRITORY0 + 8)
                grownAfter++;
        }
        unitsAfter = game_unit_count(g, -1);

        checkf(grownAfter > grownBefore,
               "land spread from %d squares of 0x0c+side to %d",
               grownBefore, grownAfter, 0);
        checkf(ownedAfter == ownedBefore,
               "the 0x08+side squares stayed at %d (now %d)",
               ownedBefore, ownedAfter, 0);
        checkf(unitsAfter >= unitsBefore,
               "units went %d -> %d", unitsBefore, unitsAfter, 0);
        printf("2000 ticks: land %d -> %d, units %d -> %d\n",
               grownBefore, grownAfter, unitsBefore, unitsAfter);

        /* Nothing ever leaves the board. */
        for (i = 0; i < UNIT_SLOTS; i++) {
            const Unit *u = &g->unit[i];
            int x, y;
            if (u->flags & 0x80) continue;
            x = u->pos & 0xff;
            y = u->pos >> 8;
            checkf(x >= 0 && x < MAP_W && y >= 0 && y < MAP_H,
                   "unit %d is at %d,%d", i, x, y);
            checkf(g->occupant[game_cell_index(x, y)] == i,
                   "unit %d is not in the occupancy array at %d,%d", i, x, y);
        }
    }

    /* Developing a square, and picking up from it. */
    {
        Map m;
        int mate, here, target, i;
        unsigned long funds;

        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        mate = g->occupant[game_cell_index(g->side[0].pos & 0xff,
                                           (g->side[0].pos >> 8) + 1)];
        check(mate >= 0, "the second unit is there to work with");

        /* It stands on the castle's 0x1d square, which is not developable. */
        check(!game_develop(g, mate), "the castle gate cannot be developed");

        /* A square this side may develop: plain ground or claimed land with no
         * productive land of its own next to it - sub_ae9e refuses when there
         * is, so the ground spreads out with gaps.  Find the nearest one. */
        target = -1;
        for (i = 0; i < MAP_W * MAP_H; i++) {
            int x = i % MAP_W, y = i / MAP_W;
            if (x < MAP_MIN || x > MAP_MAX || y < MAP_MIN || y > MAP_MAX)
                continue;
            if (g->cell[i].tile != 0) continue;
            if (g->occupant[i] >= 0) continue;
            if (game_path_to(g, mate, x, y) <= 0) continue;
            target = i;
            break;
        }
        checkf(target >= 0, "B_000 has a square side 0 can develop (%d)",
               target, 0, 0);

        /* Walk there and develop it. */
        i = game_path_to(g, mate, target % MAP_W, target / MAP_W);
        checkf(i > 0, "no path to the target (%d)", i, 0, 0);
        while (game_path_dir(g, mate) >= 0) {
            int dir = game_path_dir(g, mate);
            if (game_move(g, mate, dir)) game_path_advance(g, mate);
        }
        checkf(game_cell_index(g->unit[mate].pos & 0xff,
                               g->unit[mate].pos >> 8) == target,
               "the worker reached %d (it is on %d)", target,
               game_cell_index(g->unit[mate].pos & 0xff,
                               g->unit[mate].pos >> 8), 0);

        funds = g->side[0].funds;
        check(game_develop(g, mate), "and developed it");
        checkf(g->cell[target].tile == CELL_TERRITORY0 + 0,
               "the square became %02x, expected 0x08",
               g->cell[target].tile, 0, 0);
        checkf(g->side[0].funds == funds - DEVELOP_COST,
               "it cost %d, not %d", (int)(funds - g->side[0].funds),
               DEVELOP_COST, 0);
        /* It carried 200, spent all of it, and is finished. */
        check(g->unit[mate].flags & 0x80,
              "a worker that spends its last is finished with");
        checkf(g->cell[target].amount == (CELL_FULL_AMOUNT >> 1) + 1,
               "the square holds %d, expected %d", g->cell[target].amount,
               (CELL_FULL_AMOUNT >> 1) + 1, 0);

        /* Picking up: put a unit on its own land and let it take the amount. */
        game_init(g, &m);
        for (here = 0; here < MAP_W * MAP_H; here++)
            if (g->cell[here].tile == CELL_TERRITORY0 + 0 &&
                g->occupant[here] < 0) break;
        check(here < MAP_W * MAP_H, "side 0 has a free square of its own land");
        if (here < MAP_W * MAP_H) {
            int who = -1, k;
            for (k = 0; k < UNIT_SLOTS; k++)
                if (!(g->unit[k].flags & 0x80) && g->unit[k].side == 0 &&
                    !(g->unit[k].state & 0x20)) { who = k; break; }
            check(who >= 0, "and a worker to do it");
            if (who >= 0) {
                int had = g->unit[who].carrying, amount = g->cell[here].amount;
                /* Move it there by hand; the walk is tested elsewhere. */
                g->occupant[game_cell_index(g->unit[who].pos & 0xff,
                                            g->unit[who].pos >> 8)] = -1;
                g->unit[who].pos = (unsigned short)
                    (((here / MAP_W) << 8) | (here % MAP_W));
                g->unit[who].at = (unsigned short)(here * 2);
                g->occupant[here] = (short)who;

                checkf(game_pick_up(g, who) == amount,
                       "picked up %d, expected %d", amount, amount, 0);
                checkf(g->unit[who].carrying == had + amount,
                       "carries %d, expected %d", g->unit[who].carrying,
                       had + amount, 0);
                check(g->cell[here].amount == 1, "and left 1 behind");
            }
        }
    }

    /* The lord: it tops itself up towards the side's land total, and pushes a
     * worker out of the gate when what it holds outgrows that total. */
    {
        Map m;
        int lord, before, i;

        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        game_land_totals(g);
        lord = g->side[0].lord;

        checkf(g->side[0].landTotal > 0,
               "side 0's land holds %d in total", (int)g->side[0].landTotal,
               0, 0);

        /* The cap is the whole of what the country holds - the ground and
         * everything its units are carrying, sub_a6a5's two loops - so the
         * lord tops up towards that and stops there.  It never runs past it. */
        {
            unsigned long cap = g->side[0].landTotal;
            int i2;
            for (i2 = 0; i2 < 40; i2++) game_unit_step(g, lord);
            checkf(g->unit[lord].carrying <= (int)cap ||
                   g->unit[lord].carrying == 0xffff,
                   "the lord settled at %d against a cap of %d",
                   g->unit[lord].carrying, (int)cap, 0);
        }
        before = g->unit[lord].carrying;

        /* Drain the land and the lord pushes a worker out - but the gate is
         * taken at the start, so free it first. */
        for (i = 0; i < MAP_W * MAP_H; i++) g->cell[i].amount = 1;
        game_land_totals(g);
        {
            int gate = game_cell_index(g->side[0].pos & 0xff,
                                       (g->side[0].pos >> 8) + 1);
            int mate = g->occupant[gate];
            int units;
            if (mate >= 0) {
                g->unit[mate].flags = 0x80;
                g->occupant[gate] = -1;
            }
            units = game_unit_count(g, -1);
            before = g->unit[lord].carrying;
            game_unit_step(g, lord);
            checkf(game_unit_count(g, -1) == units + 1,
                   "a worker appeared (%d -> %d)", units,
                   game_unit_count(g, -1), 0);
            check(g->occupant[gate] >= 0, "and it is standing in the gate");
            if (g->occupant[gate] >= 0) {
                const Unit *w = &g->unit[g->occupant[gate]];
                checkf(w->carrying == (unsigned short)(before >> 2),
                       "it carries %d, expected a quarter of %d",
                       w->carrying, before, 0);
                check(w->state == UNIT_STATE_FOLLOW, "in the worker state");
                check(w->side == 0, "on our side");
            }
            checkf(g->unit[lord].carrying == (unsigned short)(before - (before >> 2)),
                   "the lord kept %d of %d", g->unit[lord].carrying, before, 0);
        }
    }

    /* Bridges.  B_014 is the spiral: four castles at the head of their own lane
     * with water across each one, so it cannot be played at all without them. */
    {
        Map m;
        int lord, i, water = -1, wx = 0, wy = 0, len;
        unsigned long funds;

        gfx_load_map(&m, d, "B_014.MAP");
        game_init(g, &m);
        /* The worker in the gate, not the lord: the lord is walled into its
         * castle until the gate square is free. */
        lord = g->occupant[game_cell_index(g->side[0].pos & 0xff,
                                           (g->side[0].pos >> 8) + 1)];
        check(lord >= 0, "B_014 side 0 has a worker in the gate");

        /* Find the water this side has to cross: the nearest square in
         * 0x30..0x5f that is off the border and has dry land next to it. */
        for (i = 0; i < MAP_W * MAP_H && water < 0; i++) {
            int x = i % MAP_W, y = i / MAP_W, d2;
            unsigned char t = g->cell[i].tile;
            if (x <= 0 || x >= MAP_W - 1 || y <= 0 || y >= MAP_H - 1) continue;
            if (t < CELL_IMPASSABLE || t >= CELL_WATER_END) continue;
            for (d2 = 0; d2 < 4; d2++) {
                static const int ox[4] = {0, 1, 0, -1}, oy[4] = {-1, 0, 1, 0};
                int n = game_cell_index(x + ox[d2], y + oy[d2]);
                if (g->cell[n].tile < CELL_IMPASSABLE &&
                    game_path_to(g, lord, x + ox[d2], y + oy[d2]) > 0) {
                    water = i;
                    wx = x;
                    wy = y;
                    break;
                }
            }
        }
        checkf(water >= 0, "B_014 has water side 0 can reach (%d)", water, 0, 0);

        /* Ordering a bridge does not walk onto the water - it walks to the
         * shore and remembers the square. */
        len = game_order_bridge(g, lord, wx, wy);
        checkf(len > 0, "an order to bridge %d,%d (%d)", wx, wy, len);
        checkf((g->unit[lord].state & 0x0f) == UNIT_STATE_BRIDGE,
               "the state is now %02x", g->unit[lord].state, 0, 0);
        checkf(g->unit[lord].home == (unsigned short)((wy << 8) | wx),
               "the target is remembered as %04x", g->unit[lord].home, 0, 0);

        while (game_path_dir(g, lord) >= 0) {
            int dir = game_path_dir(g, lord);
            if (game_move(g, lord, dir)) game_path_advance(g, lord);
        }
        checkf(g->cell[game_cell_index(g->unit[lord].pos & 0xff,
                                      g->unit[lord].pos >> 8)].tile
                   < CELL_IMPASSABLE,
               "it stopped on dry land at %d,%d",
               g->unit[lord].pos & 0xff, g->unit[lord].pos >> 8, 0);

        /* Filling costs 30 a unit of depth, capped by carrying / 16. */
        {
            int depth = g->cell[water].amount;
            int take = g->unit[lord].carrying >> 4;
            int guard = 0;
            if (take > depth + 1) take = depth + 1;
            funds = g->side[0].funds;
            game_bridge(g, lord);
            checkf(g->side[0].funds == funds - (unsigned long)take * 30,
                   "%lu funds went on %d units of depth",
                   funds - g->side[0].funds, take, 0);

            /* Keep going and the square becomes walkable. */
            while (g->cell[water].tile >= CELL_IMPASSABLE && guard++ < 200) {
                g->side[0].funds += 10000;      /* the treasury is not the test */
                if (!game_bridge(g, lord)) break;
            }
            checkf(g->cell[water].tile == CELL_BRIDGE,
                   "%d,%d is tile %02x, expected the bridge 0x20",
                   wx, wy, g->cell[water].tile);
            check(g->cell[water].tile < CELL_IMPASSABLE,
                  "and a unit can now walk over it");
            printf("bridge: worker at %d,%d, %d,%d is tile %02x, "
                   "route %d\n",
                   g->unit[lord].pos & 0xff, g->unit[lord].pos >> 8, wx, wy,
                   g->cell[water].tile, game_path_to(g, lord, wx, wy));
            checkf(game_path_to(g, lord, wx, wy) > 0,
                   "the pathfinder routes over %d,%d", wx, wy, 0);
        }

        /* The border ring is refused outright, as sub_4040 refuses row and
         * column 0 and 0x2f. */
        for (i = 0; i < MAP_W; i++) {
            unsigned char t = g->cell[game_cell_index(i, 0)].tile;
            if (t >= CELL_IMPASSABLE && t < CELL_WATER_END) {
                check(!game_order_bridge(g, lord, i, 0),
                      "the border ring cannot be bridged");
                break;
            }
        }
    }

    /* The other three square orders, the same way: find a target this side can
     * reach, order it, walk, and work until the square turns into what the
     * handler says it turns into.
     *
     *   9  woodland 0x7b  -> plain ground, free       (sub_41dc)
     *   10 a bridge 0x2x  -> a rock 0x7a, free        (sub_4247)
     *   11 a nest 0x05    -> 0x60, free               (sub_4304)
     */
    {
        static const struct {
            const char *what;
            unsigned char from, to;
            int order;
        } jobs[3] = {
            {"woodland", CELL_WOOD, 0x00, UNIT_STATE_FELL},
            {"a bridge", 0x25,      CELL_ROCK, UNIT_STATE_BREAK},
            {"a nest",   CELL_NEST, CELL_NEST_GONE, UNIT_STATE_NEST},
        };
        int j;
        for (j = 0; j < 3; j++) {
            Map m;
            int n, who = -1, target = -1, tx = 0, ty = 0, guard;

            /* Whichever of the 52 offers a reachable one first. */
            for (n = 0; n < 52 && target < 0; n++) {
                char name[32];
                int i;
                snprintf(name, sizeof name, "B_%03d.MAP", n);
                if (!gfx_load_map(&m, d, name)) continue;
                game_init(g, &m);
                who = g->occupant[game_cell_index(g->side[0].pos & 0xff,
                                                  (g->side[0].pos >> 8) + 1)];
                if (who < 0) continue;
                for (i = 0; i < MAP_W * MAP_H; i++) {
                    int x = i % MAP_W, y = i / MAP_W;
                    if (g->cell[i].tile != jobs[j].from) continue;
                    if (game_job_for(g, x, y) != jobs[j].order) continue;
                    if (game_order_job(g, who, x, y) <= 0) continue;
                    target = i;
                    tx = x;
                    ty = y;
                    break;
                }
            }
            checkf(target >= 0, "some map has %s side 0 can reach",
                   0, 0, 0);
            if (target < 0) continue;

            checkf((g->unit[who].state & 0x0f) == jobs[j].order,
                   "the state for %s is %02x", 0, g->unit[who].state, 0);
            check(g->unit[who].home == (unsigned short)((ty << 8) | tx),
                  "and the square is remembered");

            while (game_path_dir(g, who) >= 0) {
                int dir = game_path_dir(g, who);
                if (game_move(g, who, dir)) game_path_advance(g, who);
            }
            /* A nest refuses while anything stands on it; nothing does here. */
            guard = 0;
            while (g->cell[target].tile == jobs[j].from && guard++ < 400) {
                g->side[0].funds += 10000;
                g->unit[who].carrying = CELL_FULL_AMOUNT;
                if (!game_job(g, who)) break;
            }
            checkf(g->cell[target].tile == jobs[j].to,
                   "%d,%d ended as tile %02x", tx, ty, g->cell[target].tile);
        }
    }

    /* A country falling.  Two ways of showing it: by hand, so the chain is
     * pinned down, and by letting a map run, so it is reachable. */
    {
        Map m;
        int lord, i, alive;

        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        lord = g->side[0].lord;
        check(g->side[0].alive, "side 0 starts alive");

        /* sub_a9ca: the killer goes in [unit + 0x0f] and becomes the heir. */
        game_kill(g, lord, 2);
        check(g->unit[lord].flags & 2, "the lord is dying");
        checkf(g->unit[lord].retry == 2,
               "the killer recorded as side %d", g->unit[lord].retry, 0, 0);
        check(g->side[0].alive, "and the country stands until the count is up");

        /* Three more ticks of dying and the country goes with it. */
        {
            unsigned long before = g->side[2].funds;
            unsigned long had = g->side[0].funds;
            for (i = 0; i < 6 && g->side[0].alive; i++)
                game_unit_step(g, lord);
            check(!g->side[0].alive, "the country has fallen");
            checkf(g->side[0].heir == 2, "the heir is side %d",
                   g->side[0].heir, 0, 0);
            checkf(g->side[2].funds == before + had,
                   "the treasury of %lu went over (side 2 has %lu)",
                   (int)had, (int)g->side[2].funds, 0);
            check(g->side[0].funds == 0, "and the fallen side has nothing");
            check(g->side[0].ally == 0x80, "its alliance is broken");
        }

        /* The castle is levelled - all nine squares plain ground at 100. */
        {
            int cx = g->side[0].pos & 0xff, cy = g->side[0].pos >> 8;
            int dx, dy, wrong = 0;
            for (dy = -1; dy <= 1; dy++)
                for (dx = -1; dx <= 1; dx++) {
                    const Cell *c = &g->cell[game_cell_index(cx + dx, cy + dy)];
                    if (c->tile != 0 || c->amount != CELL_START_AMOUNT) wrong++;
                }
            checkf(wrong == 0, "%d of the castle's nine squares survived",
                   wrong, 0, 0);
        }

        /* Every unit it had is in state 12, the handler that changes a unit
         * over to the heir. */
        for (i = 0; i < UNIT_SLOTS; i++) {
            const Unit *u = &g->unit[i];
            if (u->flags & 0x80) continue;
            if (u->side != 0) continue;
            checkf((u->state & 0x0f) == 12,
                   "unit %d of the fallen side is in state %02x", i, u->state,
                   0);
        }
        /* And a step later they belong to the heir. */
        for (i = 0; i < UNIT_SLOTS; i++) {
            if (g->unit[i].flags & 0x80) continue;
            if (g->unit[i].side == 0) game_unit_step(g, i);
        }
        for (i = 0; i < UNIT_SLOTS; i++)
            checkf((g->unit[i].flags & 0x80) || g->unit[i].side != 0,
                   "unit %d (flags %02x state %02x) still belongs to the "
                   "fallen side", i, g->unit[i].flags, g->unit[i].state);

        /* B_051 plays itself out: three countries go and one is left.  Nobody
         * is the player here, so this is the fixed algorithm alone. */
        gfx_load_map(&m, d, "B_051.MAP");
        game_init(g, &m);
        game_land_totals(g);
        g->human = -1;
        for (i = 0; i < 12000; i++) {
            game_tick_cells(g);
            game_step(g);
        }
        alive = 0;
        for (i = 0; i < PLAYERS; i++) if (g->side[i].alive) alive++;
        /* Reported rather than asserted.  How long a map takes to settle moves
         * whenever a rule is corrected, and pinning a number here only records
         * whichever reading was current: the chain that kills a country is
         * asserted by hand above, which is the part that can actually break. */
        printf("B_051 after 12000 ticks: %d of 4 countries left\n", alive);
    }

    /* The calendar.  A day is 2^(speed + 1) turns - sub_a731 takes 0xfe,
     * shifts it left by [0x3c02], inverts it and tests the turn counter
     * against that - and the countdown starts at 3200, which is what
     * ss3.jpg's 293 + 2907 comes to. */
    {
        static const struct { int speed, turns, days; } want[] = {
            { 0,  600, 300 },   /* every 2 turns  */
            { 1,  600, 150 },   /* every 4        */
            { 2,  600,  75 },   /* every 8        */
            { 3, 1600, 100 },   /* every 16       */
        };
        unsigned k;
        Map cal;

        gfx_load_map(&cal, d, "B_000.MAP");
        for (k = 0; k < sizeof want / sizeof *want; k++) {
            int i;

            game_init(g, &cal);
            g->speed = want[k].speed;
            check(g->daysLeft == GAME_DAYS, "a new game has 3200 days left");
            for (i = 0; i < want[k].turns; i++) {
                g->turn = (g->turn + 1) & 0xff;
                game_day(g);
            }
            checkf(g->day == want[k].days,
                   "speed %d: %d turns should be %d days", want[k].speed,
                   want[k].turns, want[k].days);
            checkf(g->day + g->daysLeft == GAME_DAYS,
                   "speed %d: %d gone and %d left do not come to 3200",
                   want[k].speed, g->day, g->daysLeft);
        }
        printf("the calendar: a day is 2^(speed+1) turns, out of 3200\n");
    }

    disk_close(d);
    free(g);
    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("ok\n");
    return 0;
}
