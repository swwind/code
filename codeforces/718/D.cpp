#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"

#include <bits/stdc++.h>
#define N 500020
using namespace std;

inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int rt[505][505], dn[505][505];
// int id[505][505];

int f[505][505], g[505][505];

int main() {

  int n = read();
  int m = read();
  int k = read();
  int tot = 0;
  // for (int i = 1; i <= n; ++ i) {
  //   for (int j = 1; j <= m; ++ j) {
  //     id[i][j] = ++ tot;
  //   }
  // }
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j < m; ++ j) {
      rt[i][j] = read();
      // insert(id[i][j], id[i][j+1], read());
    }
  }
  for (int i = 1; i < n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      dn[i][j] = read();
      // insert(id[i][j], id[i+1][j], read());
    }
  }

  if (k & 1) {
    for (int i = 1; i <= n; ++ i)
      for (int j = 1; j <= m; ++ j)
        printf("-1%c", " \n"[j == m]);
  } else {
    int s = k >> 1;
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        for (int l = max(i-s,1); l <= min(i+s, n); ++ l) {
          for (int r = max(j-s,1); r <= min(j+s, m); ++ r) {
            g[l][r] = INT_MAX;
            f[l][r] = INT_MAX;
          }
        }
        g[i][j] = 0;
        for (int t = 1; t <= s; ++ t) {
          swap(f, g);
          for (int l = max(i-t,1); l <= min(i+t, n); ++ l) {
            for (int r = max(j-t,1); r <= min(j+t, m); ++ r) {
              g[l][r] = INT_MAX;
              if (l < min(i+t, n) && f[l+1][r] < INT_MAX) g[l][r] = min(g[l][r], f[l+1][r] + dn[l][r]);
              if (r < min(j+t, m) && f[l][r+1] < INT_MAX) g[l][r] = min(g[l][r], f[l][r+1] + rt[l][r]);
              if (l > max(i-t, 1) && f[l-1][r] < INT_MAX) g[l][r] = min(g[l][r], f[l-1][r] + dn[l-1][r]);
              if (r > max(j-t, 1) && f[l][r-1] < INT_MAX) g[l][r] = min(g[l][r], f[l][r-1] + rt[l][r-1]);
            }
          }
          // if (i == 2 && j == 2) {
          //   printf("\niter %d\n", t);
          //   for (int i = 1; i <= n; ++ i) {
          //     for (int j = 1; j <= n; ++ j) {
          //       printf("%d%c", g[i][j], " \n"[j == m]);
          //     }
          //   }
          // }
        }
        int ans = INT_MAX;
        for (int l = max(i-s,1); l <= min(i+s, n); ++ l) {
          for (int r = max(j-s,1); r <= min(j+s, m); ++ r) {
            ans = min(ans, g[l][r]);
          }
        }
        printf("%d%c", ans<<1, " \n"[j == m]);
      }
    }
  }
}