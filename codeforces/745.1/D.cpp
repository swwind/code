#include <bits/stdc++.h>
#define N 4020
using namespace std;

long long a[N];
int st[N], top;

int ls[N], rs[N];

// f[x][i] means select i person in node x
// and the max result we can get.
long long dp[N][N];
int n, m;
int sz[N];

void dfs(int x) {
  if (ls[x]) dfs(ls[x]);
  if (rs[x]) dfs(rs[x]);
  sz[x] = sz[ls[x]] + sz[rs[x]] + 1;

  for (int i = 0; i <= sz[ls[x]]; ++ i) {
    for (int j = 0; j <= sz[rs[x]] && i + j <= m; ++ j) {
      // self not choose
      dp[x][i + j] = max(dp[x][i + j],
        dp[ls[x]][i] + i * (a[ls[x]] - a[x]) * (m - i) +
        dp[rs[x]][j] + j * (a[rs[x]] - a[x]) * (m - j));
    }
  }
  for (int i = min(sz[ls[x]] + sz[rs[x]] + 1, m); i; -- i) {
    dp[x][i] = max(dp[x][i], dp[x][i - 1]);
  }
}

int main() {
  cin >> n >> m;

  int min_val = INT_MAX;
  int min_pos = 0;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
    if (a[i] < min_val) {
      min_val = a[i];
      min_pos = i;
    }
  }

  for (int i = 1; i <= n; ++ i) {
    int last_top = top;
    while (top > 0 && a[st[top]] > a[i]) {
      -- top;
    }
    for (int j = top + 1; j < last_top; ++ j) {
      rs[st[j]] = st[j+1];
    }
    if (top + 1 <= last_top) {
      ls[i] = st[top+1];
    }
    st[++top] = i;
  }
  while (top > 1) {
    rs[st[top-1]] = st[top];
    -- top;
  }

  dfs(min_pos);

  cout << dp[min_pos][m] << endl;

}
