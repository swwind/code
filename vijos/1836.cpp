#include <bits/stdc++.h>
#define N 5020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
double f[N];
int main(int argc, char const *argv[]) {
  int n = read(), ans = 0;
  for (int i = 1; i <= 5 * n; ++ i)
    f[i] = 998244353;
  for (int i = 1; i <= n; ++ i) {
    double hrs; int imp;
    cin >> hrs >> imp;
    for (int j = 5 * n; j >= imp; -- j) {
      f[j] = min(f[j], f[j - imp] + hrs);
      if (f[j] <= 100)
        ans = max(ans, j);
    }
  }
  cout << ans << endl;
  return 0;
}