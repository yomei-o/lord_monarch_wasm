#!/bin/sh
# Everything that can say whether this port still matches the disk.
#
#   sh tools/check.sh          build first, then run all four
#   sh tools/check.sh -n       run what is already built
set -e
cd "$(dirname "$0")/.."

# A PATH entry has to be a POSIX path here; "C:/..." is not looked up.
PATH="/c/prog/emsdk/emsdk/node/22.16.0_64bit/bin:$PATH"
export PATH

[ "$1" = -n ] || sh tools/build.sh

echo "== game_check   the rules, against the disk and the disassembly"
./tmp/game_check.exe tmp/monarch.fim
echo "== sound_check  the driver's tables and one rendered effect"
./tmp/sound_check.exe tmp/monarch.fim
echo "== wasm_check   the module under node, frames and songs"
node tests/wasm_check.js
echo "== page_check   index.html's own script against a stub DOM"
node tests/page_check.js
echo "all four passed"
