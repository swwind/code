#include <bits/stdc++.h>
#define N 5000020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

const ll inv2 = 500000004ll;
const ll inv6 = 166666668ll;

ll pri[N], cnt, phi[N];
bool mark[N];

inline void sieve() {
  phi[1] = 1;
  for (int i = 2; i < N; ++ i) {
    if (!mark[i]) pri[++ cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * pri[j] < N; ++ j) {
      mark[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
    }
  }
  for (int i = 1; i < N; ++ i) {
    phi[i] = ((ll) phi[i] * i % mod + phi[i - 1]) % mod;
  }
}

inline ll s(ll n) {
  return n * (n + 1) % mod * inv2 % mod;
}
inline ll s(ll l, ll r) {
  return (s(r) - s(l - 1) + mod) % mod;
}
inline ll s2(ll n) {
  return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
}

map<ll, ll> save;

ll sumphi(ll n) {
  if (n < N) return phi[n];
  if (save[n]) return save[n];
  ll sum = s2(n);
  for (int i = 2, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum = (sum - s(i, last) * sumphi(n / i) % mod + mod) % mod;
  }
  return save[n] = sum;
}

ll query(ll n) {
  ll sum = 0;
  for (int i = 1, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum = (sum + (last - i + 1) * sumphi(n / i) % mod) % mod;
  }
  return (sum + n) * inv2 % mod;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  sieve();
  int a = read(), b = read();
  ll ans = (query(b) - query(a - 1) + mod) % mod;
  printf("%lld\n", ans);

  return 0;
}
