#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a = 1, b = 1;
  for (int i = 2; i <= n; ++ i) {
    a = a * 2ll % mod;
    b = (long long ) b * i % mod;
  }
  printf("%d\n", ((b - a) % mod + mod) % mod);
}