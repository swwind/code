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
int to[N << 1], head[N << 1], nxt[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int a[N], id[N], out[N], tot;
void dfs(int x, int f) {
  if (id[x]) {
    return;
  }
  id[x] = ++ tot;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs(to[i], x);
  }
  out[x] = tot;
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i)
    a[i] = read();
  return 0;
}