#include <cstdio>

#define N 100020

int a[N];

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    // int n, m;
    // scanf("%d%d", &n, &m);

    int n;
    scanf("%d", &n);

    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (x >= mx) {
        mx = x;
      } else {
        ans += 1;
      }
    }

    printf("%d\n", ans);
  }
}