#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

ll n, mod;
ll inv2, inv6;

inline ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}

inline ll s1(ll n) {
  n %= mod;
  return n * (n + 1) % mod * inv2 % mod;
}
inline ll s2(ll n) {
  n %= mod;
  return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
}
inline ll s3(ll n) {
  n %= mod;
  return s1(n) * s1(n) % mod;
}

ll pri[N], cnt, phi[N];
bool mark[N];
void sieve() {
  phi[1] = 1;
  for (int i = 2; i < N; ++ i) {
    if (!mark[i]) pri[++ cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && pri[j] * i < N; ++ j) {
      mark[pri[j] * i] = 1;
      if (i % pri[j] == 0) {
        phi[pri[j] * i] = phi[i] * pri[j];
        break;
      }
      phi[pri[j] * i] = phi[i] * (pri[j] - 1);
    }
  }
  for (ll i = 1; i < N; ++ i) {
    phi[i] = (phi[i - 1] + phi[i] * i % mod * i % mod) % mod;
  }
}

map<ll, ll> mp;
ll du(ll n) {
  if (n < N) return phi[n];
  if (mp[n]) return mp[n];

  ll res = s3(n);
  for (ll i = 2, last; i <= n; i = last + 1) {
    last = n / (n / i);
    res = (res - (s2(last) - s2(i - 1) + mod) % mod * du(n / i) % mod + mod) % mod;
  }
  return mp[n] = res;
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  mod = read(); n = read();

  inv2 = fast_pow(2, mod - 2);
  inv6 = fast_pow(6, mod - 2);

  sieve();

  ll res = 0;
  for (ll i = 1, last; i <= n; i = last + 1) {
    last = n / (n / i);
    res = (res + (du(last) - du(i - 1) + mod) % mod * s3(n / i) % mod) % mod;
  }
  printf("%lld\n", res);

  return 0;
}