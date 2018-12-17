#include <bits/stdc++.h>
#define N 1020
#define mod 19650827
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int check(bool x, int y) {
  return x ? y : 0;
}
int f[N][N], a[N], g[N][N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= n; i++)
    f[i][i] = 1;
  for (int j = 1; j < n; j++) {
    for (int i = 1; i <= n - j; i++) {
      int l = i, r = i + j;
      f[l][r] = (check(a[l] < a[l + 1], f[l + 1][r]) + check(a[l] < a[r], g[l + 1][r])) % mod;
      g[l][r] = (check(a[r] > a[l], f[l][r - 1]) + check(a[r] > a[r - 1], g[l][r - 1])) % mod;
    }
  }
  cout << (f[1][n] + g[1][n]) % mod << endl;
  return 0;
}