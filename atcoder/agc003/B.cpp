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
ll a[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += a[i] >> 1;
    if ((a[i] & 1) && a[i + 1]) {
      -- a[i + 1];
      ++ ans;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
