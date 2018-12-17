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

ll a[N], s[N], g[N];

ll calc(int n, int k) {
  for (int i = 1; i <= n; ++ i) {
    s[i] = s[i - 1] + a[i];
    g[i] = g[i - 1] + (a[i] > 0 ? a[i] : 0);
  }

  ll ans = 0;
  for (int i = k; i <= n; ++ i) {
    ll rm = g[n] - g[i] + g[i - k];
    ll rf = s[i] - s[i - k];
    ans = max(ans, rm + (rf > 0 ? rf : 0));
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  int n = read(), k = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }

  ll ans = calc(n, k);

  printf("%lld\n", ans);

  return 0;
}