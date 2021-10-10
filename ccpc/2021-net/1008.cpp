#include <bits/stdc++.h>

using namespace std;

int a[20];

int cnt[20];

bool ok(int m) {
  for (int i = 1; i <= m; ++ i) {
    if (cnt[i] != 1) return false;
  }
  return true;
}

int q[10000020];

int work(int n, int m) {
  int top = 0;
  for (int i = 1; i <= n; ++ i) a[i] = i;
  do {
    for (int i = 1; i <= n; ++ i) {
      q[++ top] = a[i];
    }
  } while (next_permutation(a + 1 , a + n + 1));
  int l = 1, r = 0;
  while (r < m) ++ cnt[q[++ r]];
  int ans = ok(m);
  while (r < top) {
    ++ cnt[q[++ r]];
    -- cnt[q[l ++]];
    ans += ok(m);
  }
  while (l <= top) -- cnt[q[l ++]];
  return ans;
}

int frac[20];
int c[20][20];

int main() {
  frac[0] = 1;
  for (int i = 1; i <= 10; ++ i) frac[i] = frac[i-1]*i;
  for (int i = 0; i <= 10; ++ i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++ j) {
      c[i][j] = c[i-1][j-1]+c[i-1][j];
    }
  }

  for (int n = 1; n <= 9; ++ n) {
    printf("n=%d |\t", n);
    for (int m = 1; m <= n; ++ m) {
      // printf("n = %d, m = %d, ans = %d\n", n, m, work(n, m));
      int ans = work(n, m);
      // printf("%d%c", ans-frac[n-m], "\t\n"[n==m]);
      // int d = frac[n-m+1]*frac[m];
      // int d = frac[n];
      int d = 0;
      // for (int i = 0; i <= n; ++ i) {
      //   d += (frac[n-i]-1)*frac[n]/frac[n-i];
      // }
      // int d = 0;
      // printf("%d/%d%c", ans/d, ans%d, "\t\n"[n==m]);
      printf("%d%c", ans-d, "\t\n"[n==m]);
    }
  }

  for (int i = 4; i <= 9; ++ i) {
    printf("%d %d\n", work(i,i-2), frac[i+1] + 2 * frac[i]);
  }
}
