;(function () {
	var str = readline();
	if (str.match(/[^\d\.\(\)\+\-\*\/]/g))
		return print("FormulaException");
	str = "var k = "+str;
	if (str.match(/[^\d\.]0\d/g) ||
			str.match(/[\*\/\+\-][\*\/\+\-]/g) ||
			str.match(/((\D\.\d)|(\d\.\D)|(\D\.\D))/g))
		return print("FormulaException");
	try {
		eval(str);
	} catch (e) {
		return print("FormulaException");
	}
	if (isNaN(k) || k == Infinity || k == -Infinity)
		return print("ZeroException");
	print(k.toFixed(2));
})();