#include <bits/stdc++.h>
#define N 5020
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
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int sz[N], top;
int dfs(int x, int f, int d) { // return the maxdep of x
  sz[d] ++; int res = d;
  for (int i = head[x]; i; i = nxt[i])
    if (to[i] != f) res = max(res, dfs(to[i], x, d + 1));
  return res;
}
ll c1[N], c2[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i < n; i++)
    insert(read(), read());
  ll ans = 0;
  for (int x = 1; x <= n; x++) {
    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    for (int i = head[x]; i; i = nxt[i]) {
      memset(sz, 0, sizeof sz);
      int d = dfs(to[i], x, 1);
      for (int j = 1; j <= d; j++) {
        ans += c2[j] * sz[j];
        c2[j] += c1[j] * sz[j];
        c1[j] += sz[j];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}