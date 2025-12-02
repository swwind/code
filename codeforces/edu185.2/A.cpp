#include <bits/stdc++.h>
#include <cstdio>

int main() {
  int k, n;
  scanf("%d", &k);
  while (k--) {
    scanf("%d", &n);

    if (n == 1)
      printf("1\n");
    else if (n == 2)
      printf("9\n");
    else if (n <= 4)
      printf("%d\n", (n * n) + (n * n - 1) + (n * n - 2) + (n * n - n - 1));
    else
      printf("%d\n", (n * n - n) + (n * n - n - 1) + (n * n - n - 2) +
                         (n * n - n - n - 1) + (n * n - 1));
  }
}
