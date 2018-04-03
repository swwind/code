class Vector {
  constructor(arr) {
    this.value = arr
  }
  add(vec) {
    if (vec.value.length !== this.value.length)
      throw 'hello world'
    return new Vector(this.value.map((x, i) => x + vec.value[i]))
  }
  subtract(vec) {
    if (vec.value.length !== this.value.length)
      throw 'hello world'
    return new Vector(this.value.map((x, i) => x - vec.value[i]))
  }
  dot(vec) {
    if (vec.value.length !== this.value.length)
      throw 'hello world'
    return this.value.map((x, i) => x * vec.value[i])
      .reduce((a, b) => a + b)
  }
  norm() {
    return Math.sqrt(this.value.map(x => x * x)
      .reduce((a, b) => a + b))
  }
  toString() {
    return '(' + this.value.join(',') + ')'
  }
  equals(vec) {
    return this.toString() === vec.toString()
  }
}

var a = new Vector([1, 2, 3]);
var b = new Vector([3, 4, 5]);
var c = new Vector([5, 6, 7, 8]);

console.log(a.add(b))      // should return a new Vector([4, 6, 8])
console.log(a.subtract(b)) // should return a new Vector([-2, -2, -2])
console.log(a.dot(b))      // should return 1*3 + 2*4 + 3*5 = 26
console.log(a.norm())      // should return sqrt(1^2 + 2^2 + 3^2) = sqrt(14)
// console.log(a.add(c))      // throws an error
