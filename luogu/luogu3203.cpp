#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int c[N][2], fa[N], rev[N], sz[N], st[N], nxt[N];
bool isroot(int x) {
  return c[fa[x]][0] != x && c[fa[x]][1] != x;
}
void push_down(int x) {
  if (rev[x]) {
    rev[x] ^= 1;
    swap(c[x][0], c[x][1]);
    rev[c[x][0]] ^= 1;
    rev[c[x][1]] ^= 1;
  }
}
void push_up(int x) {
  sz[x] = sz[c[x][0]] + sz[c[x][1]] + 1;
}
void rotate(int x) { // 旋转一次
  int y = fa[x], z = fa[y];
  int r = c[y][0] == x, l = r ^ 1;
  if (!isroot(y))
    c[z][c[z][0] != y] = x;
  fa[x] = z; fa[y] = x; fa[c[x][r]] = y;
  c[y][l] = c[x][r]; c[x][r] = y;
  push_up(y); push_up(x);
}
void splay(int x) { // 旋转到根
  int top = 0; st[++ top] = x;
  for (int i = x; !isroot(i); i = fa[i])
    st[++ top] = fa[i];
  while (top) push_down(st[top --]);
  while (!isroot(x)) {
    int y = fa[x], z = fa[y];
    if (!isroot(y)) {
      if ((c[y][0] == x) ^ (c[z][0] == y)) rotate(x);
      else rotate(y);
    }
    rotate(x);
  }
}
void access(int x) { // 打通道路
  int t = 0;
  while (x) {
    splay(x);
    c[x][1] = t;
    t = x;
    x = fa[x];
  }
}
void rever(int x) { // 旋转
  access(x);
  splay(x);
  rev[x] ^= 1;
}
void link(int x, int y) { // 连边
  rever(x);
  fa[x] = y;
  splay(x);
}
void cut(int x, int y) { // 断边
  rever(x);
  access(y);
  splay(y);
  // 这时候`y`的右儿子已经是`x`了。
  c[y][0] = fa[x] = 0;
}
int find(int x) { // 寻找祖先
  access(x);
  splay(x);
  while (c[x][0])
    x = c[x][0];
  return x;
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++) {
    nxt[i] = min(i + read(), n + 1);
    fa[i] = nxt[i];
    sz[i] = 1;
  }
  sz[n + 1] = 1;
  int m = read();
  for (int i = 1; i <= m; i++) {
    int op = read(), x = read() + 1;
    if (op == 1) {
      rever(n + 1);
      access(x);
      splay(x);
      printf("%d\n", sz[c[x][0]]);
    } else {
      int t = min(x + read(), n + 1);
      cut(x, nxt[x]);
      link(x, nxt[x] = t);
    }
  }
  return 0;
}