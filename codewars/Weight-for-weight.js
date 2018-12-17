const add = (a, b) => a + b
const orderWeight = str => str.split(' ').sort((a, b) => {
  a = a.toString()
  b = b.toString()
  const va = a.split('').map(x => parseInt(x, 10)).reduce(add)
  const vb = b.split('').map(x => parseInt(x, 10)).reduce(add)
  if (va !== vb) return va - vb
  if (a > b) return 1;
  if (a < b) return -1;
  return 0;
}).join(' ')

console.log(orderWeight("103 123 4444 99 2000"))
console.log(orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123"))
