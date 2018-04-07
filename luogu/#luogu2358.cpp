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
double calc(double x, double y) {
  return sqrt(x * x + y * y);
}
int main(int argc, char const *argv[]) {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double way1 = calc(3 - x1 - x2, fabs(y1 - y2));
  double way2 = calc(1 + y1 + y2, fabs(x1 - x2));
  double way3 = calc(1 + x1 + x2, fabs(y1 - y2));
  double way4 = calc(3 - y1 - y2, fabs(x1 - x2));
  double ans = fmin(fmin(way1, way2), fmin(way3, way4));
  printf("%.3lf\n", ans);
  return 0;
}