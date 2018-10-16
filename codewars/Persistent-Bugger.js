const pipe = (f, g) => x => g(f(x))
const compose = (...args) => args.reduce(pipe, args.shift())

const str = x => x.toString()
const map = f => x => x.map(f)
const reduce = (...args) => x => x.reduce(...args)
const inc = x => x + 1
const result = r => x => r
const split = s => x => x.split(s)
const mul = (x, y) => x * y
const int = x => ~~x

const calc = compose(str, split(''), map(int), reduce(mul))
const persistence = x => x > 9 ? persistence(calc(x)) + 1 : 0

console.log(persistence(39))
console.log(persistence(4))
console.log(persistence(25))
console.log(persistence(999))
