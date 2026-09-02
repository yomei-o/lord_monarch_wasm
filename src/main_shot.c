/* Renders one screen and writes it to a PNG, without opening a window.
 *
 *   monarch_shot <image.fim> list
 *   monarch_shot <image.fim> title out.png
 *   monarch_shot <image.fim> frame out.png            [WAKU | WAKU2 | GAKU]
 *   monarch_shot <image.fim> map   B_005.MAP out.png  [--tile 8|16|32]
 *   monarch_shot <image.fim> game  B_005.MAP out.png  [--at X,Y]
 *   monarch_shot <image.fim> view  <map number> <tile size> out.png
 *                                 [--ticks N]  run the world first
 *
 * The point of this over the Win32 build is that the work happens on a machine
 * whose desktop is in use: a render that has to be looked at goes to a file, not
 * to a window that steals focus.  It also makes the drawing path testable.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "disk.h"
#include "gfx.h"
#include "png.h"

static Screen scr;

static void save(const char *path, const unsigned char *px, int w, int h,
                 int stride)
{
    unsigned char rgb[16][3];
    int i;
    for (i = 0; i < 16; i++)
        gfx_rgb(&scr, i, &rgb[i][0], &rgb[i][1], &rgb[i][2]);
    if (!png_write_indexed(path, w, h, px, stride, rgb, 16))
        fprintf(stderr, "cannot write %s\n", path);
    else
        printf("%s  %dx%d\n", path, w, h);
}

/* The in-game palette travels with the tileset: the 48 bytes appended to
 * B_0n0L.CH4.  See gfx_set_palette and the note in tools/ch4.py. */
static int palette_from_terrain(Disk *d, int terrain)
{
    char name[32];
    unsigned n = 0;
    unsigned char *b;
    snprintf(name, sizeof name, "B_%03dL.CH4", terrain);
    b = disk_read_bz(d, name, &n);
    if (!b || n < 48) {
        free(b);
        return 0;
    }
    gfx_set_palette(&scr, b + n - 48);
    free(b);
    return 1;
}

/* Measured off ss0.jpg; the title has no terrain bank to carry a table and the
 * real one has not been located yet.  4-bit values. */
static void palette_title(void)
{
    static const unsigned char t[16][3] = {
        {0, 0, 0}, {0, 2, 2}, {4, 14, 10}, {0, 8, 8},
        {4, 7, 7}, {7, 10, 10}, {10, 12, 12}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    };
    gfx_set_palette_rgb(&scr, t);
}

static int arg_int(int argc, char **argv, const char *flag, int def)
{
    int i;
    for (i = 1; i + 1 < argc; i++)
        if (!strcmp(argv[i], flag)) return atoi(argv[i + 1]);
    return def;
}

static void arg_xy(int argc, char **argv, const char *flag, int *x, int *y)
{
    int i;
    for (i = 1; i + 1 < argc; i++)
        if (!strcmp(argv[i], flag)) {
            const char *c = strchr(argv[i + 1], ',');
            *x = atoi(argv[i + 1]);
            if (c) *y = atoi(c + 1);
        }
}

int main(int argc, char **argv)
{
    Disk *d;
    const char *cmd;

    if (argc < 3) {
        fprintf(stderr, "usage: %s <image.fim> "
                "list|title|frame|map|game ...\n", argv[0]);
        return 2;
    }
    d = disk_open(argv[1]);
    if (!d) {
        fprintf(stderr, "%s\n", disk_error());
        return 1;
    }
    cmd = argv[2];

    if (!strcmp(cmd, "list")) {
        int i;
        for (i = 0; i < disk_count(d); i++)
            printf("%s\n", disk_name(d, i));
    } else if (!strcmp(cmd, "title")) {
        palette_title();
        gfx_clear(&scr, 0);
        if (!gfx_load_screen(&scr, d, "DS7TTL")) {
            fprintf(stderr, "DS7TTL: %s\n", disk_error());
            return 1;
        }
        save(argc > 3 ? argv[3] : "title.png", scr.px, SCR_W, SCR_H, SCR_W);
    } else if (!strcmp(cmd, "frame")) {
        const char *name = argc > 4 ? argv[4] : "WAKU";
        palette_from_terrain(d, arg_int(argc, argv, "--terrain", 10));
        gfx_clear(&scr, 0);
        if (!gfx_load_screen(&scr, d, name)) {
            fprintf(stderr, "%s: %s\n", name, disk_error());
            return 1;
        }
        save(argc > 3 ? argv[3] : "frame.png", scr.px, SCR_W, SCR_H, SCR_W);
    } else if (!strcmp(cmd, "map") || !strcmp(cmd, "game")) {
        const int game = !strcmp(cmd, "game");
        const int size = arg_int(argc, argv, "--tile", 8);
        int ox = game ? 160 : 0, oy = game ? 8 : 0;
        Map m;
        Bank b;
        char bank[32];

        if (argc < 5) {
            fprintf(stderr, "usage: %s <image.fim> %s <NAME.MAP> out.png\n",
                    argv[0], cmd);
            return 2;
        }
        if (!gfx_load_map(&m, d, argv[3])) {
            fprintf(stderr, "%s: %s\n", argv[3], disk_error());
            return 1;
        }
        if (!palette_from_terrain(d, m.terrain)) {
            fprintf(stderr, "terrain %d: no palette\n", m.terrain);
            return 1;
        }
        gfx_bank_name(&m, size, bank, sizeof bank);
        if (!gfx_load_bank(&b, d, bank, size)) {
            fprintf(stderr, "%s: %s\n", bank, disk_error());
            return 1;
        }
        arg_xy(argc, argv, "--at", &ox, &oy);
        gfx_clear(&scr, 0);
        if (game && !gfx_load_screen(&scr, d, "WAKU"))
            fprintf(stderr, "WAKU: %s\n", disk_error());
        gfx_draw_map(&scr, &m, &b, ox, oy, 0, 0, MAP_W, MAP_H);
        printf("%s: terrain %d, bank %s (%d tiles)\n", argv[3], m.terrain,
               bank, b.count);
        if (game) {
            save(argv[4], scr.px, SCR_W, SCR_H, SCR_W);
        } else {
            /* Just the map, at its natural size. */
            const int w = MAP_W * size, h = MAP_H * size;
            unsigned char *out = (unsigned char *)malloc((size_t)w * h);
            int y;
            for (y = 0; y < h && y < SCR_H; y++)
                memcpy(out + (size_t)y * w, scr.px + (size_t)y * SCR_W,
                       (size_t)(w < SCR_W ? w : SCR_W));
            save(argv[4], out, w < SCR_W ? w : SCR_W, h < SCR_H ? h : SCR_H, w);
            free(out);
        }
        gfx_free_bank(&b);
    } else if (!strcmp(cmd, "view")) {
        /* Straight through app.c - the same path the Win32 and WASM hosts take -
         * so a frame from here and a frame out of the browser are comparable
         * byte for byte.  A map number of -1 leaves it on the title. */
        int number, size;
        if (argc < 6) {
            fprintf(stderr,
                    "usage: %s <image.fim> view <map> <tile> out.png\n",
                    argv[0]);
            return 2;
        }
        number = atoi(argv[3]);
        size = atoi(argv[4]);
        disk_close(d);
        if (!app_init(argv[1])) {
            fprintf(stderr, "%s\n", app_status());
            return 1;
        }
        if (number >= 0 && !app_show_map(number, size)) {
            fprintf(stderr, "%s\n", app_status());
            return 1;
        }
        {
            int t, ticks = arg_int(argc, argv, "--ticks", 0);
            for (t = 0; t < ticks; t++) app_tick();
        }
        app_render();
        printf("%s\n", app_status());
        scr = *app_screen();
        save(argv[5], scr.px, SCR_W, SCR_H, SCR_W);
        app_shutdown();
        return 0;
    } else {
        fprintf(stderr, "unknown command %s\n", cmd);
        return 2;
    }
    disk_close(d);
    return 0;
}
