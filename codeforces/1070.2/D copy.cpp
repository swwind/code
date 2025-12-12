#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>

#define N 200020
#define M 200020

#define MOD 998244353

long long a[N];

int head[N], to[M << 1], nxt[M << 1], cnt;
void insert(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}

std::map<std::pair<int, int>, int> vis;
int c[N], d[M << 1];

int u[M], v[M];

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);

    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      //   c[i] = i;
      head[i] = 0;
    }

    for (int i = 1; i <= m; ++i) {
      //   int u, v;
      //   scanf("%d%d", &u, &v);
      scanf("%d%d", u + i, v + i);
      //   insert(u, v);
      //   d[cnt] = 0;
      //   insert(v, u);
      //   d[cnt] = 0;
      c[i] = i;
    }

    std::sort(c + 1, c + m + 1, [&](const int &x, const int &y) {
      if (a[v[x]] > a[u[x]] && a[v[y]] <= a[u[y]])
        return true;
      if (a[v[y]] > a[u[y]] && a[v[x]] <= a[u[x]])
        return false;

      int mxx = std::max(a[v[x]], a[u[x]]);
      int mnx = std::min(a[v[x]], a[u[x]]);

      int mxy = std::max(a[v[y]], a[u[y]]);
      int mny = std::min(a[v[y]], a[u[y]]);

      //   if (mxx == 6 && mxy == 6) {
      //     printf("%d %d\n", x, y);
      //   }

      if (mxx != mxy)
        return mxy < mxx;
      return mny < mnx;

      //   if (mxx != mxy)
      //     return mxx > mxy;
      //   return mnx > mny;
    });

    // for (int i = 1; i <= m; ++i) {
    //   printf("%d(%lld) --> %d(%lld)\n", u[c[i]], a[u[c[i]]], v[c[i]],
    //          a[v[c[i]]]);
    // }

    for (int i = 1; i <= m; ++i) {
      d[i] = 1;
      //   int ans = 1;
      int x = u[c[i]], y = v[c[i]];
      for (int k = head[y]; k; k = nxt[k]) {
        if (a[to[k]] == a[x] + a[y]) {
          d[i] = (d[i] + d[k]) % MOD;
        }
      }
      if (a[y] > a[x]) {
        insert(x, y);
      }
      //   d[cnt] = ans;
    }

    // vis.clear();

    // for (int i = 1; i <= n; ++i) {
    //   printf("%d -> %d\n", c[i], a[c[i]]);
    // }

    // for (int i = 1, j = 1; i <= n; i = ++j) {
    //   while (j + 1 <= n && a[c[i]] == a[c[j + 1]]) {
    //     ++j;
    //   }

    //   printf("[%d, %d]\n", i, j);
    //   // from i to j are same score
    //   for (int k = i; k <= j; ++k) {
    //     int x = c[k];
    //     for (int i = head[x]; i; i = nxt[i]) {
    //       d[i] = 1;
    //       printf("d[%d] = %d\n", i, 1);
    //       if (a[to[i]] > a[x]) {
    //         for (int j = head[to[i]]; j; j = nxt[j]) {
    //           if (a[to[j]] == a[x] + a[to[i]]) {
    //             d[i] = (d[i] + d[j]) % MOD;
    //             printf("d[%d] = d[%d] + d[%d] = %d\n", i, i, j, d[i]);
    //           }
    //         }
    //       }
    //     }
    //   }

    //   for (int k = i; k <= j; ++k) {
    //     int x = c[k];
    //     for (int i = head[x]; i; i = nxt[i]) {
    //       //   d[i] = 1;
    //       //   if (a[to[i]] == a[x]) {
    //       for (int j = head[to[i]]; j; j = nxt[j]) {
    //         if (a[to[j]] == a[x] + a[to[i]]) {
    //           d[i] = (d[i] + d[j]) % MOD;
    //           printf("d[%d] = d[%d] + d[%d] = %d\n", i, i, j, d[i]);
    //         }
    //       }
    //       //   }
    //     }
    //   }
    // }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      ans = (ans + d[i]) % MOD;
    }

    printf("%d\n", ans);
  }
}