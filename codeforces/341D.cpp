#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int c[2][2][N][N];
int n, m;
void update(int x, int y, int v) {
  printf("update %d %d %d\n", x, y, v);
  if (!x || !y) return;
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= n; j += j & -j) {
      c[x&1][y&1][i][j] ^= v;
    }
  }
}
int query(int x, int y) {
  printf("query %d %d\n", x, y);
  int ans = 0;
  for (int i = x; i; i ^= i & -i) {
    for (int j = y; j; j ^= j & -j) {
      ans ^= c[x&1][y&1][i][j];
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  freopen("../temp/input.in", "r", stdin);
  n = read(); m = read();
  while (m --) {
    int op = read();
    if (op == 1) {
      int x0 = read(), y0 = read(), x1 = read(), y1 = read();
      int ans = query(x1, y1);
      ans ^= query(x0 - 1, y1);
      ans ^= query(x1, y0 - 1);
      ans ^= query(x0 - 1, y0 - 1);
      cout << ans << endl;
    } else {
      int x0 = read(), y0 = read(), x1 = read(), y1 = read();
      int v = read();
      update(x1 + 1, y1 + 1, v);
      update(x0, y1 + 1, v);
      update(x1 + 1, y0, v);
      update(x0, y0, v);
    }
  }
  return 0;
}