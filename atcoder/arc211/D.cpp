#include <bits/stdc++.h>
#include <cstdio>

#define N 200030
#define M 300030

int head[N], nxt[M << 1], to[M << 1], cnt;
void insert(int x, int y) {
  nxt[++cnt] = head[x];
  to[cnt] = y;
  head[x] = cnt;
}

int vis1[N], vis2[N];
int blue[N], yell[N];

void dfs1(int x, int f) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f)
      continue;
    if (!vis1[to[i]]) {
      vis1[to[i]] = 1;
      blue[to[i]] = x;
      dfs1(to[i], x);
    }
  }
}

void dfs2(int x, int f) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f || blue[to[i]] == x)
      continue;
    if (!vis2[to[i]]) {
      vis2[to[i]] = 1;
      yell[to[i]] = x;
      dfs2(to[i], x);
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    insert(u, v);
    insert(v, u);
  }

  vis1[1] = 1;
  dfs1(1, 0);

  vis2[2] = 1;
  dfs2(2, 0);

  int fail = 0;
  for (int i = 1; i <= n; ++i) {
    if (!vis1[i])
      fail = 1;
    if (!vis2[i])
      fail = 1;
  }

  if (fail) {
    puts("No");
  } else {
    puts("Yes");
    printf("%d\n", yell[1]);
    printf("%d\n", blue[2]);
    for (int i = 3; i <= n; ++i) {
      printf("%d %d\n", blue[i], yell[i]);
    }
  }
}
