String.prototype.reverse = function () {
  return this.split('').reverse().join('');
}
String.prototype.sort = function () {
  return this.split('').sort().join('');
}

const middlePermutation = (str) => {
  str = str.sort()
  if (str.length <= 2)
    return str;
  if (str.length & 1) {
    let pos = str.length / 2;
    let pt1 = str.charAt(pos);
    let pt2 = str.charAt(pos - 1);
    let pt3 = str.slice(0, pos - 1) + str.slice(pos + 1);
    return pt1 + pt2 + pt3.reverse()
  } else {
    let pos = str.length / 2 - 1;
    let pt1 = str.charAt(pos);
    let pt2 = str.slice(0, pos) + str.slice(pos + 1);
    return pt1 + pt2.reverse();
  }
}




console.log(middlePermutation("abc"))
console.log(middlePermutation("abcd"))
console.log(middlePermutation("abcdx"))
console.log(middlePermutation("abcdxg"))
console.log(middlePermutation("abcdxgz")) // dczxgba

