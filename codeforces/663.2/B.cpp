#include <bits/stdc++.h>
using namespace std;

char s[130];
bool a[120][120];

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t --) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; ++ j) {
        a[i][j] = s[j] == 'R';
      }
    }
    int ans = 0;
    for (int i = 1; i < n; ++ i) {
      ans += a[i][m];
    }
    for (int i = 1; i < m; ++ i) {
      ans += !a[n][i];
    }
    printf("%d\n", ans);
  }
}