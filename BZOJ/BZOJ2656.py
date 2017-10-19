def f(x):
	if x == 1:
		return [x, 0]
	p, q = f(x + 1 >> 1)
	return [p + q, q] if x & 1 else [p, p + q]

t = int(input())
for i in range(t):
	print(f(int(input()))[0])