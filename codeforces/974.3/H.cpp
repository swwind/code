#include <bits/stdc++.h>

using namespace std;

struct fuck {
  int l, r;
  int cl, cr;
  int id;
} qs[200020];

int a[200020];
bool ans[200020];
bool bucket[1000020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    int size = (int)(sqrt(n));
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    for (int i = 1; i <= q; ++i) {
      scanf("%d%d", &qs[i].l, &qs[i].r);
      qs[i].cl = (qs[i].l - 1) / size + 1;
      qs[i].cr = (qs[i].r - 1) / size + 1;
      qs[i].id = i;
    }
    sort(qs + 1, qs + q + 1, [&](const fuck &a, const fuck &b) {
      return a.cl == b.cl ? a.cr < b.cr : a.cl < b.cl;
    });

    for (int i = 1; i <= n; ++i)
      bucket[a[i]] = 0;
    int l = 1, r = 1;
    int fails = bucket[a[1]] = 1;
    for (int i = 1; i <= q; ++i) {
      while (l < qs[i].l)
        (bucket[a[l++]] ^= 1) ? ++fails : --fails;
      while (l > qs[i].l)
        (bucket[a[--l]] ^= 1) ? ++fails : --fails;
      while (r < qs[i].r)
        (bucket[a[++r]] ^= 1) ? ++fails : --fails;
      while (r > qs[i].r)
        (bucket[a[r--]] ^= 1) ? ++fails : --fails;
      // printf("%d, %d = %d\n", l, r, fails);
      ans[qs[i].id] = !fails;
    }
    for (int i = 1; i <= q; ++i)
      puts(ans[i] ? "YES" : "NO");
  }
}
