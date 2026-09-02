// Runs the inline script of docs/index.html under node against a stub DOM, so
// the page is checked without a browser.
//
//   node tests/page_check.js
//
// The wasm module itself is covered by tests/wasm_check.js; what this catches is
// the wiring - a key that reaches nothing, a putImageData that never happens, a
// canvas that stays blank because the module promise was mishandled.  Those are
// exactly the mistakes that only show up in a browser otherwise.
const fs = require('fs');
const path = require('path');
const vm = require('vm');

const root = path.join(__dirname, '..');
const html = fs.readFileSync(path.join(root, 'docs', 'index.html'), 'utf8');

// The page has two script tags: the module loader, then the inline logic.
const inline = [...html.matchAll(/<script>([\s\S]*?)<\/script>/g)].map(m => m[1]);
if (inline.length !== 1) {
  console.error(`expected exactly one inline <script>, found ${inline.length}`);
  process.exit(1);
}

const puts = [];
const handlers = {};
const buttons = [];

function elem(id) {
  return {
    id,
    textContent: '',
    getAttribute: (k) => (k === 'data-key' ? '1' : null),
    addEventListener: (t, f) => { (handlers[id + ':' + t] ||= []).push(f); },
    getContext: () => ({
      createImageData: (w, h) => ({width: w, height: h,
                                   data: new Uint8ClampedArray(w * h * 4)}),
      putImageData: (img) => puts.push(img),
    }),
    width: 640,
    height: 400,
  };
}

const els = {screen: elem('screen'), status: elem('status')};
const raf = [];
const sandbox = {
  console,
  require,
  LordMonarch: require(path.join(root, 'docs', 'monarch.js')),
  requestAnimationFrame: (f) => { raf.push(f); },
  document: {
    getElementById: (id) => els[id] || elem(id),
    querySelectorAll: (sel) => {
      if (sel !== '#buttons button') return [];
      if (!buttons.length)
        for (let i = 0; i < 6; i++) buttons.push(elem('button' + i));
      return buttons;
    },
  },
  window: {
    addEventListener: (t, f) => { (handlers['window:' + t] ||= []).push(f); },
    focus: () => {},
  },
};
sandbox.window.document = sandbox.document;

vm.createContext(sandbox);
vm.runInContext(inline[0], sandbox, {filename: 'index.html inline'});

function pump(n) {
  for (let i = 0; i < n && raf.length; i++) raf.shift()();
}

function press(key, shift) {
  const list = handlers['window:keydown'] || [];
  if (!list.length) throw new Error('nothing is listening for keydown');
  let prevented = false;
  for (const f of list)
    f({key, shiftKey: !!shift, preventDefault: () => { prevented = true; }});
  return prevented;
}

function nonBlank(img) {
  const d = img.data;
  const seen = new Set();
  for (let i = 0; i < d.length; i += 4)
    seen.add((d[i] << 16) | (d[i + 1] << 8) | d[i + 2]);
  return seen.size;
}

setTimeout(() => {
  let failed = 0;
  const check = (ok, what) => {
    console.log(`${ok ? 'ok  ' : 'FAIL'}  ${what}`);
    if (!ok) failed++;
  };

  pump(4);
  check(puts.length > 0, 'the title frame reached putImageData');
  const titleColours = puts.length ? nonBlank(puts[puts.length - 1]) : 0;
  check(titleColours >= 4,
        `the title frame has ${titleColours} distinct colours`);
  check(els.status.textContent.length > 0,
        `status shows "${els.status.textContent}"`);

  check(press(' '), 'space is consumed rather than scrolling the page');
  pump(4);
  const mapColours = nonBlank(puts[puts.length - 1]);
  check(mapColours >= 6, `the map frame has ${mapColours} distinct colours`);
  check(/\.MAP/.test(els.status.textContent),
        `status shows "${els.status.textContent}"`);

  const before = els.status.textContent;
  press('ArrowRight');
  pump(4);
  check(els.status.textContent !== before,
        `right arrow moved on to "${els.status.textContent}"`);

  press('ArrowRight', true);     // shift: scroll, so the map must not change
  const scrolled = els.status.textContent;
  pump(4);
  check(els.status.textContent === scrolled,
        'shift+right scrolls instead of changing map');

  const buttonsWired = (handlers['button0:click'] || []).length > 0;
  check(buttonsWired, 'the on-screen buttons are wired up');

  process.exit(failed ? 1 : 0);
}, 400);
