#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll a[N], m[N], M = 1, _M[N], t[N];
void exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  ll t = x; x = y;
  y = t - a / b * y;
}
ll inv(ll x, ll p) {
  ll _x, _y;
  exgcd(x, p, _x, _y);
  return (_x % p + p) % p;
}
ll fast_mul(ll x, ll y, ll p) {
  ll z = 0;
  for (; y; y >>= 1, x = (x << 1) % p)
    if (y & 1) z = (z + x) % p;
  return z;
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  for (int i = 1; i <= n; ++ i) {
    m[i] = read();
    a[i] = (a[i] % m[i] + m[i]) % m[i];
    // printf("x = %d (mod %d)\n", a[i], m[i]);
    M *= m[i];
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    _M[i] = M / m[i];
    t[i] = inv(_M[i], m[i]);
    // ans = (ans + fast_mul(a[i], fast_mul(t[i], _M[i], M), M)) % M;
    ans = (ans + fast_mul(fast_mul(a[i], t[i], M), _M[i], M)) % M;
  }
  cout << (ans + M) % M << endl;
  return 0;
}