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

const toWeirdCase = compose(
  split(' '),
  map(compose(
    split(''),
    map((a, i) => i % 2 === 0 ?
      upper(a) : lower(a)),
    join('')
  )),
  join(' ')
)

console.log(toWeirdCase("String"));//=> returns "StRiNg"
console.log(toWeirdCase("Weird string case"));//=> returns "WeIrD StRiNg CaSe"
console.log(toWeirdCase('This is a test'))