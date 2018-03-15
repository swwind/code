function humanReadable(seconds) {
  const dv60 = x => Math.floor(x / 60)
  let h = dv60(dv60(seconds))
  let m = dv60(seconds) % 60
  let s = seconds % 60
  return [h, m, s].map(x => x < 10 ? '0' + x : x.toString()).join(':')
}

console.log(humanReadable(0), '00:00:00', 'humanReadable(0)');
console.log(humanReadable(5), '00:00:05', 'humanReadable(5)');
console.log(humanReadable(60), '00:01:00', 'humanReadable(60)');
console.log(humanReadable(86399), '23:59:59', 'humanReadable(86399)');
console.log(humanReadable(359999), '99:59:59', 'humanReadable(359999)');