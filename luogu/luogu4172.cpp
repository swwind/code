#include <bits/stdc++.h>
#define N 1500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int c[N][2], fa[N], rev[N], st[N], mx[N], val[N];
bool isroot(int x) {
  return c[fa[x]][0] != x && c[fa[x]][1] != x;
}
void push_down(int x) {
  if (rev[x]) {
    rev[c[x][0]] ^= 1;
    rev[c[x][1]] ^= 1;
    swap(c[x][0], c[x][1]);
    rev[x] = 0;
  }
}
void push_up(int x) {
  mx[x] = x;
  if (val[mx[c[x][0]]] > val[mx[x]]) mx[x] = mx[c[x][0]];
  if (val[mx[c[x][1]]] > val[mx[x]]) mx[x] = mx[c[x][1]];
}
void rotate(int x) {
  int y = fa[x], z = fa[y];
  int r = c[y][0] == x, l = r^1;
  if(!isroot(y)) c[z][c[z][0]!=y] = x;
  fa[x] = z; fa[y] = x; fa[c[x][r]] = y;
  c[y][l] = c[x][r]; c[x][r] = y;
  push_up(y); push_up(x);
}
void splay(int x) {
  int top = 0; st[++ top] = x;
  for (int i = x; !isroot(i); i = fa[i])
    st[++ top] = fa[i];
  while (top) push_down(st[top --]);
  while (!isroot(x)) {
    int y = fa[x], z = fa[y];
    if (!isroot(y)) {
      if ((c[z][0] == y) ^ (c[y][0] == x))
        rotate(x);
      else
        rotate(y);
    }
    rotate(x);
  }
}
void access(int x) {
  int t = 0;
  while (x) {
    splay(x);
    c[x][1] = t;
    push_up(x);
    t = x;
    x = fa[x];
  }
}
void rever(int x) {
  access(x);
  splay(x);
  rev[x] ^= 1;
}
void link(int x, int y) {
  rever(x);
  fa[x] = y;
  splay(x);
}
void cut(int x, int y) {
  rever(x);
  access(y);
  splay(y);
  c[y][0] = fa[x] = 0;
}
int query(int x, int y) {
  rever(x);
  access(y);
  splay(y);
  return mx[y];
}

struct edge {
  int x, y, v, id;
}fs[N],wss[N];
bool cmp1(const edge &a, const edge &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmp2(const edge &a, const edge &b) {
  return a.v < b.v;
}
bool cmp3(const edge &a, const edge &b) {
  return a.id < b.id;
}
int _fa[N];
int find(int x) {
  return _fa[x] == x ? x : _fa[x] = find(_fa[x]);
}
int no[N], ans[N], acnt;
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), q = read();
  for (int i = 1; i <= m; i++) {
    fs[i].x = read();
    fs[i].y = read();
    fs[i].v = read();
    if (fs[i].x > fs[i].y)
      swap(fs[i].x, fs[i].y);
  }
  // sort by value
  sort(fs + 1, fs + m + 1, cmp2);
  for (int i = 1; i <= m; i++) {
    fs[i].id = i;
    val[i + n] = fs[i].v;
    mx[i + n] = i + n;
  }
  // sort by x & y
  sort(fs + 1, fs + m + 1, cmp1);
  for (int i = 1; i <= q; i++) {
    wss[i].v = read();
    wss[i].x = read();
    wss[i].y = read();
    if (wss[i].v == 2) { // delete edge
      if (wss[i].x > wss[i].y)
        swap(wss[i].x, wss[i].y);
      int id = lower_bound(fs + 1, fs + m + 1, wss[i], cmp1) - fs;
      wss[i].id = fs[id].id;
      no[fs[id].id] = 1;
    }
  }
  // ------- Kruskal

  for (int i = 1; i <= n; i++)
    _fa[i] = i;
  sort(fs + 1, fs + m + 1, cmp3);
  int tot = 0;
  for (int i = 1; i <= m; i++) {
    if (no[fs[i].id]) continue;
    int fx = find(fs[i].x), fy = find(fs[i].y);
    if (fx == fy) continue;
    _fa[fx] = fy;
    link(fs[i].x, i + n); // ???
    link(fs[i].y, i + n); // ???
    if (++ tot == n - 1)
      break;
  }

  // --- end Kruskal

  for (int i = q; i; i--) {
    if (wss[i].v == 1) {
      int id = query(wss[i].x, wss[i].y);
      ans[++acnt] = val[id];
    } else {
      int id = query(wss[i].x, wss[i].y);
      if (val[id] > val[wss[i].id + n]) {
        // if the edge is better
        cut(fs[id - n].x, id);
        cut(fs[id - n].y, id);
        link(wss[i].x, wss[i].id + n);
        link(wss[i].y, wss[i].id + n);
      }
    }
  }
  while (acnt)
    printf("%d\n", ans[acnt --]);

  return 0;
}