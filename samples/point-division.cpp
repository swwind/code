// 点分 ?

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int to[N<<1], nxt[N<<1], head[N], val[N<<1], cnt;
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x];
  val[cnt] = w; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y];
  val[cnt] = w; head[y] = cnt;
}
int hvy, sum, sz[N], mx[N], dep[N], vis[N];
void get_hvy(int x, int f) {
  sz[x] = 1; mx[x] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f || vis[to[i]])
      continue;
    get_hvy(to[i], x);
    sz[x] += sz[to[i]];
    mx[x] = max(mx[x], sz[to[i]]);
  }
  mx[x] = max(mx[x], sum - sz[x]);
  if (!hvy || mx[x] < mx[hvy])
    hvy = x;
}
int st[N], top;
void get_dep(int x, int f) {
  st[++ top] = dep[x];
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f || vis[to[i]])
      continue;
    dep[to[i]] = dep[x] + val[i];
    get_dep(to[i], x);
  }
}
int n, k;
int get_sum(int x, int d) {
  int res = top = 0;
  dep[x] = d; get_dep(x, 0);
  sort(st + 1, st + top + 1);
  for (int i = 1, j = top; i <= top; i++) {
    while (j > i && st[i] + st[j] > k)
      j --;
    res += max(0, j - i);
  }
  return res;
}
int ans;
void get_ans(int x) {
  vis[x] = 1;
  ans += get_sum(x, 0);
  for (int i = head[x]; i; i = nxt[i]) {
    if (vis[to[i]]) continue;
    ans -= get_sum(to[i], val[i]);
    hvy = 0; sum = sz[to[i]];
    get_hvy(to[i], 0);
    get_ans(hvy);
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  for (n = read(), k = read(); n && k; n = read(), k = read()) {
    memset(vis, 0, sizeof vis);
    memset(head, 0, sizeof head);
    hvy = cnt = 0;
    for (int i = 1; i < n; i++) {
      int x = read(), y = read();
      insert(x, y, read());
    }
    sum = n; get_hvy(1, 0);
    ans = 0; get_ans(hvy);
    printf("%d\n", ans);
  }
  return 0;
}