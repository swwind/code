const pipe    = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(pipe, args.shift())

const split   = s => x => x.split(s)
const slice   = s => x => x.slice(s)
const substr  = (s, t) => x => x.substr(s, t)
const join    = s => x => x.join(s)
const map     = f => x => x.map(f)
const repeat  = x => s => s.repeat(x)
const upper   = x => x.toUpperCase()
const lower   = x => x.toLowerCase()
const replace = (...args) => s => s.replace(...args)
const add     = a => b => a + b

const toJadenCase = compose(
  split(' '),
  map(a => compose(
    lower,
    substr(1),
    add(upper(a[0]))
  )(a)),
  join(' ')
)

String.prototype.toJadenCase = function () {
  return toJadenCase(this)
}

console.log("How can mirrors be real if our eyes aren't real".toJadenCase())

