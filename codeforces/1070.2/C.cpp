#include <algorithm>
#include <cstdio>

#define N 200020

int a[N], cnta;
int b[N], cntb;
long long c[N];

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    // int n, m;
    // scanf("%d%d", &n, &m);

    int n;
    scanf("%d", &n);

    cnta = cntb = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (x & 1)
        a[++cnta] = x;
      else
        b[++cntb] = x;
    }

    std::sort(a + 1, a + cnta + 1);
    std::sort(b + 1, b + cntb + 1);

    c[0] = 0;
    for (int i = 1; i <= cntb; ++i) {
      c[i] = c[i - 1] + b[cntb - i + 1];
    }

    // long long ans = 0;

    int used = 0;

    if (!cnta) {
      for (int i = 1; i <= n; ++i) {
        printf("%d%c", 0, " \n"[i == n]);
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (i == n) {
          if (cnta % 2 == 0) {
            printf("%lld\n", 0ll);
          } else {
            printf("%lld\n", c[cntb] + a[cnta]);
          }
          break;
        }

        int even = i - 1;
        if (even > cntb) {
          even -= (even - cntb) / 2 * 2;
        }
        while (even > cntb) {
          even -= 2;
        }
        even = std::max(0, even);
        if ((i - even) % 2 == 0) {
          printf("0 ");
        } else {
          printf("%lld ", c[even] + a[cnta]);
        }
      }
    }
  }
}