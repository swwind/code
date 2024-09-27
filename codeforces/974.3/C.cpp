#include <bits/stdc++.h>

using namespace std;

int a[200020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      sum += a[i];
    }
    sort(a, a + n);
    if (n <= 2) {
      puts("-1");
      continue;
    }
    int thres = a[n / 2];
    printf("%lld\n", max(0ll, 2ll * thres * n + 1 - sum));
  }
}
