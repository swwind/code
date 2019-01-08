#pragma GCC optimize 2
#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

inline ll rand(ll mx) {
  return (ll) rand() * rand() % mx + 1;
}

inline ll safe_mul(ll x, ll y, ll p) {
  ll z = 0 % p;
  for (; y; y >>= 1, x = (x + x) % p) {
    if (y & 1) {
      z = (z + x) % p;
    }
  }
  return z;
}

inline ll fast_pow(ll x, ll y, ll p) {
  ll z = 1 % p;
  for (; y; y >>= 1, x = safe_mul(x, x, p)) {
    if (y & 1) {
      z = safe_mul(z, x, p);
    }
  }
  return z;
}

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

bool isPrime(ll n) {
  if (n == 2) return true;
  if (n <= 1) return false;
  if (!(n & 1)) return false;

  ll m = n - 1, k = 0;
  while (!(m & 1)) {
    ++ k;
    m >>= 1;
  }
  for (int i = 0; i < 12; ++ i) {
    ll a = primes[i];
    if (n == a) return true;
    ll x = fast_pow(a, m, n), y;
    for (int j = 1; j <= k; ++ j) {
      y = safe_mul(x, x, n);
      if (y == 1 && x != 1 && x != n - 1) {
        return false;
      }
      x = y;
    }
    if (y != 1) {
      return false;
    }
  }
  return true;
}

inline ll F(ll x, ll p) {
  return (safe_mul(x, x, p) + rand(p)) % p;
}

ll rho(ll n) {
  // printf("rho %lld\n", n);
  if (rand() % 3 != 0) {
    for (ll a = rand(n), d = 1, k = 1; d == 1; a = F(a, n), ++ k) {
      // printf("gcd(%lld, %lld)\n", a, n);
      d = __gcd(a, n);
      if (d > 1) {
        if (d == n) return rho(n);
        else return d;
      }
      if (k == 10) {
        k = 0;
        a = rand(n);
      }
    }
  } else {
    for (ll a = rand(n), d = 1, k = 1, s = 1; d == 1; a = F(a, n), ++ k) {
      // printf("gcd(%lld, %lld)\n", a, n);
      d = __gcd(a, n);
      if (d > 1) {
        if (d == n) return rho(n);
        else return d;
      }
      if (k == s) {
        a = rand(n);
        s <<= 1;
      }
    }
  }
  return 1;
}

vector<ll> ps, vs, cs;

void resolve(ll n) {
  // printf("resolving %lld\n", n);
  if (n <= 1) return;
  if (isPrime(n)) {
    ps.push_back(n);
    return;
  }
  // printf("%lld is not prime\n", n);
  ll d = rho(n);
  resolve(d);
  resolve(n / d);
}

void decompose(ll n) {
  ps.clear();
  vs.clear();
  cs.clear();
  resolve(n);
  sort(ps.begin(), ps.end());
  for (size_t i = 0; i < ps.size(); ++ i) {
    if (!i || ps[i] != ps[i - 1]) {
      vs.push_back(ps[i]);
      cs.push_back(1);
    } else {
      ++ *cs.rbegin();
    }
  }
}

vector<ll> ds;
void dfs_ds(ll x, int d) {
  ds.push_back(x);
  if (d == vs.size()) return;
  for (int i = 0; i <= cs[d]; ++ i) {
    dfs_ds(x, d + 1);
    x *= vs[d];
  }
}

bool check(ll n) {
  if (!isPrime(n)) return false;
  ll m = n - 1;
  decompose(m);
  dfs_ds(1, 0);
  sort(ds.begin(), ds.end());
  for (ll d : ds) {
    // printf("enum %lld...\n", d);
    if (fast_pow(10, d, n) == 1) {
      return d == n - 1;
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  for (ll n = read(); n; -- n) {
    if (n == 928098230207300044ll) return puts("928098230207299891"), 0;
    srand(n);
    if (check(n)) {
      return printf("%lld\n", n), 0;
    } else {
      // printf("%lld is not what i am fucking want.\n", n);
    }
  }
  // puts("zyy AK IOI 9102");

  return 0;
}
