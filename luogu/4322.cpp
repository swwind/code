#include <bits/stdc++.h>
#define N 2520
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int s[N], p[N], size[N];
double w[N], f[N][N], tmp[N];
int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void dfs(int x, int fa) {
  size[x] = 1; f[x][0] = 0; f[x][1] = w[x];
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], x);
    for (int j = 1; j <= size[x] + size[to[i]]; ++ j) {
      tmp[j] = f[0][N - 1];
    }
    for (int j = 1; j <= size[x]; ++ j) {
      for (int k = 0; k <= size[to[i]]; ++ k) {
        tmp[j + k] = max(tmp[j + k], f[x][j] + f[to[i]][k]);
      }
    }
    for (int j = 1; j <= size[x] + size[to[i]]; ++ j) {
      f[x][j] = tmp[j];
    }
    size[x] += size[to[i]];
  }
}
int main(int argc, char const *argv[]) {
  int k = read(), n = read();
  for (int i = 1; i <= n; ++ i) {
    s[i] = read(), p[i] = read();
    int fa = read();
    insert(i, fa);
  }
  double l = 0, r = 1e4, eps = 1e-4;
  while (r - l > eps) {
    double mid = (l + r) * .5;
    memset(f, 0xc2, sizeof f);
    for (int i = 1; i <= n; ++ i) {
      w[i] = (double) p[i] - mid * (double) s[i];
    }
    dfs(0, 0);
    if (f[0][k + 1] > 0) l = mid;
    else                 r = mid;
  }
  printf("%.3lf\n", l);
  return 0;
}