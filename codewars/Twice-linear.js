const getFirstElement = (q) => {
  for (let res in q)
    return res;
}
const dblLinear = (n) => {
  let q = {"1": 1}
  while (n --) {
    let x = getFirstElement(q);
    q[x * 2 + 1] = 1;
    q[x * 3 + 1] = 1;
    delete q[x]
  }
  return ~~getFirstElement(q)
}

console.log(dblLinear(10))
console.log(dblLinear(20))
console.log(dblLinear(30))
console.log(dblLinear(50))
console.log(dblLinear(100))

// Time limit exceeded.
