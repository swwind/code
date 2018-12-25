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

ll fast_mul(ll x, ll y, ll mod) {
  ll z = 0;
  for (; y; y >>= 1, x = (x << 1) % mod) {
    if (y & 1) {
      z = (z + x) % mod;
    }
  }
  return z;
}
ll fast_pow(ll x, ll y, ll mod) {
  ll z = 1 % mod;
  for (; y; y >>= 1, x = fast_mul(x, x, mod)) {
    if (y & 1) {
      z = fast_mul(z, x, mod);
    }
  }
  return z;
}
ll phi(ll x) {
  ll res = x;
  for (ll i = 2; i * i <= x; ++ i) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
ll pows(ll p) {
  if (p == 1) return 0;
  ll ps = phi(p);
  ll x = pows(ps) + ps;
  return fast_pow(2, x, p);
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);
  int T = read();
  while (T --) {
    int p = read();
    printf("%lld\n", pows(p));
  }
  return 0;
}