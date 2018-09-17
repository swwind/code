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
int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int n, k, max_d;
int dfs(int x, int f, int d) {
  if (d > max_d) return 0;
  int sz = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (f == to[i]) continue;
    sz += dfs(to[i], x, d + 1);
  }
  return sz;
}
int x[2020], y[2020];
int main(int argc, char const *argv[]) {
  n = read(); k = read();
  for (int i = 1; i < n; ++ i) {
    x[i] = read();
    y[i] = read();
    insert(x[i], y[i]);
  }
  int ans = 1 << 30;

  if (k & 1) {
    max_d = k >> 1;
    for (int i = 1; i < n; ++ i) {
      int sz = 0;
      sz += dfs(x[i], y[i], 0);
      sz += dfs(y[i], x[i], 0);
      ans = min(ans, n - sz);
    }
  } else {
    max_d = k >> 1;
    for (int i = 1; i <= n; ++ i) {
      int sz = dfs(i, 0, 0);
      ans = min(ans, n - sz);
    }
  }

  cout << ans << endl;
  return 0;
}

/*
树的重心有一个特性：每个点离它的距离都<=d/2
于是枚举边/点直接 DFS 判断即可。
*/