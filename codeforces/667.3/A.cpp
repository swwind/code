#include <bits/stdc++.h>
using namespace std;

int work(int x) {
  if (!x) return 0;
  if (x % 10 == 0) return x / 10;
  else return x / 10 + 1;
}

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t --) {
    scanf("%d%d", &n, &m);
    printf("%d\n", work(abs(n - m)));
  }
}