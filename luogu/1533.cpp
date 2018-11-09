#include <bits/stdc++.h>
#define N 300020
#define M 50020
using namespace std;
inline int read() {
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N], b[N];
namespace __bit_tree {
  int max_val, c[N];
  void update(int x, int v) {
    for (; x <= max_val; x += x & -x) {
      c[x] += v;
    }
  }
  int query(int x) {
    int res = 0;
    for (; x; x ^= x & -x) {
      res += c[x];
    }
    return res;
  }
  // 查询第 k 小的数
  int kth(int k) {
    int l = 0, r = max_val;
    while (l <= r) {
      // printf("%d %d\n", l, r);
      int mid = (l + r) >> 1;
      if (query(mid) < k) l = mid + 1;
      else r = mid - 1;
    }
    // printf("returns %d\n", l);
    return l;
  }
}
struct Query {
  int l, r, k, id;
} qs[M];
int ans[M];
bool cmp(const Query &a, const Query &b) {
  return a.l == b.l ? a.r < b.r : a.l < b.l;
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  __bit_tree::max_val = n;
  for (int i = 1; i <= n; ++ i) {
    b[i] = a[i] = read();
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++ i) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  }
  for (int i = 1; i <= m; ++ i) {
    qs[i].l = read();
    qs[i].r = read();
    qs[i].k = read();
    qs[i].id = i;
  }
  sort(qs + 1, qs + m + 1, cmp);
  int l = 1, r = 0;
  for (int i = 1; i <= m; ++ i) {
    while (r < qs[i].r) __bit_tree::update(a[++ r],  1);
    while (l < qs[i].l) __bit_tree::update(a[l ++], -1);
    ans[qs[i].id] = __bit_tree::kth(qs[i].k);
    // printf("%d\n", ans[qs[i].id]);
  }
  for (int i = 1; i <= m; ++ i) {
    printf("%d\n", b[ans[i]]);
  }
  return 0;
}