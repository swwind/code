#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int w[N], v[N], l[N], r[N], n, m;
ll S, s[N], k[N], ans = 1ll<<60;
ll work(int w1) {
  memset(s, 0, sizeof s);
  memset(k, 0, sizeof k);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + (w[i] >= w1);
  for (int i = 1; i <= m; i++) {
    int t = s[r[i]] - s[l[i] - 1];
    k[l[i]] += t;
    k[r[i] + 1] -= t;
  }
  for (int i = 1; i <= n; i++)
    k[i] += k[i - 1];
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    if (w[i] >= w1) {
      res += k[i] * v[i];
    }
  }
  return res;
}
int main(int argc, char const *argv[]) {
  n = read(); m = read(); S = read();
  for (int i = 1; i <= n; i++) {
    w[i] = read();
    v[i] = read();
  }
  for (int i = 1; i <= m; i++) {
    l[i] = read();
    r[i] = read();
  }
  int l = 0, r = 1e6;
  while (l < r) {
    int mid = l + r >> 1;
    ll res = work(mid);
    ans = min(ans, abs(res - S));
    if (res < S) r = mid;
    else l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}