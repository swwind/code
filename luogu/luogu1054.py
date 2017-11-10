import random
match = input().replace('^', '**')
n = int(input())
s = []
attp = 0
for i in range(n):
	s.append(input().replace('^', '**'))
for str in s:
	flag = 1
	for a in range(100)[1::]:
		try:
			ans = eval(match)
			res = eval(str)
		except Exception as e:
			flag = 0
			break
		if ans != res:
			flag = 0
			break
	if flag:
		print(chr(ord('A') + attp), end='')
	attp += 1