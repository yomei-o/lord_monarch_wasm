/* Why the "has fallen" window comes up twice.
 *
 *   tmp/fell_probe.exe tmp/monarch.fim [frames to wait before answering]
 *
 * Plays the first map with the purse kept full and prints every window as it
 * opens, with its lines - and waits a while before answering, the way a player
 * does, so a window queued behind another one shows up.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "app.h"

int main(int argc, char **argv)
{
    const char *image = argc > 1 ? argv[1] : "tmp/monarch.fim";
    const int wait = argc > 2 ? atoi(argv[2]) : 120;
    long f;
    int last = 0, windows = 0, held = 0;

    if (!app_init(image)) {
        printf("cannot open the image: %s\n", app_status());
        return 1;
    }
    if (!app_show_map(0, 16)) { printf("no map 0: %s\n", app_status()); return 1; }
    app_key(APP_KEY_RUN);

    for (f = 0; f < 400000 && windows < 20; f++) {
        int d, n, k;

        app_key(APP_KEY_MONEY);
        app_render();
        d = app_dialog();
        if (d && d != last) {
            n = app_dialog_lines();
            printf("frame %6ld  window %2d  %d line(s)\n", f, d, n);
            for (k = 0; k < n; k++)
                printf("           | %s\n", app_dialog_line(k));
            windows++;
            held = 0;
        }
        if (d) {
            if (++held >= wait) app_key(APP_KEY_START);   /* answer it */
        }
        last = d;
    }
    printf("%d windows in %ld frames\n", windows, f);
    return 0;
}
