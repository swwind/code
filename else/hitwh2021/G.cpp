#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++ i) {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    printf("Case #%d: %lld\n", i, n * m - 1);
  }
}