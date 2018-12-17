#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N], pre[N], nxt[N], vis[N];
priority_queue<pair<int, int>> q;
void remove(int x) {
  vis[x] = 1;
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  if (m > n / 2) return puts("Error!"), 0;
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    nxt[i] = i + 1;
    pre[i] = i - 1;
    q.push({a[i], i});
  }
  pre[1] = n; nxt[n] = 1;
  int ans = 0;
  while (m --) {
    while (vis[q.top().second]) q.pop();
    auto top = q.top(); q.pop();
    ans += top.first;
    int x = top.second;
    a[x] = a[pre[x]] + a[nxt[x]] - a[x];
    remove(pre[x]);
    remove(nxt[x]);
    q.push({a[x], x});
  }
  cout << ans << endl;
  return 0;
}