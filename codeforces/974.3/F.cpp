#include <bits/stdc++.h>
#define N 200020

using namespace std;

int to[2 * N], nxt[2 * N], head[N], cnt;

void insert(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

int val[N], c;
long long dp[N][2];

void dfs(int x, int fa) {
  dp[x][0] = 0;
  dp[x][1] = val[x];
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa)
      continue;
    dfs(to[i], x);
    long long mx = max(dp[to[i]][0], dp[to[i]][1]);
    dp[x][0] += mx;
    long long vx = max(dp[to[i]][0], dp[to[i]][1] - 2ll * c);
    dp[x][1] += vx;
  }
  // printf("dp[%d] = (%d, %d)\n", x, dp[x][0], dp[x][1]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%d", &n, &c);
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      head[i] = 0;
      scanf("%d", val + i);
    }

    for (int i = 2; i <= n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      insert(x, y);
      insert(y, x);
    }
    dfs(1, 1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
  }
}
