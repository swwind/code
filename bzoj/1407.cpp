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
void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1; y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
int n;
int c[N], p[N], l[N];
bool judge(int m) {
  for (int i = 1; i <= n; ++ i) {
    for (int j = i + 1; j <= n; ++ j) {
      // printf("%d %d %d\n", m, i, j);
      // c[i]+p[i]*x   = c[j]+p[j]*x (mod m)
      // x*(p[j]-p[i]) = c[i]-c[j]   (mod m)
      int cs = ((c[j] - c[i]) % m + m) % m;
      int ps = ((p[i] - p[j]) % m + m) % m;
      int gcd = __gcd(ps, m);
      if (cs % gcd) continue;
      int x, y;
      exgcd(ps, m, x, y);
      // printf("%d %d\n", x, y);
      cs /= gcd;
      int ms = m / gcd;
      int k = (cs * x % ms + ms) % ms;
      if (k <= l[i] && k <= l[j]) {
        return false;
      }
    }
  }
  return true;
}
int main(int argc, char const *argv[]) {
  // freopen("1407.in", "r", stdin);
  // freopen("1407.out", "w", stdout);
  n = read();
  int st = 0;
  for (int i = 1; i <= n; ++ i) {
    c[i] = read() - 1;
    p[i] = read();
    l[i] = read();
    st = max(st, c[i] + 1);
  }
  for (int m = st; m; ++ m) {
    if (judge(m)) {
      printf("%d\n", m);
      break;
    }
  }
  return 0;
}