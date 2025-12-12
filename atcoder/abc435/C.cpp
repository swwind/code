#include <algorithm>
#include <cstdio>

#define N 100020

int a[100020];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);

  int ans = a[1];
  for (int i = 1; i <= ans && i <= n; ++i) {
    ans = std::max(ans, i + a[i] - 1);
  }

  printf("%d\n", std::min(ans, n));
}
