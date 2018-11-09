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
int a[55][55], f[55][55][2520], ans;
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++)
      a[i][j] = read();
  memset(f, -127, sizeof f);
  f[n + 1][0][0] = 0;

  for (int j = n; j; j--)
    for (int i = 0, sum = 0; i <= n - j + 1; i++, sum += a[i][j])
      for (int k = i; k <= m; k++)
        for (int l = max(0, i - 1); l <= n - j; l++)
          f[j][i][k] = max(f[j][i][k], f[j + 1][l][k - i] + sum);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++)
      ans = max(ans, f[i][j][m]);
  cout << ans << endl;
  return 0;
}