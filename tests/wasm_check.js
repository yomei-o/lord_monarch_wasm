// Runs the WASM build under node and dumps raw frames, so the browser build can
// be checked against the native one without a browser.
//
//   node tests/wasm_check.js
//
// The point is that docs/monarch.js is the same C as tmp/monarch.exe; if the
// frames differ, something in the host layer is wrong rather than in the game.
// tests/compare.py then diffs these against the PNGs the native tool writes.
const fs = require('fs');
const path = require('path');

const root = path.join(__dirname, '..');
const LordMonarch = require(path.join(root, 'monarch.js'));

// APP_KEY_* from src/app.h.
const KEY = {
  START: 1, PREV_MAP: 2, NEXT_MAP: 3, LEFT: 4, RIGHT: 5, UP: 6, DOWN: 7,
  TILE8: 8, TILE16: 9, TILE32: 10, BACK: 11,
};

function dump(m, name) {
  m._lm_render();
  const p = m._lm_framebuffer();
  const w = m._lm_width(), h = m._lm_height();
  // A copy, not a view: the wasm heap is reused by the next render.
  const px = Buffer.from(m.HEAPU8.subarray(p, p + w * h * 4));
  const out = path.join(root, 'tmp', name);
  fs.writeFileSync(out, px);
  const status = m.UTF8ToString(m._lm_status());
  console.log(`${name}  ${w}x${h}  ${status}`);
  return px;
}

LordMonarch().then((m) => {
  if (!m._lm_init()) {
    console.error('lm_init failed: ' + m.UTF8ToString(m._lm_status()));
    process.exit(1);
  }
  const title = dump(m, 'wasm_title.raw');

  m._lm_key(KEY.START);          // title -> map view
  m._lm_key(KEY.TILE8);
  const map0 = dump(m, 'wasm_map000.raw');

  // B_014 is terrain 50, the pencil kingdom - a different palette, so this also
  // checks that a palette swap reaches the frame.
  for (let i = 0; i < 14; i++) m._lm_key(KEY.NEXT_MAP);
  const map14 = dump(m, 'wasm_map014.raw');

  const distinct = (b) => new Set(
    Array.from({length: b.length / 4}, (_, i) => b.readUInt32LE(i * 4))).size;
  console.log(`distinct colours: title ${distinct(title)}, ` +
              `map000 ${distinct(map0)}, map014 ${distinct(map14)}`);
  if (distinct(title) < 4 || distinct(map14) < 6) {
    console.error('a frame came out nearly blank');
    process.exit(1);
  }
  console.log('ok');
}).catch((e) => { console.error(e); process.exit(1); });
