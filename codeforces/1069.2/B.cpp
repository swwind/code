#include <cstdio>

int a[400020];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);

    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = i;
    }
    a[r] = a[l - 1];
    for (int i = 1; i <= n; ++i) {
      int ans = a[i] ^ a[i - 1];
      printf("%d%c", ans, " \n"[i == n]);
    }
  }
}
