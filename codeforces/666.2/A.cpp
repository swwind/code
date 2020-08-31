#include <bits/stdc++.h>
using namespace std;

int a[26];
char s[100030];

int main() {
  int t;
  scanf("%d", &t);
  while (t --) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 26; ++ i) {
      a[i] = 0;
    }
    for (int i = 1; i <= n; ++ i) {
      scanf("%s", s);
      int len = strlen(s);
      for (int j = 0; j < len; ++ j) {
        a[s[j] - 'a'] ++;
      }
    }
    bool flag = false;
    for (int i = 0; i < 26; ++ i) {
      if (a[i] % n) {
        flag = true;
      }
    }
    puts(flag ? "NO" : "YES");
  }
}
