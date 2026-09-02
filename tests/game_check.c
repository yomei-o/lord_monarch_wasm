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

        /* Developed land grows by one for each neighbour of its own kind. */
        game_init(g, &m);
        for (i = 0; i < MAP_W * MAP_H; i++)
            if (g->cell[i].tile >= CELL_TERRITORY0 &&
                g->cell[i].tile < CELL_TERRITORY0 + PLAYERS) break;
        check(i < MAP_W * MAP_H, "B_000 has developed land at the start");
        if (i < MAP_W * MAP_H) {
            c = g->cell[i].tile - CELL_TERRITORY0;
            game_neighbours(g, i, g->cell[i].tile, &same, &empty, &last);
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

        /* Its carried 1000 is at or above the total, so nothing happens. */
        before = g->unit[lord].carrying;
        game_unit_step(g, lord);
        checkf(g->unit[lord].carrying == before,
               "a lord at its cap stays at %d (now %d)", before,
               g->unit[lord].carrying, 0);

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

    disk_close(d);
    free(g);
    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("ok\n");
    return 0;
}
