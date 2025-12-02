#include <bits/stdc++.h>
#include <cstdio>

// std::pair<int, int> a[300030];
#define MOD 998244353

int a[300030];
int dp[300030];
// int sum[300030];

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      a[i] = -1;
    }

    int l, r;
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &l, &r);
      if (a[r] == -1)
        a[r] = l;
      else
        a[r] = std::max(a[r], l);
    }

    dp[1] = 1;
    int right_most = 0;
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] * 2 % MOD;
      if (a[i] > right_most) {
        dp[i] = (dp[i] - dp[a[i]] + MOD) % MOD;
        right_most = a[i];
      }
    }

    printf("%d\n", dp[n] * 2 % MOD);
  }
}