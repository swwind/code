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
  int x, y, z;
  int ans;
}a[N];
int c[N<<1], n, k;
int query(int x) {
  int res = 0;
  for (; x; x ^= x & -x)
    res += c[x];
  return res;
}
void update(int x) {
  for (; x <= k; x += x & -x)
    ++ c[x];
}
void clean(int x) {
  for (; x <= k; x += x & -x)
    c[x] = 0;
}
bool cmp(const node &a, const node &b) {
  return a.y == b.y ? a.z < b.z : a.y < b.y;
}
bool equals(const node &a, const node &b) {
  return a.x == b.x && a.y == b.y && a.z == b.z;
}
void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  sort(a + l, a + mid + 1, cmp);
  sort(a + mid + 1, a + r + 1, cmp);
  for (int j = l, i = mid + 1; i <= r; ++ i) {
    for (; j <= mid && a[j].y <= a[i].y; ++ j)
      update(a[j].z);
    a[i].ans += query(a[i].z);
  }
  for (int i = l; i <= mid; ++ i)
    clean(a[i].z);
}
int res[N];
int main(int argc, char const *argv[]) {
  n = read(); k = read();
  for (int i = 1; i <= n; ++ i) {
    a[i].x = read();
    a[i].y = read();
    a[i].z = read();
    a[i].ans = 0;
  }
  sort(a + 1, a + n + 1, [&] (const node &a, const node &b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
  });
  solve(1, n);
  sort(a + 1, a + n + 1, [&] (const node &a, const node &b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
  });
  for (int i = 1, j; i <= n; i = j) {
    j = i + 1;
    int mx = a[i].ans;
    for (; j <= n && equals(a[i], a[j]); ++ j)
      mx = max(mx, a[j].ans);
    for (int k = i; k < j; ++ k)
      a[k].ans = mx;
  }
  for (int i = 1; i <= n; ++ i)
    ++ res[a[i].ans];
  for (int i = 0; i < n; ++ i)
    printf("%d\n", res[i]);
  return 0;
}