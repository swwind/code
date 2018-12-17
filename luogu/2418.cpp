#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unordered_map>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
unordered_map<int, int> mp;
void update(int x, int v) {
  if (!mp.count(x)) mp[x] = v;
  else mp[x] = min(mp[x], v);
}
const int INF = 0x7ffffffe;
int query(int x) {
  return mp.count(x) ? mp[x] : INF;
}
int a[N], f[N], s1[N], s2[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    s1[i] = s1[i - 1] + (a[i] == 1);
    s2[i] = s2[i - 1] + (a[i] == 2);
  }
  int last1 = 0, last2 = 0;
  update(0, 0);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      f[i] = f[last2] + 1;
      last1 = i;
    } else {
      f[i] = f[last1] + 1;
      last2 = i;
    }
    f[i] = min(f[i],
      min(query(s1[i] - s2[i] - m),
          query(s1[i] - s2[i] + m)) + 1);
    update(s1[i] - s2[i], f[i]);
  }
  int ans = INF;
  if (abs(s1[n] - s2[n]) <= m) ans = 1;
  else {
    for (int i = 1; i <= n; i++) {
      if (s2[n] == s2[i] || s1[n] == s1[i])
        ans = min(ans, f[i] + 1);
      if (abs((s1[i] - s2[i]) - (s1[n] - s2[n])) <= m)
        ans = min(ans, f[i] + 1);
    }
  }
  cout << ans << endl;
  return 0;
}