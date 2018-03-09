// const data = require('fs')
//   .readFileSync('/dev/stdin')
//   .toString('ascii')
//   .trim()
const data = `43
26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961 491 2995 11942 4827 5436 32391 14604 3902 153 292 12382 17421 18716 19718 19895 5447 21726 14771 31 32 33 34 11538 1869 19912 25667 26299 17035 9894 28703 23811`
// begin --------------------

const pipe    = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(pipe, args.shift())
const curry = fn => {
  const _c = (lst, arg) => lst === 0 ?
    fn(...arg) : x => _c(lst - 1, [...arg, x]);
  return _c(fn.length, []);
}

const reduce = (...arg) => list => list.reduce(...arg)
const split = s => x => x.split(s)
const slice = s => x => x.slice(s)
const join  = s => x => x.join(s)
const trim  = x => x.trim()
const map   = fn => x => x.map(fn)
const max   = curry(Math.max)
const add   = a => b => a + b
const inc   = add(1)
const head  = x => x[0]
const last  = x => x[x.length - 1]
const eq    = q => x => x[q]
const gt    = a => b => a > b
const ifel  = (f1, f2) => x => x ? f1 : f2

// prepare :: String -> [Number]
const prepare = compose(
  split('\n'),
  last,
  split(' '),
  map(compose(trim, parseInt))
)

// main :: String -> String
const main = compose(
  prepare,
  reduce((x, y) => y > x[0]
    ? [y, x[1] + 1, max(x[1] + 1)(x[2])]
    : [y, 1, max(1)(x[2])]
    , [0, 0, 0]), // [now value, now length, max length]
  last
)

console.log(main(data))

// end ----------------------
process.exit()
