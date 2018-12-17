// 求逆元（递推式

#include <bits/stdc++.h>
#define N 3000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll inv[N];
int main(int argc, char const *argv[]) {
  ll n = read(), p = read();
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = (p - p / i) * inv[p % i] % p;
  for (int i = 1; i <= n; i++)
    printf("%lld\n", inv[i]);
  return 0;
}
/*

设 $p = ak+r$

$$
\begin{aligned}
ak+r &= 0 \pmod p \\
(ak+r)a^{-1}r^{-1} &= 0 \pmod p \\
kr^{-1}+a^{-1} &= 0 \pmod p \\
a^{-1} &= -kr^{-1} \pmod p \\
\end{aligned}
$$

因为 $k = \left\lfloor\frac pa\right\rfloor$

$$
\begin{aligned}
a^{-1} &= -\left\lfloor\frac pa\right\rfloor\times r^{-1} \pmod p \\
a^{-1} &= (p-\left\lfloor\frac pa\right\rfloor)\times r^{-1} \pmod p \\
\end{aligned}
$$

*/