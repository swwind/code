a, b = map(int, input().split(' '))
c = 1
a += 1
while a <= b :
	c = c*a%10
	a += 1
	if c == 0 :
		break
print(c)
