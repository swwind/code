#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mod 1000000007llu
#define ull unsigned long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

ull SA, SB, SC;
inline ull _rand() {
  SA ^= SA << 32;
  SA ^= SA >> 13;
  SA ^= SA << 1;
  ull t = SA;
  SA = SB;
  SB = SC;
  SC ^= t ^ SA;
  return SC;
}

int T;
ull pw1[65536], pw2[65536];
ull pm1[65536], pm2[65536];
ull ans;

inline ull fast_pow(ull y) {
  y %= (mod - 1);
  ull p1 = pm1[y >> 16] * pw1[y & 65535] % mod;
  ull p2 = pm2[y >> 16] * pw2[y & 65535] % mod;
  return (p1 - p2 + mod) % mod;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  cin >> T >> SA >> SB >> SC;
  pw1[0] = pm1[0] = pw2[0] = pm2[0] = 1;
  for (int i = 1; i < 65536; ++ i) {
    pw1[i] = pw1[i - 1] *  94153035llu % mod;
    pm1[i] = pm1[i - 1] *  64353223llu % mod;
    pw2[i] = pw2[i - 1] * 905847205llu % mod;
    pm2[i] = pm2[i - 1] * 847809841llu % mod;
  }
  while (T --) {
    ans ^= fast_pow(_rand()) * 233230706llu % mod;
  }
  printf("%llu\n", ans);

  return 0;
}