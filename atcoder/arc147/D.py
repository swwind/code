n, m = map(int, input().split(' '))
a = pow(n, m, 998244353)
b = pow(m,n-1,998244353)
print(a*b%998244353)