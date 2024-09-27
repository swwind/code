#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    puts((((k / 2) + ((k & 1) && (n & 1))) & 1) ? "NO" : "YES");
  }
}
