#include <bits/stdc++.h>
#define N 120
using namespace std;

int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int c[N];

void dfs(int x, int f) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    c[to[i]] = 1 - c[x];
    dfs(to[i], x);
  }
}

int tot[2];
int asg[N];
long long ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; ++ i) {
    scanf("%d%d", &u, &v);
    insert(u, v);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; ++ i) {
    tot[c[i]] ++;
  }

  int naive = tot[0] > tot[1] ? 1 : 0;
  assert(tot[naive] <= 50);
  int num = 0;
  long long full_mask = (1ll << 60) - 1;
  long long white_mask = (1ll << (tot[naive] + 1)) - 1;
  long long black_mask = full_mask ^ white_mask;
  for (int i = 1; i <= n; ++ i) {
    if (c[i] == naive) {
      asg[i] = num ++;
      ans[i] = white_mask ^ (1ll << asg[i]);
    }
  }
  assert(num == tot[naive]);
  for (int i = 1; i <= n; ++ i) {
    if (c[i] != naive) {
      ans[i] = black_mask;
      for (int k = head[i]; k; k = nxt[k]) {
        assert(c[to[k]] == naive);
        ans[i] |= (1ll << asg[to[k]]);
      }
    }
  }
  for (int i = 1; i <= n; ++ i) {
    printf("%lld%c", ans[i], " \n"[i == n]);
  }
}