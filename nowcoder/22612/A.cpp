#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

struct Matrix {
  bitset<200> v[200];
  int get_R(int n) {
    int last = -1;
    for (int i = 0; i < n; ++ i) {
      // find the largest
      int now = last + 1;
      while (now < n && !v[now][i]) ++ now;
      if (now == n) continue;
      if (now != ++ last) swap(v[now], v[last]);
      for (int k = last + 1; k < n; ++ k) {
        if (v[k][i]) {
          v[k] ^= v[last];
        }
      }
    }
    return last + 1;
  }
} A, B, D;

int main() {
  int n, x;
  scanf("%d", &n);

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      scanf("%d", &x);
      A.v[i][j] = x;
    }
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      scanf("%d", &x);
      B.v[i][j] = x;
    }
  }

  int ans = 0;
  for (int j = 0; j < n; ++ j) {
    // enumerate row
    D = A;
    for (int i = 0; i < n; ++ i) {
      if (B.v[i][j]) {
        D.v[i].flip(i);
      }
    }
    ans += n - D.get_R(n);
  }

  int d = 1;
  while (ans --) d = (d << 1) % mod;
  printf("%d\n", d);
}
