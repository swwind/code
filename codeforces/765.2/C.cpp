#include <bits/stdc++.h>
#define N 150020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int a[505], s[505];
int f[505][505], g[505][505];

int main() {
  int n = read();
  int l = read();
  int k = read();

  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  a[n+1] = l;
  a[n+2] = l;
  for (int i = 1; i <= n; ++ i) {
    s[i] = read();
  }

  // memset(f, 0x3f, sizeof(f));
  for (int _i = 0; _i < 505; ++ _i)
  for (int _j = 0; _j < 505; ++ _j)
  f[_i][_j] = 2e9;
  f[0][1] = a[2] * s[1];

  // f[n][m][k] 当前在第 n 个棋子，拿走了前面 m 个，最后一个没拿走的是 k 的最小代价
  for (int i = 1; i <= n; ++ i) {
    swap(f, g);
    // memset(f, 0x3f, sizeof(f));
    for (int _i = 0; _i < 505; ++ _i)
    for (int _j = 0; _j < 505; ++ _j)
    f[_i][_j] = 2e9;
    for (int j = 0; j < i; ++ j) {
      for (int k = i-j; k <= i; ++ k) {
        // 拔掉下一个棋子
        // printf("f[%d][%d][%d] = %d\n", i, j, k, g[j][k]);
        f[j+1][k] = min(f[j+1][k], g[j][k] + (a[i+2]-a[i+1])*(s[k]));
        // 保留下一个棋子
        f[j][i+1] = min(f[j][i+1], g[j][k] + (a[i+2]-a[i+1])*(s[i+1]));
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i <= k; ++ i) {
    ans = min(ans, f[i][n+1]);
  }
  printf("%d\n", ans);
}
