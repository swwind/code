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
int mp[N][N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), c = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      mp[i][j] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      mp[i][j] += mp[i][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      mp[i][j] += mp[i - 1][j];
  int ans = -1 << 30, x, y;
  for (int i = 0; i <= n - c; i++) {
    for (int j = 0; j <= m - c; j++) {
      int k = mp[i + c][j + c] - mp[i][j + c] - mp[i + c][j] + mp[i][j];
      if (k > ans) {
        x = i;
        y = j;
        ans = k;
      }
    }
  }
  cout << x + 1 << " " << y + 1 << endl;
  return 0;
}