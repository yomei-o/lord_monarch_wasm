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

  // The panel.  Two columns at x 8 and 40, seven rows, 32x32 - the geometry in
  // app.c.  Pressing one has to change what lm_status says, because that is the
  // only thing a headless run can see; a hit test that misses would leave the
  // status on the map line.
  m._lm_key(KEY.TILE16);
  const icon = (idx) => {
    const col = [8, 40][idx % 2], row = [24, 56, 120, 184, 248, 280, 312][idx >> 1];
    m._lm_click(col + 16, row + 16);
    return m.UTF8ToString(m._lm_status());
  };
  let panelFailed = 0;
  const want = [
    [0, /^GO: /,            'GO'],
    [1, /^VIEW mode/,       'VIEW'],
    [2, /^tax rate/,        'TAX'],
    [3, /^INFO/,            'INFO'],
    [4, /^speed/,           'SPEED'],
    [6, /ALLY is in the original/, 'ALLY (not ported)'],
    [7, /EDIT is in the original/, 'EDIT (not ported)'],
    [11, /FORM is in the original/, 'FORM (not ported)'],
  ];
  for (const [idx, re, what] of want) {
    const got = icon(idx);
    const ok = re.test(got);
    if (!ok) panelFailed++;
    console.log(`${ok ? 'ok  ' : 'FAIL'}  icon ${idx} ${what}: ${got}`);
  }
  // ZOOM and MAP reload the view, so they report a map line rather than their
  // own message; check the thing they change instead.
  const before = m.UTF8ToString(m._lm_status());
  icon(5);
  const zoomed = m.UTF8ToString(m._lm_status());
  const zoomOk = /32x32/.test(zoomed) || /8x8/.test(zoomed);
  if (!zoomOk) panelFailed++;
  console.log(`${zoomOk ? 'ok  ' : 'FAIL'}  icon 5 ZOOM: ${zoomed}`);
  icon(9);
  const mapped = m.UTF8ToString(m._lm_status());
  const mapOk = /^B_015[.]MAP/.test(mapped);
  if (!mapOk) panelFailed++;
  console.log(`${mapOk ? 'ok  ' : 'FAIL'}  icon 9 MAP: ${mapped}`);
  // A point that is not on any icon must not press one.
  m._lm_click(300, 200);
  const off = m.UTF8ToString(m._lm_status());
  const offOk = off === mapped;
  if (!offOk) panelFailed++;
  console.log(`${offOk ? 'ok  ' : 'FAIL'}  a click on the map presses nothing`);
  if (panelFailed) {
    console.error(`${panelFailed} panel failure(s)`);
    process.exit(1);
  }

  // Bridges, through the same clicks a person makes.  B_014 is the spiral: side
  // 0's castle is at 14,2, its worker sits in the gate at 14,3, and 12,4 is
  // water.  At 16x16 with the view unscrolled a cell is at
  // (96 + x*16 + 8, 8 + y*16 + 8).
  icon(1);                       // VIEW was left on by the panel checks above
  // PREV_MAP wraps, so walk from a known point: the title, then map 0.
  m._lm_key(KEY.BACK);
  m._lm_key(KEY.START);
  for (let i = 0; i < 14; i++) m._lm_key(KEY.NEXT_MAP);
  m._lm_key(KEY.TILE16);
  const cell = (x, y) => [96 + x * 16 + 8, 8 + y * 16 + 8];
  m._lm_click(...cell(14, 3));
  const picked = m._lm_selected();
  console.log(`${picked >= 0 ? 'ok  ' : 'FAIL'}  the gate worker is selected ` +
              `(slot ${picked})`);
  if (picked < 0) process.exit(1);
  m._lm_click(...cell(12, 4));
  const bridged = m.UTF8ToString(m._lm_status());
  const bridgeOk = /^bridge 12,4: \d+ squares to the shore, then 30 funds/
      .test(bridged);
  console.log(`${bridgeOk ? 'ok  ' : 'FAIL'}  clicking water orders a bridge: ` +
              `${bridged}`);
  if (!bridgeOk) process.exit(1);

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
