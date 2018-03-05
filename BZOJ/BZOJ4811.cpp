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
inline ull readull() {
  ull x = 0;
  scanf("%llu", &x);
  return x;
}
int nxt[N << 1], to[N << 1], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}

int op[N];
ull ax[N];
const ull inf = 0ull - 1ull;
struct node {
  // l0 左边进去是0，右边出来的值
  ull l0, l1, r0, r1;
  node(ull l0 = 0, ull l1 = inf, ull r0 = 0, ull r1 = inf) {
    this -> l0 = l0;
    this -> l1 = l1;
    this -> r0 = r0;
    this -> r1 = r1;
  }
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
  ull r0 = (b.r0 & a.r1) | ((~ b.r0) & a.r0);
  ull r1 = (b.r1 & a.r1) | ((~ b.r1) & a.r0);
  return node(l0, l1, r0, r1);
}
void rever(node &a) {
  swap(a.l0, a.r0);
  swap(a.l1, a.r1);
}

node tr[N << 2];
int fp[N], p[N];
int n, m, k;
//  p => 树剖 -> 线段树
// fp => 树剖 <- 线段树
void build(int x, int l, int r) {
  if (l == r) {
    tr[x].l0 = calc(0, ax[fp[l]], op[fp[l]]);
    tr[x].l1 = calc(inf, ax[fp[l]], op[fp[l]]);
    tr[x].r0 = calc(0, ax[fp[l]], op[fp[l]]);
    tr[x].r1 = calc(inf, ax[fp[l]], op[fp[l]]);
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x<<1|1, mid + 1, r);
  tr[x] = merge(tr[x << 1], tr[x<<1|1]);
}
void update(int x, int k, int l, int r, int o, ull v) {
  if (l == r) {
    op[fp[k]] = o; ax[fp[k]] = v;
    tr[x].l0 = calc(0, v, o);
    tr[x].l1 = calc(inf, v, o);
    tr[x].r0 = calc(0, v, o);
    tr[x].r1 = calc(inf, v, o);
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
int dep[N], son[N], tot, sz[N], top[N], fa[N];
void dfs1(int x, int f) {
  dep[x] = dep[f] + 1;
  sz[x] = 1; fa[x] = f;
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
  fp[p[x] = ++ tot] = x;
  if (!son[x]) return;
  dfs2(son[x], up);
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == son[x] || to[i] == fa[x])
      continue;
    dfs2(to[i], to[i]);
  }
}

node ansx[N], ansy[N];
node ask(int x, int y) { // 询问树链
  int f1 = top[x], f2 = top[y];
  int cntx = 0, cnty = 0;
  while (f1 != f2) {
    if (dep[f1] > dep[f2]) {
      ansx[++ cntx] = ask(1, p[f1], p[x], 1, n);
      x = fa[f1]; f1 = top[x];
    } else {
      ansy[++ cnty] = ask(1, p[f2], p[y], 1, n);
      y = fa[f2]; f2 = top[y];
    }
  }
  if (dep[x] > dep[y])
    ansx[++ cntx] = ask(1, p[y], p[x], 1, n);
  else
    ansy[++ cnty] = ask(1, p[x], p[y], 1, n);
  for (int i = 1; i <= cntx; i++)
    rever(ansx[i]);
  node res = cntx ? ansx[1] : ansy[cnty];
  for (int i = 2; i <= cntx; i++)
    res = merge(res, ansx[i]);
  for (int i = cnty - !cntx; i; i--)
    res = merge(res, ansy[i]);
  return res;
}
int main(int argc, char const *argv[]) {
  n = read(); m = read(); k = read();
  for (int i = 1; i <= n; i++)
    op[i] = read(), ax[i] = readull();
  for (int i = 1; i < n; i++)
    insert(read(), read());
  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int q = read(), x = read(), y = read();
    ll z = readull();
    if (q == 1) {
      node res = ask(x, y);
      ull ans = 0;
      for (int i = 63; ~i; i--) {
        int t0 = res.l0 >> i & 1;
        int t1 = res.l1 >> i & 1;
        if (t0 >= t1 || (1ull << i) > z) ans |= t0 ? 1ull << i : 0;
        else ans |= t1 ? 1ull << i : 0, z -= 1ull << i;
      }
      printf("%llu\n", ans);
    } else {
      update(1, p[x], 1, n, y, z);
    }
  }
  return 0;
}