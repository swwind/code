var n = 10
while (n --) {
	var k = readline().split(' ')
	var s1 = + k[0][k[0].length - 1],
		s2 = + k[1][k[1].length - 1]
	s1 %= 5, s2 %= 5
	print((s1 === 2 || s1 === 3) && (s2 === 2 || s2 === 3) ? 'Shadow' : 'Matrix67')
}
