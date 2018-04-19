#include <bits/stdc++.h>
#define N 2020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int head[N], to[N<<1], nxt[N<<1], cnt; ll val[N<<1];
void insert(int x, int y, int z) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = z;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = z;
}
int n = read(), k = read(), sz[N];
ll f[N][N];
void dfs(int x, int fa) {
  sz[x] = 1;
  f[x][0] = f[x][1] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x); sz[x] += sz[y];
    for (int j = min(k, sz[x]); ~j; -- j) {
      for (int k = 0; k <= sz[y] && k <= j; ++ k) {
        ll val = ::val[i] * (k * (::k - k) + (sz[y] - k) * (n - ::k - (sz[y] - k)));
        f[x][j] = max(f[x][j], f[y][k] + f[x][j - k] + val);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  memset(f, 128, sizeof f);
  for (int i = 1; i < n; ++ i) {
    int x = read(), y = read();
    insert(x, y, read());
  }
  dfs(1, 0);
  cout << f[1][k] << endl;
  return 0;
}