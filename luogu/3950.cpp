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
int fa[N], ch[N][2], rev[N], st[N];
bool isroot(int x) {
  return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}
void push_down(int x) {
  if (!rev[x]) return;
  rev[x] ^= 1;
  rev[ch[x][0]] ^= 1;
  rev[ch[x][1]] ^= 1;
  swap(ch[x][0], ch[x][1]);
}
void rotate(int x) {
  int y = fa[x], z = fa[y];
  int r = ch[y][0] == x, l = r ^ 1;
  if (!isroot(y)) ch[z][ch[z][0] != y] = x;
  fa[x] = z; fa[y] = x; fa[ch[x][r]] = y;
  ch[y][l] = ch[x][r]; ch[x][r] = y;
}
void splay(int x) {
  int top = 0; st[++ top] = x;
  for (int i = x; !isroot(i); i = fa[i]) {
    st[++ top] = fa[i];
  }
  for (int i = top; i; -- i) {
    push_down(st[i]);
  }
  while (!isroot(x)) {
    int y = fa[x], z = fa[y];
    if (!isroot(y)) {
      if (ch[y][0] == x ^ ch[z][0] == y) {
        rotate(x);
      } else {
        rotate(y);
      }
    }
    rotate(x);
  }
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
void cut(int x, int y) {
  rever(x); access(y); splay(y);
  ch[y][0] = fa[x] = 0;
}
int find_root(int x) {
  access(x); splay(x);
  while (ch[x][0]) {
    push_down(x);
    x = ch[x][0];
  }
  return x;
}
char str[2];
std::vector<std::pair<int, int>> wars;
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i < n; ++ i) {
    int p = read(), q = read();
    link(p, q);
  }
  for (int i = 1; i <= m; ++ i) {
    scanf("%s", str);
    if (str[0] == 'Q') {
      int x = read(), y = read();
      puts(find_root(x) == find_root(y) ? "Yes" : "No");
    }
    if (str[0] == 'C') {
      int x = read(), y = read();
      wars.push_back(make_pair(x, y));
      cut(x, y);
    }
    if (str[0] == 'U') {
      int x = read();
      link(wars[x - 1].first, wars[x - 1].second);
    }
  }
  return 0;
}