#include <bits/stdc++.h>
using namespace std;

long long a[100030];

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 1; i <= n; ++ i) {
    scanf("%lld", a + i);
  }
  sort(a + 1, a + n + 1);
  long long mincost = 1e17;
  for (long long i = 1; true; ++ i) {
    long long k = 1, cost = 0;
    bool bk = false;
    for (int j = 1; j <= n; ++ j) {
      cost += abs(k - a[j]);
      k = k * i;
      // printf("%lld\n", k);
      if (k > 1e15) {
        bk = true;
        break;
      }
    }
    if (bk) {
      break;
    }
    mincost = min(mincost, cost);
  }
  printf("%lld\n", mincost);
}
