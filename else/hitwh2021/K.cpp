#include <bits/stdc++.h>
using namespace std;

double a[204][408];

int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      scanf("%d", &x);
      a[i][j] = x;
    }
    a[i][i+n] = 1;
  }

  for (int i = 0; i < n; ++ i) {
    int j = i;
    while (j < n && a[j][i] == 0) {
      ++ j;
    }
    if (i != j) {
      swap(a[i], a[j]);
    }
    double mul = 1.0 / a[i][i];
    for (int j = 0; j < (n << 1); ++ j) {
      a[i][j] = a[i][j] * mul;
    }
    for (int k = 0; k < n; ++ k) {
      if (k == i || a[k][i] == 0) continue;
      double mul = - a[k][i];
      for (int j = 0; j < (n << 1); ++ j) {
        a[k][j] += a[i][j] * mul;
      }
    }
  }

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      printf("%.12f%c", a[i][j+n], " \n"[j + 1 == n]);
    }
  }
}