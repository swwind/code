;(function () {
	var f = new Array();
	for (var i = 1; i <= 2520; i++)
		f[i] = new Array(2521).join(0).split('')
	var str = readline().split(' '),
		n = +str[0],
		m = +str[1],
		k = +str[2],
		cnt = 0;
	var add = function (a, b, v) {
		for (var i = a; i <= n; i += i & -i)
			for (var j = b; j <= m; j += j & -j)
				f[i][j] = +f[i][j] + v
	}
	var ask = function (a, b) {
		var ans = 0
		for (var i = a; i; i ^= i & -i)
			for (var j = b; j; j ^= j & -j)
				ans += +f[i][j]
		return ans
	}
	var update = function (a, b, c, d, e) {
		add(a, b, e)
		add(a, d+1, -e)
		add(c+1, b, -e)
		add(c+1, d+1, e)
	}
	var hash = function (a, b, c, d) {
		return a * b * c * d;
	}
	while (k --) {
		var line = readline().split(' '),
			op = +line[0],
			x1 = +line[1],
			y1 = +line[2],
			x2 = +line[3],
			y2 = +line[4],
			id = hash(x1, y1, x2, y2);
		if (op == 1) {
			update(x1, y1, x2, y2, id);
		} else if (op == 2) {
			update(x1, y1, x2, y2, -id);
		} else {
			print(ask(x1, y1) === ask(x2, y2) ? 'Yes' : 'No');
			// print(ask(x1, y1))
			// print(ask(x2, y2))
		}
	}
})();