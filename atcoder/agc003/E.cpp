#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll q[N], ans[N], t[N], top;
inline void add(ll l, ll r, ll v) {
  ans[l] += v;
  ans[r + 1] -= v;
}
int main(int argc, char const *argv[]) {
  ll n = read(), m = read();
  q[++ top] = n;
  for (int i = 1; i <= m; ++ i) {
    ll x = read();
    while (top && q[top] >= x) {
      -- top;
    }
    q[++ top] = x;
  }
  t[top] = 1;
  for (int i = top; i; -- i) {
    ll x = q[i];
    ll p = upper_bound(q + 1, q + i, x) - q - 1;
    while (p) {
      t[p] += (x / q[p]) * t[i];
      x %= q[p];
      p = upper_bound(q + 1, q + p, x) - q - 1;
    }
    add(1, x, t[i]);
  }
  for (int i = 1; i <= n; ++ i) {
    ans[i] += ans[i - 1];
    printf("%lld\n", ans[i]);
  }
  return 0;
}
/*

先把 qi>qj && i<j 的 qi 全部删去，这显然没有贡献

结果你能得到一个递增的数组 q

设 t[i] 表示第 i 次操作完后的序列在最终序列中出现了多少次

显然 t[m] = 1

对于每个 q[i]，每次我们需要二分找到一个最大的 k 使得 q[k] <= q[i]

t[k] += (q[i] / q[k]) * t[i]
q[i] %= q[k]

如果 k <= q[1]，说明只能是 [1..k]，直接差分计算即可。

=====================================

样例 2

12345678                    ( 8  )
123456781                   ( 9  )
1234567811234567811         ( 19 )
1234567811234567811123      ( 22 )
123456781123456781112312345 ( 27 )


*/