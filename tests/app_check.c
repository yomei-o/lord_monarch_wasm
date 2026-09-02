/* The two things the panel and the windows have to get right, checked by
 * playing the first map to its end rather than by reading the code.
 *
 *   tmp/app_check.exe tmp/monarch.fim
 *
 * 1. A window is modal and does not touch the run flag.  0xb197 opens its
 *    window, plays 0x302, waits at sub_72ad and closes at sub_c921; nothing
 *    on that path writes [0x3bd4] or [0x3bd6].  So the world stops while the
 *    window is up - because the wait is blocking - and carries on by itself
 *    when it is answered.  The port used to clear its run flag instead, which
 *    meant GO had to be pressed again after every country that fell.
 *
 * 2. Clearing a stage moves to the next one.  0xb433: a win falls into
 *    sub_b58f and then sub_6315, which sets [0x3bc2] to the stage just
 *    reached, clears [0x3bd6] and loads the map - leaving [0x3bd4] set, so
 *    the new stage is already under way.
 *
 * The map is played the way it is known to be winnable: the tax at nought and
 * the purse kept full (APP_KEY_MONEY).
 */
#include <stdio.h>
#include <string.h>

#include "app.h"

#define DLG_TAX  2
#define DLG_FELL 7
#define DLG_OVER 8

static int failures;

static void check(int ok, const char *what)
{
    if (!ok) { printf("FAIL: %s\n", what); failures++; }
    else printf("ok:   %s\n", what);
}

int main(int argc, char **argv)
{
    long f;
    int sawFell = 0, fellRan = 0, overAt = -1;

    if (!app_init(argc > 1 ? argv[1] : "tmp/monarch.fim")) {
        printf("cannot open the image: %s\n", app_status());
        return 1;
    }
    if (!app_show_map(0, 16)) { printf("no map 0: %s\n", app_status()); return 1; }
    /* The tax down to the lowest the window offers.  ICON_TAX is index 2,
     * which is column 0 of row 1 - x 16..47, y 56..87 - and the first choice
     * is already under the pointer, so a confirm takes it. */
    app_click(24, 64);
    check(app_dialog() == DLG_TAX, "the tax icon opens the tax window");
    {
        int k;

        /* 0x4f08 walks the knob one notch at a time and 0x4f45 refuses to go
         * below nought, so this lands on nought however it started. */
        for (k = 0; k < 60; k++) app_key(APP_KEY_LEFT);
        check(strstr(app_dialog_line(3), " 0") != NULL,
              "the slider goes all the way down to nought");
    }
    app_key(APP_KEY_START);
    check(app_dialog() == 0, "and setting it closes it");
    check(strstr(app_status(), "tax rate 0 of 30") != NULL,
          "nought is what the game got");

    app_key(APP_KEY_RUN);
    check(app_running(), "GO starts the world");

    for (f = 0; f < 200000; f++) {
        int d;

        /* The tax icon's window would do this; reach for the same value. */
        app_key(APP_KEY_MONEY);
        app_render();
        d = app_dialog();
        if (d == DLG_FELL && !sawFell) {
            long k;
            int stillUp = 1;

            sawFell = 1;
            fellRan = app_running();
            /* Modal: a hundred frames must not get past it. */
            for (k = 0; k < 100; k++) {
                app_render();
                if (app_dialog() != DLG_FELL) { stillUp = 0; break; }
            }
            check(stillUp, "the fallen-country window holds the world");
            check(fellRan, "it does not put the run flag out");
            app_key(APP_KEY_START);              /* answer it */
            check(app_dialog() != DLG_FELL, "answering it closes it");
            check(app_running(), "and the world is running again, without GO");
        }
        /* Every country after the first: just answer it, or the world sits
         * behind a window that nobody closes. */
        else if (d == DLG_FELL) app_key(APP_KEY_START);
        if (d == DLG_OVER) { overAt = (int)f; break; }
    }
    check(overAt >= 0, "the first map is won");
    if (overAt >= 0) {
        int was = app_map_number(), i;

        for (i = 0; i < app_dialog_lines(); i++)
            printf("      | %s\n", app_dialog_line(i));

        check(app_running(), "the end-of-stage window leaves the run flag alone");
        app_key(APP_KEY_START);
        check(app_dialog() == 0, "answering it closes it");
        check(app_map_number() == was + 1, "and the next stage is up");
        check(app_running(), "already running, the way sub_6315 leaves it");
        printf("map %d won after %d frames, now on map %d\n",
               was, overAt, app_map_number());
    }
    check(sawFell, "a country fell on the way");
    app_shutdown();
    printf(failures ? "%d failed\n" : "all passed\n", failures);
    return failures != 0;
}
