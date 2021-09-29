#include <bits/stdc++.h>
#define N 2001
#define M 5001
using namespace std;

struct Bitset {
  __uint64_t v[32];
  friend Bitset operator | (const Bitset &a, const Bitset &b) {
    Bitset c;
    for (int i = 0; i < 32; ++ i) {
      c.v[i] = a.v[i] | b.v[i];
    }
    return c;
  }
  friend Bitset operator & (const Bitset &a, const Bitset &b) {
    Bitset c;
    for (int i = 0; i < 32; ++ i) {
      c.v[i] = a.v[i] & b.v[i];
    }
    return c;
  }
  void set(int x, bool s) {
    int p = x / 64;
    int i = x % 64;
    if (s) v[p] |=  (1ull << i);
    else   v[p] &= ~(1ull << i);
  }
  bool get(int x) {
    int p = x / 64;
    int i = x % 64;
    return (v[p] >> i) & 1;
  }
  bool any() {
    for (int i = 0; i < 32; ++ i) {
      if (v[i]) {
        return true;
      }
    }
    return false;
  }
};

int head[N], to[M], nxt[M], ww[M], cnt;
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; ww[cnt] = w;
}

int n, m;
int dis[N][N];
int www[N][N];
bool has[N][N];

struct Node {
  int d, v;
  friend bool operator < (const Node &a, const Node &b) {
    return a.d > b.d;
  }
};

priority_queue<Node> q;

void dijkstra() {
  memset(dis, 0x3f, sizeof(dis));
  for (int x = 0; x < n; ++ x) {
    dis[x][x] = 0;
    q.push(Node{0, x});
    while (!q.empty()) {
      Node now = q.top(); q.pop();
      if (now.d != dis[x][now.v]) {
        continue;
      }
      for (int i = head[now.v]; i; i = nxt[i]) {
        int u = to[i];
        if (dis[x][u] > now.d + ww[i]) {
          dis[x][u] = now.d + ww[i];
          q.push(Node{dis[x][u], u});
        }
      }
    }
  }
}

Bitset f[N], g[N], pot[N];
// bool can[N][N];

int tmp[N];

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; ++ i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    -- x; -- y;

    insert(x, y, w);
    www[x][y] = w;
    has[x][y] = 1;
  }

  dijkstra();

  int ans = 0;
  for (int x = 0; x < n; ++ x) {
    for (int y = 0; y < n; ++ y) {
      if (www[x][y] == dis[x][y]) {
        // printf("(%d, %d) is good\n", x, y);
        // can[x][y] = 1;
        f[x].set(y, 1);
        g[y].set(x, 1);
      }
    }
  }
  for (int x = 0; x < n; ++ x) {

    for (int i = 0; i < n; ++ i) {
      tmp[i] = i;
      memset(pot[i].v, 0, sizeof(pot[i].v));
    }

    sort(tmp, tmp + n, [&] (const int &a, const int &b) {
      return dis[x][a] < dis[x][b];
    });

    for (int i = 0; i < n; ++ i) {
      int u = tmp[i];
      pot[u].set(u, 1);
      for (int j = head[u]; j; j = nxt[j]) {
        int v = to[j];
        if (has[u][v] && dis[x][u] + www[u][v] == dis[x][v]) {
          pot[v] = pot[v] | pot[u];
        }
      }
    }

    for (int y = 0; y < n; ++ y) {

      if ((f[x] & g[y] & pot[y]).any()) {
        f[x].set(y, 1);
        g[y].set(x, 1);
      }

      // for (int z = 0; z < n; ++ z) {
      //   if (can[x][z] && can[z][y] && (dis[x][z] + dis[z][y] == dis[x][y])) {
      //     can[x][y] = 1;
      //     break;
      //   }
      // }
    }
  }
  for (int x = 0; x < n; ++ x) {
    for (int y = 0; y < n; ++ y) {
      ans += f[x].get(y);
      if((!f[x].get(y))&&dis[x][y]==0x3f3f3f3f)ans++;
    }
  }
  printf("%d\n", ans);
}
