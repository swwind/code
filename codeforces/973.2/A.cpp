#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int z = min(x, y);

    printf("%d\n", n ? (n - 1) / z + 1 : 0);
  }
}
