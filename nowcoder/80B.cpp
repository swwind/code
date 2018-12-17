#include <bits/stdc++.h>
#define N 100020
#define mod 998244353
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) z = z * x % mod;
  return z;
}
ll inv(ll x) {
  return fast_pow(x, mod - 2);
}
int main(int argc, char const *argv[]) {
  ll n = read(), m = read();
  cout << ((n * n - m) * inv(n * n)) % mod << endl;
  return 0;
}