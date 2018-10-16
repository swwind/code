#include <bits/stdc++.h>
#define N 1020
#define K 50
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int c[N+K][K];
int f[N][K];
int ans[N][K];
int main(int argc, char const *argv[]) {
  freopen("../temp/input.in", "r", stdin);
  freopen("../temp/output.out", "w", stdout);
  for (int i = 0; i < N+K; ++ i) {
    c[i][0] = 1;
    for (int j = 1; j < min(i + 1, K); ++ j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  f[0][0] = 1;
  for (int i = 1; i < N; ++ i) {
    for (int j = N - i - 1; ~j; -- j) {
      for (int k = K - 1; k; -- k) {
        f[j + i][k] = (f[j + i][k] + (ll) k * f[j][k - 1] % mod) % mod;
      }
    }
  }
  for (int i = 1; i < N; ++ i) {
    for (int k = 1; k < K; ++ k) {
      for (int j = 1; j <= i; ++ j) {
        if (i == 8) printf("ans[%d][%d] += f[%d][%d] * C(%d %d)\n", i, k, j, k, i-j+k, k);
        ans[i][k] = (ans[i][k] + (ll) f[j][k] * c[i-j+k][k] % mod) % mod;
      }
    }
  }
  int T = read();
  while (T --) {
    int n = read(), k = read();
    printf("%d\n", k < K ? ans[n][k] : 0);
  }
  return 0;
}