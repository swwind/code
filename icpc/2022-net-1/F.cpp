#include <cstdio>
#include <map>

typedef long long ll;
const int N = 2e6, maxn = N + 5, maxm = 35;
const ll mod = 1e9 + 7;

ll cnt, ans;
ll pri[maxn];
bool isp[maxn];
ll phi[maxn], s1[maxn], s2[maxn];
ll h[maxn][maxm];
bool vis[maxn][maxm];
std::map<ll, ll> memS1, memS2;

int fast_pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (long long)res * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return res;
}

int fact[60];
int fact_inv[60];

inline void Init() {

  for (int i = fact[0] = 1; i < 60; ++i) {
    fact[i] = (long long)fact[i - 1] * i % mod;
  }

  fact_inv[59] = fast_pow(fact[59], mod - 2);
  for (int i = 59; i; --i) {
    fact_inv[i - 1] = (long long)fact_inv[i] * i % mod;
  }

  for (int i = 2; i <= N; i++) {
    if (!isp[i]) {
      pri[++cnt] = i;
    }

    for (int j = 1; j <= cnt && (long long)i * pri[j] <= N; j++) {
      isp[i * pri[j]] = true;
    }
  }

  for (int i = 1; i <= cnt; i++)
    h[i][0] = 1, vis[i][0] = true;


}

int memF[50];
int k, n;

int ff(int p, int e) {
  if (memF[e]) return memF[e];
  int res = 1;
  for (int i = k; i <= k + e - 1; ++i) {
    res = (long long)res * i % mod;
  }
  res = (long long)res * fact_inv[e] % mod;
  return memF[e] = res;
}

int gg(int p, int e) {
  return 1;
}

inline int G(int n) {
  return n;
}

void dfs(ll nd, ll hd, ll id) {
  if (!nd || !hd)
    return;

  ans = (ans + hd * G(nd) % mod) % mod;

  for (ll i = id, p = pri[i]; i <= cnt && p * p <= nd; p = pri[++i])
    for (ll e = 2, pe = p * p; pe <= nd; pe *= p, e++) {
      if (!vis[i][e]) {
        ll f = ff(p, e), g = gg(p, e);

        for (ll j = 1; j <= e; j++)
          f = (f - g * h[i][e - j] % mod + mod) % mod, g = g * p % mod;

        h[i][e] = f, vis[i][e] = true;
      }

      if (h[i][e])
        dfs(nd / pe, hd * h[i][e] % mod, i + 1);
    }
}

inline ll solve() {
  ans = 0;
  dfs(n, 1, 1);
  return ans;
}

int main() {
  scanf("%d%d", &n, &k);
  Init();
  printf("%d\n", ff(n, k));
  printf("%d\n", gg(n, k));
  printf("%d\n", solve());
  return 0;
}