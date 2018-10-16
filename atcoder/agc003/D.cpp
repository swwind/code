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
map<ll, int> cnt, vis;
ll a[N], cub[N];
const ll MAX_CUB = 2154;
bool mark[MAX_CUB + 20];
int prime[MAX_CUB + 20], tot;
void filter_prime(int size) {
  for (int i = 2; i <= size; ++ i) {
    if (!mark[i]) prime[++ tot] = i;
    for (int j = 1; j <= size && prime[j] * i <= size; ++ j) {
      mark[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
bool isSquare(ll x) {
  ll k = sqrt(x);
  return k * k == x;
}
ll calc(ll x) {
  ll rev = 1;
  for (int i = 1; i <= tot; ++ i) {
    int c = 0;
    while (x % prime[i] == 0) {
      x /= prime[i];
      ++ c;
    }
    if (c) {
      for (; c < 3; ++ c) {
        rev *= prime[i];
      }
    }
  }
  // 此时 x 要么是质数，要么是平方数
  if (isSquare(x)) {
    rev *= sqrt(x);
  } else {
    rev *= x * x;
  }
  return rev;
}
int main(int argc, char const *argv[]) {
  // freopen("../../temp/test.in", "r", stdin);
  filter_prime(MAX_CUB);
  int n = read();
  for (int i = 2; i <= MAX_CUB; ++ i) {
    cub[i] = (ll) i * i * i;
  }
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    for (int j = 2; j <= MAX_CUB; ++ j) {
      while (a[i] % cub[j] == 0) {
        a[i] /= cub[j];
      }
    }
    ++ cnt[a[i]];
  }
  cnt[1] = min(cnt[1], 1);
  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    if (vis[a[i]]) {
      continue;
    }
    vis[a[i]] = 1;
    ll rev = calc(a[i]);
    vis[rev] = 1;
    ans += max(cnt[a[i]], cnt[rev]);
  }
  printf("%d\n", ans);
  return 0;
}
/*

首先发现将每个数的立方因子筛去对答案不会有影响。

于是对每个数使其质因子的指数都 mod 3

可以发现能与每个数相乘是立方数的数只有 1 个，这里定义其为该数的补数。

对于每个数和它的补数，将出现次数较多的计入答案。

只需要考虑如何计算补数即可。

*/