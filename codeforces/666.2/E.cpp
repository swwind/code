#include <bits/stdc++.h>
using namespace std;

long long a[1000050];

// WAWAWAWA
int main() {
  long long n, r1, r2, r3, d;
  scanf("%lld%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);

  for (int i = 1; i <= n; ++ i) {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
  }

  long long mn = a[n] * min(r1, r3) + n * min(r1 * 2, r3) + d * (n - 1);
  for (int i = 1; i < n; ++ i) {
    long long l = a[i] * min(r1, r3) + i * min(r1 * 2, r3) + d * i;
    for (int j = i + 1; j < n; ++ j) {
      long long r = (j - i) * (r2 + min(r1, r3)) + 2 * (j - i - 1) * d + d;
      long long end = (a[n] - a[j]) * min(r1, r3) + (n - j) * min(r1 * 2, r3) + 2 * (n - j - 1) * d;
      if (i == 2 && j == 3) {
        printf("= %lld %lld %lld\n", l, r, end);
      }
      mn = min(mn, l + r + end);
    }
    long long r = (n - i) * (r2 + min(r1, r3)) + 2 * (n - i - 1) * d;
    mn = min(mn, l + r);
  }

  printf("%lld\n", mn);
}
