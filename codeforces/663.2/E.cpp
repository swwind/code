#include <bits/stdc++.h>
#define N 1000020
using namespace std;

int t;

int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int fa[N], vis[N], dep[N], max_depth, max_depth_node;
void dfs(int x) {
  vis[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (!vis[to[i]]) {
      fa[to[i]] = x;
      dep[to[i]] = dep[x] + 1;
      if (dep[to[i]] > max_depth) {
        max_depth = dep[to[i]];
        max_depth_node = to[i];
      }
      dfs(to[i]);
    }
  }
}

int d[N], a[N], b[N], ans;

int main() {
  scanf("%d", &t);
  while (t --) {
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    cnt = 0;
    for (int i = 1; i <= n; ++ i) {
      head[i] = 0;
    }
    for (int i = 1; i <= m; ++ i) {
      scanf("%d%d", &x, &y);
      insert(x, y);
    }
    max_depth = 1;
    max_depth_node = 1;
    dep[1] = 1;
    for (int i = 1; i <= n; ++ i) {
      vis[i] = 0;
    }
    dfs(1);

    if (max_depth >= ceil(n * 0.5)) {
      puts("PATH");
      printf("%d\n", max_depth);
      int s = max_depth_node;
      while (s) {
        printf("%d ", s);
        s = fa[s];
      }
      puts("");
    } else {
      for (int i = 1; i <= max_depth; ++ i) {
        d[i] = 0;
      }
      ans = 0;
      for (int i = 1; i <= n; ++ i) {
        if (!d[dep[i]]) {
          d[dep[i]] = i;
        } else {
          ++ ans;
          a[ans] = d[dep[i]];
          b[ans] = i;
          d[dep[i]] = 0;
        }
      }
      puts("PAIRING");
      printf("%d\n", ans);
      for (int i = 1; i <= ans; ++ i) {
        printf("%d %d\n", a[i], b[i]);
      }
    }
  }
}