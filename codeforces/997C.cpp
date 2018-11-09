#include <bits/stdc++.h>
#define N 1000020
#define mod 998244353
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

ll frac[N];
inline ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}
inline ll inv(ll x) {
  return fast_pow(x, mod - 2);
}
inline ll C(ll n, ll m) {
  return frac[n] * inv(frac[m]) % mod * inv(frac[n - m]) % mod;
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  int n = read();
  for (int i = frac[0] = 1; i <= n; ++ i) {
    frac[i] = frac[i - 1] * i % mod;
  }

  ll ans1 = 0;
  for (int i = 0; i < n; ++ i) {
    ll res = C(n, i);
    ll ak = (mod - fast_pow(3, i)) % mod;
    ll tmp = (fast_pow(1 + ak, n) - fast_pow(ak, n) + mod) % mod;
    res = res * tmp % mod;
    if (!(i & 1)) res = (mod - res) % mod;
    ans1 = (ans1 + res) % mod;
  }

  ll ans2 = 0;
  for (int i = 1; i <= n; ++ i) {
    ll res = C(n, i);
    if (!(i & 1)) res = (mod - res) % mod;
    res = res * fast_pow(3, (ll) n * (n - i) + i);
    ans2 = (ans2 + res) % mod;
  }

  printf("%lld\n", (ans1 * 3 + ans2 * 2) % mod);


  return 0;
}
