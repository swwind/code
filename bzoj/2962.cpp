#include <bits/stdc++.h>
#define N 100020
#define mod 19940417
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int a[N];
struct node {
  int val[21], len;
  node() {
    memset(val, 0, sizeof val);
    len = 0;
  }
  node(int x) {
    memset(val, 0, sizeof val);
    len = val[0] = 1;
    val[1] = x;
  }
} ts[N << 2];
int  tag[N << 2];
bool nav[N << 2];
node merge(node x, node y) {
  node nd;
  nd.len = x.len + y.len;
  for (int i = 0; i <= 20; ++ i) {
    for (int j = 0; j <= i; ++ j) {
      nd.val[i] = (nd.val[i] + (ll) x.val[j] * y.val[i - j] % mod) % mod;
    }
  }
  return nd;
}
int c[N][25];
inline void add(int x, int v) {
  for (int i = 20; ~ i; -- i) {
    ll tmp = v;
    for (int j = 1; j <= i; ++ j) {
      ts[x].val[i] = (ts[x].val[i] + ts[x].val[i - j] * tmp % mod
        * c[ts[x].len - i + j][j] % mod) % mod;
      tmp = tmp * v % mod;
    }
  }
}
inline void naive(int x) {
  tag[x] = (mod - tag[x]) % mod;
  for (int i = 1; i <= 20; i += 2) {
    ts[x].val[i] = (mod - ts[x].val[i]) % mod;
  }
}
void push_down(int x) {
  if (nav[x]) {
    naive(x << 1);
    naive(x << 1 | 1);
    nav[x << 1] ^= 1;
    nav[x << 1 | 1] ^= 1;
    nav[x] = 0;
  }
  if (tag[x]) {
    add(x << 1, tag[x]);
    add(x << 1 | 1, tag[x]);
    tag[x << 1] = (tag[x << 1] + tag[x]) % mod;
    tag[x << 1 | 1] = (tag[x << 1 | 1] + tag[x]) % mod;
    tag[x] = 0;
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    ts[x] = node(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  ts[x] = merge(ts[x << 1], ts[x << 1 | 1]);
}
void negative(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    naive(x);
    nav[x] ^= 1;
    return;
  }
  push_down(x);
  int mid = (L + R) >> 1;
  if (r <= mid) negative(x << 1, l, r, L, mid);
  else if (l > mid) negative(x << 1 | 1, l, r, mid + 1, R);
  else negative(x << 1, l, mid, L, mid), negative(x << 1 | 1, mid + 1, r, mid + 1, R);
  ts[x] = merge(ts[x << 1], ts[x << 1 | 1]);
}
void update(int x, int l, int r, int L, int R, int v) {
  if (l == L && r == R) {
    add(x, v);
    tag[x] = (tag[x] + v) % mod;
    // printf("after %d\n", ts[x].val[1]);
    return;
  }
  push_down(x);
  int mid = (L + R) >> 1;
  if (r <= mid) update(x << 1, l, r, L, mid, v);
  else if (l > mid) update(x << 1 | 1, l, r, mid + 1, R, v);
  else update(x << 1, l, mid, L, mid, v), update(x << 1 | 1, mid + 1, r, mid + 1, R, v);
  // printf("[%d] before %d, ", x, ts[x].val[1]);
  ts[x] = merge(ts[x << 1], ts[x << 1 | 1]);
  // printf("after %d\n", ts[x].val[1]);
}
node query(int x, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return ts[x];
  }
  push_down(x);
  int mid = (L + R) >> 1;
  if (r <= mid) return query(x << 1, l, r, L, mid);
  else if (l > mid) return query(x << 1 | 1, l, r, mid + 1, R);
  return merge(query(x << 1, l, mid, L, mid), query(x << 1 | 1, mid + 1, r, mid + 1, R));
}

char str[3];

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  for (int i = 0; i <= n; ++ i) {
    c[i][0] = 1;
    for (int j = 1; j <= min(i, 20); ++ j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  build(1, 1, n);
  for (int i = 1; i <= m; ++ i) {
    scanf("%s", str);
    if (str[0] == 'I') {
      int l = read(), r = read(), x = read();
      x = (x % mod + mod) % mod;
      update(1, l, r, 1, n, x);
    }
    if (str[0] == 'Q') {
      int l = read(), r = read(), x = read();
      node res = query(1, l, r, 1, n);
      printf("%d\n", res.val[x]);
    }
    if (str[0] == 'R') {
      int l = read(), r = read();
      negative(1, l, r, 1, n);
    }
    // printf(">> %d\n", ts[1].val[1]);
  }

  return 0;
}