#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
bitset<1005> a[2005];
int n, m, ans;
bool gauss() {
  for (int i = 1; i <= n; i++){
    int mxr = 0;
    for (int j = i; j <= m && !mxr; j++)
      if (mxr |= a[j][i])
        mxr = j;
    if (!mxr) return false;
    ans = max(ans, mxr);
    if (mxr != i)
      swap(a[mxr], a[i]);
    for (int j = i == 1 ? 2 : 1; j <= m; j ++, j == i && ++ j)
      if (a[j][i]) a[j] ^= a[i];
  }
  return true;
}
char ch[5020];
int main(int argc, char const *argv[]) {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= n; j++)
      a[i][j] = ch[j] - '0';
    a[i][n + 1] = read();
  }
  if (!gauss())
    return puts("Cannot Determine"), 0;
  cout << ans << endl;
  for (int i = 1; i <= n; i++)
    cout << (a[i][n + 1] ? "?y7M#" : "Earth") << endl;
  return 0;
}