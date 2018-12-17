#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define mod 1000000007
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char str[N];
int xs[N], bs[N], ws[N];
int ls[N], rs[N], bin[N];
int lss[N];
int main(int argc, char const *argv[]) {
  // freopen("../temp/input.in", "r", stdin);
  int n = read(), k = read();
  scanf("%s", str + 1);
  bin[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    xs[i] = xs[i - 1] + (str[i] == 'X');
    bs[i] = bs[i - 1] + (str[i] == 'B');
    ws[i] = ws[i - 1] + (str[i] == 'W');
    bin[i] = bin[i - 1] * 2 % mod;
  }
  int ans = 0;
  ls[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    // ls[i] -> 1~i has no k B
    ls[i] = (str[i] == 'X' ? 2 : 1) * ls[i - 1] % mod;
    if (i >= k && ws[i] == ws[i - k] && str[i - k] != 'B') {
      lss[i] = i == k ? 1 : ls[i - k - 1];
    }
    ls[i] = (ls[i] - lss[i] + mod) % mod;
  }
  rs[n+1] = 1;
  for (int i = n; i; -- i) {
    rs[i] = (str[i] == 'X' ? 2 : 1) * rs[i + 1] % mod;
    if (i <= n-k+1 && bs[i-1] == bs[i+k-1] && str[i + k] != 'W') {
      rs[i] = (rs[i] - (i == n-k+1 ? 1 : rs[i + k + 1]) + mod) % mod;
    }
  }
  for (int i = 1; i < n; ++ i) {
    int tmp = (bin[xs[n] - xs[i]] - rs[i+1] + mod) % mod;
    ans = (ans + (ll) lss[i] * tmp % mod) % mod;
  }
  std::cout << ans << std::endl;
  return 0;
}