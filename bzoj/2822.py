n = int(raw_input())
f = [0 for i in range(n+1)]

def get(x):
	if f[x]:
		return f[x]
	for i in range(x):
		f[x] += get(x-1-i)*get(i)
	return f[x]

f[1] = f[0] = 1
print(get(n))

# print(f)