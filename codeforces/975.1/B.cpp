#include <bits/stdc++.h>

using namespace std;

int a[200020];
int f[200020], g[200020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    f[1] = a[1];
    for (int i = 2; i <= n; ++i)
      f[i] = min(f[i - 1] - 1, a[i] - 1);
    g[n] = a[n];
    for (int i = n - 1; i; --i)
      g[i] = min(g[i + 1] - 1, a[i] - 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      ans += (f[i] >= 0 && g[i] >= 0 && (f[i - 1] - 1) + (g[i + 1] - 1) < n);
    for (int i = 1; i <= n; ++i)
      printf("%4d%c", f[i], " \n"[i == n]);
    for (int i = 1; i <= n; ++i)
      printf("%4d%c", g[i], " \n"[i == n]);
    printf("%d\n", ans);
  }
}
