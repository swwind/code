#include <bits/stdc++.h>
using namespace std;

int a[105];
int mx;

int main() {
  int t, n;
  scanf("%d", &t);
  while (t --) {
    scanf("%d", &n);

    int mx = 0, total = 0;

    for (int i = 1; i <= n; ++ i) {
      scanf("%d", a + i);
      mx = max(mx, a[i]);
      total += a[i];
    }

    // if (n == 1) {
    //   puts("T");
    //   continue;
    // }

    // if (n == 2) {
    //   if (a[1] == a[2]) {
    //     puts("HL");
    //   } else {
    //     puts("T");
    //   }
    //   continue;
    // }

    if (mx > total - mx) {
      puts("T");
      continue;
    }

    puts(total % 2 ? "T" : "HL");
  }
}
