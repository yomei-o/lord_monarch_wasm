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

#define DLG_TAX     2
#define DLG_ALLY    5
#define DLG_FELL    7
#define DLG_OVER    8
#define DLG_REFUSED 9
#define DLG_VIEW    10
#define DLG_MAPSEL  11

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

    /* The look-around at 0x1b5f is a loop of its own, not a mode that stays on:
     * the arrows are the cursor's while it is up and either button leaves. */
    /* The columns are x 16..47 and 48..79 and the rows start at y 24, so
     * ICON_VIEW - index 1 - is row 0 column 1. */
    app_click(64, 40);                          /* ICON_VIEW */
    check(app_dialog() == DLG_VIEW, "the view icon opens the look-around");
    app_key(APP_KEY_RIGHT);
    check(app_dialog() == DLG_VIEW, "the arrows do not close it");
    app_key(APP_KEY_BACK);
    check(app_dialog() == 0, "and either button does");

    /* 0x1cb0 is the one command with all three guards, and sub_b52e is the one
     * that matters here: the alliance cannot be touched once the stage is under
     * way.  Before GO it opens. */
    app_click(24, 200);                         /* ICON_ALLY, row 3 column 0 */
    check(app_dialog() == DLG_ALLY, "the alliance opens before the stage starts");
    app_key(APP_KEY_BACK);

    /* 0x1e0f is a list of what is on the disk, not a step to the next stage.
     * Fifty-two will not fit in a box, so the box scrolls: 0x4ccd moves it down
     * when the selection reaches the bottom line. */
    app_click(64, 264);                         /* ICON_MAP, row 4 column 1 */
    check(app_dialog() == DLG_MAPSEL, "the map icon opens a list of stages");
    {
        int lines = app_dialog_lines(), k;
        char firstShown[40];

        snprintf(firstShown, sizeof firstShown, "%s", app_dialog_line(3));
        for (k = 0; k < 12; k++) app_key(APP_KEY_DOWN);
        check(strcmp(firstShown, app_dialog_line(3)) != 0,
              "and walking down it scrolls the box");
        check(app_dialog_lines() == lines,
              "while the box stays the same size");
    }
    app_key(APP_KEY_BACK);
    check(app_dialog() == 0, "cancel leaves the stage alone");
    check(app_map_number() == 0, "and it is still map 0");

    app_key(APP_KEY_RUN);
    check(app_running(), "GO starts the world");

    /* GO is what sets [0x3bd4], so this is the icon rather than the R key. */
    app_click(24, 40);                          /* ICON_GO, row 0 column 0 */
    app_click(24, 200);                         /* ICON_ALLY again */
    check(app_dialog() == DLG_REFUSED,
          "and sub_b52e refuses it once the stage is under way");
    app_key(APP_KEY_START);

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
        /* The distinguishing rule: 0xb3e3 only moves [0xce70] when the stage
         * just cleared was the furthest, and 0x6315 then enters whatever
         * [0xce70] names.  So the stage that comes up is the counter, not the
         * one after the stage played - clear stage 5 having reached 10 and you
         * are put back on 10. */
        check(app_reached() == was + 1, "the reached counter moved with it");
        check(app_map_number() == app_reached(),
              "and the stage entered is the one the counter names");
        check(app_running(), "already running, the way sub_6315 leaves it");
        printf("map %d won after %d frames, now on map %d\n",
               was, overAt, app_map_number());
    }
    check(sawFell, "a country fell on the way");

    /* The alliance last, and on a stage of its own, because striking one cannot
     * be undone from inside the game - the menu is four countries with no
     * "none" line - and a stage reloaded to clear it would put the tax back to
     * ten and stop the run above from being the run that was measured. */
    app_show_map(0, 16);
    app_click(24, 200);                         /* ICON_ALLY */
    check(app_dialog() == DLG_ALLY, "the alliance opens again on a fresh stage");
    /* Four countries are listed, by their own names, and 0x1ccb has already
     * moved the selection off your own before the window opened. */
    check(app_dialog_lines() == 2 + 4,
          "the alliance lists all four countries");
    /* 0x1d0c: choosing your own country does nothing at all - no sound, no
     * message, the window stays.  The selection starts on country 1, so
     * walking up to 0 and confirming is choosing yourself. */
    app_key(APP_KEY_UP);
    app_key(APP_KEY_START);
    check(app_dialog() == DLG_ALLY, "choosing your own country changes nothing");
    /* And a real one is struck.  At the start of a stage every country holds
     * the same, and 0x1d2d accepts equal - "jae" - so this one goes through
     * and the message names two pairs, not one. */
    app_key(APP_KEY_DOWN);
    app_key(APP_KEY_START);
    check(app_dialog() != DLG_ALLY, "an alliance with country 1 is struck");
    {
        int k, said = 0;
        for (k = 0; k < app_dialog_lines(); k++) {
            const char *l = app_dialog_line(k);
            if (l[0]) said++;
            printf("      | %s\n", l);
        }
        check(said >= 4, "the alliance message names both pairs");
    }
    app_key(APP_KEY_BACK);
    /* The alliance sticks, and there is no way in the game to undo one - the
     * menu has four countries and no "none" line.  So the stage is loaded again
     * before the rest of this runs, which is what game_init does to the side
     * records anyway. */
    app_shutdown();
    printf(failures ? "%d failed\n" : "all passed\n", failures);
    return failures != 0;
}
