;(function () {
	var reg = new RegExp(readline())
	while (k = readline())
		print(k.match(reg) ? 'Regular Expression is Fun!' : 'Boring String Matching...');
})();