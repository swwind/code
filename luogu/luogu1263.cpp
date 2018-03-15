#include <bits/stdc++.h>
#define N 220
#define M 5000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int head[N*N], nxt[M<<1], to[M<<1], cnt = 1, val[M<<1], res[M<<1];
void insert(int x, int y, int v, int i = 0, int j = 0) {
  to[++ cnt] = y; nxt[cnt] = head[x];
  head[x] = cnt; val[cnt] = v;
  res[cnt] = i * 300 + j;
  to[++ cnt] = x; nxt[cnt] = head[y];
  head[y] = cnt; val[cnt] = 0;
}
int dep[N*N], st, ed, q[N*N];
int bfs() {
  memset(dep, 0, sizeof dep);
  int l = 0, r = 1;
  q[r] = st; dep[st] = 1;
  while (l < r) {
    int x = q[++ l];
    for (int i = head[x]; i; i = nxt[i]) {
      if (val[i] && !dep[to[i]]) {
        q[++ r] = to[i];
        dep[to[i]] = dep[x] + 1;
      }
    }
  }
  return dep[ed];
}
int dfs(int x, int f) {
  if (x == ed) return f;
  int sum = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    if (val[i] && dep[to[i]] == dep[x] + 1) {
      int w = dfs(to[i], min(f - sum, val[i]));
      val[i] -= w; val[i ^ 1] += w;
      sum += w; if (sum == f) return f;
    }
  }
  if (!sum) dep[x] = 0;
  return sum;
}
int mp[N][N], rs[N][N], ls[N][N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      mp[i][j] = read();
  int cntls = 0, cntrs = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (mp[i][j] < 2) rs[i][j] = !rs[i][j - 1] ? ++ cntrs : cntrs;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (mp[j][i] < 2) ls[j][i] = !ls[j - 1][i] ? ++ cntls : cntls;
  st = cntls + cntrs + 1;
  ed = st + 1;
  for (int i = 1; i <= cntls; i++)
    insert(st, i, 1);
  for (int i = 1; i <= cntrs; i++)
    insert(i + cntls, ed, 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!mp[i][j]) insert(ls[i][j], rs[i][j] + cntls, 1, i, j);
  int ans = 0;
  while (bfs())
    ans += dfs(st, 1 << 30);
  cout << ans << endl;
  for (int i = (cntls + cntrs + 1) * 2; i <= cnt; i += 2)
    if (!val[i])
      printf("%d %d\n", res[i]/300, res[i]%300);

  return 0;
}