#include <bits/stdc++.h>
using namespace std;

int a[25], b[25], c[25];

int main() {
  int t, s;
  scanf("%d", &t);
  long long n;
  while (t --) {
    scanf("%lld%d", &n, &s);
    long long k = n;

    for (int i = 1; i <= 20; ++ i) {
      a[i] = n % 10;
      b[i] = b[i - 1] + a[i];
      n /= 10;
    }

    if (b[20] <= s) {
      puts("0");
      continue;
    }

    for (int i = 1; i <= 20; ++ i) {
      int flag = false;
      for (int j = a[i] + 1; j <= 9; ++ j) {
        if (j + b[20] - b[i] <= s) {
          flag = true;
          a[i] = j;
          break;
        }
      }
      if (flag) {
        break;
      }
      a[i] = 0;
    }

    long long res = 0;
    for (int i = 20; i; -- i) {
      res = res * 10 + a[i];
    }
    // printf("%lld %lld\n", res, k);
    printf("%lld\n", res - k);
  }
}