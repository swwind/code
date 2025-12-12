#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>

#define N 200020
#define M 200020

#define MOD 998244353

long long a[N];

int head[N], to[M], nxt[M], cnt;
void insert(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

// std::map<std::pair<int, int>, int> vis;
int w[M], u[M], v[M], vis[M];
std::map<std::pair<int, long long>, int> mp;

int dfs(int e) {
  if (vis[e])
    return w[e];
  vis[e] = 1;
  w[e] = 1;
  if (mp.find({v[e], a[u[e]] + a[v[e]]}) != mp.end()) {
    w[e] = (w[e] + mp[{v[e], a[u[e]] + a[v[e]]}]) % MOD;
    return w[e];
  }
  int ans = 0;
  for (int i = head[v[e]]; i; i = nxt[i]) {
    if (a[to[i]] == a[u[e]] + a[v[e]]) {
      ans = (ans + dfs(i)) % MOD;
    }
  }
  mp[{v[e], a[u[e]] + a[v[e]]}] = ans;
  w[e] = (w[e] + ans) % MOD;
  return w[e];
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);

    mp.clear();
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      //   c[i] = i;
      head[i] = 0;
    }

    for (int i = 1; i <= m; ++i) {
      //   int u, v;
      //   scanf("%d%d", &u, &v);
      scanf("%d%d", u + i, v + i);
      insert(u[i], v[i]);
      //   d[cnt] = 0;
      //   insert(v, u);
      //   d[cnt] = 0;
      //   c[i] = i;
      w[i] = 0;
      vis[i] = 0;
    }

    int ans = 0;
    for (int x = 1; x <= m; ++x) {
      ans = (ans + dfs(x)) % MOD;
    }

    printf("%d\n", ans);
  }
}