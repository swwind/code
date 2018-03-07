const data = require('fs')
  .readFileSync('/dev/stdin')
  .toString('ascii')
  .trim()
// begin --------------------

const map     = f => x => x.map(f)
const reduce  = f => x => x.reduce(f)
const trim    = s => s.trim()
const join    = s => x => x.join(s)
const split   = s => x => x.split(s)
const slice   = p => x => x.slice(p)
const merge   = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(merge, args.shift())

// compare :: List -> List -> List
const compare = x => map((a, i) => a === x[i] ? a : '*')

// main :: String -> String
const main = compose(
  split('\n'), slice(1),
  map(compose(split(' '), map(trim))),
  reduce((x, y) => compare(x)(y)),
  join(' ')
)

console.log(main(data))

// end ----------------------
process.exit()
