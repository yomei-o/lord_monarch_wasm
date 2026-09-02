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

/* The castle is a fixed 3x3 in every map:
 *
 *     70 72 78
 *     7x 1x 1d      1x = 0x14 + side, 7x = 0x74 + side
 *     71 73 79
 */
static void check_castle_shape(const Map *m, int side, int x, int y)
{
    static const unsigned char want[3][3] = {
        {0x70, 0x72, 0x78},
        {0x00, 0x00, 0x1d},         /* the middle row is side-dependent */
        {0x71, 0x73, 0x79},
    };
    int dx, dy;
    for (dy = -1; dy <= 1; dy++)
        for (dx = -1; dx <= 1; dx++) {
            int cx = x + dx, cy = y + dy;
            unsigned char got, expect;
            if (cx < 0 || cx >= MAP_W || cy < 0 || cy >= MAP_H) continue;
            got = m->cell[cy * MAP_W + cx];
            if (dy == 0 && dx == -1) expect = (unsigned char)(0x74 + side);
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

    /* Movement, on a map that has been looked at by hand.  B_000's first castle
     * is at (6,8): the lord stands on it and the second unit on (7,8), the
     * castle's 0x1d square. */
    {
        Map m;
        int lord, mate, moved, dy;
        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        lord = g->side[0].lord;
        mate = g->occupant[game_cell_index(7, 8)];

        check((g->unit[lord].pos & 0xff) == 6 && (g->unit[lord].pos >> 8) == 8,
              "B_000 side 0 lord starts at 6,8");
        check(g->occupant[game_cell_index(6, 8)] == lord,
              "the lord owns its cell in the occupancy array");
        check(mate >= 0 && g->unit[mate].side == 0,
              "the side's second unit is on 7,8");

        /* The castle's own 3x3 tiles are 0x70..0x79, all of them 0x30 or above,
         * so the only way off the middle square is the 0x1d to its right - and
         * that one is taken.  The lord starts boxed in. */
        check(g->cell[game_cell_index(6, 7)].tile >= CELL_IMPASSABLE,
              "the castle's own tiles are impassable");
        check(g->unit[lord].facing == DIR_RIGHT, "new units face right");
        check(!game_move(g, lord, DIR_RIGHT),
              "a step into an occupied cell is refused");
        check(!game_move(g, lord, DIR_UP), "turning takes the step");
        check(g->unit[lord].facing == DIR_UP, "and leaves it facing that way");
        check(!game_move(g, lord, DIR_UP),
              "and the castle wall still refuses it");

        /* The unit on 7,8 can leave: 8,8 is ordinary ground. */
        check(g->cell[game_cell_index(8, 8)].tile < CELL_IMPASSABLE,
              "8,8 is passable");
        moved = game_move(g, mate, DIR_RIGHT);
        check(moved, "the second unit steps right");
        check((g->unit[mate].pos & 0xff) == 8, "and is now on 8,8");
        check(g->occupant[game_cell_index(7, 8)] == -1, "the old cell is free");
        check(g->occupant[game_cell_index(8, 8)] == mate,
              "and the new one is claimed");

        /* Now the lord can follow it right. */
        check(!game_move(g, lord, DIR_RIGHT), "the lord turns back to the right");
        check(game_move(g, lord, DIR_RIGHT), "and then follows");
        check((g->unit[lord].pos & 0xff) == 7, "the lord is on 7,8");

        /* The outermost ring is off limits whatever the tile says. */
        dy = 0;
        for (mate = 0; mate < UNIT_SLOTS; mate++)
            if (!(g->unit[mate].flags & 0x80)) dy++;
        check(dy == game_unit_count(g, -1), "the unit count agrees with itself");
    }

    /* Pathfinding: walk a unit somewhere and see that it arrives. */
    {
        Map m;
        int who, len, steps, tx, ty, guard;
        gfx_load_map(&m, d, "B_000.MAP");
        game_init(g, &m);
        who = g->occupant[game_cell_index(7, 8)];
        check(who >= 0, "there is a unit on 7,8 to walk");

        /* Somewhere reachable and a fair distance off. */
        tx = 20; ty = 20;
        len = game_path_to(g, who, tx, ty);
        checkf(len > 0, "no path from 7,8 to 20,20 (%d)", len, 0, 0);
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

    disk_close(d);
    free(g);
    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("ok\n");
    return 0;
}
