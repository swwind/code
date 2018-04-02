const add = (a, b) => a + b
const orderWeight = str => str.split(' ').sort((a, b) => {
  a = a.toString()
  b = b.toString()
  const va = a.split('').map(x => + x).reduce(add)
  const vb = b.split('').map(x => + x).reduce(add)
  return va == vb ? a - b : va - vb
}).join(' ')

console.log(orderWeight("103 123 4444 99 2000"))
console.log(orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123"))
