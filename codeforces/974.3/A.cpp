#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, a, s = 0, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a);
      if (a >= k)
        s += a;
      else if (a == 0 && s > 0)
        --s, ++ans;
    }
    printf("%d\n", ans);
  }
}
