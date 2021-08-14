#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;

int fx[5000020], fy[5000020];

int main() {
  int x, y;
  scanf("%d%d", &x, &y);

  fx[0] = 1;
  for (int i = 1; i <= x-2; ++ i) {
    fx[i] = fx[i-1] * (x-1ll-i) % mod * 2ll % mod;
  }
  fy[0] = 1;
  for (int i = 1; i <= y-2; ++ i) {
    fy[i] = fy[i-1] * (y-1ll-i) % mod * 2ll % mod;
  }

  int ans = 0;
  for (int i = 0; i <= x + y - 4; ++ i) {
    int res = 0;
    for (int a = 0; a <= i; ++ a) {
      printf("+= f[%d] * f[%d] = %d * %d\n", a, i - a, fx[a], fy[i-a]);
      res = (res + (long long) fx[a] * fy[i - a] % mod) % mod;
    }
    printf("res = %d\n", res);
    ans |= res;
  }
  printf("%d\n", ans);

  // fx[1] = (x-2)*2;
  // fx[2] = (x-2)*2 * (x-3)*2;
  // ..
  // fx[x-2] = (x-2)*2 * (x-3)*2 * (x-4)*2 * ... * 1*2;

  // fx[a] = 2^a * (x-2)!/(x-2-a)!
  // fy[b] = 2^b * (y-2)!/(y-2-a)!

  // fx[1] = (x-2)*2;
  // fx[2] = (x-2)*2 * (x-3)*2;
  // ..
  // fx[x-2] = (x-2)*2 * (x-3)*2 * (x-4)*2 * ... * 1*2;
}