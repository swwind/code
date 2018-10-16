;(function () {
	var n = + readline()
	var a = readline().split(' ')
	for (var k = 0; k < n; k++)
		a[k] = +a[k]
	a.sort(function (a, b) {
		return a - b;
	})
	var isTri = function (a, b, c) {
		return a + b > c && a + c > b && b + c > a
	}
	for (var k = 2; k < n; k++)
		if (isTri(a[k-2], a[k-1], a[k]))
			return print('YES')
	print('NO')
})();
