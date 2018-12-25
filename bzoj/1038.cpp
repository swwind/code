#include <bits/stdc++.h>
#define N 305
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int x[N], y[N];
double res[N];

struct line {
  double k, b;
} ls[N], st[N];
struct point {
  double x, y;
  point() { }
  point(double x, double y)
    :x(x), y(y) { }
} ps[N];

const double eps = 1e-9;

inline bool cmp(const line &a, const line &b) {
  if (fabs(a.k - b.k) <= eps) return a.b < b.b;
  else return a.k < b.k;
}

inline line getLine(double x1, double y1, double x2, double y2) {
  line _line;
  _line.k = (y2 - y1) / (x2 - x1);
  _line.b = y1 - x1 * _line.k;
  return _line;
}

inline point intersect(const line &a, const line &b) {
  double x = (b.b - a.b) / (a.k - b.k);
  double y = a.k * x + a.b;
  return point(x, y);
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  int n = read(), top = 0;
  double ans = 1e60;

  for (int i = 1; i <= n; ++ i) { x[i] = read(); }
  for (int i = 1; i <= n; ++ i) { y[i] = read(); }
  for (int i = 1; i < n; ++ i) {
    ls[i] = getLine(x[i], y[i], x[i + 1], y[i + 1]);
    for (int j = 1; j <= n; ++ j) {
      res[j] = max(res[j], ls[i].k * x[j] + ls[i].b);
    }
  }
  for (int i = 1; i <= n; ++ i) {
    ans = min(ans, res[i] - y[i]);
  }
  sort(ls + 1, ls + n, cmp);
  for (int i = 1; i < n; ++ i) {
    while (top && fabs(ls[i].k - st[top].k) <= eps) {
      -- top;
    }
    while (top > 1 && intersect(ls[i], st[top]).x <= intersect(st[top], st[top - 1]).x) {
      -- top;
    }
    st[++ top] = ls[i];
  }
  for (int i = 1; i < top; ++ i) {
    point p = intersect(st[i], st[i + 1]);
    int j = lower_bound(x + 1, x + n + 1, p.x) - x - 1;
    // printf("%.4lf is between [%d, %d]\n", p.x, j, j + 1);
    line l = getLine(x[j], y[j], x[j + 1], y[j + 1]);
    // printf("height is %.4lf %.4lf\n", p.y, (l.k * p.x + l.b));
    ans = min(ans, p.y - (l.k * p.x + l.b));
  }

  printf("%.3lf\n", ans);
	return 0;
}