#include <bits/stdc++.h>
#define N 100020
#define mod 1000000007

using namespace std;

int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int ans;

int dfs(int x, int f) {
  int res = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    res = (long long) res * dfs(to[i], x) % mod;
  }
  ans = (ans + res) % mod;
  return res + 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int c = 1; c <= t; ++ c) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++ i) {
      head[i] = 0;
    } cnt = 0;

    for (int i = 1; i < n; ++ i) {
      int x, y;
      scanf("%d%d", &x, &y);
      insert(x, y);
    }

    ans = 0;
    dfs(1, 0);
    printf("Case #%d: %d\n", c, ans);

  }
  
}
