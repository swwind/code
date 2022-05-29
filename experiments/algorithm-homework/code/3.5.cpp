#include <bits/stdc++.h>
using namespace std;

int v[] = { 1, 4, 6, 8 };
int w[] = { 1, 2, 4, 6 };

int dp[100];
int s[100];

int main() {
  int n = 4, y = 12;

  for (int i = 0; i <= y; i++) {
    dp[i] = INT_MAX;
    s[i] = 0;
  }

  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = v[i]; j <= y; ++j) {
      if (dp[j - v[i]] + w[i] < dp[j]) {
        dp[j] = dp[j - v[i]] + w[i];
        s[j] = i + 1;
      }
    }
    for (int j = 0; j <= y; ++j) {
      printf("%d%c", s[j], " \n"[j == y]);
    }
  }
}