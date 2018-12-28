#include <bits/stdc++.h>
#define N 10020
#define M 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
const int inf = 1061109567;
int to[M], nxt[M], head[N], val[M], cst[M], cnt = 1;
void insert(int x, int y, int w, int c) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = w; cst[cnt] = c;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = 0; cst[cnt] = - c;
}
int S, T;
bool vis[N];
int dis[N], q[M];
bool spfa() {
  memset(vis, 0, sizeof vis);
  memset(dis, 0x3f, sizeof dis);
  int l = 0, r = 1;
  q[1] = T; dis[T] = 0; vis[T] = 1;
  while (l < r) {
    int x = q[++ l];
    for (int i = head[x]; i; i = nxt[i]) {
      if (val[i ^ 1] && dis[to[i]] > dis[x] - cst[i]) {
        dis[to[i]] = dis[x] - cst[i];
        if (!vis[to[i]]) {
          vis[to[i]] = 1;
          q[++ r] = to[i];
        }
      }
    }
    vis[x] = 0;
  }
  return dis[S] != inf;
}
int ans;
int dfs(int x, int f) {
  vis[x] = 1;
  if (x == T) {
    return f;
  }
  int used = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    if (!vis[to[i]] && val[i] && dis[to[i]] == dis[x] - cst[i]) {
      int w = dfs(to[i], min(val[i], f - used));
      ans += w * cst[i];
      val[i] -= w;
      val[i ^ 1] += w;
      used += w;
      if (used == f) {
        return f;
      }
    }
  }
  return used;
}

int zkw() {
  while (spfa()) {
    vis[T] = 1;
    while (vis[T]) {
      memset(vis, 0, sizeof vis);
      dfs(S, inf);
    }
  }
  return ans;
}

int a[N], s[N], t[N], c[N];
int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  int n = read(), m = read();
  S = n + 2; T = n + 3;

  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  for (int i = 1; i <= m; ++ i) {
    s[i] = read();
    t[i] = read();
    c[i] = read();
  }

  for (int i = 1; i <= n; ++ i) {
    insert(i + 1, i, inf, 0);
  }
  for (int i = 1; i <= n + 1; ++ i) {
    if (a[i] >= a[i - 1]) {
      insert(S, i, a[i] - a[i - 1], 0);
    } else {
      insert(i, T, a[i - 1] - a[i], 0);
    }
  }
  for (int i = 1; i <= m; ++ i) {
    insert(s[i], t[i] + 1, inf, c[i]);
  }

  // puts("hello world");
  printf("%d\n", zkw());

  return 0;
}