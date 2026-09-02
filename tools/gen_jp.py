# Generates src/jp.h: every string the dialogs show, in English and in the
# original's own Shift-JIS, written as hex escapes so the C source stays ASCII.
pairs = [
    ("JP_INFO_TITLE",   "THE FOUR COUNTRIES", "四つの国"),
    ("JP_INFO_HEAD",    "     LAND  HELD   FUNDS",
                        "      領地  保有    資金"),
    ("JP_GONE",         "GONE", "滅亡"),
    ("JP_TAX_TITLE",    "TAX RATE - NOW %d OF 256",
                        "税率 ― いま %d / 256"),
    ("JP_TAX_ITEM",     "%2d OF 256 PER SQUARE", "1升あたり %2d / 256"),
    ("JP_SPEED_TITLE",  "SPEED", "速度"),
    ("JP_FAST",         "FAST", "速    い"),
    ("JP_NORMAL",       "NORMAL", "普    通"),
    ("JP_SLOW",         "SLOW", "遅    い"),
    ("JP_ZOOM_TITLE",   "SQUARE SIZE", "拡大縮小"),
    ("JP_ZOOM16",       "16 X 16", "16 × 16"),
    ("JP_ZOOM32",       "32 X 32", "32 × 32"),
    ("JP_ZOOM8",        "8 X 8   (WHOLE MAP)", "8 × 8　全体"),
    ("JP_ALLY_TITLE",   "ALLIANCE", "同盟"),
    ("JP_ALLY_ITEM",    "ALLY WITH COUNTRY %d", "第%d国と同盟"),
    ("JP_ALLY_NOW",     "   (NOW)", "  （現在）"),
    ("JP_ALLY_NONE",    "NO ALLIANCE", "同盟しない"),
    ("JP_CLOSE",        "CLOSE", "閉じる"),
    ("JP_ORDER_TITLE",  "SQUARE %d,%d - TILE %02x", "座標 : %d , %d   %02x"),
    ("JP_WALK",         "WALK THERE", "ここまで進軍"),
    ("JP_BRIDGE",       "BRIDGE IT  30 A DEPTH", "橋を掛ける"),
    ("JP_FELL",         "CLEAR THE WOOD", "林を伐る"),
    ("JP_THICKEN",      "THICKEN THE WOOD", "林を育てる"),
    ("JP_PLANT",        "PLANT A WOOD", "林を作る"),
    ("JP_ATTACK",       "ATTACK THE GROUND", "土地を攻める"),
    ("JP_BREAK",        "BREAK THE BRIDGE", "橋を壊す"),
    ("JP_NEST",         "PULL THE NEST DOWN", "巣を潰す"),
    ("JP_NOTHING",      "NOTHING", "何もしない"),
    ("JP_PANEL",        "PANEL", "パネル"),
]

def esc(t):
    b = t.encode('cp932')
    out = []
    for ch in b:
        if 0x20 <= ch < 0x7f and chr(ch) not in '"\\%':
            out.append(chr(ch))
        elif chr(ch) == '%':
            out.append('%')
        elif chr(ch) in '"\\':
            out.append('\\' + chr(ch))
        else:
            out.append('\\x%02x' % ch)
    # a hex escape swallows following hex digits, so break the string there
    s = ''
    prev_hex = False
    for piece in out:
        if prev_hex and (piece[0] in '0123456789abcdefABCDEF') and len(piece) == 1:
            s += '" "'
        s += piece
        prev_hex = piece.startswith('\\x')
    return '"' + s + '"'

lines = []
lines.append('/* Every word the dialogs show, twice: the original wrote them in')
lines.append(' * Shift-JIS and the kanji live in the PC-98 font ROM, so with a ROM')
lines.append(' * loaded the port says what the game says and without one it falls')
lines.append(' * back to English.  Generated, and escaped, so this file stays ASCII')
lines.append(' * whatever an editor decides to do with it. */')
lines.append('#ifndef JP_H')
lines.append('#define JP_H')
lines.append('')
lines.append('/* jp(a, b) picks by whether a font ROM is loaded. */')
lines.append('#define JP2(en, jp) (app_japanese() ? (jp) : (en))')
lines.append('')
for name, en, jp in pairs:
    lines.append('#define %-16s JP2(%s, %s)' % (name, esc(en), esc(jp)))
lines.append('')
lines.append('#endif')
open('src/jp.h', 'w', encoding='ascii', newline='\n').write('\n'.join(lines) + '\n')
print('wrote src/jp.h with', len(pairs), 'strings')
