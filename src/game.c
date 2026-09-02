#include "game.h"

#include <string.h>

/* The loader writes (tile, 0x64) into every cell - see the note in game.h. */
#define CELL_START_AMOUNT 0x64

void game_init(Game *g, const Map *m)
{
    int i;

    memset(g, 0, sizeof *g);
    g->terrain = m->terrain;
    for (i = 0; i < SIDES; i++) g->castleX[i] = g->castleY[i] = -1;

    for (i = 0; i < MAP_W * MAP_H; i++) {
        unsigned char t = m->cell[i];
        g->cell[i].tile = t;
        g->cell[i].amount = CELL_START_AMOUNT;
        g->occupant[i] = -1;
        if (t >= CELL_CASTLE0 && t < CELL_CASTLE0 + SIDES) {
            int side = t - CELL_CASTLE0;
            g->castleX[side] = i % MAP_W;
            g->castleY[side] = i / MAP_W;
        }
    }
    for (i = 0; i < UNIT_SLOTS; i++)
        g->unit[i].flags = 0x80;        /* every slot starts out of play */
}

void game_step(Game *g)
{
    /* 0x40 >> speed, minus one: the original loads 0x40, shifts by [0x3c02] and
     * decrements before using it as the loop count. */
    int todo = (0x40 >> (g->speed & 7)) - 1;
    int slot = g->cursor;

    if (todo < 1) todo = 1;
    while (todo--) {
        Unit *u = &g->unit[slot & (UNIT_SLOTS - 1)];
        if (!(u->flags & 0x80)) {
            u->flags &= (unsigned char)~1u;
            /* The order handlers (the sixteen-entry table at CS:3a47) are not
             * ported yet; this keeps the visiting order honest in the meantime
             * so that when they are, nothing else has to change. */
        }
        slot = (slot + 31) & (UNIT_SLOTS - 1);
    }
    g->cursor = slot;
}
