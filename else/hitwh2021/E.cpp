#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  scanf("%d%d", &k, &n);
  int mx = INT_MIN;
  int mn = INT_MAX;
  for (int i = 1; i <= n; ++ i) {
    int x;
    scanf("%d", &x);
    mn = min(mn, x);
    mx = max(mx, x);
  }
  printf("%d\n", min(abs(k - mx), abs(k - mn)) + mx - mn);
}