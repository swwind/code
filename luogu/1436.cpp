#include <bits/stdc++.h>
#define N 10
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N][N];
int S(int x1, int y1, int x2, int y2) {
  int x = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
  return x * x;
}
int f[20][N][N][N][N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      a[i][j] = read() + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }

  memset(f, 63, sizeof f);

  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      for (int k = i; k <= 8; k++)
        for (int l = j; l <= 8; l++)
          f[1][i][j][k][l] = S(i, j, k, l);

  for (int s = 2; s <= n; s++) {
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        for (int k = i; k <= 8; k++) {
          for (int l = j; l <= 8; l++) {
            for (int t = i; t < k; t++) {
              f[s][i][j][k][l] = min(
                f[s][i][j][k][l],
                min(
                  f[s - 1][i][j][t][l] + f[1][t + 1][j][k][l],
                  f[1][i][j][t][l] + f[s - 1][t + 1][j][k][l]
                )
              );
            }
            for (int t = j; t < l; t++) {
              f[s][i][j][k][l] = min(
                f[s][i][j][k][l],
                min(
                  f[s - 1][i][j][k][t] + f[1][i][t + 1][k][l],
                  f[1][i][j][k][t] + f[s - 1][i][t + 1][k][l]
                )
              );
            }
          }
        }
      }
    }
  }

  cout << f[n][1][1][8][8] << endl;

  return 0;
}