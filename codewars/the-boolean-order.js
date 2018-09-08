'use strict';

const solve = (s, ops) => {
  const n = s.length;
  const f = [];
  for (let i = 0; i < n; ++ i) {
    const fi = [];
    for (let j = 0; j < n; ++ j) {
      if (i === j) {
        const ch = s.charAt(i);
        fi.push([!(ch === 't'), !(ch === 'f')]);
      } else {
        fi.push([0, 0]);
      }
    }
    f.push(fi);
  }
  // length
  for (let i = 1; i < n; ++ i) {
    // start
    for (let j = 0; j < n; ++ j) {
      // end
      let k = j + i;
      if (k >= n) break;
      // mid
      for (let l = j; l < k; ++ l) {
        const op = ops.charAt(l);
        if (op == '^') {
          f[j][k][1] += f[j][l][1] * f[l+1][k][0];
          f[j][k][1] += f[j][l][0] * f[l+1][k][1];
          f[j][k][0] += f[j][l][1] * f[l+1][k][1];
          f[j][k][0] += f[j][l][0] * f[l+1][k][0];
        }
        if (op == '&') {
          f[j][k][0] += f[j][l][1] * f[l+1][k][0];
          f[j][k][0] += f[j][l][0] * f[l+1][k][1];
          f[j][k][1] += f[j][l][1] * f[l+1][k][1];
          f[j][k][0] += f[j][l][0] * f[l+1][k][0];
        }
        if (op == '|') {
          f[j][k][1] += f[j][l][1] * f[l+1][k][0];
          f[j][k][1] += f[j][l][0] * f[l+1][k][1];
          f[j][k][1] += f[j][l][1] * f[l+1][k][1];
          f[j][k][0] += f[j][l][0] * f[l+1][k][0];
        }
      }
    }
  }
  return f[0][n-1][1];
}

console.log(solve("tft","^&"),2);
console.log(solve("ttftff","|&^&&"),16);
console.log(solve("ttftfftf","|&^&&||"),339);
console.log(solve("ttftfftft","|&^&&||^"),851);
console.log(solve("ttftfftftf","|&^&&||^&"),2434);

