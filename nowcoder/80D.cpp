#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
double t, g[N];
int n, z[N], cnt;
int main(int argc, char const *argv[]) {
  cin >> t >> n;
  for (int i = 1; i <= n; i++)
    z[i] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 501; j++)
      g[++ cnt] = (double) z[i] / j;
  sort(g + 1, g + cnt + 1);
  for (int i = cnt; i >= 1; i--) {
    if (g[i] == g[i + 1]) continue;
    double l = g[i] * t, r = g[i];
    int res = 0, flag = 0;
    for (int k = 1; k <= n; k++) {
      int xx = z[k] / l;
      int yy = z[k] / r + 1 - 1e-6;
      if (xx < yy) {
        flag = 1;
        break;
      }
      res += yy - 1;
    }
    if (!flag)
      return printf("%d\n", res), 0;
  }
  return 0;
}