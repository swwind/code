def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)

def work(n, k):
	if n > k:
		return '0 1'
	else:
		a = (k+1)**(n-1)*(k+1-n);
		b = k**n;
		k = gcd(a, b)
		return str(a//k) + ' ' + str(b//k)

T = int(raw_input())

for x in range(T):
	n, k = map(int, raw_input().split(' '))
	print(work(n, k))