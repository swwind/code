#include <bits/stdc++.h>
#define N 520
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int f[N][N], g[N][N], a[N][N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = g[i][j] = a[i][j] = read();
  if (!k) return puts("1"), 0;
  for (int ans = 1; ans < min(n, m); ans++) {
    for (int i = 1; i <= n - ans; i++) {
      for (int j = 1; j <= m - ans; j++) {
        f[i][j] = max(max(f[i][j + 1], f[i + 1][j]), max(a[i][j], a[i+ans][j+ans]));
        g[i][j] = min(min(g[i][j + 1], g[i + 1][j]), min(a[i][j], a[i+ans][j+ans]));
        if (f[i][j] - g[i][j] >= k)
          return printf("%d\n", ans + 1), 0;
      }
    }
  }
  puts("-1");
  return 0;
}