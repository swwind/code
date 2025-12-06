#include <cstdio>

int a[4000];
int cnt[1002];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 1000; ++i)
      cnt[i] = 0;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (!cnt[a[i]]) {
        ans += 1;
        cnt[a[i]] = 1;
      }
    }

    while (ans < 1000) {
      int x = ans;
      if (cnt[x])
        break;
      ans += 1;
      cnt[x] = 1;
    }

    printf("%d\n", ans);
  }
}
