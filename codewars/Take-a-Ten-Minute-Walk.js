const pipe    = (f, g) => (...args) => g(f(...args))
const compose = (...args) => args.reduce(pipe, args.shift())

const split   = s => x => x.split(s)
const slice   = s => x => x.slice(s)
const reduce  = fn => x => x.reduce(fn)
const substr  = (s, t) => x => x.substr(s, t)
const join    = s => x => x.join(s)
const map     = f => x => x.map(f)
const filter  = f => x => x.filter(f)
const repeat  = x => s => s.repeat(x)
const upper   = x => x.toUpperCase()
const lower   = x => x.toLowerCase()
const replace = (...args) => s => s.replace(...args)
const reverse = s => s.reverse()
const add     = (a, b) => a + b
const append  = a => b => b + a
const str     = (...args) => x => x.toString(...args)
const bool    = x => !!x
const is      = s => x => typeof x === s
const isNot   = s => x => typeof x !== s
const array   = x => new Array(x).fill(0)

const check_ns = x => x === 'n' ? 1 : x === 's' ? -1 : 0
const check_we = x => x === 'w' ? 1 : x === 'e' ? -1 : 0

const isValidWalk = x => x.length === 10 && !reduce(add)(map(check_we)(x)) && !reduce(add)(map(check_ns)(x))

console.log(isValidWalk(['n','s','n','s','n','s','n','s','n','s']))
console.log(isValidWalk(['w','e','w','e','w','e','w','e','w','e','w','e']))
console.log(isValidWalk(['w']))
console.log(isValidWalk(['n','n','n','s','n','s','n','s','n','s']))
