const fs = require('fs');

const liner = function (x) {
  return 4 * x + 60;
}

const data = [["x", "y"]];

for (let i = 0; i < 100; ++ i) {
  let x = Math.random() * 50; // [0, 50)
  let y = liner(x) + (Math.random() * 10 - 5) // 土5
  data.push([x, y]);
}

const res = data.map(x => x.map(y => typeof y === 'string' ? '"' + y + '"' : y.toString()).join(',')).join('\n');

// console.log(res);

fs.writeFileSync('data.csv', res);
