// const data = require('fs')
//   .readFileSync('/dev/stdin')
//   .toString('utf8')
//   .trim()
const data = `16
FF
2`
// begin --------------------

let [a, s, b] = data.split('\n')
a = parseInt(a, 10)
b = parseInt(b, 10)
console.log(parseInt(s, a).toString(b).toUpperCase())

// end ----------------------
process.exit()
