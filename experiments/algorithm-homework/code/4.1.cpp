#include <bits/stdc++.h>

using namespace std;

int main() {
  int t[] = { 1, 3, 2, 15, 10, 6, 12 };
  sort(t, t + 7);
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    ans += t[i] * (7 - i - 1);
  }
  printf("%d\n", ans);
}