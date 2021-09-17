#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(NULL));
  int n = 10, q = 100;
  printf("%d %d\n", n, q);
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", rand() % n + 1, " \n"[i == n]);
  }
  int total_k = 1e7;
  for (int i = 1; i <= q; ++ i) {
    int l = rand() % n + 1, r = rand() % n + 1;
    if (l > r) swap(l, r);
    int k = rand() % max(min(n - r + 1, l)-2,1);
    k = min(k, total_k);
    printf("%d %d %d\n", l, r, k);
    total_k -= k;
  }
}