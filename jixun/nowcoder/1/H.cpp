#include <bits/stdc++.h>
#define N 500020
using namespace std;
int a[N];
bool b[N];

int n;

bool check(int ans) {
  for (int i = 0; i < ans; ++ i) b[i] = 0;
  for (int i = 0; i < n; ++ i) {
    bool *s = &b[a[i]%ans];
    if (*s) return false;
    *s = 1;
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++ i) {
    cin >> a[i];
  }
  for (int ans = n; true; ++ ans) {
    if (check(ans)) {
      printf("%d\n", ans);
      return 0;
    }
  }
}


/*
0 7 23 18 29 27 6 28 24 11

0 6 7 11 18 23 24 27 28 29 mod x differ
  6 7 11 18 23 24 27 28 29 mod x (!= 0)
    1 5  12 17 18 21 22 23 mod x (!= 0 != 6)

6 1 4 7 5 1 3 1 1
*/