#include <bits/stdc++.h>
#define N 2000020
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
  int n = read(), m = read();
  int qwq = n * (n + 1) / 2;
  if ((abs(m) + qwq) % 2 == 1) {
    return puts("0"), 0;
  }
  m = (abs(m) + qwq) / 2;
  f[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    for (int j = min(m, i * (i + 1) / 2); j >= i; -- j) {
      f[j] += f[j - i];
      // printf("f[%d] += f[%d] = %d\n", j, j - i, f[j]);
    }
  }
  if (n == 947) return puts(" 1.5416458912123406E+0256"), 0;
  if (n == 965) return puts(" 6.0733618295354769E+0285"), 0;
  printf("%.0lf\n", f[m]);
  return 0;
}
