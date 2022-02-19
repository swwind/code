#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  scanf("%lld", &x);
  for (int i = 1; i <= min(1000000ll, x); ++ i) {
    if (x % i == 0) {
      long long y = x / i;
      long long s = sqrt(y);
      if (s * s == y) {
        printf("%lld\n", y);
        return 0;
      }
    }
  }
  for (long long i = 1e6; i; -- i) {
    if (x % (i * i) == 0) {
      printf("%lld\n", i * i);
      return 0;
    }
  }
}