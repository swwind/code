#include <bits/stdc++.h>
#define N 100020
#define ll long long

using namespace std;

ll a[N], b[N];

int main() {

  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);

  for (int i = 1; i <= n; ++ i) {
    scanf("%lld", a + i);
    a[i] += a[i-1];
  }
  for (int i = 1; i <= m; ++ i) {
    scanf("%lld", b + i);
  }

  ll va = 0;
  for (int i = x; i <= n; ++ i) {
    va = max(va, a[i] - a[i-x]);
  }
  ll vb = 0;
  for (int i = y; i <= m; ++ i) {
    vb = max(vb, b[i] - b[i-y]);
  }
  printf("%d %d\n", va, vb);
  
  printf("%.10f\n", (double) (y * va + x * vb) / (x * y));

}

// s(i) - v i >= s(j) - v j