#include <bits/stdc++.h>
#define N 100020
#define mod 10000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int ks[10], s[4000020], vis[4000020], h[4000020];
int S(int x) {
  if (s[x]) return s[x];
  int res = 0, y = x;
  while (x)
    res += ks[x % 10], x /= 10;
  return s[y] = res;
}
int H(int x) {
  if (h[x]) return h[x];
  if (vis[x] == 2) return x;
  S(x);
  vis[x] ++;
  h[x] = min(min(x, s[x]), H(s[x]));
  vis[x] --;
  return h[x];
}
int main(int argc, char const *argv[]) {
  int k = read(), a = read(), b = read();
  for (int i = 1; i < 10; i++) {
    ks[i] = 1;
    for (int j = 1; j <= k; j++)
      ks[i] *= i;
  }
  int ans = 0;
  h[1] = 1;
  for (int i = a; i <= b; i++)
    ans = (ans + H(i)) % mod;
  cout << ans << endl;
  return 0;
}