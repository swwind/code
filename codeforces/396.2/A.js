;(function () {
	var a = readline(),
		b = readline()
	if (a === b) print(-1)
	else print(Math.max(a.length, b.length))
})();