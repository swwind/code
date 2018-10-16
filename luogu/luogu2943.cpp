#include <bits/stdc++.h>
#define N 40020
#define M 205
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int g[N][M], f[N], a[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 2, j; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      for (int j = 1; j <= 200; j++)
        g[i][j] = g[i - 1][j];
    } else {
      g[i][1] = i - 1;
      for (j = 2; j <= 200; j++) {
        if (a[g[i - 1][j - 1]] != a[i])
          g[i][j] = g[i - 1][j - 1];
        else break;
      }
      for (; j <= 200; j++)
        g[i][j] = g[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] = 1 << 30;
    for (int j = 1; j <= 200; j++)
      f[i] = min(f[i], f[g[i][j]] + j * j);
  }
  cout << f[n] << endl;
  return 0;
}