#include <bits/stdc++.h>
#define N 2020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll frac[N*N];
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}
ll inv(ll x) {
  return fast_pow(x, mod - 2);
}
ll C(ll m, ll n) {
  return frac[m] * inv(frac[n]) % mod * inv(frac[m - n]) % mod;
}
int f[N][N];
int main(int argc, char const *argv[]) {

  frac[0] = 1;
  for (int i = 1; i <= 4000000; ++ i) {
    frac[i] = frac[i - 1] * i % mod;
  }

  int n = read(), k = read();

  if (k == 1) {
    return puts("1"), 0;
  }

  f[0][1] = 1;
  for (int j = 1; j <= n; ++ j) {
    for (int i = 0; i <= j; ++ i) {
      if (i < j) f[i + 1][j] = (f[i + 1][j] + f[i][j]) % mod;
      if (j < n) f[i][j + 1] = (f[i][j + 1] + f[i][j] * C(i + (j + 1) * (k - 1) - 1, k - 2) % mod) % mod;
    }
  }
  printf("%lld\n", f[n][n] * frac[n] % mod);
  return 0;
}
/*
问题转化为拓扑计数问题

颜色顺序最后乘一个阶乘即可，现在要计算的是如下图的拓扑方案数。

| (0)->(0)->(0)->(0)->(0)
|  |    |    |    |    |
|  v    v    v    v    v
| (1)->(2)->(3)->(4)->(5)
|  |    |    |    |    |
|  v    v    v    v    v
| (1)  (2)  (3)  (4)  (5)
|  |    |    |    |    |
|  v    v    v    v    v
| (1)  (2)  (3)  (4)  (5)
|  |    |    |    |    |
|  v    v    v    v    v
| (1)  (2)  (3)  (4)  (5)

只需按照前两行从后往前转移即可。

f[i][j] 表示选了 i 个 0, j 种颜色的方案数。

每次转移相当于加入一个 0 或者加入一列。

|               .-- i ---.
|                (0)->(0)
|                 |    |
|                 v    v
|      (2)->(3)->(4)->(5)
|       |    |    |    |
|       v    v    v    v
|      (2)  (3)  (4)  (5)
|       |    |    |    |
|       v    v    v    v
|      (2)  (3)  (4)  (5)
|       |    |    |    |
|       v    v    v    v
|      (2)  (3)  (4)  (5)
|     `-------- j -------'

f[i+1][j] += f[i][j]
f[i][j+1] += f[i][j] * C(i+j*(k-1)+k-2, k-2)

ans = f[n][n] * n!

*/