#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll rl[N], ans[N], mx;
void manacher(char *s, ll len) {
  ll mxr = -1, pos = 0;
  for (ll i = 0; i < len; i++) {
    rl[i] = i < mxr ?
      min(rl[2 * pos - i], mxr - i) : 1;
    while (i - rl[i] >= 0 && i + rl[i] < len && s[i - rl[i]] == s[i + rl[i]])
      rl[i] ++;
    if (i + rl[i] - 1 > mxr) {
      mxr = i + rl[i] - 1;
      pos = i;
    }
    ++ ans[rl[i]];
    mx = max(mx, rl[i]);
  }
}
char s[N];
const int mod = 19930726;
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) z = z * x % mod;
  return z;
}
int main(int argc, char const *argv[]) {
  ll n = read(), k = read();
  scanf("%s", s);
  manacher(s, n);
  ll res = 1;
  for (ll i = mx; i; -- i) {
    ll m = min(ans[i], k);
    res = res * fast_pow(2*i-1, m) % mod;
    k -= m;
    if (!k) break;
    ans[i - 1] += ans[i];
  }
  cout << res << endl;
  return 0;
}