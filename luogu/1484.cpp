#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct node {
  int id;
  ll val;
  friend bool operator < (const node &a, const node &b) {
    return a.val < b.val;
  }
};
priority_queue<node> p;
int pre[N], nxt[N], die[N];
ll a[N];
int main(int argc, char const *argv[]) {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    pre[i] = i - 1;
    nxt[i] = i + 1;
    p.push({i, a[i]});
  }
  pre[n + 1] = n;
  nxt[0] = 1;
  ll ans = 0;

  while (k --) {
    while (die[p.top().id])
      p.pop();
    node t = p.top();
    p.pop();
    if (t.val < 0)
      break;
    ans += t.val;
    int x = t.id;
    t.val = a[x] = a[pre[x]] + a[nxt[x]] - a[x];
    die[pre[x]] = die[nxt[x]] = 1;
    pre[x] = pre[pre[x]]; nxt[pre[x]] = x;
    nxt[x] = nxt[nxt[x]]; pre[nxt[x]] = x;
    p.push(t);
  }

  cout << ans << endl;

  return 0;
}