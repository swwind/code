// 反向 dp

#include <bits/stdc++.h>
#define N 15
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
double f[105][1<<N];
int cst[N], deps[N];
int main(int argc, char const *argv[]) {
  int m = read(), n = read();
  for (int i = 0; i < n; ++ i) {
    cst[i] = read();
    while (int x = read()) {
      deps[i] |= (1 << x - 1);
    }
  }
  int ns = 1 << n;
  double nfz = 1. / n;
  for (int i = m; i; -- i) {
    for (int j = 0; j < ns; ++ j) {
      for (int k = 0; k < n; ++ k) {
        if ((j & deps[k]) == deps[k]) {
          f[i][j] += nfz * fmax(f[i + 1][j], f[i + 1][j | (1 << k)] + cst[k]);
        } else {
          f[i][j] += nfz * f[i + 1][j];
        }
      }
    }
  }
  printf("%.6lf\n", f[1][0]);
  return 0;
}
// e-hentai.org
// liuli.pw