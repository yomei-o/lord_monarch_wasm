/* Run the floppy in Neko Project II, under node, with no window.
 *
 *   node tools/np2run.mjs <image.hdm> [seconds] [out-prefix]
 *
 * np2-wasm is built for a browser: it wants a canvas and it plays through a
 * ScriptProcessorNode.  Neither exists here, so both are stubbed - and the
 * stubs are the point.  The fake AudioContext hands the emulator a buffer and
 * keeps what it writes, which is the emulator's own sound with no loopback
 * device involved, and the fake canvas keeps the pixels.
 *
 * Why bother: this port has no reference for what the game sounds like, and
 * ss0.jpg is the only reference for what it looks like.  This would give both.
 *
 * NOT WORKING YET.  How far it gets:
 *
 *   - np2-wasm 0.3.1 from npm, unpacked into tmp/np2/dist.  The emulator's
 *     own package is browser-only, so this drives dist/np2.js directly rather
 *     than the NP2 wrapper class, which wants a real canvas and document.
 *   - the module loads under node: handing over Module.wasmBinary avoids
 *     emscripten's instantiateAsync reaching for fetch, which node will not
 *     do for a file:// URL.  calledRun goes true and onRuntimeInitialized
 *     fires.
 *   - the disk mounts.  The image is the FIM with its 256-byte header cut
 *     off, which is a raw 1232 x 1024 dump - the .hdm layout - and
 *     ccall('diskdrv_setfddex', [0, name, 0, 0]) takes it, the same call the
 *     wrapper's setFdd makes.
 *   - getConfig is the real one now: the emulator asks for each setting by
 *     name and wants the answer written into its heap, and an earlier version
 *     that returned a JS object left every setting unset.
 *
 *   - the config is read to the end: with NP2_TRACE=1 in the environment this
 *     logs all 58 settings the emulator asks for, finishing at no_mouse.
 *   - /font.bmp and the disk image are both in the emulator's filesystem when
 *     start-up runs.
 *   - SDL2 is told to take its software renderer.  emscripten's ENV is a
 *     module-scope var with no way in from outside, so the line declaring it
 *     is seeded on the way past, into the copy that gets imported.
 *
 * What is left: Module.onReady never fires, so start-up is stopping before the
 * EM_ASM that calls it, and _np2_resume then dies on "MainLoop.scheduler is
 * not a function" because emscripten_set_main_loop was never reached.  Nothing
 * comes out of print or printErr, so it is not aborting - it is returning.
 *
 * np2_main in src/sdl2/np2.c of irori/np2-wasm has exactly four places it can
 * leave early, and the config and the two files rule nothing out but narrow
 * it: fontmng_init, sysmenu_create, scrnmng_create, and flagload returning
 * DID_CANCEL when np2oscfg.resume is set.  The last is the cheapest to
 * eliminate - pass resume: false - and scrnmng_create is the likeliest, since
 * it is the one that wants a window.  Putting a printf in each and rebuilding
 * from source would settle it in one run; build-wasm.sh in that repo is two
 * lines of emcmake and ninja.
 */
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const here = path.dirname(fileURLToPath(import.meta.url));
const dist = path.join(here, '..', 'tmp', 'np2', 'dist');

const imagePath = process.argv[2] || path.join(here, '..', 'tmp', 'np2', 'monarch.hdm');
const seconds = parseFloat(process.argv[3] || '20');
const prefix = process.argv[4] || path.join(here, '..', 'tmp', 'np2', 'out');

const RATE = 44100;

/* ---------------------------------------------------------- the stubs ---- */

const audioChunks = [];
let audioNode = null;

class FakeAudioParam { constructor(v) { this.value = v; } setValueAtTime() {} }

class FakeAudioBuffer {
  constructor(channels, length, rate) {
    this.numberOfChannels = channels;
    this.length = length;
    this.sampleRate = rate;
    this._data = [];
    for (let i = 0; i < channels; i++) this._data.push(new Float32Array(length));
  }
  getChannelData(i) { return this._data[i]; }
}

class FakeScriptProcessor {
  constructor(bufferSize, inCh, outCh, ctx) {
    this.bufferSize = bufferSize;
    this.onaudioprocess = null;
    this._ctx = ctx;
    this._out = new FakeAudioBuffer(outCh || 2, bufferSize, ctx.sampleRate);
    audioNode = this;
  }
  connect() {}
  disconnect() {}
  /* Called by the harness, standing in for the browser's audio thread. */
  pump() {
    if (!this.onaudioprocess) return;
    const ev = { outputBuffer: this._out, inputBuffer: this._out };
    for (const c of this._out._data) c.fill(0);
    this.onaudioprocess(ev);
    const l = this._out.getChannelData(0);
    const r = this._out.numberOfChannels > 1 ? this._out.getChannelData(1) : l;
    const pcm = new Int16Array(l.length * 2);
    for (let i = 0; i < l.length; i++) {
      pcm[i * 2] = Math.max(-32768, Math.min(32767, Math.round(l[i] * 32767)));
      pcm[i * 2 + 1] = Math.max(-32768, Math.min(32767, Math.round(r[i] * 32767)));
    }
    audioChunks.push(Buffer.from(pcm.buffer, 0, pcm.byteLength));
    this._ctx.currentTime += this.bufferSize / this._ctx.sampleRate;
  }
}

class FakeAudioContext {
  constructor() {
    this.sampleRate = RATE;
    this.currentTime = 0;
    this.state = 'running';
    this.destination = {};
  }
  createScriptProcessor(n, i, o) { return new FakeScriptProcessor(n, i, o, this); }
  createGain() { return { gain: new FakeAudioParam(1), connect() {}, disconnect() {} }; }
  createBuffer(c, l, r) { return new FakeAudioBuffer(c, l, r); }
  createBufferSource() { return { buffer: null, connect() {}, start() {}, stop() {} }; }
  resume() { return Promise.resolve(); }
  suspend() { return Promise.resolve(); }
  close() { return Promise.resolve(); }
}

/* A canvas that keeps the pixels rather than showing them. */
let lastImage = null;
function makeCanvas(w, h) {
  const canvas = {
    width: w, height: h, clientWidth: w, clientHeight: h,
    style: {},
    addEventListener() {}, removeEventListener() {},
    getBoundingClientRect() { return { left: 0, top: 0, width: w, height: h }; },
    getContext(kind) {
      if (kind !== '2d') return null;
      return {
        canvas,
        createImageData(a, b) {
          const ww = a.width || a, hh = a.height || b;
          return { width: ww, height: hh, data: new Uint8ClampedArray(ww * hh * 4) };
        },
        getImageData(x, y, ww, hh) {
          return { width: ww, height: hh, data: new Uint8ClampedArray(ww * hh * 4) };
        },
        putImageData(img) { lastImage = img; },
        drawImage() {}, fillRect() {}, clearRect() {},
        drawImage2() {},
      };
    },
  };
  return canvas;
}

/* Enough of a DOM for emscripten's SDL layer to come up. */
const listeners = {};
const documentStub = {
  addEventListener(t, f) { (listeners[t] ||= []).push(f); },
  removeEventListener() {},
  createElement(tag) {
    if (tag === 'canvas') return makeCanvas(640, 400);
    return { style: {}, addEventListener() {}, appendChild() {} };
  },
  getElementById() { return null },
  querySelector() { return null },
  body: { appendChild() {}, style: {} },
  documentElement: { style: {} },
  hidden: false,
  visibilityState: 'visible',
};

globalThis.window = globalThis;
globalThis.document = documentStub;
globalThis.AudioContext = FakeAudioContext;
globalThis.webkitAudioContext = FakeAudioContext;
globalThis.navigator ||= { userAgent: 'node', platform: 'node' };
globalThis.self = globalThis;
globalThis.alert = (m) => console.log('[alert]', m);
globalThis.requestAnimationFrame = (f) => setTimeout(() => f(Date.now()), 0);
globalThis.cancelAnimationFrame = (id) => clearTimeout(id);
globalThis.addEventListener = () => {};
globalThis.removeEventListener = () => {};

/* --------------------------------------------------------------- run ---- */

const canvas = makeCanvas(640, 400);
const image = fs.readFileSync(imagePath);
const font = fs.readFileSync(path.join(dist, 'font.bmp'));

/* SDL2 under emscripten picks a GL renderer by default and there is no GL
 * here.  The hint that stops it is an environment variable, and emscripten's
 * ENV is a module-scope var with no way in from outside - so the line that
 * declares it gets seeded on the way past, into a copy that is what gets
 * imported. */
const np2src = fs.readFileSync(path.join(dist, 'np2.js'), 'utf8');
const seeded = np2src.replace('var ENV={}',
  'var ENV={SDL_RENDER_DRIVER:"software",SDL_VIDEODRIVER:"emscripten"}');
if (seeded === np2src) console.warn('warning: could not seed ENV');
const patched = path.join(dist, 'np2_node.js');
fs.writeFileSync(patched, seeded);
const factory = (await import('file://' + patched.replace(/\\/g, '/'))).default;

let ready = false;
/* SNDboard 1 is the 26K, which is the YM2203 this game probes for. */
const config = { fontfile: 'font.bmp', SampleHz: RATE, Latencys: 100, SNDboard: 1,
                 BEEP_vol: 3, xspeaker: false };
const Module = {
  canvas,
  /* node's fetch will not take a file:// URL, and emscripten's instantiateAsync
   * reaches for it; handing over the bytes skips that path entirely. */
  wasmBinary: fs.readFileSync(path.join(dist, 'np2.wasm')),
  locateFile: (f) => path.join(dist, f),
  arguments: [],
  print: (t) => console.log('[np2]', t),
  printErr: (t) => console.error('[np2!]', t),
  preRun: [() => {
    Module.FS.writeFile('/font.bmp', font);
    Module.FS.writeFile('/' + path.basename(imagePath), image);
  }],
  onReady: () => { ready = true; console.log('[np2] onReady'); },
  onRuntimeInitialized: () => console.log('[np2] runtime initialized'),
  /* The real thing: the emulator asks for each setting by name and expects the
   * answer written into its own heap.  Returning an object, as this first did,
   * leaves every setting unset and start-up never reaches onReady. */
  getConfig: (pName, type, pValue, size) => {
    const name = Module.UTF8ToString(pName);
    const value = config[name];

    if (process.env.NP2_TRACE) console.log('[cfg]', name, type, value);

    if (value === undefined) return;
    switch (type) {
    case 0: if (typeof value === 'string') Module.stringToUTF8(value, pValue, size); break;
    case 1: Module.HEAP8[pValue] = value ? 1 : 0; break;
    case 2: if (Array.isArray(value)) for (let i = 0; i < size; i++) Module.HEAPU8[pValue + i] = value[i]; break;
    case 3: Module.HEAP8[pValue] = value; break;
    case 6: case 9: Module.HEAPU8[pValue] = value; break;
    case 4: Module.HEAP16[pValue >> 1] = value; break;
    case 7: case 10: Module.HEAPU16[pValue >> 1] = value; break;
    case 5: Module.HEAP32[pValue >> 2] = value; break;
    case 8: case 11: Module.HEAPU32[pValue >> 2] = value; break;
    default: break;
    }
  },
  setConfig: () => {},
  onDiskChange: (n) => console.log('[disk]', n),
  onExit: () => console.log('[np2] exited'),
};

console.log('booting np2...');
await factory(Module);

/* onReady comes out of the emulator's own start-up; the main loop is driven by
 * requestAnimationFrame, which here is a setTimeout, so it only turns while
 * this function awaits. */
const tick = () => new Promise((r) => setTimeout(r, 0));
for (let i = 0; i < 2000 && !ready; i++) await tick();
try {
  console.log('font in FS:', Module.FS.analyzePath('/font.bmp').exists,
              ' disk in FS:', Module.FS.analyzePath('/' + path.basename(imagePath)).exists);
} catch (e) { console.log('FS probe failed:', e.message); }
console.log('ready:', ready, ' calledRun:', Module.calledRun,
            ' remaining deps:', Module.getPreloadedPackage ? '?' : '-');

const diskName = path.basename(imagePath);
Module.ccall('diskdrv_setfddex', undefined,
             ['number', 'string', 'number', 'number'], [0, diskName, 0, 0]);
console.log('mounted', diskName);
Module._np2_reset();
Module._np2_resume();
Module.resumeMainLoop && Module.resumeMainLoop();

/* Run.  The emulator makes sound only when something asks its
 * ScriptProcessorNode for a block, so the harness has to ask. */
const wantBlocks = Math.ceil(seconds * RATE / 4096);
let blocks = 0, spins = 0;
while (blocks < wantBlocks && spins < wantBlocks * 400 + 20000) {
  await tick();
  spins++;
  if (audioNode) { audioNode.pump(); blocks++; }
}
console.log('audio blocks:', blocks, 'of', wantBlocks, ' frames drawn:', lastImage ? 'yes' : 'no');

/* The WAV. */
const pcm = Buffer.concat(audioChunks);
const wav = Buffer.alloc(44 + pcm.length);
wav.write('RIFF', 0); wav.writeUInt32LE(36 + pcm.length, 4); wav.write('WAVEfmt ', 8);
wav.writeUInt32LE(16, 16); wav.writeUInt16LE(1, 20); wav.writeUInt16LE(2, 22);
wav.writeUInt32LE(RATE, 24); wav.writeUInt32LE(RATE * 4, 28);
wav.writeUInt16LE(4, 32); wav.writeUInt16LE(16, 34);
wav.write('data', 36); wav.writeUInt32LE(pcm.length, 40);
pcm.copy(wav, 44);
fs.writeFileSync(prefix + '.wav', wav);
console.log(prefix + '.wav', (pcm.length / 4 / RATE).toFixed(2) + 's');

/* The screen, as a raw RGBA dump the caller can turn into a PNG. */
if (lastImage) {
  fs.writeFileSync(prefix + '.rgba', Buffer.from(lastImage.data.buffer));
  console.log(prefix + '.rgba', lastImage.width + 'x' + lastImage.height);
}
process.exit(0);
