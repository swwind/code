#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y;
};

vector<point> a[105][105];

int main() {
  int n, r, q;
  scanf("%d%d%d", &n, &r, &q);

  for (int i = 1; i <= n; ++ i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x/1000][y/1000].push_back({x, y});
  }
  for (int i = 1; i <= q; ++ i) {
    int x, y;
    scanf("%d%d", &x, &y);
    int x1 = (x - r) / 1000;
    int x2 = (x + r) / 1000;
    int y1 = (y - r) / 1000;
    int y2 = (y + r) / 1000;
    int ans = 0;
    for (int xx = x1; xx <= x2; ++ xx) {
      for (int yy = y1; yy <= y2; ++ yy) {
        for (point p : a[xx][yy]) {
          if ((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) <= r * r) {
            ++ ans;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}