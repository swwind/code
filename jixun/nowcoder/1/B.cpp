#include <bits/stdc++.h>
using namespace std;
int main() {
  double r,a,b,h;
  cin >> r >> a >> b >> h;
  if (2 * r < b) {
    puts("Drop");
  } else {
    puts("Stuck");
    double theta = atan2((a-b)/2.0, h);
    double v = r / cos(theta);
    double s = v / tan(theta);
    double ds = b/2.0 / tan(theta);
    printf("%.10lf\n", s - ds);
  }  
}
