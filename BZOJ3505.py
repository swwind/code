def gcd(a, b):
	if b:
		return gcd(b, a%b)
	else:
		return a

n, m = map(int, input().split(' '))
n = n + 1
m = m + 1
nm = n * m
c = [[1, 0, 0, 0] for i in range(nm+1)]

for i in range(nm):
	for j in range(3):
		c[i+1][j+1] = c[i][j] + c[i][j+1]

ans = c[nm][3]-n*c[m][3]-m*c[n][3]

for i in range(1, n):
	for j in range(1, m):
		gg = gcd(i, j)
		if gg > 1:
			ans -= (gg-1)*(n-i)*(m-j)*2

print(ans)