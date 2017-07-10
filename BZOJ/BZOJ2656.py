def f(x):
	if x == 1:
		return [x, 0]
	p, q = map(int, f((x+1)>>1))
	return [p+q, q] if x&1 else [p, p+q]

t = int(raw_input())
for i in range(t):
	print(f(int(raw_input()))[0])