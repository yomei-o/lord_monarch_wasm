/* Why is nothing happening?  Prints the numbers the lord's decision depends on,
 * tick by tick, so a stall can be read rather than guessed at.
 *
 *   tmp/probe.exe tmp/monarch.fim [map] [ticks]
 *
 * The lord pushes a worker out of the gate when carried / 2 > the side's land
 * total, and otherwise tops itself up towards that same total (sub_3c7f).  So
 * the only thing that can ever start a worker is the total falling, which is
 * what the castle's collection does when it takes value off the ground.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "game.h"
#include "gfx.h"

static Game g;

int main(int argc, char **argv)
{
    Disk *d = disk_open(argc > 1 ? argv[1] : "tmp/monarch.fim");
    int mapNo = argc > 2 ? atoi(argv[2]) : 0;
    long ticks = argc > 3 ? atol(argv[3]) : 1200;
    char name[32];
    Map m;
    long t;
    int lastUnits = -1;

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
    g.human = 0;                /* as in play: side 0 is the player */
    if (argc > 4) g.side[0].rate = (unsigned char)atoi(argv[4]);

    printf("%s\n", name);
    printf("%6s %6s %8s %8s %7s %5s %5s\n",
           "tick", "units", "carried", "landTot", "funds", "plain", "held");
    for (t = 0; t <= ticks; t++) {
        int lord = g.side[0].lord;
        int units = game_unit_count(&g, 0);
        int plain, held;
        game_land_count(&g, 0, &plain, &held);
        if (t % 100 == 0 || units != lastUnits) {
            printf("%6ld %6d %8d %8lu %7lu %5d %5d%s\n",
                   t, units,
                   lord >= 0 ? g.unit[lord].carrying : -1,
                   g.side[0].landTotal, g.side[0].funds, plain, held,
                   units != lastUnits ? "   <- changed" : "");
            lastUnits = units;
        }
        if (t == 200 || t == 500) {
            int got = game_collect(&g, 0);
            printf("       calling game_collect(0) directly at %ld -> %d\n",
                   t, got);
        }
        game_tick_cells(&g);
        game_step(&g);
    }
    disk_close(d);
    return 0;
}
