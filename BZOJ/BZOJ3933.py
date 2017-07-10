def A(a):
	return (209*1234**(a%3388)+3181)%3389

n = int(raw_input())
t = int(raw_input())
m = int(raw_input())
C = 1
ans = 0
_t = 1

for i in range(n-m+1):
	if i:
		C *= m+i
		C //= i
		_t *= t
	ans += C*_t*A(m+i)

print(ans)