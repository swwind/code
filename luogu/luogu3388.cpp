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
int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
  to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int tot, low[N], dfn[N], ans;
bool ok[N];
void tarjan(int x, int f) {
  int tmp = 0;
  low[x] = dfn[x] = ++ tot;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (!dfn[y]) {
      tarjan(y, f);
      low[x] = min(low[x], low[y]);
      if (low[y] >= dfn[x] && x != f)
        ok[x] = 1;
      if (x == f) tmp ++;
    }
    low[x] = min(low[x], dfn[y]);
  }
  if (x == f && tmp >= 2)
    ok[x] = 1;
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++)
    insert(read(), read());
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, i);
  for (int i = 1; i <= n; i++)
    ans += ok[i];
  cout << ans << endl;
  for (int i = 1; i <= n; i++)
    if (ok[i]) cout << i << " ";
  cout << endl;
  return 0;
}