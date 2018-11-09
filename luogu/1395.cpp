#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int fa[N], sz[N], pa[N];
void dfs(int x, int f) {
  fa[x] = f; sz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs(to[i], x);
    sz[x] += sz[to[i]];
    pa[x] += pa[to[i]] + sz[to[i]];
  }
}
int n = read(), ans = 1 << 30, pos = 1 << 30;
// 到第 i 个点，从他父亲过来的权值为 d
void render(int x, int d) {
  int cost = pa[x] + d;
  if (cost == ans) pos = min(pos, x);
  if (cost < ans) ans = cost, pos = x;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa[x]) continue;
    render(to[i], cost - pa[to[i]] - sz[to[i]] + n - sz[to[i]]);
  }
}
int main(int argc, char const *argv[]) {
  for (int i = 1; i < n; i++)
    insert(read(), read());
  dfs(1, 0);
  render(1, 0);
  cout << pos << " " << ans << endl;
  return 0;
}