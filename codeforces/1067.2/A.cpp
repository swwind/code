#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

#define N 200030

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, y, r;
    scanf("%d", &n);
    scanf("%d%d", &y, &r);

    printf("%d\n", std::min(n, y / 2 + r));
  }
}