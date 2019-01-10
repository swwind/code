#include <bits/stdc++.h>
#define N 100020
#define mod 1000000007
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

ll fast_pow(ll x, ll y) {
  y %= (mod - 1);
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  ll w = read(), n = read(), k = read();
  printf("%lld\n", w * fast_pow(500000004, k) % mod);

  return 0;
}