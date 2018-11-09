#include <bits/stdc++.h>
#define N 200020
#define mod 1000000007
#define ll long long
using namespace std;
char ch[N];
ll frac[N];
ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) z = z * x % mod;
  return z;
}
ll inv(ll x) {
  return fast_pow(x, mod - 2);
}
ll C(ll n, ll m) {
  return frac[n] * inv(frac[m]) % mod * inv(frac[n - m]) % mod;
}
int r[N], l[N];
int main(int argc, char const *argv[]) {
  scanf("%s", ch + 1);
  int n = strlen(ch + 1);
  frac[0] = 1;
  for (int i = 1; i <= n; i++)
    frac[i] = frac[i - 1] * i % mod;
  for (int i = n; i; i--)
    r[i] = r[i + 1] + (ch[i] == ')');
  for (int i = 1; i <= n; i++)
    l[i] = l[i - 1] + (ch[i] == '(');
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (ch[i] == '(') {
      int x = r[i], y = l[i];
      ans = (ans + C(x + y - 1, x - 1)) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}

/*
枚举最靠右的左括号的位置，预处理该位置左边左括号的数量x和右边右括号的数量y。
答案即为∑C(x-1,i)*C(y,i)其中i≤min(x,y)。
而∑C(x-1,i)*C(y,i)=∑C(x-1,x-i-1)*C(y,i)=C(x+y-1,x-1)。
时间复杂度O(N)。

1 2
1

2 2
3

3 1
3

*/