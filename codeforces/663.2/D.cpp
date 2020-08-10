#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

char s[1000020];
int a[5][1000020], b[1000020];
int n, m;

int bitcount(int x) {
  int ans = 0;
  while (x) {
    x -= x & -x;
    ++ ans;
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  if (n >= 4 && m >= 4) {
    puts("-1");
    return 0;
  }
  if (n <= 1 || m <= 1) {
    puts("0");
    return 0;
  }
  bool sp = false;
  if (n > m) {
    sp = true;
  }
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++ j) {
      if (sp) {
        a[j][i] = s[j] == '1';
      } else {
        a[i][j] = s[j] == '1';
      }
    }
  }
  if (sp) swap(n, m);
  // n = 4, m = 10w
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      b[j] |= (a[i][j] << (i - 1));
    }
  }
  // for (int j = 1; j <= m; ++ j) {
  //   printf("%d\n", b[j]);
  // }
  int aa[2] = {0, 0};
  for (int i = 0; i < n; ++ i) {
    if (i & 1) {
      aa[0] |= (1 << i);
    } else {
      aa[1] |= (1 << i);
    }
  }
  // printf("%d %d\n", aa[0], aa[1]);
  int damn = (1 << n) - 1, ans = 1e8;
  for (int xx = 0; xx < (1 << n); ++ xx) {
    for (int cc = 0; cc < 2; ++ cc) {
      int yy = (xx ^ aa[cc]);
      int res = 0;
      for (int j = 1; j <= m; ++ j) {
        int zz = (j & 1) ? xx : yy;
        res += min(bitcount(b[j] ^ zz), bitcount(b[j] ^ (zz ^ damn)));
      }
      ans = min(ans, res);
    }
  }

  printf("%d\n", ans == 1e8 ? -1 : ans);

}
// 001
// 011
// 110