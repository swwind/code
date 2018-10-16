def A(n, m):
	if n < m:
		return 0
	ans = 1
	for i in range(n-m+1, n+1):
		ans *= i
	return ans

n, m = map(int, raw_input().split(' '))

print(A(n, n)*(A(n+1, 2)*A(n+3, m)+2*m*A(n+1, 1)*A(n+2, m-1)))