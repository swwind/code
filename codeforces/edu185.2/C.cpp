#include <bits/stdc++.h>
#include <cstdio>

#define N 200020

int q[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", q + i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", r + i);
    }

    std::sort(q + 1, q + n + 1);
    std::sort(r + 1, r + n + 1);

    int pos = n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      // q * (r + 1) + r <= k
      // q <= (k - r) / (r + 1)
      long long limit = (k - r[i]) / (r[i] + 1);
      while (pos > 0 && q[pos] > limit) {
        pos--;
      }
      if (pos > 0 && q[pos] <= limit) {
        pos--;
        ans++;
      }
    }

    printf("%d\n", ans);
  }
}