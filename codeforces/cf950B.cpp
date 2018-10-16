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
int a[N], b[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= m; i++)
    b[i] = read();
  int suma = 0, sumb = 0;
  int posa = 0, posb = 0;
  int ans = 0;
  while (posa <= n && posb <= m) {
    if (suma == sumb)
      ans ++;
    if (suma > sumb)
      sumb += b[++ posb];
    else
      suma += a[++ posa];
  }
  cout << ans - 1 << endl;
  return 0;
}