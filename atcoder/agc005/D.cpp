#include <bits/stdc++.h>
#define N 2020
#define mod 924844033
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
bool is_end[N];
int dp[N<<1][N][2], a[N];
ll frac[N];
int main(int argc, char const *argv[]) {
  // freopen("../../temp/.in", "r", stdin);
  int n = read(), k = read();
  int top = 1;
  for (int i = frac[0] = 1; i <= n; ++ i) {
    frac[i] = frac[i - 1] * i % mod;
  }
  for (int i = 1; i <= k; ++ i) {
    int len = (n - i) / k + 1;
    is_end[top] = 1; top += len;
    is_end[top] = 1; top += len;
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= 2 * n; ++ i) {
    for (int j = 0; j <= i / 2; ++ j) {
      dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
      if (!is_end[i]) {
        dp[i][j][1] = dp[i-1][j-1][0];
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++ i) {
    ll value = (dp[2*n][i][0] + dp[2*n][i][1]) % mod * frac[n-i] % mod;
    if (i & 1) value = (mod - value) % mod;
    ans = (ans + value) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
/*

计算 f[i] 表示有至少 i 个 ai 满足 |ai-i|=k，
答案即为\sigma_{i=0}^{n}{ f[i] * (n-i)! * (-1)^i }

想象出两列 1~n 的数列，将左边的 i 向右边的 i-k 和 i+k 连边。

大概像这样：

(1)    (6)
   \  /
(2) \/ (7)
   \/\/
(3)/\/\(8)
   \/\/
(4)/\/\(9)
    /\
(5)/  \(10)

每条边 (i, j) 的含义为：aj = i 不合法。

选择其中的一条边即为有一个不合法。

我们把这几条边拉直：

(1)----(8)----(5)

(6)----(3)----(10)

(2)----(9)

(4)----(7)

然后把他们用假边连起来：

(1)----(8)----(5)
  ____________/
 /
(6)----(3)----(10)
  ____________/
 /
(2)----(9)
  _____/
 /
(4)----(7)

然后就可以 dp 来求 f[i] 了！

记 dp[i][j][0/1] 为选到了第 i 个点，已经选了 j 条边，最后一个点是否选了的方案数。

  dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
  dp[i][j][1] = dp[i-1][j-1][0] (if i-1 to i is not fake)

  f[i] = dp[2*n][i][0] + dp[2*n][i][1]

复杂度：O(n^2)
*/
