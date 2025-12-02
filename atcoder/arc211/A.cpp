#include <bits/stdc++.h>
#include <cstdio>

#define N 200030

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a[10];
    int not_good = 0;
    for (int i = 1; i <= 9; ++i) {
      scanf("%d", a + i);
    }
    int non_zero = 0;
    long long sum = 0;
    for (int i = 1; i <= 9; ++i) {
      if (a[i] > 0 && a[10 - i] > 0)
        not_good = 1;
      if (a[i] > 0)
        non_zero += 1;
      sum += a[i];
    }
    if (non_zero == 1 && not_good) {
      printf("%lld\n", sum - 1);
    } else if (non_zero == 2 && not_good) {
      puts("1");
    } else {
      printf("%lld\n", std::max(0ll, a[5] - 1 - (sum - a[5])));
    }
  }
}
