// #pragma GCC optimize(2)
#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
// #include <vector>

int a[100020];

// int f[400][400];
// int g[400][400];
// int dp[400][400];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }

    std::vector<std::vector<int>> f(k + 1, std::vector<int>(k + 1));
    std::vector<std::vector<int>> g(k + 1, std::vector<int>(k + 1));
    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(k + 1));

    for (int x = 0; x <= k; ++x) {
      for (int y = 0; y <= k; ++y) {
        f[x][y] = -99999999;
      }
    }

    f[0][0] = 0;

    // int last_non_zero = 0;
    // for (int i = 1; i <= n; ++i)
    //   if (a[i] > 0)
    //     last_non_zero = i;

    // dp[i][x][y] -> i-th friend, the max before is x, the cards used is y
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] <= mx)
        continue;
      else
        mx = a[i];

      std::swap(f, g);
      int h = (n - i + 1);

      for (int x = 0; x <= k; ++x) {
        for (int y = 0; y <= k; ++y) {
          // f[x][y] = -99999999;
          f[x][y] = g[x][y]; // no choosing
          // if (x == 0) {
          //   dp[0][y] = g[0][y];
          // } else {
          //   dp[x][y] = std::max(dp[x - 1][y], g[x][y] - x * h);
          // }
        }
      }

      // for (int x = 0; x <= k; ++x) {
      //   for (int y = 0; y <= k; ++y) {
      //     for (int c = 0; c <= std::min(y, a[i]); ++c) {
      //       int nx = std::max(x, c);
      //       f[nx][y] = std::max(f[nx][y], g[x][y - c] + nx);
      //     }
      //   }
      // }

      // // dp[x][y] = max(g[c][y] - c * h for c in [0..x]);
      for (int y = 0; y <= k; ++y) {
        dp[0][y] = g[0][y];
      }
      for (int x = 1; x <= k; ++x) {
        for (int y = 0; y <= k; ++y) {
          dp[x][y] = std::max(dp[x - 1][y], g[x][y] - x * h);
        }
      }

      // int h = (n - i + 1);
      for (int c = 1; c <= a[i]; ++c) {
        for (int y = c; y <= k; ++y) {
          // int ans = -99999999;
          // for (int x = 0; x < c; ++x) {
          //   ans = std::max(ans, g[x][y - c] - x * h);
          // }
          int ans = dp[c - 1][y - c];
          f[c][y] = std::max(f[c][y], ans + c * h);
        }
      }
    }

    int ans = 0;
    for (int x = 0; x <= k; ++x) {
      for (int y = 0; y <= k; ++y) {
        ans = std::max(ans, f[x][y]);
      }
    }

    printf("%d\n", ans);
  }
}
