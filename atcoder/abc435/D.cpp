#include <algorithm>
#include <cstdio>

#define N 300030
#define M 300030
#define Q 300030

int head[N], nxt[M], to[M], cnt;
void insert(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

// int op[Q], qx[Q];
int vis[N];

void dfs(int x, int f) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f)
      continue;
    if (vis[to[i]])
      continue;
    vis[to[i]] = 1;
    dfs(to[i], x);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    // insert(x, y);
    insert(y, x);
  }

  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int op, qx;
    scanf("%d%d", &op, &qx);

    if (op == 1) {
      if (vis[qx])
        continue;
      vis[qx] = 1;
      dfs(qx, 0);
    } else {
      puts(vis[qx] ? "Yes" : "No");
    }
  }
}
