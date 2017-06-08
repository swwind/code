mp = {'T':'A', 'A':'T', 'C':'G', 'G':'C'}

n, m = map(int, raw_input().split())
str1 = raw_input()
str2 = raw_input()
f = [0]*(m+1)
f[0] = 1

for i in range(n):
	for j in range(m)[::-1]:
		if mp[str1[i]] == str2[j]:
			f[j+1] += f[j]

print(f[m])
