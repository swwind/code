#include <bits/stdc++.h>

using namespace std;

long long st[200020];
int tot[200020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
      long long x;
      scanf("%lld", &x);

      if (!cnt || x > st[cnt]) {
        st[++cnt] = x;
        tot[cnt] = 1;
      } else if (x == st[cnt]) {
        tot[cnt]++;
      } else {
        int j = cnt;

        long long total = x;
        int all = 1;

        while (j > 0 && st[j] > total / all) {
          total += st[j] * tot[j];
          all += tot[j];
          j--;
        }

        // int j = 1;
        // while (st[j] < x)
        //   ++j;
        // // range st[j, cnt] can be averaged
        // long long total = x;
        // int all = 1;
        // for (int k = j; k <= cnt; ++k) {
        //   total += st[k] * tot[k];
        //   all += tot[k];
        // }

        if (total % all == 0) {
          long long v = total / all;
          st[cnt = j + 1] = v;
          tot[cnt] = all;
        } else {
          long long v = total / all;
          int more = total % all;
          st[cnt = j + 1] = v;
          tot[cnt] = all - more;
          st[++cnt] = v + 1;
          tot[cnt] = more;
        }
      }

      // for (int k = 1; k <= cnt; ++k) {
      //   printf("s[%d] = %lld, %d\n", k, st[k], tot[k]);
      // }
      // printf("===\n");
    }

    printf("%lld\n", st[cnt] - st[1]);
  }
}
