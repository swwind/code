#include <bits/stdc++.h>
#define N 1020
#define M 205
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
long long f[M][M] = {1}, sum[M][M], n, m, ki;
char a[N], b[M];
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  int n = read(), m = read(), K = read();
  scanf("%s%s", a, b);
  for (int i = 1; i <= n; ++ i) {
    for (int j = m; j >= 1; -- j) {
      for (int k = K; k >= 1; -- k) {
        sum[j][k] = a[i - 1] == b[j - 1] ? sum[j - 1][k] + f[j - 1][k - 1] : 0;
        f[j][k] = (f[j][k] + sum[j][k]) % mod;
      }
    }
  }
  printf("%lld\n", f[m][K]);
  return 0;
}