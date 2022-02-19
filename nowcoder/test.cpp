#include <bits/stdc++.h>
char s[30];
using namespace std;

int a[30][30], b[30][30];
int mp[30][30];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
  srand(time(0));
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++ i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++ j) {
      mp[i][j] = s[j] == '1';
    }
  }

  int ans = 0;
  int test_cases = 500;
  for (int t = 1; t <= test_cases; ++ t) {
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        a[i][j] = mp[i][j];
      }
    }

    for (int x = 1; x <= 50000; ++ x) {
      int c = rand() & 3;
      for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
          b[i][j] = mp[i][j] && (a[i-dx[c]][j-dy[c]] || a[i][j] && !mp[i+dx[c]][j+dy[c]]);
        }
      }
      memcpy(a, b, sizeof(a));
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        cnt += a[i][j];
      }
    }

    if (cnt <= 1) printf("#%d failed: cnt = %d\n", t, cnt);
    else printf("#%d passing: cnt = %d\n", t, cnt), ++ ans;
  }

  puts("");
  printf("%d passed, %d failed\n", ans, test_cases - ans);
  printf("passing rate: %.2f%%\n", (double) ans / test_cases * 100);
}
