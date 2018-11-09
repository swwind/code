#include <bits/stdc++.h>
#define N 2020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll c[N][N], ans;
int a[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) a[i] = read();
  for (int i = 0; i <= 2000; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
  }
  for (int i = 0, f = 1; i <= n; ++ i, f = -f) {
    ll res = (c[n][i] * f % mod + mod) % mod;
    for (int j = 1; j <= m; j++)
      res = res * c[a[j]+n-i-1][n-i-1] % mod;
    ans = ((ans + res) % mod + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}