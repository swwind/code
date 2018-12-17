#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
std::map<string, int> mp;
int val[N], g[N], f[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    string x; cin >> x;
    mp[x] = i;
  }
  for (int i = 1; i <= n; i++)
    val[i] = read();
  for (int i = 1; i <= m; i++) {
    int s = read();
    g[i] = 2e9;
    for (int j = 1; j <= s; j++) {
      int x = read();
      f[x] = i;
      g[i] = min(g[i], val[x]);
    }
  }
  long long res = 0;
  for (int i = 1; i <= k; i++) {
    string x; cin >> x;
    res += g[f[mp[x]]];
  }
  cout << res << endl;
  return 0;
}