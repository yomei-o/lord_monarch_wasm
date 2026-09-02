/* Runs the world for a long time and prints what happens, so it can be seen
 * whether the sides actually expand, meet and knock each other out.
 *
 *   tmp/sim.exe tmp/monarch.fim [map] [ticks] [every]
 *
 * This is a diagnostic, not a test: game_check.c asserts the individual rules,
 * this one watches the whole thing move.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "game.h"
#include "gfx.h"

static Game g;

static int units_of(const Game *game, int side)
{
    return game_unit_count(game, side);
}

int main(int argc, char **argv)
{
    Disk *d = disk_open(argc > 1 ? argv[1] : "tmp/monarch.fim");
    int mapNo = argc > 2 ? atoi(argv[2]) : 0;
    long ticks = argc > 3 ? atol(argv[3]) : 200000;
    long every = argc > 4 ? atol(argv[4]) : 20000;
    char name[32];
    Map m;
    long t;
    int i;

    if (!d) {
        fprintf(stderr, "%s\n", disk_error());
        return 1;
    }
    snprintf(name, sizeof name, "B_%03d.MAP", mapNo);
    if (!gfx_load_map(&m, d, name)) {
        fprintf(stderr, "%s: %s\n", name, disk_error());
        return 1;
    }
    game_init(&g, &m);
    game_land_totals(&g);
    g.human = -1;              /* nobody is the player, so every side is AI */

    printf("%s, terrain %d\n", name, m.terrain);
    printf("%8s %5s", "tick", "units");
    for (i = 0; i < PLAYERS; i++) printf("  %d:land/hold/purse", i);
    printf("\n");

    for (t = 0; t <= ticks; t++) {
        if (t % every == 0) {
            printf("%8ld %5d", t, units_of(&g, -1));
            for (i = 0; i < PLAYERS; i++) {
                int p, c;
                game_land_count(&g, i, &p, &c);
                printf("  %4d/%4d/%6lu%s", p, c, g.side[i].funds,
                       g.side[i].alive ? "" : "*");
            }
            printf("\n");
        }
        game_tick_cells(&g);
        game_step(&g);
    }

    {
        int hist[16], k, dying = 0, withPath = 0;
        memset(hist, 0, sizeof hist);
        for (k = 0; k < UNIT_SLOTS; k++) {
            const Unit *u = &g.unit[k];
            if (u->flags & 0x80) continue;
            hist[u->state & 0x0f]++;
            if (u->flags & 2) dying++;
            if (u->link != 0xff) withPath++;
        }
        printf("\nstates:");
        for (k = 0; k < 16; k++) if (hist[k]) printf(" %d:%d", k, hist[k]);
        printf("   dying %d, with a path %d\n", dying, withPath);
        printf("carried:");
        for (k = 0; k < UNIT_SLOTS && k < 20; k++)
            if (!(g.unit[k].flags & 0x80))
                printf(" %d/%d", g.unit[k].side, g.unit[k].carrying);
        printf("\n");
    }

    printf("\nunits left:\n");
    for (i = 0; i < SIDES; i++)
        printf("  side %d: %d\n", i, units_of(&g, i));
    disk_close(d);
    return 0;
}
