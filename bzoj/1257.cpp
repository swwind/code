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

ll sum(ll l, ll r) {
  return (l + r) * (r - l + 1) / 2;
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  ll n = read(), k = read();
  // ll ans = n * k;
  ll ans = 0;
  // printf("%lld\n", ans);
  for (int i = 1, last; i <= n; i = last + 1) {
    if (k / i == 0) last = n;
    else last = min(k / (k / i), n);
    ans += k * (last - i + 1) - (k / i) * sum(i, last);
    // printf("%d %d %lld %lld\n", i, last, n / i, sum(i, last));
  }
  printf("%lld\n", ans);

  return 0;
}