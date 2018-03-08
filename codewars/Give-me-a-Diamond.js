const pipe    = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(pipe, args.shift())

const split   = s => x => x.split(s)
const slice   = s => x => x.slice(s)
const substr  = (s, t) => x => x.substr(s, t)
const join    = s => x => x.join(s)
const map     = f => x => x.map(f)
const filter  = f => x => x.filter(f)
const repeat  = x => s => s.repeat(x)
const upper   = x => x.toUpperCase()
const lower   = x => x.toLowerCase()
const replace = (...args) => s => s.replace(...args)
const reverse = s => s.reverse()
const add     = a => b => a + b
const append  = a => b => b + a
const str     = x => x.toString()
const bool    = x => !!x
const is      = s => x => typeof x === s
const isNot   = s => x => typeof x !== s
const array   = x => new Array(x).fill(0)

const spaces = (x, i) => Math.abs(i - (x - 1) / 2)
const work = x => compose(
  array,
  map((a, i) => add
    (repeat(spaces(x, i))(' '))
    (repeat(x - 2 * spaces(x, i))('*'))),
  join('\n'),
  append('\n')
)(x)

const diamond = x => x > 0 && x % 2 === 1 ? work(x) : null

console.log(diamond(3))
console.log(diamond(2))
console.log(diamond(-3))
console.log(diamond(0))

