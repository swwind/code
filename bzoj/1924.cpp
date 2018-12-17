#include <bits/stdc++.h>
#define N 100020
#define M 4000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
#define mp(x, y) (((ll)x-1)*r+y)
std::map<long long, int> mp;
struct vectors {
  int _head[N*10], _to[N*10], _cnt, _nxt[N*10];
  void push_back(int x, int y) {
    _to[++ _cnt] = y;
    _nxt[_cnt] = _head[x];
    _head[x] = _cnt;
  }
};
vectors row, col;
int t[N], x[N], y[N];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
// graph
int to[M], nxt[M], head[N], cnt;
int ex[M], ey[M], ent;
void insert(int x, int y) {
  // printf("%d -> %d\n", x, y);
  ex[++ ent] = x; ey[ent] = y;
  to[++ cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
int in[N], f[N];
void insert2(int x, int y) {
  ++ in[y];
  to[++ cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
int dfn[N], low[N], tot, que[N], qnt;
int blo[N], bnt, sz[N];
void tarjan(int x) {
  dfn[x] = low[x] = ++ tot;
  que[++ qnt] = x;
  for (int i = head[x]; i; i = nxt[i]) {
    if (!dfn[to[i]]) {
      tarjan(to[i]);
      low[x] = min(low[x], low[to[i]]);
    } else if (!blo[to[i]]) {
      low[x] = min(low[x], dfn[to[i]]);
    }
  }
  if (dfn[x] == low[x] && ++ bnt) {
    while (que[qnt + 1] != x) {
      blo[que[qnt --]] = bnt;
      ++ sz[bnt];
    }
  }
}
int main(int argc, char const *argv[]) {
  // freopen("1924.in", "r", stdin);
  // freopen("1924.out", "w", stdout);
  // prepare
  int n = read(), r = read(), c = read();
  for (int i = 1; i <= n; ++ i) {
    x[i] = read();
    y[i] = read();
    t[i] = read();
    mp[mp(x[i], y[i])] = i;
    row.push_back(x[i], i);
    col.push_back(y[i], i);
  }
  // build graph
  for (int i = 1; i <= n; ++ i) {
    if (t[i] == 1) {
      for (int j = row._head[x[i]]; j; j = row._nxt[j]) {
        int to = row._to[j];
        if (to == i) continue;
        insert(i, to);
      }
    }
    if (t[i] == 2) {
      for (int j = col._head[y[i]]; j; j = col._nxt[j]) {
        int to = col._to[j];
        if (to == i) continue;
        insert(i, to);
      }
    }
    if (t[i] == 3) {
      for (int j = 0; j < 8; ++ j) {
        int nx = x[i] + dx[j];
        int ny = y[i] + dy[j];
        int to = mp[mp(nx, ny)];
        if (!to) continue;
        insert(i, to);
      }
    }
  }
  // tarjan
  for (int i = 1; i <= n; ++ i) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  // for (int i = 1; i <= n; ++ i) {
  //   printf("%d ", blo[i]);
  // } puts("");
  // build new graph
  cnt = 0;
  memset(head, 0, sizeof head);
  // printf("%d\n", ent);
  for (int i = 1; i <= ent; ++ i) {
    if (blo[ex[i]] != blo[ey[i]]) {
      insert2(blo[ex[i]], blo[ey[i]]);
      // printf("%d -> %d\n", blo[ex[i]], blo[ey[i]]);
    }
  }
  // topsort
  queue<int> q;
  memset(f, -0x3f, sizeof f);
  for (int i = 1; i <= bnt; ++ i) {
    if (!in[i]) {
      q.push(i);
      f[i] = sz[i];
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = nxt[i]) {
      f[to[i]] = max(f[to[i]], f[x] + sz[to[i]]);
      if (!-- in[to[i]]) {
        q.push(to[i]);
      }
    }
  }
  // printf("%d\n", bnt);
  int ans = 0;
  for (int i = 1; i <= bnt; ++ i) {
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
  // printf("%.10lf\n", sizeof row);
  return 0;
}
/*
10 7 7
2 2 1
2 4 2
1 7 2
2 7 3
4 2 2
4 4 1
6 7 3
7 7 1
7 5 2
5 2 1
我 TM 的再也不做这种题了！！！
*/