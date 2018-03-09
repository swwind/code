const pipe    = (f, g) => (...args) => g(f(...args))
const compose = (...args) => args.reduce(pipe, args.shift())

const split   = s => x => x.split(s)
const slice   = s => x => x.slice(s)
const reduce  = (...args) => x => x.reduce(...args)
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
const str     = (...args) => x => x.toString(...args)
const bool    = x => !!x
const is      = s => x => typeof x === s
const isNot   = s => x => typeof x !== s
const array   = x => new Array(x).fill(0)

const sum = reduce((a, b) => a + b, 0)
const match = reg => x => (x.match(reg) || []).length

const countSmileys = pipe(map(match(/^[:;][\-~]?[\)D]$/g)), sum)

console.log(countSmileys([]))
console.log(countSmileys([':D',':~)',';~D',':)']))
console.log(countSmileys([':)',':(',':D',':O',':;']))
console.log(countSmileys([';]', ':[', ';*', ':$', ';-D']))
