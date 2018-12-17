a, b = input().split(' ')
ans = bns = 0
lbc = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
for i in a:
	ans += lbc[int(i)]
for i in b:
	bns += lbc[int(i)]
print(ans - bns)