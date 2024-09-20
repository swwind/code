#include <bits/stdc++.h>
#define N 200020

using namespace std;

int to[2 * N], nxt[2 * N], head[N], cnt;

void insert(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
  to[++cnt] = x;
  nxt[cnt] = head[y];
  head[y] = cnt;
}

int dep[N], f[N];
void dfs(int x, int fa) {
  f[x] = fa;
  dep[x] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa)
      continue;
    dfs(to[i], x);
    dep[x] = max(dep[x], dep[to[i]] + 1);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    int x, y;
    scanf("%d", &n);
    memset(head, 0, sizeof(head));

    cnt = 0;
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &x, &y);
      insert(x, y);
    }
    scanf("%d%d", &x, &y);
    dfs(1, 0);

    while (f[y] != 1)
      y = f[y];

    int a = 0;
    for (int i = head[1]; i; i = nxt[i])
      if (to[i] != y)
        a = max(a, dep[to[i]]);
    int b = dep[x];
    int c = dep[y] - dep[x];
    // printf("%d %d %d\n", a, b, c);

    if ((a > max(c, b)) || ((c & 1 == 1) && (c > b))) {
      puts("Alice");
    } else {
      puts("Bob");
    }
  }
}
