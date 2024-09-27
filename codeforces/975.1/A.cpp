#include <bits/stdc++.h>

using namespace std;

long long a[200020], b[200020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long k;
    long long sum = 0;
    scanf("%d%lld", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      b[i] = a[i] + b[i - 1];
    }

    printf("%lld\n", min((long long)n, (b[n] + k) / n));
  }
}
