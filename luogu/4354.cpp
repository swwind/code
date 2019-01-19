#include <bits/stdc++.h>
#define N 100020
#define M 520
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

const double eps = 1e-6;
double R[M][M];

struct Line {
  double A, B, C;
  Line(double x1, double y1, double x2, double y2) {
    // (x-x1)/(x2-x1) = (y-y1)/(y2-y1)
    // (x-x1)(y2-y1) = (y-y1)(x2-x1)
    // (y2-y1)x-(y2-y1)x1 = (x2-x1)y-(x2-x1)y1
    // (y2-y1)x-(x2-x1)y +(x2-x1)y1-(y2-y1)x1 = 0
    A = y2 - y1;
    B = x1 - x2;
    C = (x2 - x1) * y1 - (y2 - y1) * x1;
  }
  double valueAt(double x) {
    return - (A * x + C) / B;
  }
  double distanceTo(double x, double y) {
    return fabs(A * x + B * y + C) / sqrt(A * A + B * B);
  }
};

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read();
  for (int i = 1; i <= n; ++ i) {
    int x = read(), y = read();
    scanf("%lf", &R[x][y]);
  }
  int m = read();
  for (int i = 1; i <= m; ++ i) {
    int x1 = read(), y1 = read();
    int x2 = read(), y2 = read();
    Line line(x1, y1, x2, y2);
    // printf("%.4lf x + %.4lf y + %.4lf = 0\n", line.A, line.B, line.C);
    int ans = 0;
    if (fabs(line.B) <= eps) {
      int l = min(y1, y2), r = max(y1, y2);
      for (int y = l; y <= r; ++ y)
        ans += R[x1][y] > 0;
    } else {
      int l = min(x1, x2), r = max(x1, x2);
      if (line.valueAt(l) < line.valueAt(r)) {
        for (int x = l; x <= r; ++ x) {
          int ll = x == l ? floor(line.valueAt(x) + eps) : floor(line.valueAt(x - 1) + eps);
          int rr = x == r ? ceil(line.valueAt(x) - eps) : ceil(line.valueAt(x + 1) - eps);
          // printf("scan %d [%d, %d]\n", x, ll, rr);
          for (int y = ll; y <= rr; ++ y) {
            if (R[x][y] > 0 && line.distanceTo(x, y) <= R[x][y]) {
              // printf("hit %d %d with %.3lf\n", x, y, line.distanceTo(x, y));
              ++ ans;
            }
          }
        }
      } else {
        for (int x = l; x <= r; ++ x) {
          int ll = x == r ? floor(line.valueAt(x) + eps) : floor(line.valueAt(x + 1) + eps);
          int rr = x == l ? ceil(line.valueAt(x) - eps) : ceil(line.valueAt(x - 1) - eps);
          // printf("scan %d [%d, %d]\n", x, ll, rr);
          for (int y = ll; y <= rr; ++ y) {
            if (R[x][y] > 0 && line.distanceTo(x, y) <= R[x][y]) {
              // printf("hit %d %d with %.3lf\n", x, y, line.distanceTo(x, y));
              ++ ans;
            }
          }
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
