;(function () {
	var n = parseInt(readline())

	for (var i = 1; i <= n; i++) {
		var s = readline().split(' '),
			x = parseInt(s[1]),
			y = parseInt(s[2]);

		if (x >= 2400 && y > x)
			return print("YES");
	}
	print("NO");
})();
