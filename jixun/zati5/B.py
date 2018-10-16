def gcd(a, b):
	return gcd(b, a % b) if b else a

n = int(input())
ans = 1
for i in range(n):
	x = int(input())
	ans = ans * x // gcd(ans, x)
print(ans)