// The windows a fallen country puts up, in the browser build.
//
//   node tests/fell_wasm.js
const path = require('path');
const root = path.join(__dirname, '..');
const LordMonarch = require(path.join(root, 'monarch.js'));

const KEY = { START: 1, RUN: 13, MONEY: 16 };

LordMonarch().then((m) => {
  if (!m._lm_init()) { console.error('lm_init failed'); process.exit(1); }
  m._lm_render();
  m._lm_key(KEY.START);            // the display question
  m._lm_render();
  m._lm_key(KEY.START);            // the title
  m._lm_render();
  m._lm_key(KEY.RUN);              // GO: load the first stage and run it
  let last = 0, windows = 0, held = 0;
  for (let f = 0; f < 400000 && windows < 10; f++) {
    m._lm_key(KEY.MONEY);
    m._lm_render();
    const d = m._lm_dialog();
    if (d && d !== last) {
      const n = m._lm_dialog_lines();
      const lines = [];
      for (let k = 0; k < n; k++) {
        const p = m._lm_dialog_line(k);
        let end = p;
        while (m.HEAPU8[end]) end++;
        lines.push(Buffer.from(m.HEAPU8.subarray(p, end)).toString('binary'));
      }
      console.log('frame', f, 'window', d, '|',
                  lines.map((t) => Buffer.from(t, 'binary').toString('hex'))
                       .join(' / '));
      windows++;
      held = 0;
    }
    if (d && ++held >= 60) m._lm_key(KEY.START);
    last = d;
  }
  console.log(windows, 'windows');
});
