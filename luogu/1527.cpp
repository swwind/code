// 整体二分

#include <bits/stdc++.h>
#define N 520
#define M 60020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
// points
struct point {
  int x, y, z;
  friend bool operator < (const point &a, const point &b) {
    return a.z < b.z;
  }
} p[N*N];
struct querys {
  int x1, y1, x2, y2, k;
} q[M];
int n, pnt, qnt, Q, ans[M], id[M];
namespace fake {
  int a[N][N];
  void update(int x, int y, int v) {
    for (int i = x; i <= n; i += i & -i)
      for (int j = y; j <= n; j += j & -j)
        a[i][j] += v;
  }
  int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i ^= i & -i)
      for (int j = y; j; j ^= j & -j)
        res += a[i][j];
    return res;
  }
  int query(querys x) {
    int ans = query(x.x2, x.y2);
    ans -= query(x.x2, x.y1 - 1);
    ans -= query(x.x1 - 1, x.y2);
    ans += query(x.x1 - 1, x.y1 - 1);
    return ans;
  }
}
int t1[M], t2[M], last[M];
void solve(int l, int r, int ql, int qr) {
  if (ql > qr) return;
  if (l == r) {
    for (int i = ql; i <= qr; ++ i)
      ans[id[i]] = p[l].z; // plz = please
    return;
  }
  int m = (l + r) >> 1, c1 = 0, c2 = 0;
  for (int i = l; i <= m; ++ i)
    fake::update(p[i].x, p[i].y, 1);
  for (int i = ql; i <= qr; ++ i) {
    int now = id[i];
    int res = last[now] + fake::query(q[now]);
    if (res >= q[now].k) t1[++ c1] = now;
    else t2[++ c2] = now, last[now] = res;
  }
  for (int i = 1; i <= c1; ++ i) id[ql + i - 1] = t1[i];
  for (int i = 1; i <= c2; ++ i) id[ql + c1 + i - 1] = t2[i];
  for (int i = l; i <= m; ++ i)
    fake::update(p[i].x, p[i].y, -1);
  solve(l, m, ql, ql + c1 - 1);
  solve(m + 1, r, ql + c1, qr);
}
int main(int argc, char const *argv[]) {
  n = read(); Q = read();
  for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
      p[++ pnt] = {i, j, read()};
  for (int i = 1; i <= Q; ++ i) {
    int x1 = read(), y1 = read();
    int x2 = read(), y2 = read();
    q[i] = {x1, y1, x2, y2, read()};
    id[i] = i;
  }
  sort(p + 1, p + pnt + 1);
  solve(1, pnt, 1, Q);
  for (int i = 1; i <= Q; ++ i)
    printf("%d\n", ans[i]);
  return 0;
}