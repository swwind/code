#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, x, y, a, b, n;
  scanf("%d", &t);
  while (t --) {
    scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);
    if (n >= a - x + b - y) {
      printf("%lld\n", (long long) x * y);
      continue;
    }
    long long res1 = n >= (a - x) ? (long long) x * (b - (n - (a - x))) : (long long) (a - n) * b;
    long long res2 = n >= (b - y) ? (long long) y * (a - (n - (b - y))) : (long long) (b - n) * a;
    printf("%lld\n", min(res1, res2));
  }
}