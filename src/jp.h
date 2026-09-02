/* Every word the dialogs show, twice: the original wrote them in
 * Shift-JIS and the kanji live in the PC-98 font ROM, so with a ROM
 * loaded the port says what the game says and without one it falls
 * back to English.  Generated, and escaped, so this file stays ASCII
 * whatever an editor decides to do with it. */
#ifndef JP_H
#define JP_H

/* jp(a, b) picks by whether a font ROM is loaded. */
#define JP2(en, jp) (app_japanese() ? (jp) : (en))

#define JP_INFO_TITLE    JP2("THE FOUR COUNTRIES", "\x8el\x82\xc2\x82\xcc\x8d\x91")
#define JP_INFO_HEAD     JP2("     LAND  HELD   FUNDS", "      \x97\xcc\x92n  \x95\xdb\x97L    \x8e\x91\x8b\xe0")
#define JP_GONE          JP2("GONE", "\x96\xc5\x96S")
#define JP_TAX_TITLE     JP2("TAX RATE - NOW %d OF 256", "\x90\xc5\x97\xa6 \x81\\ \x82\xa2\x82\xdc %d / 256")
#define JP_TAX_ITEM      JP2("%2d OF 256 PER SQUARE", "1\x8f\xa1\x82\xa0\x82\xbd\x82\xe8 %2d / 256")
#define JP_SPEED_TITLE   JP2("SPEED", "\x91\xac\x93x")
#define JP_FAST          JP2("FAST", "\x91\xac    \x82\xa2")
#define JP_NORMAL        JP2("NORMAL", "\x95\x81    \x92\xca")
#define JP_SLOW          JP2("SLOW", "\x92x    \x82\xa2")
#define JP_ZOOM_TITLE    JP2("SQUARE SIZE", "\x8ag\x91\xe5\x8fk\x8f\xac")
#define JP_ZOOM16        JP2("16 X 16", "16 \x81~ 16")
#define JP_ZOOM32        JP2("32 X 32", "32 \x81~ 32")
#define JP_ZOOM8         JP2("8 X 8   (WHOLE MAP)", "8 \x81~ 8\x81@\x91S\x91\xcc")
#define JP_ALLY_TITLE    JP2("ALLIANCE", "\x93\xaf\x96\xbf")
#define JP_ALLY_ITEM     JP2("ALLY WITH COUNTRY %d", "\x91\xe6%d\x8d\x91\x82\xc6\x93\xaf\x96\xbf")
#define JP_ALLY_NOW      JP2("   (NOW)", "  \x81i\x8c\xbb\x8d\xdd\x81j")
#define JP_ALLY_NONE     JP2("NO ALLIANCE", "\x93\xaf\x96\xbf\x82\xb5\x82\xc8\x82\xa2")
#define JP_CLOSE         JP2("CLOSE", "\x95\xc2\x82\xb6\x82\xe9")
#define JP_ORDER_TITLE   JP2("SQUARE %d,%d - TILE %02x", "\x8d\xc0\x95W : %d , %d   %02x")
#define JP_WALK          JP2("WALK THERE", "\x82\xb1\x82\xb1\x82\xdc\x82\xc5\x90i\x8cR")
#define JP_BRIDGE        JP2("BRIDGE IT  30 A DEPTH", "\x8b\xb4\x82\xf0\x8a|\x82\xaf\x82\xe9")
#define JP_FELL          JP2("CLEAR THE WOOD", "\x97\xd1\x82\xf0\x94\xb0\x82\xe9")
#define JP_THICKEN       JP2("THICKEN THE WOOD", "\x97\xd1\x82\xf0\x88\xe7\x82\xc4\x82\xe9")
#define JP_PLANT         JP2("PLANT A WOOD", "\x97\xd1\x82\xf0\x8d\xec\x82\xe9")
#define JP_ATTACK        JP2("ATTACK THE GROUND", "\x93y\x92n\x82\xf0\x8dU\x82\xdf\x82\xe9")
#define JP_BREAK         JP2("BREAK THE BRIDGE", "\x8b\xb4\x82\xf0\x89\xf3\x82\xb7")
#define JP_NEST          JP2("PULL THE NEST DOWN", "\x91\x83\x82\xf0\x92\xd7\x82\xb7")
#define JP_NOTHING       JP2("NOTHING", "\x89\xbd\x82\xe0\x82\xb5\x82\xc8\x82\xa2")
#define JP_PANEL         JP2("PANEL", "\x83p\x83l\x83\x8b")

#endif
