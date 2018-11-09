#include <bits/stdc++.h>
#define N 100020
#define mod 51061
#define ll long long
using namespace std;
inline int read() {
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int fa[N], ch[N][2], rev[N], sz[N];
ll sum[N], tsum[N], tmul[N], val[N];
bool isroot(int x) {
  return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}
void mul(int x, int v) {
  tmul[x] = tmul[x] * v % mod;
  tsum[x] = tsum[x] * v % mod;
  sum[x] = sum[x] * v % mod;
  val[x] = val[x] * v % mod;
}
void add(int x, int v) {
  tsum[x] = (tsum[x] + v) % mod;
  sum[x] = (sum[x] + v * sz[x]) % mod;
  val[x] = (val[x] + v) % mod;
}
void push_down(int x) {
  int &ls = ch[x][0], &rs = ch[x][1];
  if (rev[x]) {
    rev[ls] ^= 1;
    rev[rs] ^= 1;
    swap(ls, rs);
    rev[x] = 0;
  }
  if (tmul[x] != 1) {
    mul(ls, tmul[x]);
    mul(rs, tmul[x]);
  }
  if (tsum[x]) {
    add(ls, tsum[x]);
    add(rs, tsum[x]);
  }
  tmul[x] = 1;
  tsum[x] = 0;
}
void push_up(int x) {
  sum[x] = (sum[ch[x][0]] + sum[ch[x][1]] + val[x]) % mod;
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
void rotate(int x) {
  int y = fa[x], z = fa[y];
  int r = ch[y][0] == x, l = r^1;
  if (!isroot(y)) ch[z][ch[z][0] != y] = x;
  fa[x] = z; fa[y] = x; fa[ch[x][r]] = y;
  ch[y][l] = ch[x][r]; ch[x][r] = y;
  push_up(y);
}
int st[N];
void splay(int x) {
  int top = 0; st[++ top] = x;
  for (int i = x; !isroot(i); i = fa[i])
    st[++ top] = fa[i];
  for (int i = top; i; -- i)
    push_down(st[i]);
  while (!isroot(x)) {
    int y = fa[x], z = fa[y];
    if (!isroot(y)) {
      if ((ch[y][0] == x) ^ (ch[z][0] == y)) rotate(x);
      else rotate(y);
    }
    rotate(x);
  } push_up(x);
}
void access(int x) {
  int t = 0;
  while (x) {
    splay(x);
    ch[x][1] = t;
    t = x; x = fa[x];
  }
}
void rever(int x) {
  access(x); splay(x);
  rev[x] ^= 1;
}
void link(int x, int y) {
  rever(x);
  fa[x] = y;
  splay(x);
}
void split(int x, int y) {
  rever(x); access(y); splay(y);
}
void cut(int x, int y) {
  split(x, y);
  ch[y][0] = fa[x] = 0;
}
char shi[3];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i)
    val[i] = sz[i] = tmul[i] = 1;
  for (int i = 1; i < n; ++ i)
    link(read(), read());
  for (int i = 1; i <= m; ++ i) {
    scanf("%s", shi);
    if (shi[0] == '+') {
      int x = read(), y = read(), z = read();
      split(x, y); add(y, z);
    }
    if (shi[0] == '-') {
      int x1 = read(), y1 = read();
      int x2 = read(), y2 = read();
      cut(x1, y1); link(x2, y2);
    }
    if (shi[0] == '*') {
      int x = read(), y = read(), z = read();
      split(x, y); mul(y, z);
    }
    if (shi[0] == '/') {
      int x = read(), y = read();
      split(x, y);
      printf("%lld\n", sum[y]);
    }
  }
  return 0;
}