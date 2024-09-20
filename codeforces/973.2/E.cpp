#include <bits/stdc++.h>

using namespace std;

int a[100020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      // g = g ? __gcd(g, a[i]) : a[i];
    }
    // for (int i = 0; i < n; ++i)
    //   a[i] /= g;
    sort(a, a + n);
    for (int s = 1; s <= 30 && s < n; ++s) {
      int min = 1e6, pos = 0, g = a[0];
      for (int i = 1; i < s; ++i)
        g = __gcd(g, a[i]);
      for (int i = s; i < n; ++i) {
        if (__gcd(g, a[i]) < min) {
          min = __gcd(g, a[i]);
          pos = i;
        }
      }
      swap(a[s], a[pos]);
    }

    int g = a[0];
    long long ans = g;
    for (int i = 1; i < n; ++i) {
      g = __gcd(g, a[i]);
      ans += g;
    }
    printf("%lld\n", ans);
  }
}
