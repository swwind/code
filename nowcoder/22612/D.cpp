#include <bits/stdc++.h>
#define N 100020
using namespace std;
struct fuck {
  int st, ed;
}f[N];
bool cmp(const fuck &a, const fuck &b) {
  return a.ed < b.ed;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++ i) {
    scanf("%d%d", &f[i].st, &f[i].ed);
  }
  sort(f + 1, f + n + 1, cmp);

  long long ans = 0;
  int last = 0;
  for (int i = 1, j = 1; i <= n; i = ++ j) {
    while (j <= n && f[j+1].ed == f[i].ed) ++ j;
    int mx = last + 1;
    for (int k = i; k <= j; ++ k) {
      mx = max(mx, f[k].st);
    }
    ans += (long long) mx * (j - i + 1);
    last = mx;
  }
  printf("%lld\n", ans);
}