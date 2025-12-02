#include <bits/stdc++.h>
#include <cstdio>

#define N 200030

// int a[N << 1];
int cnt[N << 1];
// int cpy[N << 1];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= 2 * n; ++i) {
      int a;
      scanf("%d", &a);
      cnt[a]++;
    }

    int odd = 0;
    int even = 0;
    int count = 0;
    for (int i = 1; i <= 2 * n; ++i) {
      if (cnt[i] > 0) {
        count += 1;
        if (cnt[i] & 1)
          odd += 1;
        else
          even += 1;
      }
    }

    if ((n + count) & 1) {
      if (odd) {
        printf("%d\n", odd + even * 2);
      } else {
        printf("%d\n", odd + even * 2 - 2);
      }
    } else {
      if (odd) {
        printf("%d\n", odd + even * 2);
      } else {
        printf("%d\n", odd + even * 2);
      }
    }
  }
}
