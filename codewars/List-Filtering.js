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
const str     = x => x.toString()
const bool    = x => !!x
const is      = s => x => typeof x === s
const isNot   = s => x => typeof x !== s

const filter_list = filter(is('number'))

console.log(filter_list([1,2,'a','b']))
console.log(filter_list([1,'a','b',0,15]))
console.log(filter_list([1,2,'aasf','1','123',123]))

