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

const trydiv = x => y => y <= 1 ? false : y % x === 0 ? x === y : trydiv(x + 1)(y)
const isPrime = trydiv(2)

console.log(isPrime(0))
console.log(isPrime(1))
console.log(isPrime(2))
console.log(isPrime(3))
console.log(isPrime(4))
console.log(isPrime(5))
console.log(isPrime(6))
console.log(isPrime(7))
console.log(isPrime(8))
console.log(isPrime(9))
console.log(isPrime(10))
console.log(isPrime(11))
