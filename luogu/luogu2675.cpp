#include <bits/stdc++.h>
#define N 1000020
#define mod 10007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) z = z * x % mod;
  return z;
}
ll inv(ll x) {
  return fast_pow(x, mod - 2);
}
ll frav[N];
ll C(ll n, ll m) {
  if (n < m) return mod;
  if (n < mod && m < mod)
    return frav[n] * inv(frav[m]) % mod * inv(frav[n - m]) % mod;
  else
    return C(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}
int main(int argc, char const *argv[]) {
  int n = read();
  frav[0] = 1;
  for (int i = 1; i <= mod; i++)
    frav[i] = frav[i - 1] * i % mod;
  ll ans = 0, k = 0;
  for (int i = 1; i <= n; i += 2) {
    // printf("%d\n", i);
    ans = (ans + C(n-1, k++) * i % mod) % mod;
  }
  for (int i = n/2*2; i; i -= 2) {
    // printf("%d\n", i);
    ans = (ans + C(n-1, k++) * i % mod) % mod;
  }
  cout << ans << endl;
  return 0;
}