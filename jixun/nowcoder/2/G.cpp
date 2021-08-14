#include <bits/stdc++.h>
#define N 5020
using namespace std;

struct Pair {
  int l, r;
} pr[N];

bool cmp(const Pair &a, const Pair &b) {
  return a.l == b.l ? a.r < b.r : a.l < b.l;
}

int f[N][N];
int g[N][N];

int st[N][14], logn[N];

int st_query(int l, int r) {
  int s = logn[r - l + 1];
  return min(st[l][s], st[r - (1 << s) + 1][s]);
}

void check_better(int &f, int &g, int v, int t) {
  if (v > f) {
    f = v;
    g = t;
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++ i) {
    scanf("%d%d", &pr[i].l, &pr[i].r);
  }

  sort(pr + 1, pr + n + 1, cmp);

  for (int i = 2; i <= n; ++ i) {
    logn[i] = logn[i / 2] + 1;
  }
  for (int i = 1; i <= n; ++ i) {
    st[i][0] = pr[i].r;
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  // i = 1
  for (int i = 1; i <= n; ++ i) {
    if (st_query(1, i) - pr[i].l > 0) {
      f[i][1] = st_query(1, i) - pr[i].l;
    } else {
      f[i][1] = -1e9;
    }
    g[i][1] = 1;
  }

  for (int i = 2; i <= n; ++ i) {

    for (int j = 1; j <= k; ++ j) {
      if (st_query(g[i-1][j], i) - pr[i].l > 0) {
        check_better(f[i][j], g[i][j],
          f[i-1][j]
          - (st_query(g[i-1][j], i-1) - pr[i-1].l)
          + (st_query(g[i-1][j], i) - pr[i].l),
          g[i-1][j]);
        // printf("update %d %d, %d %d\n", i, j, f[i-1][j]
          // - (st_query(g[i-1][j], i-1) - pr[i-1].l)
          // + (st_query(g[i-1][j], i) - pr[i].l), g[i-1][j]);
      }
      if (j > 1) {
        check_better(f[i][j], g[i][j], f[i-1][j-1] + pr[i].r - pr[i].l, i);
        // printf("update %d %d, %d %d\n", i, j, f[i-1][j-1] + pr[i].r - pr[i].l, i);
      }
    }
  }

  // for (int i = 1; i <= n; ++ i) {
  //   for (int j = 1; j <= k; ++ j) {
  //     printf("f[%d][%d] = %d\n", i, j, f[i][j]);
  //   }
  // }

  // for (int i = 1; i <= n; ++ i) {
  //   for (int j = i; j <= n; ++ j) {
  //     printf("st_query(%d, %d) = %d\n", i, j, st_query(i, j));
  //   }
  // }

  printf("%d\n", f[n][k] > 0 ? f[n][k] : 0);
}

// ---------------
//   ----------------
//      ------------------
//          -------------


// f[i][k] = f[i-1][k-1] + a[i]
// f[i][k] = f[i-1][k] + 