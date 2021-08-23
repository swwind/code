#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

char A[5020], B[5020];

int frac[10020], invf[10020];

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

void initialize() {
  frac[0] = 1;
  invf[0] = 1;
  for (int i = 1; i <= 10000; ++ i) {
    frac[i] = (long long) frac[i-1] * i % mod;
    invf[i] = inv(frac[i]);
  }
}

int C(int n, int m) {
  return (long long) frac[n] * invf[m] % mod * invf[n - m] % mod;
}

int calc(int a, int b) {
  return C(a + b, a);
}

int f[5020][5020];

int main() {
  scanf("%s%s", A+1, B+1);
  int n = strlen(A + 1);
  int m = strlen(B + 1);
  initialize();

  for (int i = 0; i <= n; ++ i) {
    for (int j = 0; j <= m; ++ j) {
      if (!i || !j) f[i][j] = 1;
      else {
        f[i][j] = (f[i-1][j] + f[i][j-1]) % mod;
        if (A[i] != B[j]) {
          f[i][j] = (f[i][j] + mod - f[i-1][j-1]) % mod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      if (A[i] < B[j]) {
        ans = (ans + (long long) f[i-1][j-1] * calc(n - i, m - j) % mod) % mod;
      }
    }
  }
  printf("%d\n", ans);
}
