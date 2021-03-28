# def f(x):
# 	if x == 1:
# 		return [x, 0]
# 	p, q = f(x + 1 >> 1)
# 	return [p + q, q] if x & 1 else [p, p + q]

def f(x):
	if x == 1:
		return [1, 1]
	p, q = f(x >> 1)
	return [p + q, q] if x & 1 else [p, p + q]

t = int(input())
for i in range(t):
	print(f(int(input()))[0])

# A{2i}   = A{i}
# A{2i+1} = A{i} + A{i+1}

# f(x): A{x}, A{x+1}
# x=2i?
# A{x}   = A{x/2}
# A{x+1} = A{x/2} + A{x/2+1}

# x=2i+1?
# A{x}   = A{x/2} + A{x/2+1}
# A{x+1} = A{x/2+1}
