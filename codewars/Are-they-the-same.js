// WA

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
const add     = a => b => a + b
const append  = a => b => b + a
const str     = (...args) => x => x.toString(...args)
const bool    = x => !!x
const is      = s => x => typeof x === s
const isNot   = s => x => typeof x !== s
const array   = x => new Array(x).fill(0)

const contains = p => x => x.indexOf(p) > -1

const _and = (x, y) => x && y

const ok = x => x && x.length
// comp :: [a] -> [b] -> bool
const comp = (a, b) => ok(a) && ok(b) ? reduce(_and)(map(x => contains(x * x)(b))(a)) : false

var a1 = [121, 144, 19, 161, 19, 144, 19, 11];
var a2 = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19];
console.log(comp(a1, a2))
