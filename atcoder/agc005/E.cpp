#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

struct Tree {

  int to[N<<1], nxt[N<<1], head[N], cnt;

  Tree() {
    cnt = 0;
    memset(to, 0, sizeof to);
    memset(nxt, 0, sizeof nxt);
    memset(head, 0, sizeof head);
  }

  void insert(int x, int y) {
    to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
    to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
  }

} red, blue;

int dep[N], fa[N];

void dfs(int x, int f) {
  fa[x] = f;
  dep[x] = dep[f] + 1;
  for (int i = blue.head[x]; i; i = blue.nxt[i]) {
    if (blue.to[i] == f) continue;
    dfs(blue.to[i], x);
  }
}

int rx[N], ry[N];
bool nige[N];

// check if distance btw x and y <= 2
bool check(int x, int y) {
  if (dep[x] > dep[y]) {
    swap(x, y);
  }
  if (dep[y] == dep[x]) {
    return fa[y] == fa[x];
  }
  if (dep[y] - dep[x] == 1) {
    return fa[y] == x;
  }
  if (dep[y] - dep[x] == 2) {
    return fa[fa[y]] == x;
  }
  return false;
}

bool vis[N];

void escape(int x, int f, int d) {

  if (dep[x] <= d) return;
  vis[x] = 1;
  for (int i = red.head[x]; i; i = red.nxt[i]) {
    if (red.to[i] == f) continue;
    escape(red.to[i], x, d + 1);
  }
}

int main(int argc, char const *argv[]) {
  // freopen("../../temp/.in", "r", stdin);

  int n = read(), x = read(), y = read();
  
  for (int i = 1; i < n; ++ i) {
    rx[i] = read();
    ry[i] = read();
    red.insert(rx[i], ry[i]);
  }
  
  for (int i = 1; i < n; ++ i) {
    blue.insert(read(), read());
  }

  dfs(y, 0);
  
  for (int i = 1; i < n; ++ i) {
    if (!check(rx[i], ry[i])) {
      nige[rx[i]] = nige[ry[i]] = true;
    }
  }

  escape(x, 0, 1);

  int ans = 0;

  for (int i = 1; i <= n; ++ i) {
    if (vis[i] && nige[i]) {
      return puts("-1"), 0;
    }
    if (vis[i]) {
      ans = max(ans, dep[i] - 1);
    }
  }

  printf("%d\n", ans << 1);

  return 0;
}
/*

当 A 到达一条红树上的边 (x, y) 的端点时（这条边满足 x 和 y 在蓝树的距离大于 2），B 还没抓到 A，显然就 -1 了。

除了这种情况 A 都会被抓到。

以 B 的初始点为根，发现 A 每次就是往子树逃，或往兄弟逃，或往父亲逃。
只要 B 步步下潜，就能抓到 A。

删除红树上满足 A 一旦到达就会 -1 的那些边，然后做 bfs 求出 A 能能跑到的点（即到达该点前不会被 B 抓），
A 一定会选择在蓝树中深度最大的，然后待在那弃疗。

*/