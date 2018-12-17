#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define N 500020
#define ll long long
using namespace std;
using namespace __gnu_pbds;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

namespace __luogu3765 {

int n, k;

// self-balancing binary search tree

typedef
  __gnu_pbds::tree<int, null_type, less<int>,
    rb_tree_tag, tree_order_statistics_node_update>
  Tree;

Tree t[N];
int a[N];

int _query_times(int x, int l, int r) {
  return t[x].order_of_key(r + 1) - t[x].order_of_key(l);
}

bool _check_valid(int x, int l, int r) {
  return _query_times(x, l, r) > (r - l + 1) / 2;
}

// segment tree

int mx[N<<2]; // the result

void _push_up(int x, int l, int r) {
  int mid = (l + r) >> 1;
  if (mx[x << 1] && _check_valid(mx[x << 1], l, mid)) {
    mx[x] = mx[x << 1];
    return;
  }
  if (mx[x << 1 | 1] && _check_valid(mx[x << 1 | 1], mid + 1, r)) {
    mx[x] = mx[x << 1 | 1];
    return;
  }
  mx[x] = 0;
}

void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  _push_up(x, l, r);
}

int _l, _r;

int query(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return _check_valid(mx[x], _l, _r) ? mx[x] : 0;
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return query(x << 1, l, r, L, mid);
  if (l > mid) return query(x << 1 | 1, l, r, mid + 1, R);
  int _lans = query(x << 1, l, mid, L, mid);
  return _lans ? _lans : query(x << 1 | 1, mid + 1, r, mid + 1, R);
}

void modify(int x, int k, int l, int r) {
  if (l == r) {
    mx[x] = a[k];
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid) modify(x << 1, k, l, mid);
  else modify(x << 1 | 1, k, mid + 1, r);
  _push_up(x, l, r);
}

void modify_value(int x, int v) {
  // printf("%d -> %d\n", x, v);
  t[a[x]].erase(x);
  a[x] = v;
  t[a[x]].insert(x);
  modify(1, x, 1, n);
}

int do_election() {
  int l = read(), r = read(), s = read(), k = read();
  _l = l; _r = r;
  int res = query(1, l, r, 1, n);
  if (!res) res = s;
  for (int i = 1; i <= k; ++ i) {
    int x = read();
    modify_value(x, res);
  }
  return res;
}

} // end __luogu3765

using namespace __luogu3765;

int main(int argc, char const *argv[]) {

  n = read();
  k = read();
  
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    t[a[i]].insert(i);
  }

  build(1, 1, n);

  for (int i = 1; i <= k; ++ i) {
    printf("%d\n", do_election());
  }

  int president = query(1, 1, n, 1, n);
  if (president) {
    printf("%d\n", president);
  } else {
    puts("-1");
  }
  
  return 0;
}