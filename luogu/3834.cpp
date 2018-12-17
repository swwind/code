#include <bits/stdc++.h>
#define N 200020
#define M 4000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N], b[N], cnt = 1;
struct node {
  int c, l, r;
}d[M];
int new_node(int c, int l, int r) {
  d[cnt].c = c;
  d[cnt].l = l;
  d[cnt].r = r;
  return cnt++;
}
int insert(int rt, int l, int r, int k) {
  if (l <= k && k <= r) {
    if (l == r)
      return new_node(d[rt].c + 1, 0, 0);
    int m = l + r >> 1;
    return new_node(d[rt].c + 1,
      insert(d[rt].l, l, m, k),
      insert(d[rt].r, m + 1, r, k));
  }
  return rt;
}
int query(int x, int y, int l, int r, int k) {
  if (l == r)
    return b[l];
  int m = l + r >> 1;
  int sz = d[d[y].l].c - d[d[x].l].c;
  if (sz >= k)
    return query(d[x].l, d[y].l, l, m, k);
  else
    return query(d[x].r, d[y].r, m + 1, r, k - sz);
}
int rt[N];
int main(int argc, char const *argv[]) {
  int n = read();
  int q = read();
  for (int i = 1; i <= n; i++)
    a[i] = b[i] = read();
  sort(b + 1, b + n + 1);
  int m = unique(b + 1, b + n + 1) - b - 1;
  rt[0] = new_node(0, 0, 0);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    rt[i] = insert(rt[i - 1], 1, m, a[i]);
  }
  while (q --) {
    int l = read(), r = read(), k = read();
    printf("%d\n", query(rt[l - 1], rt[r], 1, m, k));
  }
  return 0;
}