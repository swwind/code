#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, x, y;
  scanf("%d", &t);
  while (t --) {
    scanf("%d%d%d", &n, &x, &y);
    if (x > y) swap(x, y);
    int dist = y - x;
    int st, sp, mn = 1e9+7;
    for (int d = 1; d <= dist; ++ d) {
      if (dist % d) {
        continue;
      }
      int k = dist / d + 1;
      if (k > n) continue;
      int left = (x - 1) / d;
      if (left + k >= n) {
        st = x - (n - k) * d;
        sp = d;
        break;
      }
      int mx = (n - left - k) * d + y;
      if (mx < mn) {
        mn = mx;
        st = x - left * d;
        sp = d;
      }
    }

    for (int i = 0; i < n; ++ i) {
      printf("%d%c", st + sp * i, " \n"[i + 1 == n]);
    }
  }
}