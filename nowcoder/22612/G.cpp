#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  if ((x ^ y) < x) {
    printf("1\n%lld\n", x ^ y);
  } else {
    long long m = 1;
    while ((m << 1) <= y) m <<= 1;
    assert((x & m) == 0);
    printf("2\n%lld %lld\n", m, (x ^ m) ^ y);
  }
}