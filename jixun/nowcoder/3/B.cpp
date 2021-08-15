#include <bits/stdc++.h>
#define N 5002
using namespace std;

struct Edge {
  int x, y, v;
} e[N * N];

int main() {
  int n, m, a, b, c, d, p;
  scanf("%d%d%d%d%d%d%d", &n, &m, &a, &b, &c, &d, &p);

  int cnt = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      a = (((long long) a * a % p * b % p + (long long) a * c % p) % p + d) % p;
      e[++ cnt] = (Edge) { i, j + n, a };
    }
  }
}