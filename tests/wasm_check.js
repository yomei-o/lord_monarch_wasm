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
  TILE8: 8, TILE16: 9, TILE32: 10, BACK: 11, CASTLES: 12, RUN: 13, STEP: 14,
  TITLE: 15,
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

  // The panel and its dialogs.  Two columns at x 8 and 40, seven rows, 32x32 -
  // the geometry in app.c.  What a command answers has to appear in a dialog on
  // the game's own screen, not in the host's status line, so these check
  // lm_dialog rather than the text under the canvas.
  const DLG = {NONE: 0, INFO: 1, TAX: 2, SPEED: 3, ZOOM: 4, ALLY: 5, ORDER: 6};
  m._lm_key(KEY.TILE16);
  const icon = (idx) => {
    const col = [8, 40][idx % 2], row = [24, 56, 120, 184, 248, 280, 312][idx >> 1];
    m._lm_click(col + 16, row + 16);
    return m.UTF8ToString(m._lm_status());
  };
  const dlgText = () => {
    const out = [];
    for (let i = 0; i < m._lm_dialog_lines(); i++)
      out.push(m.UTF8ToString(m._lm_dialog_line(i)));
    return out.join(' | ');
  };
  let panelFailed = 0;
  const wantDialog = [
    [3, DLG.INFO,  'INFO'],
    [2, DLG.TAX,   'TAX'],
    [4, DLG.SPEED, 'SPEED'],
    [5, DLG.ZOOM,  'ZOOM'],
    [6, DLG.ALLY,  'ALLY'],
  ];
  for (const [idx, want, what] of wantDialog) {
    icon(idx);
    const got = m._lm_dialog();
    const ok = got === want;
    if (!ok) panelFailed++;
    console.log(`${ok ? 'ok  ' : 'FAIL'}  icon ${idx} ${what} opened dialog ` +
                `${got}: ${dlgText().slice(0, 60)}`);
    m._lm_key(KEY.BACK);                  // cancel it again
    if (m._lm_dialog() !== DLG.NONE) {
      panelFailed++;
      console.log('FAIL  cancel did not close it');
    }
  }
  // GO has no dialog: it just starts the world.
  let st = icon(0);
  const goOk = /^GO: /.test(st) && m._lm_dialog() === DLG.NONE;
  if (!goOk) panelFailed++;
  console.log(`${goOk ? 'ok  ' : 'FAIL'}  icon 0 GO: ${st}`);
  icon(0);                                 // and back to paused

  // A choice in a dialog has to take effect.  SPEED: FAST, NORMAL, SLOW.
  icon(4);
  m._lm_key(KEY.DOWN);
  m._lm_key(KEY.DOWN);
  m._lm_key(KEY.START);
  st = m.UTF8ToString(m._lm_status());
  const slowOk = /speed slow/.test(st) && m._lm_dialog() === DLG.NONE;
  if (!slowOk) panelFailed++;
  console.log(`${slowOk ? 'ok  ' : 'FAIL'}  choosing the third line: ${st}`);
  icon(4); m._lm_key(KEY.START);           // back to fast

  // The ones this port does not do say so instead of doing nothing.
  for (const [idx, what] of [[7, 'EDIT'], [11, 'FORM']]) {
    st = icon(idx);
    const ok = st.indexOf(what) === 0;
    if (!ok) panelFailed++;
    console.log(`${ok ? 'ok  ' : 'FAIL'}  icon ${idx} ${what}: ${st}`);
  }

  // A click on the map presses no icon.
  st = m.UTF8ToString(m._lm_status());
  m._lm_click(300, 200);
  console.log(`${m._lm_dialog() === DLG.NONE ? 'ok  ' : 'FAIL'}  ` +
              `a click on the map opens no dialog`);
  m._lm_key(KEY.BACK);
  m._lm_key(KEY.BACK);
  if (panelFailed) {
    console.error(`${panelFailed} panel failure(s)`);
    process.exit(1);
  }

  // Bridges, through the same clicks a person makes.  B_014 is the spiral: side
  // 0's castle is at 14,2, its worker sits in the gate at 14,3, and 12,4 is
  // water.  At 16x16 with the view unscrolled a cell is at
  // (96 + x*16 + 8, 8 + y*16 + 8).
  // PREV_MAP wraps, so walk from a known point: the title, then map 0.
  // (BACK is the original's cancel now - it opens the panel - so the way back
  // to the title is its own key.)
  m._lm_key(KEY.TITLE);
  m._lm_key(KEY.START);
  for (let i = 0; i < 14; i++) m._lm_key(KEY.NEXT_MAP);
  m._lm_key(KEY.TILE16);
  const cell = (x, y) => [96 + x * 16 + 8, 8 + y * 16 + 8];
  m._lm_click(...cell(14, 3));
  const picked = m._lm_selected();
  console.log(`${picked >= 0 ? 'ok  ' : 'FAIL'}  the gate worker is selected ` +
              `(slot ${picked})`);
  if (picked < 0) process.exit(1);
  // Naming a destination puts the order menu up, as sub_20f0 does, and the
  // choices are the ones that square allows.
  m._lm_click(...cell(12, 4));
  const menu = dlgText();
  const menuOk = m._lm_dialog() === DLG.ORDER && /BRIDGE IT/.test(menu);
  console.log(`${menuOk ? 'ok  ' : 'FAIL'}  the order menu offers a bridge: ${menu}`);
  if (!menuOk) process.exit(1);
  m._lm_key(KEY.DOWN);            // WALK THERE -> BRIDGE IT
  m._lm_key(KEY.START);
  const bridged = m.UTF8ToString(m._lm_status());
  const bridgeOk = /^bridge 12,4/.test(bridged);
  console.log(`${bridgeOk ? 'ok  ' : 'FAIL'}  and choosing it gives the order: ` +
              `${bridged}`);
  if (!bridgeOk) process.exit(1);

  // Keyboard only, all the way to an order.  B_014 side 0's castle is at 14,2
  // and the cursor starts on the gate below it at 14,3, holding a worker.
  m._lm_key(KEY.TITLE);
  m._lm_key(KEY.START);
  for (let i = 0; i < 14; i++) m._lm_key(KEY.NEXT_MAP);
  m._lm_key(KEY.TILE16);
  st = m.UTF8ToString(m._lm_status());
  console.log(`${/^B_014/.test(st) ? 'ok  ' : 'FAIL'}  keys reached B_014: ${st}`);

  m._lm_key(KEY.START);           // confirm on the gate: pick the worker up
  st = m.UTF8ToString(m._lm_status());
  const pickedByKey = m._lm_selected() >= 0;
  console.log(`${pickedByKey ? 'ok  ' : 'FAIL'}  confirm picked a unit up: ${st}`);
  if (!pickedByKey) process.exit(1);

  // Walk the cursor onto the water at 12,4 and confirm: a bridge order.
  m._lm_key(KEY.LEFT); m._lm_key(KEY.LEFT); m._lm_key(KEY.DOWN);
  m._lm_key(KEY.START);
  const keyMenuOk = m._lm_dialog() === DLG.ORDER;
  console.log(`${keyMenuOk ? 'ok  ' : 'FAIL'}  confirm put the order menu up: ` +
              `${dlgText().slice(0, 60)}`);
  if (!keyMenuOk) process.exit(1);
  m._lm_key(KEY.DOWN);
  m._lm_key(KEY.START);
  st = m.UTF8ToString(m._lm_status());
  const bridgedByKey = /^bridge 12,4/.test(st);
  console.log(`${bridgedByKey ? 'ok  ' : 'FAIL'}  and the order was given: ${st}`);
  if (!bridgedByKey) process.exit(1);

  // Pushing the cursor off the left of the map opens the panel.
  for (let i = 0; i < 20; i++) m._lm_key(KEY.LEFT);
  st = m.UTF8ToString(m._lm_status());
  const inPanel = /^panel: /.test(st);
  console.log(`${inPanel ? 'ok  ' : 'FAIL'}  the left edge opened the panel: ${st}`);
  if (!inPanel) process.exit(1);

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
