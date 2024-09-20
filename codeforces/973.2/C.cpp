#include <bits/stdc++.h>

using namespace std;

char prefix[102];
char suffix[102];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d", &n);

    int a = 0, b = 0;
    memset(prefix, 0, sizeof(prefix));
    memset(suffix, 0, sizeof(suffix));

    while (b < n) {
      suffix[b] = (rand() & 1) + '0';

      printf("? %s\n", suffix);
      fflush(stdout);
      scanf("%d", &x);

      if (x) {
        b++;
        continue;
      }

      suffix[b] ^= 1;

      printf("? %s\n", suffix);
      fflush(stdout);
      scanf("%d", &x);

      if (x) {
        b++;
        continue;
      }

      suffix[b] = 0;
      break;
    }

    // add prefix

    while (a + b < n) {
      ++a;
      prefix[n - b - a] = (rand() & 1) + '0';

      printf("? %s%s\n", &prefix[n - b - a], suffix);
      fflush(stdout);
      scanf("%d", &x);

      if (x) {
        continue;
      }

      prefix[n - b - a] ^= 1;
    }

    printf("! %s%s\n", prefix, suffix);
    fflush(stdout);
  }
}
