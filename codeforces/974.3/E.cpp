#include <bits/stdc++.h>
#define N 200020
#define M 200020
#define inf 0x7f7f7f7f7f7f7f7fll

using namespace std;

int to[4 * M + N], nxt[4 * M + N], val[4 * M + N], head[2 * N], cnt;

void insert(int x, int y, int w) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  val[cnt] = w;
  head[x] = cnt;
}

long long dis1[2 * N], dis2[2 * N];

struct Node {
  int x;
  long long d;
  friend bool operator<(const Node &a, const Node &b) { return a.d > b.d; }
};
priority_queue<Node> p;
void dijkstra(int st, long long *dis) {
  dis[st] = 0ll;
  p.push((Node){st, 0ll});
  while (!p.empty()) {
    Node node = p.top();
    p.pop();
    if (dis[node.x] != node.d)
      continue;
    for (int i = head[node.x]; i; i = nxt[i]) {
      if (dis[to[i]] > node.d + val[i]) {
        dis[to[i]] = node.d + val[i];
        p.push((Node){to[i], dis[to[i]]});
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);

    cnt = 0;
    memset(head, 0, sizeof(head));

    for (int i = 0; i < h; ++i) {
      int x;
      scanf("%d", &x);
      insert(x, x + n, 0);
    }
    for (int i = 0; i < m; ++i) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      insert(x, y, w);
      insert(y, x, w);
      insert(x + n, y + n, w / 2);
      insert(y + n, x + n, w / 2);
    }

    // memset(dis1, 0x7f, sizeof(dis1));
    // memset(dis2, 0x7f, sizeof(dis2));
    for (int i = 1; i <= n; ++i) {
      dis1[i] = dis1[i + n] = inf;
      dis2[i] = dis2[i + n] = inf;
    }

    dijkstra(1, dis1);
    dijkstra(n, dis2);

    // for (int i = 1; i <= 2 * n; ++i)
    //   printf("dis[%d] = %lld\n", i, dis1[i]);

    long long ans = inf;
    for (int i = 1; i <= n; ++i) {
      dis1[i] = min(dis1[i], dis1[i + n]);
      dis2[i] = min(dis2[i], dis2[i + n]);
      // printf("%lld, %lld\n", dis1[i], dis2[i]);
      if (dis1[i] < inf && dis2[i] < inf) {
        ans = min(ans, max(dis1[i], dis2[i]));
      }
    }
    if (ans == inf)
      puts("-1");
    else
      printf("%lld\n", ans);
  }
}
