#include <bits/stdc++.h>
#define N 100020
#define mod 19940417
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
inline ll sum(ll l, ll r) {
  return (l + r) * (r - l + 1) % mod * 9970209 % mod;
}
inline ll _sum_2(ll n) {
  return n * (n + 1) % mod * (2 * n + 1) % mod * 3323403 % mod;
}
inline ll sum_2(ll l, ll r) {
  return (_sum_2(r) - _sum_2(l - 1) + mod) % mod;
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  ll n = read(), m = read();
  if (n > m) swap(n, m);
  ll n2 = (ll) n * n % mod;
  ll m2 = (ll) m * m % mod;
  ll sum1 = 0, sum2 = 0;
  for (int i = 1, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum1 = (sum1 + sum(i, last) * (n / i) % mod) % mod;
  }
  for (int i = 1, last; i <= m; i = last + 1) {
    last = m / (m / i);
    sum2 = (sum2 + sum(i, last) * (m / i) % mod) % mod;
  }
  ll ans = n2 * m2 % mod;
  ll res = (n2 * sum2 % mod + m2 * sum1 % mod) % mod;
  ans = (ans - res + mod) % mod;
  ans = (ans + sum1 * sum2 % mod) % mod;

  ans = (ans - n2 * m % mod) % mod;
  ans = (ans + m * sum1 % mod) % mod;
  for (int i = 1, last; i <= n; i = last + 1) {
    last = min(m / (m / i), n);
    ans = (ans + n * (m / i) % mod * sum(i, last) % mod) % mod;
  }
  for (int i = 1, last; i <= n; i = last + 1) {
    last = min(n / (n / i), m / (m / i));
    ans = (ans - sum_2(i, last) * (n / i) % mod * (m / i) % mod + mod) % mod;
  }

  printf("%lld\n", ans);

  return 0;
}
/*

$$
\begin{aligned}
&\sum_{i=1}^{n}\sum_{j=1}^{m}(n-i\left\lfloor\frac{n}{i}\right\rfloor)(m-j\left\lfloor\frac{m}{j}\right\rfloor) \\
=&n^2m^2-\sum_{i=1}^{n}\sum_{j=1}^{m}mi\left\lfloor\frac{n}{i}\right\rfloor-\sum_{i=1}^{n}\sum_{j=1}^{m}nj\left\lfloor\frac{m}{j}\right\rfloor+\sum_{i=1}^{n}\sum_{j=1}^{m}ij\left\lfloor\frac{n}{i}\right\rfloor\left\lfloor\frac{m}{j}\right\rfloor \\
=&n^2m^2-m^2\sum_{i=1}^{n}i\left\lfloor\frac{n}{i}\right\rfloor-n^2\sum_{j=1}^{m}j\left\lfloor\frac{m}{j}\right\rfloor+\sum_{i=1}^{n}i\left\lfloor\frac{n}{i}\right\rfloor\sum_{j=1}^{m}j\left\lfloor\frac{m}{j}\right\rfloor
\end{aligned}
$$

$$
\begin{aligned}
&\sum_{i=1}^{n}(n \mod i)(m \mod i) \\
=&\sum_{i=1}^{n}(n-i\left\lfloor\frac{n}{i}\right\rfloor)(m-i\left\lfloor\frac{m}{i}\right\rfloor) \\
=&n^2m-m\sum_{i=1}^{n}i\left\lfloor\frac{n}{i}\right\rfloor-n\sum_{i=1}^{n}i\left\lfloor\frac{m}{i}\right\rfloor+\sum_{i=1}^{n}i^2\left\lfloor\frac{n}{i}\right\rfloor\left\lfloor\frac{m}{i}\right\rfloor \\
\end{aligned}
$$

*/