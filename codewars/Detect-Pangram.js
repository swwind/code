const pipe = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(pipe, args.shift())

const match  = reg => x => x.match(reg)
const reduce = (f, s) => x => x.reduce(f, s)
const split  = s => x => x.split(s)
const map    = s => x => x.map(s)
const filter = s => x => x.filter(s)
const test   = x => reg => reg.test(x)
const sort   = x => x.sort()
const and    = (x, y) => x && y
const or     = (x, y) => x || y
const not    = x => !x
const upper  = x => x.toUpperCase()

const isPangram =
  compose(
    split(''),
    map(upper),
    sort,
    filter(match(/[A-Z]/)),
    filter((x, i, arr) => !i || x !== arr[i - 1]),
    x => x.length === 26)

console.log(isPangram("The quick brown fox jumps over the lazy dog."))
console.log(isPangram("This is not a pangram."))
console.log(isPangram("aaaaaaaaaaaaaaaaaaaaaaaaaa"))



