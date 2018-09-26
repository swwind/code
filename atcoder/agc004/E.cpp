#include <bits/stdc++.h>
#define N 105
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int n,m,a[N][N],sx,sy,f[2][N][N][N];
char str[N];

int get(int x1, int x2, int y1, int y2) {
  return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}

inline void _max(int &a, int b) {
  a = max(a, b);
}

int main(int argc, char const *argv[]) {
  n = read(); m = read();
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; ++ j) {
      if (str[j] == 'E') sx = i, sy = j;
      if (str[j] == 'o') ++ a[i][j];
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  int ans = 0, now = 0;
  for (int i = 0; i < sx; ++ i) {
    now ^= 1;
    for (int j = 0; j < sy; ++ j) {
      for (int k = 0; k < n - sx + 1; ++ k) {
        for (int l = 0; l < m - sy + 1; ++ l) {
          f[now][j][k][l] = 0;
          if (i && sx - i > k) _max(f[now][j][k][l], f[now^1][j][k][l] + get(sx-i, sx-i, max(sy-j, l+1), min(sy+l, m-j)));
          if (j && sy - j > l) _max(f[now][j][k][l], f[now][j-1][k][l] + get(max(sx-i, k+1), min(sx+k, n-i), sy-j, sy-j));
          if (k && n-sx-k+1>i) _max(f[now][j][k][l], f[now][j][k-1][l] + get(sx+k, sx+k, max(sy-j, l+1), min(sy+l, m-j)));
          if (l && m-sy-l+1>j) _max(f[now][j][k][l], f[now][j][k][l-1] + get(max(sx-i, k+1), min(sx+k, n-i), sy+l, sy+l));
          _max(ans, f[now][j][k][l]);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
/*

Ctrl+C && Ctrl+V

+-----------------------------------------------------------+
|  这个世界不喜欢与众不同的人。不要让别人告诉你，你该成为什么样的人。   |
|                                                           |
|                                                 ---- 卡尔  |
+-----------------------------------------------------------+

*/
