#include <bits/stdc++.h>
#define N 1520
#define M 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int to[M], nxt[M], head[N], cnt, val[M], from[M];
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = w; from[cnt] = x;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = w; from[cnt] = y;
}

int dis[4][N];
bool vis[N];
queue<int> que;
void spfa(int st, int *dis) {
  memset(vis, 0x00, sizeof vis);
  dis[st] = 0;
  que.push(st);

  while (!que.empty()) {
    int x = que.front();
    que.pop();
    vis[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
      if (dis[to[i]] > dis[x] + val[i]) {
        dis[to[i]] = dis[x] + val[i];
        if (!vis[to[i]]) {
          que.push(to[i]);
          vis[to[i]] = 1;
        }
      }
    }
  }
}

vector<int> graph[N];
int timber[N][N], inq[N], ans[N], len[N][N];

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read(), m = read();
  int x1 = read(), y1 = read(), x2 = read(), y2 = read();

  for (int i = 1; i <= m; ++ i) {
    int x = read(), y = read();
    insert(x, y, read());
  }

  memset(dis, 0x3f, sizeof dis);
  spfa(x1, dis[0]);
  spfa(y1, dis[1]);
  spfa(x2, dis[2]);
  spfa(y2, dis[3]);

  int len1 = dis[0][y1];
  int len2 = dis[2][y2];

  for (int i = 1; i <= cnt; ++ i) {
    int x = from[i], y = to[i];
    if (dis[0][x] + val[i] + dis[1][y] == len1) {
      graph[x].push_back(y);
      ++ timber[x][y];
      ++ timber[y][x];
      len[x][y] = len[y][x] = val[i];
      ++ inq[y];
    }
    if (dis[2][x] + val[i] + dis[3][y] == len2) {
      ++ timber[x][y];
      ++ timber[y][x];
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; ++ i) {
    if (!inq[i]) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : graph[x]) {
      ans[y] = max(ans[y], ans[x] + (timber[x][y] == 2 ? len[x][y] : 0));
      if (!--inq[y]) {
        q.push(y);
      }
    }
  }

  printf("%d\n", ans[y1]);

  return 0;
}