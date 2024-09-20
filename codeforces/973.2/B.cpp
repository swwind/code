#include <bits/stdc++.h>

using namespace std;

int a[200020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      ans += a[i];
    }
    ans -= a[n - 2] * 2;
    printf("%lld\n", ans);
  }
}
