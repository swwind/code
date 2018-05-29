#include <bits/stdc++.h>
#define N 320
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N], mp[N][N], ans;
int f[N][N];
int dfs(int x, int fa, int d) {
  if (~f[x][d]) return f[x][d];
  f[x][d] = 0;
  for (int i = 1; i <= n; ++ i) {
    
  }
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    for (int j = 1; j <= i; ++ j) {
      ll kk = (ll) a[i] * a[j];
      ll k  = sqrt(kk);
      if (k * k == kk)
        mp[i][j] = mp[j][i] = 1;
    }
  }
  for (int i = 1; i <= n; ++ i) {
    memset(f, -1, sizeof f);
    ans = (ans + dfs(i, 0, 1)) % mod;
  }
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      printf("%d ", mp[i][j]);
    }
    puts("");
  }
  return 0;
}