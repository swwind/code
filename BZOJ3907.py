n, m = map(int, input().split(' '))
f = [0 for i in range(n+m+1)]

def C(n, m):
	return f[n]//f[m]//f[n-m]

f[0] = 1

for i in range(n+m):
	f[i+1] = f[i]*(i+1)

print(C(n+m, n) - C(n+m, n+1))