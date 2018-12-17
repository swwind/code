;(function () {
	var n = 1 * readline()
	for (var a = 0; a <= n; a += 1234567)
		for (var b = 0; a + b <= n; b += 123456)
			if ((n - a - b) % 1234 === 0)
				return print('YES');
	print('NO');
})();