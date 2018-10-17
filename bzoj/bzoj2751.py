def mi(a, b):
	ans = 1
	while b > 0:
		if b&1:
			ans = ans*a%1000000007
		b //= 2
		a = a*a%1000000007
	return ans

n, m, k = map(int, input().split(' '))
ask = [[]] * k
_tmp = n*(n+1)//2%1000000007
s = 1
tot = 0
tmp = 0

for i in range(k):
	ask[i] = list(map(int, input().split(' ')))

list.sort(ask)

# print(ask)
# print(ans)

for i in range(k):
	if (i > 0) and (ask[i][0] != ask[i-1][0]):
		# print('s*=', tmp)
		s = s*tmp%1000000007
		tmp = _tmp
		tot = tot+1
	if (i > 0) and (ask[i][0] == ask[i-1][0]) and (ask[i][1] == ask[i-1][1]):
		continue
	tmp -= ask[i][1]
	if tmp < 0:
		tmp += _tmp

print(s*tmp*mi(_tmp, m-tot-1)%1000000007)
