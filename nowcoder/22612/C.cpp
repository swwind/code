#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long cnt = min(a, b), ans = 0;
  ans += cnt * 2;
  a -= cnt;
  b -= cnt;
  if (a > 0) {
    ans += (a / 3) * 3;
    ans += (a % 3 == 2) * 1;
  }
  if (b > 0) {
    ans += (b / 3) * 6;
    ans += (b % 3 == 2) * 4;
  }
  printf("%lld\n", ans);
}