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
double fcalc(double x, double y) {
  return sqrt(x * x + y * y);
}
int main(int argc, char const *argv[]) {
  double x1, y1, x2, y2, ans = 1e60;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 += .5; x2 += .5; y1 += .5; y2 += .5;
  ans = fmin(ans, fcalc(3 - x1 - x2, y1 - y2));
  ans = fmin(ans, fcalc(1 + y1 + y2, x1 - x2));
  ans = fmin(ans, fcalc(1 + x1 + x2, y1 - y2));
  ans = fmin(ans, fcalc(3 - y1 - y2, x1 - x2));

  ans = fmin(ans, fcalc(x2 + y1 + 1, x1 + y2));
  ans = fmin(ans, fcalc(y1 + 2 - x2, 1 - x1 + y2));
  ans = fmin(ans, fcalc(y2 + 2 - x1, 1 - x2 + y1));
  ans = fmin(ans, fcalc(3 - x1 - y2, 2 - y1 - x2));

  ans = fmin(ans, fcalc(3 - x2 - y1, 2 - x1 - y2));
  ans = fmin(ans, fcalc(x2 + 2 - y1, 1 - y2 + x1));
  ans = fmin(ans, fcalc(x1 + 1 + y2, x2 + y1));
  ans = fmin(ans, fcalc(x1 + 2 - y2, 1 - y1 + x2));
  printf("%.3lf\n", ans);
  return 0;
}