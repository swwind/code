#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline int read() {
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

const int mod = 999911658;
ll n, G, frac[50010], a[5], b[5] = {2, 3, 4679, 35617};

inline ll fast_pow(ll x, ll y, ll p) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % p) {
    if (y & 1) {
      z = z * x % p;
    }
  }
  return z;
}

inline void init(ll p) {
  frac[0] = 1;
  for (ll i = 1; i <= p; ++i) {
    frac[i] = frac[i - 1] * i % p;
  }
}

inline ll inv(ll x, ll p) {
  return fast_pow(x, p - 2, p);
}

inline ll C(ll n, ll m, ll p) {
  if (n < m) {
    return 0;
  }
  return frac[n] * inv(frac[m], p) % p * inv(frac[n - m], p) % p;
}

ll lucas(ll n, ll m, ll p) {
  if (n < m) {
    return 0;
  }
  if (!n) {
    return 1;
  }
  return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

inline ll CRT() {
  ll res = 0;
  for (ll i = 0; i < 4; ++i) {
    res = (res + a[i] * (mod / b[i]) % mod * inv(mod / b[i], b[i])) % mod;
  }
  return res;
}


int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  ll n = read(), G = read();
  if (G % (mod + 1) == 0) {
    return puts("0"), 0;
  }
  for (ll k = 0; k < 4; k++) {
    init(b[k]);
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        a[k] = (a[k] + lucas(n, i, b[k])) % b[k];
        if (i * i != n) {
          a[k] = (a[k] + lucas(n, n / i, b[k])) % b[k];
        }
      }
    }
  }

  printf("%lld\n", fast_pow(G, CRT(), mod + 1));
  return 0;
}