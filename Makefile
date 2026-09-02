# Native and WASM builds.
#
# mingw from w64devkit for the native side; -mwindows keeps a console off the
# window build, while monarch_shot stays a console tool so a render can be
# checked without a window opening on a desktop somebody is using.
#
# The WASM build bakes the floppy image in with --embed-file, so the page is
# just two files and the disk reader is the same code as the native build's.
CC      ?= gcc
CFLAGS  ?= -O2 -Wall -Wextra -std=c99
OUT     ?= tmp
EMCC    ?= C:/prog/emsdk/emsdk/upstream/emscripten/emcc.exe
# Spelled out rather than "python": Windows ships a Store alias of that name
# which answers and then does nothing.
PYTHON  ?= C:/Python313/python.exe
IMAGE   ?= $(firstword $(wildcard orig/*.FIM))

CORE = src/disk.c src/gfx.c src/bz.c src/lmz.c
APP  = src/app.c src/game.c src/sound.c src/ssg.c $(CORE)

all: $(OUT)/monarch.exe $(OUT)/monarch_shot.exe $(OUT)/game_check.exe $(OUT)/sim.exe $(OUT)/probe.exe $(OUT)/sound_check.exe

$(OUT)/monarch.exe: src/main_win32.c $(APP) | $(OUT)
	$(CC) $(CFLAGS) -mwindows -municode -o $@ $^ -lgdi32

$(OUT)/monarch_shot.exe: src/main_shot.c src/png.c $(APP) | $(OUT)
	$(CC) $(CFLAGS) -o $@ $^

$(OUT)/game_check.exe: tests/game_check.c src/game.c $(CORE) | $(OUT)
	$(CC) $(CFLAGS) -Isrc -o $@ $^

$(OUT)/sim.exe: tests/sim.c src/game.c $(CORE) | $(OUT)
	$(CC) $(CFLAGS) -Isrc -o $@ $^

$(OUT)/probe.exe: tests/probe.c src/game.c $(CORE) | $(OUT)
	$(CC) $(CFLAGS) -Isrc -o $@ $^

$(OUT)/sound_check.exe: tests/sound_check.c src/sound.c src/ssg.c $(CORE) | $(OUT)
	$(CC) $(CFLAGS) -Isrc -o $@ $^ -lm

# The rules, checked against what the disk and the disassembly say.
check: $(OUT)/game_check.exe $(OUT)/sound_check.exe $(OUT)/monarch.fim
	$(OUT)/game_check.exe $(OUT)/monarch.fim
	$(OUT)/sound_check.exe $(OUT)/monarch.fim
	node tests/wasm_check.js
	node tests/page_check.js

$(OUT):
	mkdir -p $(OUT)

# Regenerate the verification renders through the native code path.
shots: $(OUT)/monarch_shot.exe
	sh tools/shots.sh

# GitHub Pages serves the repository root, so index.html, monarch.js and
# monarch.wasm live there; docs/ keeps only the pictures the README uses.
#
# The image on the disk is named in Shift-JIS half-width katakana, which no
# shell here passes through intact, so it is copied to an ASCII name first.
wasm: monarch.js stamp

$(OUT)/monarch.fim: $(IMAGE) | $(OUT)
	cp "$(IMAGE)" $@

# The page carries the build's own hash so a browser cannot serve a monarch.js
# from one build with a monarch.wasm from another - which it will, given the
# chance, and then fail on whichever export was added in between.
stamp: monarch.wasm
	$(PYTHON) tools/stamp.py monarch.wasm index.html

monarch.js: src/main_wasm.c $(APP) $(OUT)/monarch.fim font/shinonome.fnt
	$(EMCC) -O2 -std=c99 -o $@ src/main_wasm.c $(APP) --embed-file $(OUT)/monarch.fim@/monarch.fim --embed-file font/shinonome.fnt@/shinonome.fnt -s MODULARIZE=1 -s EXPORT_NAME=LordMonarch -s EXPORTED_RUNTIME_METHODS=ccall,cwrap,UTF8ToString,HEAPU8,HEAPU32 -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=web,worker,node

clean:
	rm -f $(OUT)/monarch.exe $(OUT)/monarch_shot.exe $(OUT)/game_check.exe $(OUT)/sim.exe monarch.js monarch.wasm

.PHONY: all shots wasm check clean stamp
