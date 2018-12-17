const zero  = x => x ? x(0) : 0
const one   = x => x ? x(1) : 1
const two   = x => x ? x(2) : 2
const three = x => x ? x(3) : 3
const four  = x => x ? x(4) : 4
const five  = x => x ? x(5) : 5
const six   = x => x ? x(6) : 6
const seven = x => x ? x(7) : 7
const eight = x => x ? x(8) : 8
const nine  = x => x ? x(9) : 9

const plus      = x => y => y + x
const minus     = x => y => y - x
const times     = x => y => y * x
const dividedBy = x => y => y / x

console.log(seven(times(five())))
console.log(four(plus(nine())))
console.log(eight(minus(three())))
console.log(six(dividedBy(two())))
