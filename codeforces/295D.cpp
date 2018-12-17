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

ll dp[N][N];

int main(int argc, char const *argv[]) {

  int n = read(), m = read();

  for (int i = 1; i <= n; ++ i) { dp[i][1] = 1; }
  for (int i = 1; i <= m; ++ i) { dp[1][i] = 1; }

  for (int i = 2; i <= n; ++ i) {
    int sigma = 0;
    for (int j = 2; j <= m; ++ j) {
      sigma = (sigma + dp[i - 1][j]) % mod;
      dp[i][j] = (dp[i][j - 1] + sigma) % mod;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 2; j <= m; ++ j) {
      ans = (ans + (dp[i][j] - dp[i - 1][j] + mod) % mod
          * dp[n - i + 1][j] % mod * (m - j + 1) % mod) % mod;
    }
  }

  printf("%lld\n", ans);

  return 0;
}