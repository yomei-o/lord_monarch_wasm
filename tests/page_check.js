// Runs the inline script of index.html under node against a stub DOM, so
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
const html = fs.readFileSync(path.join(root, 'index.html'), 'utf8');

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
    getBoundingClientRect: () => ({left: 0, top: 0, width: 1280, height: 800}),
    width: 640,
    height: 400,
  };
}

// Enough of an AudioContext for the page's own audio path to run.  Without
// one, audioKick() gives up and the music is never asked for at all - which
// is how a check can pass while the thing it is meant to cover does nothing.
const processors = [];
function FakeAudio() {
  const nul = {connect() {}, disconnect() {}};
  return {
    state: 'running',
    sampleRate: 48000,
    currentTime: 0,
    destination: nul,
    resume() { this.state = 'running'; },
    close() {},
    createGain: () => ({
      gain: {value: 1, setValueAtTime() {}, linearRampToValueAtTime() {}},
      connect() {}, disconnect() {},
    }),
    createOscillator: () => ({
      type: '', frequency: {value: 0},
      connect() {}, start() {}, stop() {},
    }),
    createBuffer: (ch, len) => ({
      length: len, getChannelData: () => new Float32Array(len),
    }),
    createBufferSource: () => ({buffer: null, connect() {}, start() {}}),
    createScriptProcessor: (n) => {
      const node = {bufferSize: n, onaudioprocess: null,
                    connect() {}, disconnect() {}};
      processors.push(node);
      return node;
    },
  };
}

const els = {screen: elem('screen'), status: elem('status')};
const raf = [];
const sandbox = {
  console,
  require,
  // The page decodes the game's Shift-JIS with this; without it the dialog
  // headings come back as mojibake and a check on their text is meaningless.
  TextDecoder,
  LordMonarch: require(path.join(root, 'monarch.js')),
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
    TextDecoder,
    AudioContext: FakeAudio,
  },
};
sandbox.window.document = sandbox.document;

vm.createContext(sandbox);
// The inline script keeps the module in a local; hold on to it here so the
// export check below can see what it actually got.
const realModule = sandbox.LordMonarch;
sandbox.LordMonarch = function (opts) {
  return realModule(opts).then((m) => {
    sandbox.LordMonarch.__mod = m;
    return m;
  });
};
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

  // Every lm_* the page calls has to exist on the module.  This is the check
  // that was missing when the page went out calling _lm_sound against a
  // monarch.js that did not have it yet - the browser said
  // "mod._lm_sound is not a function" and nothing here noticed.
  {
    const wanted = [...new Set(html.match(/_lm_[a-z_]+/g) || [])].sort();
    const missing = wanted.filter(
        (n) => typeof sandbox.LordMonarch.__mod?.[n] !== 'function');
    check(wanted.length > 5, `the page calls ${wanted.length} lm_ functions`);
    check(missing.length === 0,
          missing.length ? `the module is missing ${missing.join(', ')}`
                         : 'and the module exports every one of them');
  }

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

  // The arrows move the cursor while playing; choosing a map is on [ and ].
  const before = els.status.textContent;
  press('ArrowRight');
  pump(4);
  check(/tile [0-9a-f]{2} amount/.test(els.status.textContent),
        `the right arrow moved the cursor: "${els.status.textContent}"`);

  press(']');
  pump(4);
  check(els.status.textContent !== before,
        `"]" moved on to "${els.status.textContent}"`);
  press('[');
  pump(4);
  check(/^B_000\.MAP/.test(els.status.textContent),
        '"[" came back to the first map');

  // Keyboard only, the way the original is played: cancel opens the panel,
  // the arrows walk it, confirm presses an icon, cancel comes back.
  check(press('Backspace'), 'cancel is consumed');
  pump(2);
  check(/^panel: GO/.test(els.status.textContent),
        `cancel opened the panel: "${els.status.textContent}"`);
  press('ArrowDown');
  pump(2);
  check(/^panel: TAX/.test(els.status.textContent),
        `down moved two icons on: "${els.status.textContent}"`);
  press('ArrowRight');
  pump(2);
  check(/^panel: INFO/.test(els.status.textContent),
        `right moved a column: "${els.status.textContent}"`);
  press(' ');
  pump(2);
  // sub_4faf draws no heading - each country gets its own little frame - so the
  // readout's first line is a country's name off the floppy, and the wording
  // depends on the tileset.  What is always there is the share of the land,
  // "@3b.@1b%", so that is what this looks for rather than any words.
  check(/^dialog: /.test(els.status.textContent) &&
        /%/.test(els.status.textContent),
        `confirm opened the dialog on the game's own screen: ` +
        `"${els.status.textContent}"`);
  press('Backspace');            // close the dialog
  pump(2);
  press('Backspace');            // and leave the panel
  pump(2);
  check(/back to the map/.test(els.status.textContent),
        'cancel came back to the map');

  // The music.  Everything above has already pressed keys, so the page's
  // AudioContext is awake and bgmSync has had frames to run in.
  {
    pump(4);
    check(processors.length > 0,
          `the page opened ${processors.length} audio node(s) for the music`);
    const node = processors[processors.length - 1];
    check(node && typeof node.onaudioprocess === 'function',
          'and gave it something to pull samples from');
    if (node && node.onaudioprocess) {
      const out = new Float32Array(node.bufferSize);
      let loud = 0, peak = 0;

      // Several buffers: the first tick of a song can legitimately be silent.
      for (let k = 0; k < 8; k++) {
        out.fill(0);
        node.onaudioprocess({outputBuffer: {getChannelData: () => out}});
        for (let i = 0; i < out.length; i++) {
          const v = Math.abs(out[i]);
          if (v > 1e-4) loud++;
          if (v > peak) peak = v;
        }
      }
      check(loud > node.bufferSize,
            `it produced ${loud} sounding samples, peak ${peak.toFixed(3)}`);
      check(peak <= 1.0, 'and nothing clipped past full scale');
    }
  }

  const buttonsWired = (handlers['button0:click'] || []).length > 0;
  check(buttonsWired, 'the on-screen buttons are wired up');

  // The pointer.  The canvas is presented at 1280 x 800, so client pixels have
  // to come back to the frame's 640 x 400 - a click at 1280,... lands at 640.
  const point = (t, cx, cy) => {
    const list = handlers['screen:' + t] || [];
    if (!list.length) throw new Error('nothing is listening for ' + t);
    for (const f of list) f({clientX: cx, clientY: cy});
  };
  check((handlers['screen:mousemove'] || []).length > 0,
        'the canvas listens for mousemove');
  check((handlers['screen:click'] || []).length > 0,
        'the canvas listens for click');

  // Somewhere inside the map view: VIEW_X is 160 of 640, so 400 client pixels.
  point('mousemove', 400, 100);
  pump(4);
  check(puts.length > 0, 'hovering redrew the frame');

  // B_001's side 0 castle is at 3,5 with its second unit on 4,5.  Clicking a
  // cell picks a unit up if one of ours is standing there; there is no way to
  // read that back from the page, so this only checks nothing throws and the
  // frame keeps coming.
  const putsBefore = puts.length;
  point('click', 400, 100);
  pump(4);
  check(puts.length > putsBefore, 'clicking redrew the frame');

  process.exit(failed ? 1 : 0);
}, 400);
