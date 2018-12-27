#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int ans[N << 2];
double ma[N << 2];
int query(int x, int l, int r, double v) {
  if (ma[x] <= v) {
    return 0;
  }
  if (l == r) {
    return ma[x] > v;
  } else if (ma[x << 1] <= v) {
    return query(x << 1 | 1, ((l + r) >> 1) + 1, r, v);
  }
  return query(x << 1, l, (l + r) >> 1, v) + ans[x] - ans[x << 1];
}
void update(int x, int l, int r, int k, double v) {
  if (l == k && r == k) {
    ans[x] = 1;
    ma[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid)
    update(x << 1, l, mid, k, v);
  else
    update(x << 1 | 1, mid + 1, r, k, v);
  ma[x] = max(ma[x << 1], ma[x << 1 | 1]);

  ans[x] = ans[x << 1] + query(x << 1 | 1, mid + 1, r, ma[x << 1]);
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  int n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    update(1, 1, n, x, (double) y / x);
    printf("%d\n", ans[1]);
  }
  return 0;
}