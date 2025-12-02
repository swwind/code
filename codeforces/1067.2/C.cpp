#include <bits/stdc++.h>
#include <climits>
#include <cstdio>

#define N 200030

int a[N], b[N];
long long dp[N][2];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
      scanf("%d", b + i);
    for (int i = 1; i <= n; ++i)
      dp[i][0] = dp[i][1] = 0;

    dp[0][0] = dp[0][1] = -2e15;
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = std::max((long long)a[i], dp[i - 1][0] + a[i]);
      dp[i][1] =
          std::max((long long)a[i] + b[i],
                   std::max(dp[i - 1][0] + a[i] + b[i], dp[i - 1][1] + a[i]));
    }

    int op = k & 1;
    long long ans = -2e15;
    for (int i = 1; i <= n; ++i) {
      ans = std::max(ans, dp[i][op]);
    }
    printf("%lld\n", ans);
  }
}