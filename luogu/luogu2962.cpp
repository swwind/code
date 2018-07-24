#include <bits/stdc++.h>
#define N 40
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll hack[N];
map<ll, int> ass, ssr;
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 0; i < n; ++ i) {
    hack[i] |= (1ll << i);
  }
  for (int i = 0; i < m; ++ i) {
    int x = read() - 1, y = read() - 1;
    hack[x] |= (1ll << y);
    hack[y] |= (1ll << x);
  }
  int n1 = (n >> 1), n2 = n - n1;
  for (int i = 0; i < (1 << n1); ++ i) {
    ll fuck = 0;
    int cnt = 0;
    for (int j = 0; j < n1; ++ j) {
      if (i >> j & 1) {
        fuck ^= hack[j];
        ++ cnt;
      }
    }
    if (!ass.count(fuck)) {
      ass[fuck] = cnt;
    } else {
      ass[fuck] = min(ass[fuck], cnt);
    }
  }
  ass[0] = 0;
  for (int i = 0; i < (1 << n2); ++ i) {
    ll fuck = 0;
    int cnt = 0;
    for (int j = 0; j < n2; ++ j) {
      if (i >> j & 1) {
        fuck ^= hack[j + n1];
        ++ cnt;
      }
    }
    if (!ssr.count(fuck)) {
      ssr[fuck] = cnt;
    } else {
      ssr[fuck] = min(ssr[fuck], cnt);
    }
  }
  ssr[0] = 0;
  int ans = 1 << 30;
  for (const auto &timber : ass) {
    // printf("%lld\n", timber.first);
    ll zhzh = ((1ll << n) - 1) ^ timber.first;
    if (ssr.count(zhzh)) {
      ans = min(ans, timber.second + ssr[zhzh]);
    }
  }
  cout << ans << endl;
  return 0;
}