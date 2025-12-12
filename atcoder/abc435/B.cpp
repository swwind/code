#include <cstdio>

#define N 100020

int a[10020];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);

  int ans = 0;
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      int ok = 1;
      int sum = 0;
      for (int k = l; k <= r; ++k) {
        sum += a[k];
      }
      for (int k = l; k <= r; ++k) {
        if (sum % a[k] == 0) {
          ok = 0;
        }
      }

      ans += ok;
    }
  }

  printf("%d\n", ans);
}
