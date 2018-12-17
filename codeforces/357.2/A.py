n = int(input())
i = 1
while i <= n:
	s, x, y = input().split(' ')
	x = int(x)
	y = int(y)
	if (x >= 2400) and (y > x):
		print('YES')
		exit(0)
	i = i+1
print('NO')