#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>

#define N 200020

int a[N];
int b[N], cnt;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int limit = std::sqrt(k);

    std::map<int, int> mp, vis;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      mp[a[i]] = 1;
    }

    cnt = 0;
    std::sort(a + 1, a + n + 1);

    int ok = 1;
    for (int i = 1; i <= n; ++i) {
      if (!vis[a[i]]) {
        b[++cnt] = a[i];
        for (int j = a[i]; j <= k && ok; j += a[i]) {
          if (!mp[j]) {
            ok = 0;
            break;
          }
          vis[j] = 1;
        }
      }
    }

    if (ok) {
      printf("%d\n", cnt);
      for (int i = 1; i <= cnt; ++i) {
        printf("%d%c", b[i], " \n"[i == cnt]);
      }
    } else {
      puts("-1");
    }
  }
}
