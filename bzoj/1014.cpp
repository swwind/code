#pragma GCC optimize 2
#include <bits/stdc++.h>
#define N 100020
#define mod 998244353
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

char str[N];
int hsh[N], ch[N][2], fa[N], sz[N], rt;
ll pw[N];

void push_up(int x) {
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
  hsh[x] =
  ( hsh[ch[x][0]] * (pw[sz[ch[x][1]] + 1]) % mod
  + str[x] * pw[sz[ch[x][1]]] % mod
  + hsh[ch[x][1]]) % mod;
}
void push_down(int x) {
  // nothing to do here
}
void rotate(int x, int &k) {
  int y = fa[x], z = fa[y];
  int kind = ch[y][1] == x;
  if (y == k) k = x;
  else ch[z][ch[z][1] == y] = x;
  fa[x] = z; fa[y] = x; fa[ch[x][!kind]] = y;
  ch[y][kind] = ch[x][!kind]; ch[x][!kind] = y;
  push_up(y);
  push_up(x);
}
void splay(int x, int &k) {
  while (x != k) {
    int y = fa[x], z = fa[y];
    if (y != k) {
      if (ch[y][1] == x ^ ch[z][1] == y) {
        rotate(x, k);
      } else {
        rotate(y, k);
      }
    }
    rotate(x, k);
  }
}
int kth(int x, int k) {
  push_down(x);
  int r = sz[ch[x][0]] + 1;
  if (k == r) return x;
  if (k < r) return kth(ch[x][0], k);
  else return kth(ch[x][1], k - r);
}
void split(int l, int r) {
  int x = kth(rt, l), y = kth(rt, r + 2);
  splay(x, rt);
  splay(y, ch[rt][1]);
}
int get_hash(int l, int r) {
  split(l, r);
  return hsh[ch[ch[rt][1]][0]];
}
int build(int l, int r, int f) {
  if (l > r) return 0;
  if (l == r) {
    fa[l] = f;
    sz[l] = 1;
    hsh[l] = str[l];
    return l;
  }
  int mid = (l + r) >> 1;
  ch[mid][0] = build(l, mid - 1, mid);
  ch[mid][1] = build(mid + 1, r, mid);
  fa[mid] = f;
  push_up(mid);
  return mid;
}
void insert(int p, char c, int id) {
  split(p, p - 1);
  ch[ch[rt][1]][0] = id;
  fa[id] = ch[rt][1];
  sz[id] = 1;
  hsh[id] = c;
  str[id] = c;
  push_up(ch[rt][1]);
  push_up(rt);
}
void change(int p, char c) {
  split(p, p);
  hsh[ch[ch[rt][1]][0]] = c;
  str[ch[ch[rt][1]][0]] = c;
  push_up(ch[rt][1]);
  push_up(rt);
}
int lcq(int x, int y, int len) {
  int l = 0, r = len - max(x, y) + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (get_hash(x, x + mid - 1) == get_hash(y, y + mid - 1)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l - 1;
}
/*
void print_tree(int x) {
  putchar('(');
  if (ch[x][0]) print_tree(ch[x][0]);
  printf("%d", x);
  if (ch[x][1]) print_tree(ch[x][1]);
  putchar(')');
  if (x == rt) puts("");
}
*/
char op[3], vl[3];
int main(int argc, char const *argv[]) {
  // freopen("1014.in", "r", stdin);
  // freopen("1014.out", "w", stdout);

  for (int i = pw[0] = 1; i < N; ++ i) {
    pw[i] = pw[i - 1] * 19260817ll % mod;
  }

  scanf("%s", str + 2);
  int n = strlen(str + 2) + 2;
  rt = build(1, n, 0);

  int q = read();
  for (int i = 1; i <= q; ++ i) {
    scanf("%s", op);
    if (op[0] == 'Q') {
      int x = read(), y = read();
      printf("%d\n", lcq(x, y, n - 2));
    }
    if (op[0] == 'R') {
      int p = read();
      scanf("%s", vl);
      change(p, vl[0]);
    }
    if (op[0] == 'I') {
      int p = read();
      scanf("%s", vl);
      insert(p + 1, vl[0], ++ n);
    }
  }

  return 0;
}