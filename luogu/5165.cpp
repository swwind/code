#include <bits/stdc++.h>
#define N 100020
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
ll prb, qrb, rrb;
ll n, m, p, q;
inline ll calc(ll x) {
  return ((1 - fast_pow(qrb, x)) % mod + mod) % mod * inv(((1 - qrb) % mod + mod) % mod) % mod;
}
int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);
  
  n = read(), m = read();
  p = read(), q = read();
  prb = p * inv(q) % mod;
  qrb = ((1 - prb) % mod + mod) % mod * inv(prb) % mod;
  rrb = (mod - 1) * inv(((1 - 2 * prb % mod) % mod + mod) % mod) % mod;
  if (q == 2 && p == 1) {
    printf("%lld\n", ((2 * n % mod - m) % mod + mod) % mod * m % mod);
  } else {
    ll ans = ((1 - rrb) % mod + mod) % mod;
    ans = ans * (((calc(n) - calc(n - m)) % mod + mod) % mod) % mod;
    ans = (ans + m * rrb % mod) % mod; 
    printf("%lld\n", ans);
  }
  return 0;
}
