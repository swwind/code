#include <bits/stdc++.h>
#define N 2020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
const int mod = 1073741824;
int pri[N], cnt, mark[N], mu[N];
void prepare(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!mark[i]) pri[++ cnt] = i, mu[i] = - 1;
    for (int j = 1; j <= cnt && i * pri[j] <= n; j++) {
      mark[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        mu[i * pri[j]] = 0;
        break;
      } else {
        mu[i * pri[j]] = - mu[i];
      }
    }
  }
}
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
int g[N][N];
int main(int argc, char const *argv[]) {
  ll a = read(), b = read(), c = read();
  if (a > b) swap(a, b);
  ll mx = max(max(a, b), c);
  prepare(a);
  for (int i = 1; i <= mx; ++ i)
    for (int j = 1; j <= mx; ++ j)
      g[i][j] = gcd(i, j);
  ll ans = 0;
  for (int i = 1; i <= c; ++ i) {
    for (int d = 1; d <= a; ++ d) {
      if (g[i][d] == 1) {
        ll a1 = 0, a2 = 0;
        for (int j = 1; j <= a / d; ++ j) 
          if (g[i][j] == 1) a1 += a / d / j;
        for (int j = 1; j <= b / d; ++ j) 
          if (g[i][j] == 1) a2 += b / d / j;
        ans += a1 * a2 % mod * mu[d] * (c / i) % mod;
      }
    }
  }
  cout << (ans % mod + mod) % mod << endl;
  return 0;
}