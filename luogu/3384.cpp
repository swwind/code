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
int n, m, r, mod, a[N];

// Edge map
int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
  to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}

// Segment tree
int sum[N<<2], tag[N<<2];
void push_down(int x, int l, int r) {
  if (tag[x]) {
    int mid = (l + r) >> 1;
    tag[x << 1] = (tag[x << 1] + tag[x]) % mod;
    sum[x << 1] = (sum[x << 1] + (mid - l + 1) * tag[x] % mod) % mod;
    tag[x<<1|1] = (tag[x<<1|1] + tag[x]) % mod;
    sum[x<<1|1] = (sum[x<<1|1] + (r - mid) * tag[x] % mod) % mod;
    tag[x] = 0;
  }
}
void update(int x, int l, int r, int L, int R, int v) {
  // printf("%d %d %d %d %d %d\n", x, l, r, L, R, v);
  if (l == L && r == R) {
    tag[x] = (tag[x] + v) % mod;
    sum[x] = (sum[x] + (r - l + 1) * v) % mod;
    return;
  }
  push_down(x, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid) update(x << 1, l, r, L, mid, v);
  else if (l > mid) update(x<<1|1, l, r, mid + 1, R, v);
  else update(x << 1, l, mid, L, mid, v), update(x<<1|1, mid + 1, r, mid + 1, R, v);
  sum[x] = (sum[x << 1] + sum[x<<1|1]) % mod;
}
int query(int x, int l, int r, int L, int R) {
  if (l == L && r == R)
    return sum[x];
  push_down(x, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid) return query(x << 1, l, r, L, mid);
  if (l > mid) return query(x<<1|1, l, r, mid + 1, R);
  return (query(x << 1, l, mid, L, mid) + query(x<<1|1, mid + 1, r, mid + 1, R)) % mod;
}

// Tree chain cut
int dep[N], fa[N], sz[N], son[N];
void dfs1(int x, int f) {
  dep[x] = dep[f] + 1;
  fa[x] = f;
  sz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs1(to[i], x);
    if (sz[to[i]] > sz[son[x]])
      son[x] = to[i];
    sz[x] += sz[to[i]];
  }
}
int fp[N], p[N], pos, top[N];
void dfs2(int x, int up) {
  top[x] = up;
  fp[p[x] = ++pos] = x;
  if (!son[x]) return;
  dfs2(son[x], up);
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == son[x] || to[i] == fa[x])
      continue;
    dfs2(to[i], to[i]);
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    sum[x] = a[fp[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid + 1, r);
  sum[x] = (sum[x << 1] + sum[x<<1|1]) % mod;
}

// work
int ask_sum(int x, int y) {
  int fx = top[x], fy = top[y];
  int res = 0;
  while (fx != fy) {
    if (dep[fx] < dep[fy])
      swap(fx, fy), swap(x, y);
    res = (res + query(1, p[fx], p[x], 1, n)) % mod;
    x = fa[fx]; fx = top[x];
  }
  if (dep[x] > dep[y]) swap(x, y);
  return (res + query(1, p[x], p[y], 1, n)) % mod;
}
void update_sum(int x, int y, int v) {
  int fx = top[x], fy = top[y];
  while (fx != fy) {
    if (dep[fx] < dep[fy])
      swap(fx, fy), swap(x, y);
    update(1, p[fx], p[x], 1, n, v);
    x = fa[fx]; fx = top[x];
  }
  if (dep[x] > dep[y]) swap(x, y);
  update(1, p[x], p[y], 1, n, v);
}
int ask_tree(int x) {
  return query(1, p[x], p[x] + sz[x] - 1, 1, n);
}
void update_tree(int x, int v) {
  update(1, p[x], p[x] + sz[x] - 1, 1, n, v);
}

int main(int argc, char const *argv[]) {
  n = read(); m = read();
  r = read(); mod = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i < n; i++)
    insert(read(), read());
  dfs1(r, 0);
  dfs2(r, r);
  build(1, 1, n);
  // cout << pos << endl;
  while (m --) {
    int op = read();
    if (op == 1) {
      int x = read(), y = read(), z = read();
      update_sum(x, y, z);
    }
    if (op == 2) {
      int x = read(), y = read();
      printf("%d\n", ask_sum(x, y));
    }
    if (op == 3) {
      int x = read(), z = read();
      update_tree(x, z);
    }
    if (op == 4) {
      int x = read();
      printf("%d\n", ask_tree(x));
    }
    // printf("%d\n", ask_tree(r));
  }
  return 0;
}