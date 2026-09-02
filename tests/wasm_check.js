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
  // The wording depends on whether a font image is present, so this checks the
  // shape of the menu rather than its text: a heading, a blank, and then walk,
  // bridge and nothing.
  const menuOk = m._lm_dialog() === DLG.ORDER && m._lm_dialog_lines() === 5;
  console.log(`${menuOk ? 'ok  ' : 'FAIL'}  the order menu has the three ` +
              `choices water allows (${m._lm_dialog_lines()} lines)`);
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

  // A whole thing played out on the keys the browser sends, because a test that
  // only checks an order was accepted does not show that it finishes.  B_014's
  // side 0 starts with its castle at 14,2 and a worker in the gate at 14,3, and
  // 12,4 is water.
  //
  //   water 0x35  ->  bridge 0x20  ->  rock 0x7a
  //
  // built with order 7 and then pulled down again with order 10, each ordered
  // through the menu the game puts up.
  {
    let cx = 14, cy = 3;
    const move = (x, y) => {
      while (cx > x) { m._lm_key(KEY.LEFT); cx--; }
      while (cx < x) { m._lm_key(KEY.RIGHT); cx++; }
      while (cy > y) { m._lm_key(KEY.UP); cy--; }
      while (cy < y) { m._lm_key(KEY.DOWN); cy++; }
      return m.UTF8ToString(m._lm_status());
    };
    // The status line only says what is under the cursor when the cursor moves,
    // so step off the square and back to read it.
    const look = (x, y) => { move(x + 1, y); return move(x, y); };
    const tile = (x, y) => {
      const hit = /tile ([0-9a-f]{2})/.exec(look(x, y));
      return hit ? parseInt(hit[1], 16) : -1;
    };

    m._lm_key(KEY.TITLE);
    m._lm_key(KEY.START);
    for (let i = 0; i < 14; i++) m._lm_key(KEY.NEXT_MAP);
    m._lm_key(KEY.TILE16);
    cx = 14; cy = 3;

    let t = tile(12, 4);
    let ok = t >= 0x30 && t < 0x60;
    console.log(`${ok ? 'ok  ' : 'FAIL'}  12,4 starts as water (tile ${t.toString(16)})`);
    if (!ok) process.exit(1);

    move(14, 3);                          // reading a tile left the cursor there
    m._lm_key(KEY.START);                 // pick the worker in the gate up
    if (m._lm_selected() < 0) {
      console.error('FAIL  nothing was picked up');
      process.exit(1);
    }
    move(12, 4);
    m._lm_key(KEY.START);                 // the order menu
    m._lm_key(KEY.DOWN);                  // walk -> bridge
    m._lm_key(KEY.START);
    console.log(`ok    ordered: ${m.UTF8ToString(m._lm_status())}`);

    let built = -1;
    for (let i = 0; i < 400 && built < 0; i++) {
      m._lm_key(KEY.STEP);
      if (tile(12, 4) === 0x20) built = i;
    }
    console.log(`${built >= 0 ? 'ok  ' : 'FAIL'}  the bridge went in after ` +
                `${built} ticks`);
    if (built < 0) process.exit(1);

    // The unit that built it is standing on one of the shores.
    let who = null;
    for (const [x, y] of [[13, 4], [12, 3], [12, 5], [11, 4]])
      if (/yours/.test(look(x, y))) { who = [x, y]; break; }
    console.log(`${who ? 'ok  ' : 'FAIL'}  the builder is on the shore at ${who}`);
    if (!who) process.exit(1);

    m._lm_key(KEY.START);
    move(12, 4);
    m._lm_key(KEY.START);
    const lines = m._lm_dialog_lines();
    console.log(`${lines === 5 ? 'ok  ' : 'FAIL'}  a bridge offers walk, break ` +
                `and nothing (${lines} lines)`);
    m._lm_key(KEY.DOWN);                  // walk -> break
    m._lm_key(KEY.START);
    console.log(`ok    ordered: ${m.UTF8ToString(m._lm_status())}`);

    let broke = -1;
    for (let i = 0; i < 800 && broke < 0; i++) {
      m._lm_key(KEY.STEP);
      if (tile(12, 4) === 0x7a) broke = i;
    }
    console.log(`${broke >= 0 ? 'ok  ' : 'FAIL'}  and it came down to a rock ` +
                `after ${broke} ticks`);
    if (broke < 0) process.exit(1);
  }

  // The lord gets no menu - sub_20f0 skips it for anything with bit 0x20 - and
  // it does walk, which it has to: taking a castle means walking your own
  // monarch into it.
  {
    m._lm_key(KEY.TITLE);
    m._lm_key(KEY.START);
    m._lm_key(KEY.TILE16);
    // B_000's side 0 castle is at 8,6 and the cursor starts in the gate at 8,7.
    m._lm_key(KEY.UP);                    // onto the castle, where the lord is
    m._lm_key(KEY.START);
    const picked = m._lm_selected();
    m._lm_key(KEY.DOWN);
    m._lm_key(KEY.DOWN);                  // two below the castle
    m._lm_key(KEY.START);
    const noMenu = m._lm_dialog() === DLG.NONE;
    const st2 = m.UTF8ToString(m._lm_status());
    console.log(`${picked >= 0 && noMenu ? 'ok  ' : 'FAIL'}  the lord takes an ` +
                `order without a menu: ${st2}`);
    if (picked < 0 || !noMenu) process.exit(1);
    for (let i = 0; i < 200; i++) m._lm_key(KEY.STEP);
    const moved = /lord is walking/.test(st2);
    console.log(`${moved ? 'ok  ' : 'FAIL'}  and it is on its way`);
    if (!moved) process.exit(1);
  }

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
