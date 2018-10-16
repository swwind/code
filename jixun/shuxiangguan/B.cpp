// CF573C
#include <bits/stdc++.h>
#define N 200020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return f?x:-x;
}
int head[N], to[N<<1], nxt[N<<1], cnt;
void link(int x, int y) {
  to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int c[N], d[N], e[N];
void dfs(int x, int f) {
  d[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f || c[to[i]] > 2)
      continue;
    dfs(to[i], x);
  }
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    link(x, y); c[x] ++; c[y] ++;
  }
  for (int i = 1; i <= n; i++)
    if (c[i] == 1) dfs(i, 0);
  for (int x = 1; x <= n; x++)
    for (int i = head[x]; i; i = nxt[i])
      e[x] += d[to[i]];
  for (int x = 1; x <= n; x++) {
    if (d[x]) continue;
    int cnt = 0;
    for (int i = head[x]; i; i = nxt[i])
      if (!d[to[i]] && c[to[i]] - min(e[to[i]], 2) >= 2)
        ++cnt;
    if (cnt > 2)
      return puts("No") & 0;
  }
  puts("Yes");
  return 0;
}