const pipe    = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(pipe, args.shift())

const split   = s => x => x.split(s)
const join    = s => x => x.join(s)
const map     = f => x => x.map(f)
const repeat  = x => s => s.repeat(x)
const upper   = x => x.toUpperCase()
const lower   = x => x.toLowerCase()
const replace = (...args) => s => s.replace(...args)
const add     = a => b => a + b

const accum = compose(
  split(''),
  map((a, i) => compose(
    lower,
    repeat(i),
    add(upper(a))
  )(a)),
  join('-')
)

console.log(accum("abcd"))
console.log(accum("RqaEzty"))
console.log(accum("cwAt"))
console.log(accum("ZpglnRxqenU"))
console.log(accum("NyffsGeyylB"))
console.log(accum("MjtkuBovqrU"))
console.log(accum("EvidjUnokmM"))
console.log(accum("HbideVbxncC"))
