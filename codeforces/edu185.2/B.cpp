#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

#define N 200020

int b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", b + i);
    }

    std::sort(b + 1, b + n + 1);

    long long mx = 0;
    long long non_zero = 0;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (b[i] > 0)
        non_zero++;
      sum += b[i];
      mx = std::max(mx, (long long)b[i]);
    }

    // printf("%lld\n", std::min(non_zero, mx - non_zero + 1));
    printf("%lld\n", std::min(non_zero, sum - n + 1));
  }
}