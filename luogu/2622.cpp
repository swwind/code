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
int a[105][15];
int f[1<<10];
int q[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= m; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      a[i][j] = read();
    }
  }
  int ns = 1 << n;
  int l = 0, r = 1;
  memset(f, 63, sizeof f);
  f[ns - 1] = 0;
  q[1] = ns - 1;
  while (l < r) {
    int x = q[++ l];
    for (int i = 1; i <= m; ++ i) {
      int xx = x;
      for (int j = 1; j <= n; ++ j) {
        if (a[i][j] ==  1) (xx & (1 << (j - 1))) && (xx ^= (1 << (j - 1)));
        if (a[i][j] == -1) (xx |= (1 << (j - 1)));
      }
      // printf("%d -> %d\n", x, xx);
      if (f[x] + 1 <= f[xx]) {
        f[xx] = f[x] + 1;
        q[++ r] = xx;
      }
    }
  }
  if (f[0] > 1e9) cout << "-1" << endl;
  else cout << f[0] << endl;
  return 0;
}