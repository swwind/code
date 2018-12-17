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
struct node {
  int x, y, v, c;
  friend bool operator < (const node &a, const node &b) {
    return a.v == b.v ? a.c < b.c : a.v < b.v;
  }
}a[N];
int n, m, k, fa[N], ans;
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int check(int x) {
  for (int i = 1; i <= n; ++ i) fa[i] = i;
  for (int i = 1; i <= m; ++ i)
    if (!a[i].c) a[i].v += x;
  sort(a + 1, a + m + 1);
  int res = 0; ans = 0;
  for (int i = 1; i <= m; ++ i) {
    int x = find(a[i].x), y = find(a[i].y);
    if (x == y) continue;
    fa[x] = y;
    res += !a[i].c;
    ans += a[i].v;
  }
  for (int i = 1; i <= m; ++ i)
    if (!a[i].c) a[i].v -= x;
  return res;
}
int main(int argc, char const *argv[]) {
  // 直接选 need 条白边被 Hack 掉了，那怎么办办呢
  // 我们只能写正解了
  n = read(); m = read(); k = read();
  for (int i = 1; i <= m; ++ i) {
    a[i].x = read() + 1; a[i].y = read() + 1;
    a[i].v = read(); a[i].c = read();
  }
  int l = -300, r = 300;
  int res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid) >= k) l = mid + 1, res = ans - k * mid;
    else r = mid - 1;
    // printf("[%d, %d], %d %d\n", l, r, res, ans);
  }
  cout << res << endl;
  return 0;
}