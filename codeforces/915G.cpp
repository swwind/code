#include <bits/stdc++.h>
#define N 2000020
#define mod 1000000007
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
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}

ll pri[N], mark[N], cnt, mu[N];
ll filter_mu(const ll max_size) {
  mu[1] = 1;
  for (int i = 2; i <= max_size; ++ i) {
    if (!mark[i]) pri[++ cnt] = i, mu[i] = -1;
    for (int j = 1; j <= cnt && pri[j] * i <= max_size; ++ j) {
      mark[pri[j] * i] = 1;
      if (i % pri[j] == 0) {
        break;
      } else {
        mu[pri[j] * i] = - mu[i];
      }
    }
  }
}

ll pw[N], b[N];

int main(int argc, char const *argv[]) {

  int n = read(), k = read();

  for (int i = 1; i <= k; ++ i) {
    pw[i] = fast_pow(i, n);
  }
  filter_mu(k);

  for (int d = 1; d <= k; ++ d) {
    for (int x = 1; x * d <= k; ++ x) {
      b[x * d] = (b[x * d] + (mod + mu[d]) * (pw[x] - pw[x - 1] + mod) % mod) % mod;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= k; ++ i) {
    b[i] = (b[i] + b[i - 1]) % mod;
    ans = (ans + (b[i] ^ i)) % mod;
  }

  printf("%lld\n", ans);

  return 0;
}