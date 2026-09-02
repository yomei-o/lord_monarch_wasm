#!/bin/sh
# Build everything.  There is no make on this machine and no node on PATH, so
# the Makefile is a description rather than something that runs; this is the
# thing that does.
#
#   sh tools/build.sh          native tools and the wasm
#   sh tools/build.sh native   just the native side
#   sh tools/build.sh wasm     just monarch.js / monarch.wasm
set -e
cd "$(dirname "$0")/.."

EMSDK=C:/prog/emsdk/emsdk
# A PATH entry has to be a POSIX path here; "C:/..." is not looked up.
PATH="/c/prog/emsdk/emsdk/node/22.16.0_64bit/bin:$PATH"
export PATH

CC="sh tools/cc.sh -O2 -Wall -Wextra -std=c99"
CORE="src/disk.c src/gfx.c src/bz.c src/lmz.c"
SND="src/sound.c src/ssg.c src/opn.c"
APP="src/app.c src/game.c $SND $CORE"

mkdir -p tmp
IMG=$(ls orig/*.FIM | head -1)
[ -f tmp/monarch.fim ] || cp "$IMG" tmp/monarch.fim

what=${1:-all}

if [ "$what" = all ] || [ "$what" = native ]; then
    echo "== native"
    $CC -o tmp/monarch_shot.exe src/main_shot.c src/png.c $APP
    $CC -Isrc -o tmp/game_check.exe  tests/game_check.c  src/game.c $CORE
    $CC -Isrc -o tmp/app_check.exe   tests/app_check.c   $APP
    $CC -Isrc -o tmp/sound_check.exe tests/sound_check.c $SND $CORE
    $CC -Isrc -o tmp/song_wav.exe    tests/song_wav.c    $SND $CORE
    $CC -Isrc -o tmp/sim.exe         tests/sim.c         src/game.c $CORE
    $CC -Isrc -o tmp/probe.exe       tests/probe.c       src/game.c $CORE
fi

if [ "$what" = all ] || [ "$what" = wasm ]; then
    echo "== wasm"
    "$EMSDK/upstream/emscripten/emcc.exe" -O2 -std=c99 -o monarch.js \
        src/main_wasm.c $APP \
        --embed-file tmp/monarch.fim@/monarch.fim \
        --embed-file font/shinonome.fnt@/shinonome.fnt \
        -s MODULARIZE=1 -s EXPORT_NAME=LordMonarch \
        -s EXPORTED_RUNTIME_METHODS=ccall,cwrap,UTF8ToString,HEAPU8,HEAPU32 \
        -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=web,worker,node
    # The page carries the build's hash so a browser cannot pair one build's
    # monarch.js with another's monarch.wasm.
    python tools/stamp.py monarch.wasm index.html
fi

echo "-> tmp/"
