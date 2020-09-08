#include <bits/stdc++.h>
using namespace std;

int x[200040], ll[200040], rr[200040];

int main() {
  int t;
  scanf("%d", &t);
  while (t --) {
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i) {
      scanf("%d", x + i);
    }
    for (int i = 1; i <= n; ++ i) {
      scanf("%d", &tmp);
    }
    sort(x + 1, x + n + 1);
    int l = 1;
    for (int r = 1; r <= n; ++ r) {
      while (x[l] < x[r] - k) {
        ++ l;
      }
      ll[r] = r - l + 1;
      ll[r] = max(ll[r], ll[r - 1]);
    }
    l = n;
    for (int r = n; r; -- r) {
      while (x[l] > x[r] + k) {
        -- l;
      }
      rr[r] = l - r + 1;
      // rr[r] = max(rr[r], rr[r + 1]);
    }

    int mx = ll[1];
    for (int i = 1; i < n; ++ i) {
      mx = max(mx, ll[i] + rr[i + 1]);
    }

    printf("%d\n", mx);
  }
}
