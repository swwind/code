#include <bits/stdc++.h>

using namespace std;

int n = 30000, k = 100;
int a[30020];

int main() {
  printf("%d\n", n);
  for (int i = 1; i <= n; ++ i) a[i] = i;
  for (int i = 1; i <= n; ++ i) {
    printf("%d", k);
    random_shuffle(a + 1, a + n + 1);
    for (int j = 1; j <= k; ++ j) {
      printf(" %d", a[j]);
    }
    puts("");
  }
}