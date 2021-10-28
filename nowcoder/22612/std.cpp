#include <bits/stdc++.h>
#define N 100020
using namespace std;
int a[N];
int b[N];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; ++ i) {
    scanf("%d", a + i);
  }

  while (q --) {
    int L, R, k;
    scanf("%d%d%d", &L, &R, &k);

    int ans = INT_MAX, best = 0;
    for (int x = L; x <= R; ++ x) {
      for (int i = 1; i <= n; ++ i) {
        b[i] = a[i] ^ x;
      }
      sort(b + 1, b + n + 1);
      ans = min(ans, b[k]);
      if (b[k] == ans) best = x;
    }

    printf("%d\n", ans);
    printf("best: %d\n", best);
  }
}
