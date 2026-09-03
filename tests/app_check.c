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

#define DLG_INFO    1
#define DLG_TAX     2
#define DLG_SPEED   3
#define DLG_SAVE    15
#define DLG_LOAD    16
#define DLG_KING    18
#define DLG_ALLYBROKE 19
#define DLG_ALLY    5
#define DLG_FELL    7
#define DLG_OVER    8
#define DLG_REFUSED 9
#define DLG_VIEW    10
#define DLG_MAPSEL  11

static int failures;

/* The four playable countries.  game.h is not included here - this test drives
 * the app through its own interface only - so the number is written out. */
#define PLAYERS_HERE 4

static void check(int ok, const char *what)
{
    if (!ok) { printf("FAIL: %s\n", what); failures++; }
    else printf("ok:   %s\n", what);
}

static void checkf(int ok, const char *fmt, int a, int b, int c)
{
    if (!ok) {
        printf("FAIL: ");
        printf(fmt, a, b, c);
        printf("\n");
        failures++;
    } else {
        printf("ok:   ");
        printf(fmt, a, b, c);
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    long f;
    int sawFell = 0, fellRan = 0, overAt = -1, sawKing = 0, kingFirst = 0;
    int sawAllyBroke = 0;

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

    /* The three knob windows do not agree about cancel, and both readings come
     * straight off the loops: 0x53f1 and 0x5309 put back the byte they saved on
     * the way in, while 0x4f66 restores nothing at all.  Since every move has
     * already been written to the live byte, a cancelled tax is a set tax.
     */
    app_click(24, 64);                          /* ICON_TAX */
    check(app_dialog() == DLG_TAX, "the tax window opens again");
    app_key(APP_KEY_RIGHT);
    app_key(APP_KEY_RIGHT);
    app_key(APP_KEY_RIGHT);
    check(strstr(app_dialog_line(3), " 3") != NULL,
          "three notches up from nought is three");
    app_key(APP_KEY_BACK);                      /* 0x4f66 - cancel */
    check(app_dialog() == 0, "cancel closes the tax window");
    checkf(app_tax() == 3,
           "cancel left the tax at %d - 0x4f66 restores nothing",
           app_tax(), 0, 0);
    /* Put it back where the run below wants it. */
    app_click(24, 64);
    {
        int k;
        for (k = 0; k < 60; k++) app_key(APP_KEY_LEFT);
    }
    app_key(APP_KEY_START);

    /* Speed is the other way round. */
    {
        int was;

        app_click(24, 128);                     /* ICON_SPEED, row 2 column 0 */
        check(app_dialog() == DLG_SPEED, "the speed window opens");
        was = app_speed();
        app_key(APP_KEY_DOWN);
        checkf(app_speed() != was,
               "the knob moved and the world is at speed %d already",
               app_speed(), 0, 0);
        app_key(APP_KEY_BACK);                  /* 0x53f1 - cancel restores */
        checkf(app_speed() == was, "cancel put the speed back to %d from %d",
               app_speed(), was, 0);
    }

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
        /* 0xaa50 puts the king's window up and only then calls sub_b102 at
         * 0xaa67, so the king is announced before the country.  Seeing the
         * country's window without having seen a king's would mean the port
         * had lost that order. */
        if (d == DLG_KING) {
            if (!sawKing) {
                sawKing = 1;
                kingFirst = !sawFell;
                printf("      | %s\n", app_dialog_line(0));
            }
            app_key(APP_KEY_START);
            continue;
        }
        /* 0xb230: the second fall dissolves what the two survivors had. */
        if (d == DLG_ALLYBROKE) {
            if (!sawAllyBroke) {
                sawAllyBroke = 1;
                printf("      | %s\n", app_dialog_line(0));
                printf("      | %s\n", app_dialog_line(1));
            }
            app_key(APP_KEY_START);
            continue;
        }
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
            printf("      | %s\n", app_dialog_line(0));
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
    check(sawKing, "and its king was announced first");
    check(kingFirst, "the king's window came before the country's");

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
    /* The country readout.  Both of its lines are the game's own templates,
     * DS:0x1a54 and DS:0x1a74, run through the format engine, so this checks
     * the numbers that come out of it rather than any wording: four countries
     * at three lines each, and the four shares of the land adding up to a
     * hundred, because 0x503a works each one out as sub_bcce over sub_bc99.
     *
     * A fresh stage first, and some ticks, because sub_a6a5 is what puts a
     * total in the side records and before the first sweep every share is
     * nought over nought.
     */
    {
        int k, lines, found = 0, tenths = 0;

        app_show_map(0, 16);
        for (k = 0; k < 400; k++) app_key(APP_KEY_STEP);
        app_click(64, 72);                      /* ICON_INFO, row 1 column 1 */
        check(app_dialog() == DLG_INFO, "the info icon opens the readout");
        lines = app_dialog_lines();
        check(lines == PLAYERS_HERE * 3,
              "four countries at a name and two lines each");
        for (k = 0; k < lines; k++) {
            const char *l = app_dialog_line(k);
            const char *dot = strchr(l, '.');

            printf("      | %s\n", l);
            /* "@3b.@1b%" - the whole percent, a dot, the tenth, a per cent
             * sign - is the only place a dot is followed by one digit and a
             * percent, so this finds the share without knowing the column. */
            if (dot && dot[1] >= '0' && dot[1] <= '9' && dot[2] == '%') {
                int whole = 0;
                const char *d = dot;

                while (d > l && d[-1] >= '0' && d[-1] <= '9') d--;
                while (d < dot) whole = whole * 10 + (*d++ - '0');
                tenths += whole * 10 + (dot[1] - '0');
                found++;
            }
        }
        check(found == PLAYERS_HERE, "every country states its share");
        checkf(tenths >= 995 && tenths <= 1005,
               "the four shares come to %d tenths of a per cent",
               tenths, 0, 0);
        app_key(APP_KEY_START);
        check(app_dialog() == 0, "and any key closes it");
    }

    /* SAVE and LOAD.  The list is the game's own - DS:0x10bd's one template
     * indexed by line number over the twelve-byte directory at DS:0xf67e - and
     * what goes in a slot is the port's own shape, because there is no floppy
     * here to be byte-compatible with.  What this checks is that the round trip
     * puts the world back where it was.
     *
     * The icons are column 0 of rows 4 and 5: LOAD is index 8 and SAVE 10, and
     * the rows start at y 248 and 280.
     */
    {
        int k, was, later;

        app_show_map(0, 16);
        app_key(APP_KEY_RUN);
        for (k = 0; k < 300; k++) app_render();
        was = app_day();
        checkf(was > 0, "the world reached day %d before saving",
               was, 0, 0);

        app_click(24, 288);                     /* ICON_SAVE */
        check(app_dialog() == DLG_SAVE, "the save icon opens the slot list");
        check(app_dialog_lines() == 2 + 10,
              "ten of the eighty slots are shown");
        check(strstr(app_dialog_line(2), "----") != NULL,
              "slot one starts empty");
        app_key(APP_KEY_START);                 /* write slot one */
        check(app_dialog() == DLG_SAVE, "the list stays up after a save");
        {
            const char *l = app_dialog_line(2);
            printf("      | %s\n", l);
            check(strstr(l, "MAP-No.") != NULL,
                  "and slot one now names a stage");
        }
        app_key(APP_KEY_BACK);
        check(app_dialog() == 0, "cancel is what leaves the list");

        for (k = 0; k < 600; k++) app_render();
        later = app_day();
        checkf(later != was, "the world moved from day %d to %d after the save",
               was, later, 0);

        app_click(24, 256);                     /* ICON_LOAD */
        check(app_dialog() == DLG_LOAD, "the load icon opens the same list");
        app_key(APP_KEY_START);
        check(app_dialog() == 0, "loading closes the list");
        checkf(app_day() == was, "the load put the day back to %d from %d",
               app_day(), was, 0);

        /* 0x1f39: an empty slot cannot be chosen - the list stays up. */
        app_click(24, 256);
        for (k = 0; k < 5; k++) app_key(APP_KEY_DOWN);
        app_key(APP_KEY_START);
        check(app_dialog() == DLG_LOAD, "an empty slot cannot be loaded");
        app_key(APP_KEY_BACK);
    }

    app_shutdown();
    printf(failures ? "%d failed\n" : "all passed\n", failures);
    return failures != 0;
}
