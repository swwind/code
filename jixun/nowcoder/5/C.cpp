#include <bits/stdc++.h>
#define N 1000020
#define mod 998244353

using namespace std;

char str[N];

int wp[N], lp[N];
int pw[N], pl[N];
int f[N];
int last[N<<1];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str + 1);
  int cntw = 0, cntl = 0;

  for (int i = 1; i <= n; ++ i) {
    if (str[i] == 'W') {
      wp[++ cntw] = i;
    } else {
      lp[++ cntl] = i;
    }
    pw[i] = cntw;
    pl[i] = cntl;
  }
  int now = n;
  for (int i = 0; i <= (n<<1); ++ i) {
    last[i] = n+1;
  }
  for (int i = n; i >= 1; -- i) {
    f[i] = min(last[now-2], last[now+2]);
    last[now] = i;
    if (str[i] == 'W') now --;
    else now ++;
  }

  int mul = 1, res = 0;
  for (int i = 1; i <= n; ++ i) {
    int noww = pw[0];
    int nowl = pl[0];
    int ans = 0;
    while (noww + i <= cntw || nowl + i <= cntl) {
      int pos = min(noww+i>cntw?n+1:wp[noww + i], nowl+i>cntl?n+1:lp[nowl + i]);
      // printf("i = %d, pos = %d\n", i, pos);
      int countw = pw[pos] - noww;
      int countl = pl[pos] - nowl;
      // printf("cw = %d, cl = %d\n", countw, countl);
      if (abs(countw - countl) >= 2) {
        noww = pw[pos];
        nowl = pl[pos];
        ans += countw > countl;
        // printf("round end\n");
        continue;
      }
      if (pos+1 > n) break;
      if (str[pos+1] == 'W') countw ++;
      else countl ++;
      // printf("cw = %d, cl = %d\n", countw, countl);
      if (abs(countw - countl) >= 2) {
        noww = pw[pos+1];
        nowl = pl[pos+1];
        ans += countw > countl;
        // printf("round end\n");
        continue;
      }
      assert(countw == countl);
      pos = f[pos+1];
      // printf("jumpped to %d\n", pos);
      if (pos > n) break;
      countw = pw[pos] - noww;
      countl = pl[pos] - nowl;
      noww = pw[pos];
      nowl = pl[pos];
      ans += countw > countl;
    }
    // printf("%d\n", ans);
    res = (res + (long long) ans * mul % mod) % mod;
    mul = (long long) mul * (n + 1) % mod;
  }
  printf("%d\n", res);
}