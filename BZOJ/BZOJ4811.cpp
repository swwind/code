#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define ull unsigned long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int nxt[N << 1], to[N << 1], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}

int op[N];
ull ax[N];
struct node {
  // l0 左边进去是0，右边出来的值
  ull l0, l1, r0, r1;
};
ull calc(ull a, ull b, int c) {
  if (c == 1) return a & b;
  if (c == 2) return a | b;
  if (c == 3) return a ^ b;
  throw "calc(): c must be in [1, 3]!";
}
node merge(node a, node b) {
  ull l0 = (a.l0 & b.l1) | ((~ a.l0) & b.l0);
  ull l1 = (a.l1 & b.l1) | ((~ a.l1) & b.l0);
  ull r0 = (a.r0 & b.r1) | ((~ a.r0) & b.r0);
  ull r1 = (a.r1 & b.r1) | ((~ a.r1) & b.r0);
  return {l0, l1, r0, r1};
}

node tr[N << 2];
int fp[N], p[N];
//  p => 树剖 -> 线段树
// fp => 树剖 <- 线段树
const ull inf = 0ull - 1ull;
void build(int x, int l, int r) {
  if (l == r) {
    tr[x].l0 = calc(0, ax[i], op[l]);
    tr[x].l1 = calc(inf, ax[i], op[l]);
    tr[x].r0 = calc(0, ax[i], op[l]);
    tr[x].r1 = calc(inf, ax[i], op[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid + 1, r);
  tr[x] = merge(tr[x << 1], tr[x<<1|1]);
}
void update(int x, int k, int l, int r, int o, ull v) {
  if (l == r) {
    op[k] = o;
    ax[k] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid) update(x << 1, k, l, mid, o, v);
  else update(x<<1|1, k, mid + 1, r, o, v);
  tr[x] = merge(tr[x << 1], tr[x<<1|1]);
}
node ask(int x, int l, int r, int L, int R) {
  if (l == L && r == R)
    return tr[x];
  int mid = (L + R) >> 1;
  if (r <= mid) return ask(x << 1, l, r, L, mid);
  else if (l > mid) return ask(x<<1|1, l, r, mid + 1, R);
  else return merge(ask(x << 1, l, mid, L, mid), ask(x<<1|1, mid + 1, r, mid + 1, R));
}
int dep[N], son[N], tot, sz[N], top[N], fa[N][20];
void dfs1(int x, int f) {
  dep[x] = dep[f] + 1;
  fp[p[x] = ++ tot] = x;
  sz[x] = 1; fa[x][0] = f;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs1(to[i], x);
    if (sz[to[i]] > sz[son[x]])
      son[x] = to[i];
    sz[x] += sz[to[i]];
  }
}
void dfs2(int x, int up) {
  top[x] = up;
  if (!son[x]) return;
  dfs2(son[x], up);
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == son[x] || to[i] == fa[x][0])
      continue;
    dfs2(to[i], to[i]);
  }
}

node ask(int x, int y) { // 询问树链
  
}

int main(int argc, char const *argv[]) {
  int n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    op[i] = read();
    ax[i] = read();
  }
  for (int i = 1; i < n; i++)
    insert(read(), read());
  for (int i = 1; i <= m; i++) {
    int q = read(), x = read(), y = read();
    ll z = read();
    if (q == 1) {
      node res = ask(x, y);
      printf("%lld\n", res);
    } else {
      // update pos x opt -> y, ax -> z
      update(1, p[x], 1, n, y, z);
    }
  }
  return 0;
}