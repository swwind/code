#include <bits/stdc++.h>
#define N 100020

using namespace std;

map<pair<int, int>, int> mp;

char str[N];

int main() {

  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d", &n);
    scanf("%s", str + 1);

    mp.clear();

    int sx = 0;
    int sy = 0;
    mp[{sx, sy}] = 1;

    long long ans = 0;

    for (int i = 1; i <= n; ++ i) {
      if (str[i] == 'U') {
        sx --;
      }
      if (str[i] == 'D') {
        sx ++;
      }
      if (str[i] == 'L') {
        sy --;
      }
      if (str[i] == 'R') {
        sy ++;
      }
      int x = mp[{sx, sy}];
      ans += x;
      mp[{sx, sy}] = x + 1;
    }

    printf("%lld\n", ans);
  }
}
