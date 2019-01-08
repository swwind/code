#include <bits/stdc++.h>
#define N 10000020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

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

struct $v$ {
  int p, v;
  friend bool operator < (const $v$ &a, const $v$ &b) {
    return a.p == b.p ? a.v < b.v : a.p < b.p;
  }
} ps[N];
int cnt;
void decompose(int x) {
  for (int i = 2; i * i <= x; ++ i) {
    if (x % i == 0) {
      ps[++ cnt].p = i;
      while (x % i == 0) {
        ++ ps[cnt].v;
        x /= i;
      }
    }
  }
  if (x > 1) {
    ps[++ cnt].p = x;
    ps[cnt].v = 1;
  }
}

ll pw[N];
ll resolve(int l, int r) {
  int p = ps[l].p, n = ps[r].v;
  for (int i = pw[0] = 1; i <= n; ++ i) {
    pw[i] = pw[i - 1] * p % mod;
  }
  for (int i = pw[0] = 1; i <= n; ++ i) {
    pw[i] = (pw[i] + pw[i - 1]) % mod;
  }
  ll res = 1;
  for (int i = l; i <= r; ++ i) {
    res = res * pw[ps[i].v] % mod;
  }
  res = (res - 1 + mod) % mod;
  res = res * (p - 1) % mod;
  res = res * inv(p) % mod;
  return (res + 1) % mod;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read();
  for (int i = 1; i <= n; ++ i) {
    decompose(read());
  }

  sort(ps + 1, ps + cnt + 1);

  ll ans = 1;

  for (int i = 1, j = 1; i <= cnt; i = j + 1) {
    while (j < cnt && ps[j + 1].p == ps[i].p) {
      ++ j;
    }
    // TODO
    ans = ans * resolve(i, j) % mod;
  }

  printf("%lld\n", ans);

  return 0;
}