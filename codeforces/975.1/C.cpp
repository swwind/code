#include <bits/stdc++.h>
#define N 500050

using namespace std;

int head[N], nxt[N << 1], to[N << 1], cnt;
void insert(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

int dep[N], mxd[N];
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  mxd[x] = dep[x];
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa)
      continue;
    dfs(to[i], x);
    mxd[x] = max(mxd[x], mxd[to[i]]);
  }
}

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = head[i] = 0;
    }
    for (int i = 1, x, y; i < n; ++i) {
      scanf("%d%d", &x, &y);
      insert(x, y);
      insert(y, x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
      a[dep[i]]++;
      a[mxd[i] + 1]--;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = max(ans, a[i] += a[i - 1]);
    }
    printf("%d\n", n - ans);
  }
}
