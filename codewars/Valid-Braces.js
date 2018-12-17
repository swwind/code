const last = x => x[x.length - 1]
const validBraces = a => a.split('').reduce((x, y) =>
  x === false ? false :
  y === '{' || y === '(' || y === '[' ? x + y :
  x === '' ? false :
  last(x) === '{' && y === '}' ? x.substr(0, x.length - 1) :
  last(x) === '[' && y === ']' ? x.substr(0, x.length - 1) :
  last(x) === '(' && y === ')' ? x.substr(0, x.length - 1) :
  false
) === ''

console.log(validBraces("(){}[]"))
console.log(validBraces("([{}])"))
console.log(validBraces("(}"))
console.log(validBraces("[(])"))
console.log(validBraces("[({})](]"))

console.log(validBraces("()"))
console.log(validBraces("[(])"))

