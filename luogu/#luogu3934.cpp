#include <bits/stdc++.h>
#define N 500020
#define P 20000020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll fast_pow(ll x, ll y, ll p) {
  ll z = 1 % p;
  for (; y; y >>= 1, x = x * x % p)
    if (y & 1) z = z * x % p;
  return z;
}
int pri[P], phi[P], cnt;
bool mark[P];
void shai(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++ i) {
    if (!mark[i]) pri[++ cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && pri[j] * i <= n; ++ j) {
      mark[pri[j] * i] = true;
      if (i % pri[j] == 0) {
        phi[pri[j] * i] = phi[i] * pri[j];
        break;
      } else {
        phi[pri[j] * i] = phi[i] * (pri[j] - 1);
      }
    }
  }
}
ll c[N];
void update(int x, ll v) {
  for (; x < N; x += x & -x)
    c[x] += v;
}
ll query(int x) {
  ll ans = 0;
  for (; x; x ^= x & -x)
    ans += c[x];
  return ans;
}
ll a[N];
ll solve(int l, int r, ll p) {
  // printf("> %lld %lld %lld\n", l, r, p);
  if (p == 1) return 0;
  ll k = 0, d = query(l) % p, _p = p, x = 1;
  // printf("[ %lld\n", d);
  if (l == r || d <= 1) {
    return d % p;
  }
  while (_p % d == 0)
    _p /= d, ++ k, x *= d;
  ll phi = ::phi[p];
  ll nxt = solve(l + 1, r, phi);
  nxt = ((nxt - k) % phi + phi) % phi;
  return x % p * fast_pow(d, nxt, _p) % p;
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    update(i, a[i] - a[i - 1]);
  }
  shai(2e7);
  for (int i = 1; i <= m; ++ i) {
    int t = read(), l = read(), r = read();
    ll x = read();
    if (t == 1) {
      update(l, x);
      update(r + 1, -x);
    } else {
      printf("%lld\n", solve(l, r, x));
    }
  }
  return 0;
}