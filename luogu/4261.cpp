#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int b[N], tot, cnt[2], d0[N], d1[N];
int al[2][N], ar[2][N];

inline int positive(int x, int y) {
  return x + y;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("../tmp/.in", "r", stdin);
#endif
  int T = read();
  while (T --) {
    int n = read();
    tot = cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; ++ i) {
      int x = read(), y = read();
      int w = read(), h = read();
      int d = read();
      int l = positive(x, y);
      int r = positive(x + w, y + h);
      ++ cnt[d];
      al[d][cnt[d]] = l;
      ar[d][cnt[d]] = r;
      b[++ tot] = l;
      b[++ tot] = r;
    }
    memset(d0, 0, sizeof d0);
    memset(d1, 0, sizeof d1);
    sort(b + 1, b + tot + 1);
    int *end = unique(b + 1, b + tot + 1), len = end - b - 1;
    for (int i = 1; i <= cnt[0]; ++ i) {
      int l = lower_bound(b + 1, end, al[0][i]) - b;
      int r = lower_bound(b + 1, end, ar[0][i]) - b;
      // printf("%d %d\n", l, r);
      d0[l] ++; d0[r] --;
    }
    for (int i = 1; i <= cnt[1]; ++ i) {
      int l = lower_bound(b + 1, end, al[1][i]) - b;
      int r = lower_bound(b + 1, end, ar[1][i]) - b;
      // printf("%d %d\n", l, r);
      d1[l] ++; d1[r] --;
    }
    int ans = 0;
    for (int i = 1; i <= len; ++ i) {
      d0[i] += d0[i - 1];
      d1[i] += d1[i - 1];
      ans = max(ans, (!!d0[i]) + (!!d1[i]));
    }
    printf("%d\n", ans);
  }
  return 0;
}