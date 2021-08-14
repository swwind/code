#include <bits/stdc++.h>
using namespace std;
int b[1000020], a[1000020];
struct Pair {
  int x, y;
} pr[1000020];
int st[1000020];
bool cmp(const Pair &a, const Pair &b) {
  return a.x == b.x ? a.y > b.y : a.x < b.x;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= k; ++ i) {
    int p, x;
    scanf("%d%d", &p, &x);
    b[p] = x;
  }

  int last = 0;
  int fail = false;
  for (int i = 1; i <= n && !fail; ++ i) {
    if (b[i]) {
      if (b[i] > last + 1) {
        fail = true;
        break;
      } else {
        last = b[i];
      }
    } else {
      b[i] = ++ last;
    }
  }
  if (fail) return puts("-1") & 0;

  for (int i = 1; i <= n; ++ i) {
    pr[i].x = b[i];
    pr[i].y = i;
  }

  sort(pr + 1, pr + n + 1, cmp);

  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    a[pr[i].y] = ++ ans;
  }

  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", a[i], " \n"[i == n]);
  }

  // for (int i = 1; i <= n; ++ i) {
  //   printf("%d%c", b[i], " \n"[i == n]);
  // }

  // self check
  int top = 0;
  for (int i = 1; i <= n; ++ i) {
    while (top && st[top] > a[i]) {
      -- top;
    }
    st[++ top] = a[i];
    assert(b[i] == top);
  }
}

// ? 2 ? ? 4
// 1 2 
// ? 1 2 3 4
// 1 1 2 3 4
// 1 3 