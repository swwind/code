#include <bits/stdc++.h>
#define N 100020
#define mod 1000000007
#define ll long long
using namespace std;
inline long long read(){
  long long x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

long long s[N], f[N], g[N];

int main(int argc, char const *argv[]) {
  long long n = read(), a = read(), b = read();
  for (int i = 1; i <= n; ++ i) {
    s[i] = read();
  }
  if (a > b) swap(a, b);
  for (int i = 3; i <= n; ++ i) {
    if (s[i] - s[i-2] < a){
      puts("0");
      return 0;
    }
  }
  s[0]     = - 2e18;
  s[n + 1] =   2e18;
  f[0] = g[0] = 1;
  int l = 0, r = 0;
  for (int i = 1; i <= n + 1; ++ i) {
    while (r < i - 1 && s[i] - s[r + 1] >= b)
      ++ r;
    if (l <= r) {
      f[i] = (g[r] + mod - (l ? g[l - 1] : 0)) % mod;
    }
    g[i] = (g[i - 1] + f[i]) % mod;
    if (i > 1 && s[i] - s[i - 1] < a) {
      l = i - 1;
    }
  }
  printf("%d\n", f[n + 1]);
}
