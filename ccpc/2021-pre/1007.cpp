#include <bits/stdc++.h>

using namespace std;

int g[1000020];
// vector<int> gg[60];

int gg[55][56000];

struct Query {
  int a, b, c, d;
  int n, id;
} q[10020];
long long ans[10020];

bool cmp(const Query &a, const Query &b) {
  return a.n < b.n;
}

int main() {

  // for (int i = 1; i <= 1000000; ++ i) {
  //   g[i] = g[i / 10] + i % 10;
  //   fuck[g[i]]++;
  // }
  // int mx = 0;
  // for (int i = 1; i <= 60; ++ i) {
  //   mx = max(mx, fuck[i]);
  //   printf("fuck[%d] = %d\n", i, fuck[i]);
  // }
  // printf("mx = %d\n", mx);

  int t; scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d%d%d%d%d", &q[i].a, &q[i].b, &q[i].c, &q[i].d, &q[i].n);
    q[i].id = i;
  }
  sort(q+1, q+t+1, cmp);

  int now = 0;
  for (int i = 1; i <= t; ++ i) {

    while (now < q[i].n) {
      ++ now;
      g[now] = g[now / 10] + now % 10;
      // gg[g[now]].push_back(now);
      gg[g[now]][++ gg[g[now]][0]] = now;
    }

    int a = q[i].a, b = q[i].b, c = q[i].c, d = q[i].d;
    int id = q[i].id;
    ans[id] = LONG_LONG_MAX;

    for (int g = 1; g <= 54; ++ g) {
      if (!gg[g][0]) continue;

      long long A = 1ll * a * g + b;
      long long B = 1ll * (c * g + d) * g;
      long long x;

      if (A <= 0) {
        x = gg[g][1];
        ans[id] = min(ans[id], A * x * x + B * x);
        x = gg[g][gg[g][0]];
        ans[id] = min(ans[id], A * x * x + B * x);
      } else {
        int l = 1, r = gg[g][0];
        while (r - l >= 3) {
          int mid1 = (l + l + r) / 3;
          int mid2 = (l + r + r) / 3;

          long long res1 = A * gg[g][mid1] * gg[g][mid1] + B * gg[g][mid1];
          long long res2 = A * gg[g][mid2] * gg[g][mid2] + B * gg[g][mid2];

          if (res1 < res2) {
            r = mid2;
          } else {
            l = mid1;
          }
        }
        for (int i = l; i <= r; ++ i) {
          x = gg[g][i];
          ans[id] = min(ans[id], A * x * x + B * x);
        }
      }

    }

    // long long res = LONG_LONG_MAX;
    // for (long long x = 1; x <= q[i].n; ++ x) {
    //   res = min(res, a*x*x*g[x]+b*x*x+c*x*g[x]*g[x]+d*x*g[x]);
    // }

    // printf("%lld\n", res);
    // printf("%lld\n", ans[id]);
    // assert(ans[id] == res);
  }

  for (int i = 1; i <= t; ++ i) {
    printf("%lld\n", ans[i]);
  }
}