/// 1 2 3 with same pi=1/3

/*

suppose EY = f[y] means how much step can go after getting y

if next we have x<y, x=y, or x>y

f[y] = p[1..y-1] + (1+f[y])*p[y] + (1+f[y+1..n])*p[y+1..n]

f[y] = 1 + f[y]*p[y] + f[y+1..n]*p[y+1..n]

f[y] = (1 + f[y+1..n]*p[y+1..n]) / (1 - p[y])


now we trying to get E(Y^2) = g[y] after getting y

but first we have g[y+1] = E((Y+1)^2) = E(Y^2)+2EY+1 = g[y]+2f[y]+1

same as f[y], we have x<y, x=y, or x>y

g[y] = p[1..y-1]*1 + p[y]*g[y+1] + g[y+2..n+1]*p[y+1..n]

g[y] = p[1..y-1]*1 + p[y]*(g[y]+2f[y]+1) + (g[y+1..n]+2f[y+1..n]+1)*p[y+1..n]

g[y] = (1 + 2f[y]p[y] + (g[y+1..n]+2f[y+1..n])*p[y+1..n]) / (1 - p[y])

*/

#include <bits/stdc++.h>
#define N 100020
#define mod 998244353

using namespace std;

int w[N], p[N], inv1subp[N], f[N], g[N];

int fast_pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = (long long) x * x % mod) {
    if (y & 1) {
      z = (long long) z * x % mod;
    }
  }
  return z;
}

int inv(int x) {
  return fast_pow(x, mod - 2);
}

int main() {

  int n; scanf("%d", &n);
  int sumw = 0;
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", w + i);
    sumw += w[i];
  }

  int inv_sumw = inv(sumw);
  for (int i = 1; i <= n; ++ i) {
    p[i] = (long long) w[i] * inv_sumw % mod;
    inv1subp[i] = inv((mod + 1 - p[i]) % mod);
  }

  int sumfp = 0;
  for (int i = n; i; -- i) {
    f[i] = (long long) (1 + sumfp) % mod * inv1subp[i] % mod;
    sumfp = (sumfp + (long long) f[i] * p[i] % mod) % mod;
  }

  int sumgfp = 0;
  for (int i = n; i; -- i) {
    g[i] = (1 + 2ll * f[i] % mod * p[i] % mod + sumgfp) % mod * inv1subp[i] % mod;
    sumgfp = (sumgfp + (long long) (g[i] + 2ll * f[i] % mod) % mod * p[i] % mod) % mod;
  }

  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans = (ans + (g[i] + 2ll * f[i] % mod + 1) % mod * p[i] % mod) % mod;
  }

  printf("%lld\n", ans);
}

