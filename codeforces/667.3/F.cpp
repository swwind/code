#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;

int n, m, a[250], b[250];
char s[250], c[20];

// to position i, used j times, there is k c[0] before
int f[202][202], g[202][202];

int maxx(int a, int b) {
  if (a == inf) return b;
  return max(a, b);
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  scanf("%s", c);
  for (int i = 1; i <= n; ++ i) {
    a[i] = s[i] == c[0] ? 1 : s[i] == c[1] ? 2 : 0;
    // printf("a[%d] = %d\n", i, a[i]);
    b[i] = b[i - 1] + (a[i] == 1);
  }

  if (c[0] == c[1]) {
    int isk = min(b[n] + m, n);
    // C(isk, 2) = isk!/isk-2
    printf("%d\n", isk * (isk - 1) / 2);
    return 0;
  }

  memset(g, 0x7f, sizeof g);
  // printf("%x\n", g[0][0]);
  g[0][0] = 0;
  for (int i = 1; i <= n; ++ i) {
    swap(f, g);
    memset(g, 0x7f, sizeof g);
    // printf("%d\n", f[0][0]);

    for (int j = 0; j <= min(i, m); ++ j) {
      for (int k = 0; k <= i; ++ k) {
        if (f[j][k] == inf) continue;

        if (a[i] == 1) {
          g[j][k + 1] = maxx(g[j][k + 1], f[j][k]);
        } else if (a[i] == 2) {
          g[j][k] = maxx(g[j][k], f[j][k] + k);
        } else {
          g[j][k] = maxx(g[j][k], f[j][k]);
        }
        // change to 1
        g[j + 1][k + 1] = maxx(g[j + 1][k + 1], f[j][k]);
        // change to 2
        g[j + 1][k] = maxx(g[j + 1][k], f[j][k] + k);
      }
    }
    // for (int j = 0; j <= m; ++ j) {
    //   for (int k = 0; k <= n; ++ k) {
    //     printf("%d%c", g[j][k], " \n"[k == n]);
    //   }
    // }
    // puts("=======");
  }

  int ans = 0;
  for (int j = 0; j <= m; ++ j) {
    for (int k = 0; k <= n; ++ k) {
      if (g[j][k] != inf) {
        ans = maxx(ans, g[j][k]);
      }
    }
  }
  printf("%d\n", ans);
}
