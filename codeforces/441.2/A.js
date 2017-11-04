;(function () {
	var n = + readline();
	var a = + readline();
	var b = + readline();
	var c = + readline();
	if (n === 1) return print(0);
	if (n === 2) return print(Math.min(a, b));
	print(Math.min(a, b) + Math.min(a, Math.min(b, c)) * (n - 2));
})();