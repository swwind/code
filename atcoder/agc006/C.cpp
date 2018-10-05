#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll f[N][64], x[N], y[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    x[i] = read();
    y[i] = x[i] - x[i - 1];
    f[i][0] = i;
  }
  int m = read();
  ll k = read();
  for (int i = 1; i <= m; ++ i) {
    int a = read();
    swap(f[a][0], f[a + 1][0]);
  }

  for (int i = 1; i <= 63; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      f[j][i] = f[f[j][i - 1]][i - 1];
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    int p = i;
    for (int j = 63; ~j; -- j) {
      if (k >> j & 1) {
        p = f[p][j];
      }
    }
    printf("%lld.0\n", ans += y[p]);
  }

  return 0;
}
/*
首先可以推出

  f[x] = f[x-1] + f[x+1] - f[x]

我们差分一下来看

before

  f[x-1], f[x], f[x+1]
  ->  f[x]-f[x-1], f[x+1]-f[x]

after

  f[x-1], f[x-1] + f[x+1] - f[x], f[x+1]
  -> f[x+1]-f[x], f[x]-f[x-1]

发现变换就是差分之后交换两个相邻的数。。。

那么直接倍增就好了
*/