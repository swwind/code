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
double f[N][N];
int a[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      f[i][j] = a[i] > a[j];
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    f[x][y] = f[y][x] = .5;
    for (int i = 1; i <= n; i++) {
      if (i == x || i == y) continue;
      f[x][i] = f[y][i] = (f[x][i] + f[y][i]) / 2;
      f[i][x] = f[i][y] = (f[i][x] + f[i][y]) / 2;
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      ans += f[i][j];
  printf("%.15lf\n", ans);
  return 0;
}