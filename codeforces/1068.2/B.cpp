#include <algorithm>
#include <cstdio>

#define N 100020

int a[N];
int b[N];
long long dp[N][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
      scanf("%d", b + i);

    for (int i = 1; i <= n; ++i) {
      dp[i][0] = std::max(dp[i - 1][0] - a[i], b[i] - dp[i - 1][1]);
      dp[i][1] = std::min(dp[i - 1][1] - a[i], b[i] - dp[i - 1][0]);
    }

    printf("%lld\n", dp[n][0]);
  }
}
