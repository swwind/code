#include <bits/stdc++.h>
#define N 2050
#define mod 100003
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int f[N][N], v[N];
int main(int argc, char const *argv[]) {
  int a = read(), b = read(), c = read(), d = read(), k = read();
  for (int i = 1; i <= c; ++ i) {
    v[i] = d;
    f[i][0] = 1;
  }
  for (int i = 1; i <= a; ++ i) {
    v[c + i] = d + b;
    f[c + i][0] = 1;
  }
  f[0][0] = 1;
  for (int j = 1; j <= a + c; ++ j) {
    for (int i = 1; i <= k; ++ i) {
      f[j][i] = (f[j - 1][i] + f[j - 1][i - 1] * (v[j] - i + 1)) % mod;
    }
  }
  cout << f[a + c][k] << endl;
  return 0;
}