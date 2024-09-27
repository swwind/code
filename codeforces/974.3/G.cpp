#include <bits/stdc++.h>

using namespace std;

int ds[100020];
int as[100020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    int good = 0, l = 1, r = 0, now = 1;
    for (int i = 1; i <= n; ++i) {
      int d, a;
      scanf("%d%d", &d, &a);

      while (l <= r && ds[l] + k <= d) {
        // expires milk first
        now = max(now, ds[l]);
        int step = ds[l] + k;
        int days = step - now;
        int consumes = days * m;
        while (l <= r && consumes > 0) {
          if (as[r] > consumes) {
            as[r] -= consumes;
            consumes = 0;
          } else {
            consumes -= as[r];
            as[r] = 0;
            --r;
          }
        }
        int eaten = (days * m - consumes) / m;
        // printf("%d -> %d: %d\n", now, step, eaten);
        good += eaten;
        ++l;
        now = step;
      }

      ds[++r] = d;
      as[r] = a;
    }

    while (l <= r) {
      now = max(now, ds[l]);
      int step = ds[l] + k;
      int days = step - now;
      int consumes = days * m;
      while (l <= r && consumes > 0) {
        if (as[r] > consumes) {
          as[r] -= consumes;
          consumes = 0;
        } else {
          consumes -= as[r];
          as[r] = 0;
          --r;
        }
      }
      int eaten = (days * m - consumes) / m;
      // printf("%d -> %d: %d\n", now, step, eaten);
      good += eaten;
      ++l;
      now = step;
    }

    printf("%d\n", good);
  }
}
