#include <bits/stdc++.h>
using namespace std;
int dp[26];
int a[26][26];
int cnt[26];
char s[500020], t[500020];
int main() {
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s);
  int m = strlen(t);

  for (int i = 0; i < m; ++i) {
    int c = t[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      if (cnt[j]) {
        a[j][c] = 1;
      }
    }
    cnt[c] = 1;
  }

  // for (int k = 0; k < 26; ++k) {
  //   for (int i = 0; i < 26; ++i) {
  //     for (int j = 0; j < 26; ++j) {
  //       a[i][j] |= (a[i][k] & a[k][j]);
  //     }
  //   }
  // }

  //   A   B   A
  // a[a][b] = 1
  // a[b][a] = 1
  // a[b][b] = 1

  // for (int i = 0; i < 26; ++i) {
  //   for (int j = 0; j < 26; ++j) {
  //     if (a[i][j]) {
  //       printf("%c -> %c\n", i + 'a', j + 'a');
  //     }
  //   }
  // }

  int spare = 0;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (!cnt[c]) { ++spare; continue; }
    int res = dp[c];
    for (int j = 0; j < 26; ++j) {
      if (!a[j][c]) {
        res = max(res, dp[j] + 1);
      }
    }
    dp[c] = res;
  }

  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    // printf("dp[%c] = %d\n", i + 'a', dp[i]);
    ans = max(ans, dp[i]);
  }

  printf("%d\n", ans + spare);
}