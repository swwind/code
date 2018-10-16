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
int f[N], g[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    f[i] = 1;
  }
  g[1] = 1;
  for (int i = 1; i <= m; ++ i) {
    int x = read(), y = read();
    if (g[x]) g[y] = 1;
    if (!--f[x]) g[x] = 0;
    ++ f[y];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += g[i];
  }
  cout << ans << endl;
  return 0;
}