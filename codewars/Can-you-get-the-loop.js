const loop_size = (node) => {
  let list = [node];
  node = node.next;
  while (list.indexOf(node) === -1) {
    list.push(node);
    node = node.next;
  }
  return list.length - list.indexOf(node)
}

var a = {}
var b = {next: a}
a.next = b;
console.log(loop_size(a))

