/* The windows a fallen country puts up, as pictures.
 *
 *   tmp/fell_shot.exe tmp/monarch.fim
 *
 * Writes tmp/fell_<n>_<window>.png for the first few windows the first map
 * throws up, so what the player actually sees can be looked at rather than
 * read out of dlg.line[].
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "gfx.h"
#include "png.h"

int main(int argc, char **argv)
{
    const char *image = argc > 1 ? argv[1] : "tmp/monarch.fim";
    long f;
    int last = 0, shots = 0, held = 0;

    if (!app_init(image)) {
        printf("cannot open the image: %s\n", app_status());
        return 1;
    }
    if (!app_show_map(0, 16)) { printf("no map 0: %s\n", app_status()); return 1; }
    app_key(APP_KEY_RUN);

    for (f = 0; f < 400000 && shots < 6; f++) {
        int d;

        app_key(APP_KEY_MONEY);
        app_render();
        d = app_dialog();
        if (d && d != last) {
            const Screen *s = app_screen();
            unsigned char rgb[16][3];
            char path[64];
            int i;

            for (i = 0; i < 16; i++)
                gfx_rgb(s, i, &rgb[i][0], &rgb[i][1], &rgb[i][2]);
            snprintf(path, sizeof path, "tmp/fell_%d_win%d.png", shots, d);
            if (png_write_indexed(path, SCR_W, SCR_H, s->px, SCR_W, rgb, 16))
                printf("%s  (frame %ld, window %d)\n", path, f, d);
            shots++;
            held = 0;
        }
        if (d && ++held >= 90) app_key(APP_KEY_START);
        last = d;
    }
    return 0;
}
