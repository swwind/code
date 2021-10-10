#include <bits/stdc++.h>
#define N 100020
#define M 200020

using namespace std;

inline long long read(){
	long long x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int head[N+M], nxt[M*3], to[M*3], ww[M*3], cnt;
void insert(int x, int y, int w) {
  // printf("%d --> %d: %d\n", x, y, w);
  to[++ cnt] = y;
  ww[cnt] = w;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

struct Edge {
  int u, v, a, b;
} e[M];

bool cmp(const Edge &a, const Edge &b) {
  return a.v == b.v ? a.a > b.a : a.v < b.v;
}
bool cmp2(const Edge &a, const Edge &b) {
  return a.a > b.a;
}

int point;
int pt[N], ls[M], rs[M], et[M];

long long dis[N+M];
const long long kInf = 0x3ffffffffffffffll;
struct Node {
  int x; long long d;
  friend bool operator < (const Node &a, const Node &b) {
    return a.d > b.d;
  }
};
priority_queue<Node> q;

void dijkstra() {
  for (int i = 1; i <= point; ++ i) {
    dis[i] = kInf;
  }
  dis[pt[1]] = 0;
  q.push((Node){pt[1],0});
  while (!q.empty()) {
    Node node = q.top();
    // printf("%d, %d\n", node.x, node.d);
    q.pop();
    if (node.d != dis[node.x]) {
      continue;
    }
    for (int i = head[node.x]; i; i = nxt[i]) {
      if (dis[to[i]] > dis[node.x] + ww[i]) {
        dis[to[i]] = dis[node.x] + ww[i];
        q.push((Node){to[i],dis[to[i]]});
      }
    }
  }
}
// int Find(int l,int r,int v){

// }
int main() {
  int T = read();
  while (T --) {
    point = cnt = 0;
    int n = read();
    int m = read();

    for (int i = 1; i <= m; ++ i) {
      e[i].u = read();
      e[i].v = read();
      e[i].a = read();
      e[i].b = read();
    }
    sort(e + 1, e + m + 1, cmp);

    for (int i = 1; i <= n+m; ++ i) {
      head[i] = 0;
    }

    // 拆点
    for (int i = 1, last = 1; i <= n; ++ i) {
      // printf("start point %d\n", i);
      pt[i] = ++ point;

      ls[i] = last;
      while (last <= m && e[last].v == i) {
        ++ last;
      }
      rs[i] = last;

      int lp = pt[i];
      for (int j = ls[i]; j < rs[i]; ++ j) {
        et[j] = ++ point;
        insert(et[j], lp, 0);
        lp = et[j];
      }
    }

    // puts("split ending");

    for (int i = 1; i <= m; ++ i) {
      int u = e[i].u;
      int v = e[i].v;
      int a = e[i].a;
      int b = e[i].b;

      // puts("normal edge");
      insert(pt[u], et[i], a);
      int k = upper_bound(e + ls[u], e + rs[u], (Edge){0,0,a,0}, cmp2) - e;
      if (k < rs[u]) {
        // puts("fucking edge");
        insert(et[k], et[i], a-b);
      }
    }

    dijkstra();
    for (int i = 1; i <= n; ++ i) {
      printf("%lld%c", dis[pt[i]]==kInf?-1ll:dis[pt[i]], " \n"[i == n]);
    }
  }
}
