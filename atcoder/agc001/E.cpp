#include <bits/stdc++.h>
#define N 200020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N], b[N];
template <typename T, int L, int R>
struct Array {
  T a[R - L + 1];
  T& operator [] (int x) {
    return a[x - L];
  }
  T* operator + (int x) {
    return a + (x - L);
  }
};
Array<Array<int, -2020, 2020>, -2020, 2020> dp;
ll frac[8020];
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}
ll inv(ll x) {
  return fast_pow(x, mod - 2);
}
ll C(ll n, ll m) {
  return frac[n] * inv(frac[m]) % mod * inv(frac[n - m]) % mod;
}
int main(int argc, char const *argv[]) {
  frac[0] = 1;
  for (int i = 1; i <= 8000; ++ i) {
    frac[i] = frac[i - 1] * i % mod;
  }

  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    b[i] = read();
    dp[-a[i]][-b[i]] += 1;
  }
  for (int i = -2000; i <= 2000; ++ i) {
    for (int j = -2000; j <= 2000; ++ j) {
      dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i - 1][j]) % mod;
    }
  }
  int ans = 0, res = 0;
  for (int i = 1; i <= n; ++ i) {
    ans = (ans + dp[a[i]][b[i]]) % mod;
    res = (res + C(a[i]+b[i]+a[i]+b[i], a[i]+a[i])) % mod;
  }
  ans = ((ans - res) % mod + mod) % mod;
  ans = ans * 500000004ll % mod;
  printf("%d\n", ans);
  return 0;
}
/*
求
\sigma{(i,j)∈S} C(Ai+Aj+Bi+Bj, Ai+Aj)

回想组合数的暴力求法，c[i][j]=c[i-1][j]+c[i][j-1]
对于每个点，将c[-a[i]][-b[i]]=1，dp之后的c[a[j]][b[j]]即为(i,j)的贡献
这个dp可以一起算。
接着将答案减去(i,i)的贡献并除以2即为所求。

注意想清楚数组大小
*/