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
ll f[N], x[N];
int main(int argc, char const *argv[]) {

  int n = read();
  ll E = read(), T = read();

  for (int i = 1; i <= n; ++ i) {
    x[i] = read();
  }

  memset(f, 0x3f, sizeof f);
  f[0] = 0;

  ll mn = 1ll << 60;
  for (int i = 1, j = 0; i <= n; ++ i) {
    while (T <= 2 * (x[i] - x[j + 1])) {
      mn = min(mn, f[j] - 2 * x[j + 1]);
      ++ j;
    }
    f[i] = min(f[j] + T, mn + 2 * x[i]);
  }

  printf("%lld\n", f[n] + E);

  return 0;
}
/*

只有两种情况。

          | wait T )
----------+------------>
0         A            B            E


-----------------------.
          .------------`
          `--------------->
0         A            B            E

dp 计算需要多走多少时间即可。

*/