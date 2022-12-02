#include <cstdio>
#include <map>

typedef long long ll;
const int N = 2e6, maxn = N + 5, maxm = 35;
const ll P = 1e9 + 7;

ll n, k, cnt, ans;
ll pri[maxn];
bool isp[maxn];
ll phi[maxn], s1[maxn], s2[maxn];
ll h[maxn][maxm];
bool vis[maxn][maxm];
std::map < ll, ll > memS1, memS2;
int fast_pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (long long)res * x % P;
    x = (long long)x * x % P;
    y >>= 1;
  }
  return res;
}

int fact[60];
int fact_inv[60];

inline void Init() {

  for (int i = fact[0] = 1; i < 60; ++i) {
    fact[i] = (long long)fact[i - 1] * i % P;
  }

  fact_inv[59] = fast_pow(fact[59], P - 2);
  for (int i = 59; i; --i) {
    fact_inv[i - 1] = (long long)fact_inv[i] * i % P;
  }

  phi[1] = 1;

  for (ll i = 2; i <= N; i++) {
    if (!isp[i])
      pri[++cnt] = i, phi[i] = i - 1;

    for (ll t, j = 1; j <= cnt && (t = i * pri[j]) <= N; j++) {
      isp[t] = true;

      if (!(i % pri[j])) {
        phi[t] = phi[i] * pri[j];
        break;
      }

      phi[t] = phi[i] * phi[pri[j]];
    }
  }

  for (ll i = 1; i <= N; i++)
    s1[i] = (s1[i - 1] + phi[i]) % P;

  for (ll i = 1; i <= (N >> 1); i++)
    s2[i] = (s2[i - 1] + phi[i << 1]) % P;

  for (ll i = 1; i <= cnt; i++)
    h[i][0] = 1, vis[i][0] = true;
}

ll S1(ll n) {
  if (n <= N)
    return s1[n];

  if (memS1.count(n))
    return memS1[n];

  ll res = n % P * (n % P + 1) / 2 % P;

  for (ll r, l = 2; l <= n; l = r + 1) {
    r = n / (n / l);
    res = (res - (r - l + 1) % P * S1(n / l) % P + P) % P;
  }

  return memS1[n] = res;
}

ll S2(ll n) {
  if (n <= (N >> 1))
    return s2[n];

  if (memS2.count(n))
    return memS2[n];

  return memS2[n] = (S1(n) + S2(n / 2)) % P;
}

inline ll G(ll n) {
  return n;
  return (S1(n) + 2 * S2(n / 2)) % P;
}


ll memF[50];
ll calc(ll e) {
  if (memF[e]) return memF[e];
  ll res = 1;
  for (int i = k; i <= k + e - 1; ++i) {
    res = res * i % P;
  }
  res = res * fact_inv[e] % P;
  return memF[e] = res;
}

void dfs(ll nd, ll hd, ll id) {
  if (!nd || !hd)
    return;

  ans = (ans + hd * G(nd) % P) % P;

  for (ll i = id, p = pri[i]; i <= cnt && p * p <= nd; p = pri[++i])
    for (ll e = 2, pe = p * p; pe <= nd; pe *= p, e++) {
      if (!vis[i][e]) {
        ll f = calc(e), g = 1;

        for (ll j = 1; j <= e; j++)
          f = (f - g * h[i][e - j] % P + P) % P, g = g * p % P;

        h[i][e] = f, vis[i][e] = true;
      }

      if (h[i][e])
        dfs(nd / pe, hd * h[i][e] % P, i + 1);
    }
}

inline ll solve() {
  ans = 0;
  dfs(n, 1, 1);
  return ans;
}

int main() {
  scanf("%lld%lld", &n, &k);
  Init();
  printf("%lld\n", solve());
  return 0;
}