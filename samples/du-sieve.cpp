// 杜教筛
// luogu P4213

#include <bits/stdc++.h>
#define N 5000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

ll pri[N], cnt, phi[N], mu[N];
bool mark[N];

inline void sieve() {
  phi[1] = 1;
  mu[1] = 1;
  for (int i = 2; i < N; ++ i) {
    if (!mark[i]) pri[++ cnt] = i, phi[i] = i - 1, mu[i] = - 1;
    for (int j = 1; j <= cnt && i * pri[j] < N; ++ j) {
      mark[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        mu[i * pri[j]] = 0;
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
      mu[i * pri[j]] = - mu[i];
    }
  }
  for (int i = 1; i < N; ++ i) {
    phi[i] += phi[i - 1];
    mu[i] += mu[i - 1];
  }
}

inline ll s(ll n) {
  return n * (n + 1) / 2;
}
inline ll s(ll l, ll r) {
  return s(r) - s(l - 1);
}
inline ll s2(ll n) {
  return n * (n + 1) * (2 * n + 1) / 6;
}

namespace solve1 {

unordered_map<ll, ll> save;
ll solve(ll n) {
  if (n < N) return phi[n];
  if (save[n]) return save[n];
  ll sum = s(n);
  for (int i = 2, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum -= (last - i + 1) * solve(n / i);
  }
  return save[n] = sum;
}

}

namespace solve2 {

unordered_map<ll, ll> save;
ll solve(ll n) {
  if (n < N) return mu[n];
  if (save[n]) return save[n];
  ll sum = 1;
  for (int i = 2, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum -= (last - i + 1) * solve(n / i);
  }
  return save[n] = sum;
}

}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  sieve();

  int T = read();
  while (T --) {
    int n = read();
    printf("%lld %lld\n"
      , solve1::solve(n)
      , solve2::solve(n));
  }

  return 0;
}

/*

比如说要求 $S(n) = \sum_{i=1}^{n}f(i)$
我们构造 $h = f \times g$ (狄利克雷卷积，其中 $g$ 和 $h$ 的前缀和都很好求)
那么有
$$
S(n) = \sum_{i=1}^{n}h(i) - \sum_{i=2}^{n}g(i)S(\left\lfloor\frac{n}{i}\right\rfloor)
$$

分块 + 预处理

e.g.

> 求
> 
> $$
> S(n) = \sum_{i=1}^{n}\varphi(i)
> $$
> 
> 我们发现 $id = \varphi \times l$
> 
> 那么
> 
> $$
> S(n) = \frac{n(n+1)}{2} - \sum_{i=2}^{n}S(\left\lfloor\frac{n}{i}\right\rfloor)
> $$


> 求
> 
> $$
> S(n) = \sum_{i=1}^{n}\mu(i)
> $$
> 
> 我们发现 $\varepsilon = \mu \times l$
> 
> 那么
> 
> $$
> S(n) = 1 - \sum_{i=2}^{n}S(\left\lfloor\frac{n}{i}\right\rfloor)
> $$

*/