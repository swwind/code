;(function () {
	readline()
	var res = 0
	while (x = readline()) {
		var k = x.split(' ')
		switch (k[0]) {
			case '|': res |= + k[1]; break;
			case '&': res &= + k[1]; break;
			case '^': res ^= + k[1]; break;
		}
	}
	res ? print('1\n| ' + res) : print('0')
})();