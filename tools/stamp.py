"""Stamps index.html with the build's own hash.

    python tools/stamp.py monarch.wasm index.html

A browser will happily keep a monarch.js from one build and fetch a monarch.wasm
from another, and then fail on whichever export was added in between - which is
exactly what happened once, with "mod._lm_sound is not a function" on a page
whose JS was a build behind.  Putting the hash of the wasm on both URLs makes
that impossible.

This is a two-line job that sed does perfectly well, except that the sed in
w64devkit exits with 0xC00000FF after doing it, which fails the make rule.
"""
import hashlib
import re
import sys


def main():
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    wasm, page = sys.argv[1], sys.argv[2]

    with open(wasm, 'rb') as f:
        tag = hashlib.md5(f.read()).hexdigest()[:8]

    with open(page, encoding='utf-8') as f:
        html = f.read()

    out, n = re.subn(r"window\.LM_BUILD = '[^']*'",
                     "window.LM_BUILD = '%s'" % tag, html)
    if not n:
        raise SystemExit('%s has no window.LM_BUILD to stamp' % page)
    out = re.sub(r'src="monarch\.js(\?v=[^"]*)?"',
                 'src="monarch.js?v=%s"' % tag, out)
    with open(page, 'w', encoding='utf-8', newline='\n') as f:
        f.write(out)
    print('%s stamped %s' % (page, tag))


if __name__ == '__main__':
    main()
