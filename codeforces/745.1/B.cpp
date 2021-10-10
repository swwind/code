#include <bits/stdc++.h>

using namespace std;

int f[102][102][102];
int mod;

int C[102][102];
int frac[102];

// calculate numbers of permutations which contains n elements
// and with exactly k elements which only has m different values
int calc(int n, int m, int k) {
  if (n == 1) {
    return (m == 1 && k == 1) || (k == 0 && m != 1);
  }
  if (m > n) return (k == 0) * frac[n];
  if (n == 0) return k == 0;
  if (k > n) return 0;
  if (m == 1) {
    return (k == 1) * frac[n];
  }
  if (f[n][m][k] > -1) return f[n][m][k];

  int &res = f[n][m][k];
  res = 0;
  for (int i = 1; i <= n; ++ i) {
    int ln = i-1;
    int rn = n-i;
    int ans = 0;
    for (int j = 0; j <= k; ++ j) {
      int ans1 = calc(ln, m - 1, j);
      if (ans1) {
        ans = (ans + (long long) ans1 * calc(rn, m - 1, k - j) % mod) % mod;
      }
      // printf("f[%d][%d][%d] += f[%d][%d][%d] * f[%d][%d][%d] = %d * %d\n", n,m,k,ln,m-1,j,rn,m-1,k-j,calc(ln, m - 1, j),calc(rn, m - 1, k - j));
    }
    // printf("i = %d, ans = %d\n", i, ans);
    res = (res + (long long) ans * C[n-1][i-1] % mod) % mod;
  }
  // printf("f[%d][%d][%d] = %d\n", n, m, k, f[n][m][k]);
  return res;
}

int main() {
  int n, m, k;
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  memset(f, -1, sizeof(f));

  for (int i = 0; i <= n; ++ i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++ j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  frac[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    frac[i] = (long long) frac[i-1] * i % mod;
  }

  printf("%d\n", calc(n, m, k));

}
