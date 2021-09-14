#include <bits/stdc++.h>
#define N 10000020
#define mod 1000000009
using namespace std;

int pow2[N], frac[N], invf[N];

int fast_pow(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long) x * x % mod) {
    if (y & 1) {
      ans = (long long) ans * x % mod;
    }
  }
  return ans;
}

int inv(int x) {
  return fast_pow(x, mod - 2);
}

int C(int n, int m) {
  if (n < m) {
    return 0;
  }
  if (n < 0 || m < 0) {
    return 0;
  }
  return (long long) frac[n] * invf[m] % mod * invf[n - m] % mod;
}

int main() {
  int x, y;
  scanf("%d%d", &x, &y);

  pow2[0] = 1;
  frac[0] = 1;
  for (int i = 1; i <= x+y; ++ i) {
    pow2[i] = (long long) pow2[i-1] * 2 % mod;
    frac[i] = (long long) frac[i-1] * i % mod;
  }
  invf[x+y] = inv(frac[x+y]);
  for (int i = x+y-1; i >= 0; -- i) {
    invf[i] = (long long) invf[i+1] * (i+1) % mod;
  }

  int ans1 = 0, ans2 = 0;
  for (int k = 0; k <= x+y-4; ++ k) {
    int res = (long long) pow2[k] * frac[k] % mod;
    res = (long long) res * C(x+y-4, k) % mod;
    // printf("f[%d] = %d\n", k, res);
    ans1 ^= res;
  }

  int A = 1; // A = S(n+m-k, n)
  int B = 0; // B = S(n+m-k, n-k-1)
  for (int k = x+y-4; k >= 0; -- k) {
    int res = (long long) frac[x-2] * frac[y-2] % mod * pow2[k] % mod;
    res = (long long) res * invf[x+y-4-k] % mod * ((A - B + mod) % mod) % mod;
    A = ((long long) 2 * A % mod - C(x+y-4-k, x-2) + mod) % mod;
    B = ((long long) 2 * B % mod - C(x+y-4-k, x-2-k-1) + mod) % mod;
    B = (B + C(x+y-4-k+1, x-2-k)) % mod;
    ans2 ^= res;
    // printf("f[%d] = %d\n", k, res);
  }

  printf("%d %d\n", ans1, ans2);

  // fx[0] = 1;
  // for (int i = 1; i <= x-2; ++ i) {
  //   fx[i] = fx[i-1] * (x-1ll-i) % mod * 2ll % mod;
  // }
  // fy[0] = 1;
  // for (int i = 1; i <= y-2; ++ i) {
  //   fy[i] = fy[i-1] * (y-1ll-i) % mod * 2ll % mod;
  // }

  // int ans = 0;
  // for (int i = 0; i <= x + y - 4; ++ i) {
  //   int res = 0;
  //   for (int a = 0; a <= i; ++ a) {
  //     // printf("+= f[%d] * f[%d] = %d * %d\n", a, i - a, fx[a], fy[i-a]);
  //     res = (res + (long long) fx[a] * fy[i - a] % mod) % mod;
  //   }
  //   // printf("res = %d\n", res);
  //   ans ^= res;
  // }
  // printf("%d\n", ans);

  // fx[1] = (x-2)*2;
  // fx[2] = (x-2)*2 * (x-3)*2;
  // ..
  // fx[x-2] = (x-2)*2 * (x-3)*2 * (x-4)*2 * ... * 1*2;

  // fx[a] = 2^a * (x-2)!/(x-2-a)!
  // fy[b] = 2^b * (y-2)!/(y-2-a)!

  // fx[1] = (x-2)*2;
  // fx[2] = (x-2)*2 * (x-3)*2;
  // ..
  // fx[x-2] = (x-2)*2 * (x-3)*2 * (x-4)*2 * ... * 1*2;
}