#include <bits/stdc++.h>
#define mod 998244353

using namespace std;

// f[x][y] indicates there are x numbers and their sum is y
int f[52][2502], g[52][2502];

int fast_pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = (long long) x * x % mod) {
    if (y & 1) {
      res = (long long) res * x % mod;
    }
  }
  return res;
}
int n, k, D;
int frac[2520];
int inv[2520];
int rc[] = { 1, -1 };

int calculate(int x, int y) {
  return (long long) fast_pow(n - x, D + n * k - y) * frac[n * k - y] % mod;
}

int C[55][55];

void initialize_C() {
  for (int i = 0; i < 55; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}

int main() {

  scanf("%d%d%d", &n, &k, &D);
  initialize_C();

  int dd = 1;
  for (int i = 1; i <= n*k; ++ i) {
    dd = (long long) dd * i % mod;
  }
  inv[n*k] = fast_pow(dd, mod - 2);
  for (int i = n*k-1; i >= 0; -- i) {
    inv[i] = (long long) inv[i+1] * (i + 1) % mod;
  }

  for (int i = n*k+1; i <= D+n*k; ++ i) {
    dd = (long long) dd * i % mod;
  }
  frac[n*k] = fast_pow(dd, mod - 2);
  for (int i = n*k-1; i >= 0; -- i) {
    frac[i] = (long long) frac[i+1] * (D + i + 1) % mod;
  }

  f[0][0] = 1;
  // for (int t = 1; t <= n; ++ t) {
  //   swap(f, g);
  //   memcpy(f, g, sizeof(g));

  //   for (int i = 0; i < t; ++ i) {
  //     for (int v = 0; v < k; ++ v) {
  //       for (int j = 0; j <= i*(k-1); ++ j) {
  //         f[i+1][j+v] = (f[i+1][j+v] + (long long) g[i][j] * inv[v] % mod) % mod;
  //       }
  //     }
  //   }
  // }

  f[0][0] = 1;
  for (int i = 1; i <= n; ++ i) {
    for (int v = 0; v < k; ++ v) {
      for (int j = v; j <= i*(k-1); ++ j) {
        f[i][j] = (f[i][j] + (long long) f[i-1][j-v] * inv[v] % mod) % mod;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++ i) {
    for (int j = 0; j <= n * k; ++ j) {
      int v = (long long) f[i][j] * calculate(i, j) % mod * C[n][i] % mod;
      if (i & 1) {
        ans = (ans + mod - v) % mod;
      } else {
        ans = (ans + v) % mod;
      }
    }
  }

  dd = 1;
  for (int i = 1; i <= D; ++ i) {
    dd = (long long) dd * i % mod;
  }

  printf("%d\n", (long long) ans * dd % mod);

}