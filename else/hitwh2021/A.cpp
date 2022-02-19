#include <bits/stdc++.h>
#define N 100020
#define K 100005
using namespace std;

int to[N<<1], nxt[N<<1], head[N], ww[N<<1], cnt;
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; ww[cnt] = w;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; ww[cnt] = w;
}

int a[K], t[K];

int dis1[N], dis2[N];

struct Node {
  int x;
  int d;
  friend bool operator < (const Node &a, const Node &b) {
    return a.d > b.d;
  }
};
priority_queue<Node> p;
void dijkstra(int st, int* dis) {
  dis[st] = 0;
  p.push((Node){st, 0});
  while (!p.empty()) {
    Node node = p.top();
    p.pop();
    if (dis[node.x] != node.d) {
      continue;
    }
    for (int i = head[node.x]; i; i = nxt[i]) {
      if (dis[to[i]] > node.d + ww[i]) {
        dis[to[i]] = node.d + ww[i];
        p.push((Node){to[i], dis[to[i]]});
      }
    }
  }
}

int main() {

  int _vr, _vt;
  scanf("%d%d", &_vr, &_vt);
  double vr = _vr, vt = _vt;

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++ i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    insert(u, v, w);
  }

  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; ++ i) {
    scanf("%d%d", a+i, t+i);
  }

  memset(dis1, 0x3f, sizeof(dis1));
  memset(dis2, 0x3f, sizeof(dis2));
  dijkstra(1, dis1);
  dijkstra(n, dis2);

  if (dis1[n] == dis1[0]) {
    puts("-1");
    return 0;
  }

  double ans = dis1[n] / vt;
  for (int i = 1; i <= k; ++ i) {
    ans = min(ans, dis1[a[i]] / vt + t[i] + dis2[a[i]] / vr);
  }
  printf("%.6f\n", ans);
}
