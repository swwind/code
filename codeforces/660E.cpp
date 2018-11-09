#include <bits/stdc++.h>
#define N 1000020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) z = z * x % mod;
  return z;
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  ll ans = fast_pow(m, n);
  for (int i = 1; i <= n; i++) {
    ans += fast_pow(m, i) * fast_pow(2 * m - 1, n - i) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

/*
明显，长度为$i$的本质不同的子序列共有$N^i$个。

对于每个子序列，只考虑其在数列中第一次出现的位置。因此，答案为

$$
\sum_{i=0}^NN^i\sum_{j=i}^N\binom ji(M-1)^{j-i}M^{N-i}
$$

观察发现上式有二项式反演的雏形，但是$j$的循环范围从$i$开始，并不理想。不妨把$i$和$j$两重循环交换一下：

$$
\sum_{j=0}^NM^{N-j}\sum_{i=0}^j\binom jiN^i(M-1)^{j-i}
$$

二项式反演：

$$
\sum_{j=0}^NM^{N-j}(N+M-1)^j
$$

即可在O(N)时间内求解。
*/