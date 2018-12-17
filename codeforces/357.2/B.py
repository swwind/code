n = int(input())
a = 0
while a <= n:
	b = 0
	while a + b <= n:
		if (n - a - b) % 1234 == 0:
			print('YES')
			exit(0)
		b += 123456
	a += 1234567
print('NO')
