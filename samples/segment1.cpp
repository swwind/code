// 线段树1
// 单点赋值，区间max

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
int a[N], b[N], p[N];
struct TreeA {
  int mx[N<<2];
  void update(int x, int k, int L, int R, int v) {
    if (L == R) {
      mx[x] = max(mx[x], v);
      return;
    }
    int mid = L + R >> 1;
    if (k <= mid) update(x << 1, k, L, mid, v);
    else update(x<<1|1, k, mid + 1, R, v);
    mx[x] = max(mx[x << 1], mx[x<<1|1]);
  }
  int query(int x, int l, int r, int L, int R) {
    if (l > r) return 0;
    if (l == L && r == R)
      return mx[x];
    int mid = L + R >> 1;
    if (r <= mid) return query(x << 1, l, r, L, mid);
    else if (l > mid) return query(x<<1|1, l, r, mid + 1, R);
    return max(query(x << 1, l, mid, L, mid), query(x<<1|1, mid + 1, r, mid + 1, R));
  }
}ta;
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read(),p[a[i]]=i;
  for (int i = 1; i <= n; i++)
    b[i] = p[read()];
  for (int i = 1; i <= n; i++) {
  // for (int i = n; i; i--) {
    int x = ta.query(1, 1, b[i] - 1, 1, n);
    ta.update(1, b[i], 1, n, x + 1);
  }
  cout << ta.query(1, 1, n, 1, n) << endl;
  return 0;
}