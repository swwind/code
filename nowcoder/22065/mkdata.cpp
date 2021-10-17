#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 10;
  printf("%d\n", n);
  srand(time(0));
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", rand() % 5 + 1, " \n"[i == n]);
  }
}