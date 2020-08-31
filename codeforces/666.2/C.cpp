#include <bits/stdc++.h>
using namespace std;

long long a[100030];

int main() {
  long long n;
  scanf("%lld", &n);
  
  for (int i = 1; i <= n; ++ i) {
    scanf("%lld", a + i);
  }

  if (n == 1) {
    puts("1 1");
    puts("0");
    puts("1 1");
    puts("0");
    puts("1 1");
    printf("%d\n", -a[1]);
    return 0;
  }

  printf("%d %d\n%d\n", 1, 1, -a[1]);
  printf("%d %d\n", 2, n);
  for (int i = 2; i <= n; ++ i) {
    printf("%lld%c", a[i]*(n-1), " \n"[i == n]);
  }
  printf("%d %d\n0 ", 1, n);
  for (int i = 2; i <= n; ++ i) {
    printf("%lld%c", -a[i]*n, " \n"[i == n]);
  }
}
