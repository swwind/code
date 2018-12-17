#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

const int N = 300005;
const ll mod = 998244353;

ll a[N], b[N];

ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}

int n, len, rev[N];

void init(int m) {
  for (n = 1; n <= m; n <<= 1, ++ len);
  for (int i = 0; i < n; ++ i)
    rev[i] = rev[i >> 1] >> 1 | ((i & 1) << len - 1);
}

void NTT(ll *a, bool type) {
  for (int i = 0; i < n; ++ i) {
    if (i > rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    ll wn = fast_pow(3, (mod - 1) / (i << 1));
    int m = i << 1;
    for (int j = 0; j < n; j += m) {
      ll w = 1;
      for (int k = 0; k < i; ++ k, w = w * wn % mod) {
        ll tmp = (a[j+i+k] * w) % mod;
        a[i+j+k] = (a[j+k] - tmp + mod) % mod;
        a[j+k] = (a[j+k] + tmp) % mod;
      }
    }
  }
  if (!type) {
    reverse(a + 1, a + n);
  }
}

char str1[N], str2[N];

int main(int argc, char const *argv[]) {
  // freopen("../temp/.in", "r", stdin);

  /*
  scanf("%s", str1);
  scanf("%s", str2);
  int n = strlen(str1), m = strlen(str2);
  init(n + m);
  for (int i = 0; i < n; ++ i) {
    a[i] = str1[i] - '0';
  }
  for (int i = 0; i < m; ++ i) {
    b[i] = str2[i] - '0';
  }
  */

  int n = read(), m = read();
  init(n + m);
  for (int i = 0; i <= n; ++ i) {
    a[i] = read();
  }
  for (int i = 0; i <= m; ++ i) {
    b[i] = read();
  }

  NTT(a, 1);
  NTT(b, 1);

  for (int i = 0; i < ::n; ++ i) {
    a[i] = a[i] * b[i] % mod;
  }

  NTT(a, 0);

  ll t = fast_pow(::n, mod - 2);
  for (int i = 0; i < ::n; ++ i) {
    a[i] = a[i] * t % mod;
  }

  for (int i = 0; i <= m + n; ++ i) {
    printf("%lld ", a[i]);
  }

  return 0;
}
