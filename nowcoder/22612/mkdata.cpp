#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(0));
  int n = 20, q = 5;
  printf("%d %d\n", n, q);
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", rand() & 0xf, " \n"[i == n]);
  }
  for (int i = 1; i <= q; ++ i) {
    int L = rand() & 0xf;
    int R = rand() & 0xf;
    if (L > R) swap(L, R);
    printf("%d %d %d\n", L, R, rand() % n + 1);
  }
}