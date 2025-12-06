#include <climits>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

// int limit;

// int dfs(int depth, int x) {
//   // printf("%d, %d\n", depth, x);
//   if (!depth)
//     return 0;
//   if (x >= limit)
//     return 0;

//   int ans = 0;
//   int a[32];
//   for (int i = 0; i < 32; ++i) {
//     a[i] = (x >> i) & 1;
//   }

//   for (int i = 0; i < 32; ++i) {
//     if (i == 0 ? a[i] : (a[i] == 1 && a[i - 1] == 0)) {
//       // printf("%d -> %d\n", x, i);
//       int nxt = x + (1 << i);
//       int cnt = 0;
//       for (int j = i; j < 32 && a[j]; ++j)
//         cnt += 1;
//       ans = std::max(ans, cnt + dfs(depth - 1, nxt));
//     }
//   }

//   return ans;
// }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[32];

    int lwbit = -1;
    int mxbit = 0;
    for (int i = 0; i < 32; ++i) {
      a[i] = (n >> i) & 1;
      if (a[i])
        mxbit = i;
      if (a[i] && lwbit == -1)
        lwbit = i;
    }

    // limit = (1 << (mxbit + 1));
    // printf("limit = %d\n", limit);

    int fa[32], fb[32], ca = 0, cb = 0;
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    for (int i = lwbit + 1, j = lwbit; i <= mxbit + 1; ++i) {
      if (a[i] == 1 && a[i - 1] == 0) {
        fb[++cb] = i - j;
        j = i;
      } else if (a[i] == 0 && a[i - 1] == 1) {
        fa[++ca] = i - j;
        j = i;
      }
    }

    int estimate = 1;
    for (int i = lwbit; i < mxbit; ++i) {
      if (a[i] == 0)
        estimate += 1;
    }
    // printf("estimate = %d\n", estimate);

    // for (int i = 0; i < 32; ++i) {
    //   printf("%d", a[i]);
    // }
    // puts("");
    // for (int i = 1; i <= ca; ++i)
    //   printf("%d%c", fa[i], " \n"[i == ca]);
    // for (int i = 1; i <= cb; ++i)
    //   printf("%d%c", fb[i], " \n"[i == cb]);

    int step = std::min(k, estimate);

    int dp[ca + 1][step + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= step; ++j)
      dp[0][j][0] = dp[0][j][1] = -99999999;
    dp[0][0][1] = -99999999;

    for (int i = 1; i <= ca; ++i) {
      // do nothing
      for (int j = 0; j <= step; ++j) {
        dp[i][j][0] = std::max(dp[i - 1][j][1], dp[i - 1][j][0]);
      }
      dp[i][0][1] = -99999999;
      // use one step to gain points
      for (int j = 1; j <= step; ++j) {
        dp[i][j][1] =
            std::max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + fa[i];
      }
      // or use moresteps to gain points
      if (i > 1) {
        for (int j = fb[i - 1]; j <= step; ++j) {
          dp[i][j][1] = std::max(dp[i][j][1], dp[i - 1][j - fb[i - 1]][1] +
                                                  fa[i] + fb[i - 1]);
        }
      }

      // for (int j = 0; j <= step; ++j) {
      //   printf("dp[%d][%d] = (%d, %d)\n", i, j, dp[i][j][0], dp[i][j][1]);
      // }
    }

    int cost = 0;
    for (int i = 0; i <= step; ++i) {
      cost = std::max(cost, std::max(dp[ca][i][0], dp[ca][i][1]) + (step - i));
    }
    // printf("%d\n", cost);

    if (k <= estimate) {
      // int cost = dfs(k, n);
      printf("%d\n", cost);
    } else {
      // int cost = dfs(estimate, n);
      printf("%d\n", cost + (k - estimate));
    }
  }
}
