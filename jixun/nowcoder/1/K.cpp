#include <bits/stdc++.h>
#define N 50020

using namespace std;

int b[N];

double calc(int x, int y) {
  return sqrt(abs(x - y));
}

void fuck(int n) {
  for (int i = 0; i < n; ++ i) {
    for (int j = i + 1; j < n; ++j) {
      if (calc(i, b[j]) + calc(j, b[i]) < calc(i, b[i]) + calc(j, b[j])) {
        swap(b[i], b[j]);
      }
    }
  }
}

void solve1(int n) {
  fuck(n);
  fuck(n);
  fuck(n);
  fuck(n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", b[i], " \n"[i + 1 == n]);
  }
}

int main() {

  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    // if (n < 10) {
    //   // printf("what the fuck\n");
    //   solve2(n);
    //   // printf("what the fuck\n");
    // } else {
      solve1(n);
    // }
  }
}
