
#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct node {
  int l, r;
} a[N], b[N];
deque<pair<int, int>> q[N];
int mxr, ans, mx[N], tot, dp[N][105];
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  int n = read(), k = read();
  for (int i = 1; i <= n; i++)
    b[i] = (node){read(), read()};
  sort(b + 1, b + 1 + n, [&] (const node& a, const node& b) {
    return a.l == b.l ? a.r > b.r : a.l < b.l;
  });
  a[++tot] = b[1];
  for (int i = 2; i <= n; i++) {
    if (b[i].r > mxr) {
      a[++tot] = b[i], mxr = a[i].r;
    } else {
      k--;
    }
  }
  k = max(k, 0);
  n = tot;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j >= i)
        break;
      int dt = i - j - 1;
      while (!q[dt].empty() && a[q[dt].front().second].r <= a[i].l) {
        int x = q[dt].front().second;
        q[dt].pop_front();
        mx[dt] = max(mx[dt], dp[x][x - dt]);
      }
      dp[i][j] = mx[dt] + a[i].r - a[i].l;
      if (!q[dt].empty())
        dp[i][j] = max(dp[i][j], q[dt].front().first + a[i].r);
      int w = dp[i][j] - a[i].r;
      dt++;
      while (!q[dt].empty() && q[dt].front().first <= w)
        q[dt].pop_back();
      q[dt].push_back(make_pair(w, i));
    }
    if (k - (n - i) >= 0) {
      ans = max(ans, dp[i][k - (n - i)]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
#if 0
int f[N][102];
int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);
  int n = read(), k = read();
  for (int i = 1; i <= n; ++ i) {
    a[i].l = read();
    a[i].r = read();
  }
  sort(a + 1, a + n + 1, [&] (const node &a, const node &b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
  });
  int maxr = 1e9+7, m = 0;
  for (int i = n; i; -- i) {
    if (a[i].l < maxr) {
      b[++ m] = a[i];
      maxr = a[i].l;
    }
  }
  sort(b + 1, b + m + 1, [&] (const node &a, const node &b) {
    return a.l < b.l;
  });

  if (n - m >= k) {
    // puts("fire unrated employee");
    int lp, rp = -1;
    int ans = 0;
    for (int i = 1; i <= m; ++ i) {
      // printf("%d %d\n", b[i].l, b[i].r);
      if (b[i].l > rp) {
        lp = b[i].l;
      }
      rp = b[i].r;
      ans = max(ans, rp - lp);
    }
    printf("%d\n", ans);
  } else {
    // say good bye to these people
    int byebye = k - (n - m);
    int ans = 0;
    for (int i = 1; i <= m; ++ i) {
      // printf("%d %d\n", b[i].l, b[i].r);
      for (int last = 0; last < i; ++ last) {
        for (int c = i - last - 1; c <= byebye; ++ c) {
          f[i][c] = max(f[i][c], f[last][c - (i - last - 1)] + b[i].r - max(b[i].l, b[last].r));
        }
      }
      if (m - i <= byebye) {
        ans = max(ans, f[i][byebye - (m - i)]);
      }
    }
    puts("fuck you");
    printf("%d\n", ans);
  }
  return 0;
}
#endif