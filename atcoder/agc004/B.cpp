#include <bits/stdc++.h>
#define N 2020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll a[N], b[N], x;
int main(int argc, char const *argv[]) {
  int n = read();
  x = read();
  for (int i = 0; i < n; ++ i) {
    b[i] = a[i] = read();
  }
  ll res = 1ll << 60;
  for (int len = 0; len < n; ++ len) {
    // 枚举左移位数
    for (int i = 0; i < n; ++ i) {
      b[i] = min(b[i], a[(i - len + n) % n]);
    }
    ll ans = len * x;
    for (int i = 0; i < n; ++ i) {
      ans += b[i];
    }
    res = min(res, ans);
  }
  printf("%lld\n", res);
  return 0;
}
