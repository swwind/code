#include <bits/stdc++.h>
#define mod 998244353
#define N 5020

using namespace std;

int frac[N*N];
int inv[N*N];

int fast_pow(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) res = (long long) res * x % mod;
    x = (long long) x * x % mod;
    y >>= 1;
  }
  return res;
}

int A(int n, int m) {
  if (n < m) return 0;
  return (long long) frac[n] * inv[n-m] % mod;
}

int main() {
  int t;
  scanf("%d", &t);

  frac[0] = 1;
  for (int i = 1; i <= 25000000; i++) {
    frac[i] = (long long) i * frac[i-1] % mod;
  }
  inv[25000000] = fast_pow(frac[25000000], mod-2);
  for (int i = 25000000-1; i >= 0; i--) {
    inv[i] = (long long) inv[i+1] * (i+1) % mod;
  }

  while (t--) {
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; ++ i) {
      sum = (sum + A(n*n-i, n-1)) % mod;
      // printf("i=%d, %d\n", i, A(n*n-i, n-1));
    }
    int ans = (long long) sum * frac[n*n-n] % mod;
    ans = (long long) ans * n % mod;
    ans = (long long) ans * n % mod;
    printf("%d\n", ans);
  }
}
