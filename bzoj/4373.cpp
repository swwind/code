#pragma GCC optimize 2
#include <bits/stdc++.h>
#define N 300020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
// 线段树：维护最大值、最小值、gcd
#define lc (x << 1)
#define rc (x<<1|1)
int mx[N<<2], mn[N<<2], gcd[N<<2], premax[N<<2];
int a[N], pre[N];
int merge_gcd(int a, int b, int c) {
  if (a == -1 && b == -1) return c;
  if (a == -1) return __gcd(b, c);
  if (b == -1) return __gcd(a, c);
  return __gcd(__gcd(a, b), c);
}
void push_up(int x, int l, int r) {
  int mid = (l + r) >> 1;
  mx[x] = max(mx[lc], mx[rc]);
  mn[x] = min(mn[lc], mn[rc]);
  premax[x] = max(premax[lc], premax[rc]);
  gcd[x] = merge_gcd(gcd[lc], gcd[rc], abs(a[mid] - a[mid + 1]));
}
void update(int x, int l, int r, int k, int v) {
  if (l == r) {
    mx[x] = mn[x] = v;
    premax[x] = pre[l];
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid) update(lc, l, mid, k, v);
  else update(rc, mid + 1, r, k, v);
  push_up(x, l, r);
}
int queryMax(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return mx[x];
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return queryMax(lc, l, r, L, mid);
  else if (l > mid) return queryMax(rc, l, r, mid + 1, R);
  else return max(queryMax(lc, l, mid, L, mid), queryMax(rc, mid + 1, r, mid + 1, R));
}
int queryPremax(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return premax[x];
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return queryPremax(lc, l, r, L, mid);
  else if (l > mid) return queryPremax(rc, l, r, mid + 1, R);
  else return max(queryPremax(lc, l, mid, L, mid), queryPremax(rc, mid + 1, r, mid + 1, R));
}
int queryMin(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return mn[x];
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return queryMin(lc, l, r, L, mid);
  else if (l > mid) return queryMin(rc, l, r, mid + 1, R);
  else return min(queryMin(lc, l, mid, L, mid), queryMin(rc, mid + 1, r, mid + 1, R));
}
int queryGcd(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return gcd[x];
  }
  int mid = (L + R) >> 1;
  if (r <= mid) return queryGcd(lc, l, r, L, mid);
  else if (l > mid) return queryGcd(rc, l, r, mid + 1, R);
  else return merge_gcd(queryGcd(lc, l, mid, L, mid), queryGcd(rc, mid + 1, r, mid + 1, R), abs(a[mid] - a[mid + 1]));
}
void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = mn[x] = a[l];
    premax[x] = pre[l];
    gcd[x] = -1;
    return;
  }
  int mid = (l + r) >> 1;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  push_up(x, l, r);
}
map<int, set<int> > pos;
int main(int argc, char const *argv[]) {
  // freopen("4373.in", "r", stdin);
  // freopen("4373.out", "w", stdout);
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    if (pos.count(a[i])) {
      pre[i] = * -- pos[a[i]].end();
    }
    pos[a[i]].insert(i);
  }
  build(1, 1, n);
  int last_ans = 0;
  while (m --) {
    int op = read();
    if (op == 1) {
      int x = read(), y = read();
      x ^= last_ans;
      y ^= last_ans;
      pos[a[x]].erase(pos[a[x]].find(x));
      set<int>::iterator it = pos[a[x]].lower_bound(x);
      if (it != pos[a[x]].end()) {
        pre[*it] = pre[x];
        update(1, 1, n, *it, a[*it]);
      }
      it = pos[y].lower_bound(x);
      if (it != pos[y].end()) {
        pre[x] = pre[*it];
        pre[*it] = x;
        update(1, 1, n, *it, a[*it]);
      } else if (pos[y].size()) {
        pre[x] = * -- pos[y].end();
      } else {
        pre[x] = 0;
      }
      pos[y].insert(x);
      a[x] = y;
      update(1, 1, n, x, y);
    } else {
      int l = read(), r = read(), k = read();
      l ^= last_ans;
      r ^= last_ans;
      k ^= last_ans;
      int mx = queryMax(1, l, r, 1, n);
      int mn = queryMin(1, l, r, 1, n);
      int gcd = queryGcd(1, l, r, 1, n);
      int premax = queryPremax(1, l, r, 1, n);
      if (l == r) {
        puts("Yes");
        ++ last_ans;
      } else if (!k && mx == mn && !gcd) {
        puts("Yes");
        ++ last_ans;
      } else if (mx - mn == (long long) k * (r - l) && gcd == k && premax < l) {
        puts("Yes");
        ++ last_ans;
      } else {
        puts("No");
      }
    }
  }
  return 0;
}