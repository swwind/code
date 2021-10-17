#include <bits/stdc++.h>
#define N 1000020

using namespace std;

int a[N];
int b[N];
int c[N];
int mn[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  // int* end = unique(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++ i) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    c[i] = lower_bound(b + 1, b + n + 1, b[i]) - b;
  }
  int mx = 0, ans = 0;
  mn[n+1] = INT_MAX;
  for (int i = n; i; -- i) {
    mn[i] = min(mn[i+1], a[i]);
  }
  for (int i = 1; i <= n; ++ i) {
    mx = max(mx, a[i]);
    // printf("mx = %d, mn = %d, b[i] = %d\n", mx, mn[i+1], c[i+1]);
    if (mx <= i && mn[i+1] >= c[i+1]) {
      ++ ans;
    }
  }

  printf("%d\n", ans);

}