#include <bits/stdc++.h>
#define N 5000020
#define mod 1000000007
#define ll long long
using namespace std;

const ll inv2 = 500000004ll;

ll pri[N], phi[N], cnt;
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
    phi[i] = (phi[i] + phi[i - 1]) % mod;
  }
}

inline ll s(ll n) {
  return n * (n + 1) % mod * inv2 % mod;
}

unordered_map<ll, ll> save;
ll sumphi(ll n) {
  if (n < N) return phi[n];
  if (save[n]) return save[n];
  ll sum = s(n % mod);
  for (ll i = 2, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum = ((sum - (last - i + 1) * sumphi(n / i) % mod) % mod + mod) % mod;
  }
  return save[n] = (sum + mod) % mod;
}

ll solve(ll n) {
  ll sum = 0;
  for (ll i = 1, last; i <= n; i = last + 1) {
    last = n / (n / i);
    ll l = (n / i) % mod;
    ll fuck = (sumphi(last) - sumphi(i - 1) + mod) % mod;
    sum = (sum + l * l % mod * fuck % mod) % mod;
  }
  return (sum + mod) % mod;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  // freopen("../tmp/.out", "w", stdout);

  sieve();

  ll n;
  cin >> n;
  cout << solve(n) << endl;

  return 0;
}
