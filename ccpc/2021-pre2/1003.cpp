#include <bits/stdc++.h>
#define N 100020
#define mod 998244353

using namespace std;

int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int f[N][3];

void dfs(int x, int fa) {
  f[x][0] = 1;
  f[x][1] = 1;
  f[x][2] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x);

    f[x][0] = (long long) f[x][0] * (f[y][0] + f[y][1]) % mod;
    f[x][1] = (long long) f[x][1] * ((f[y][0] + f[y][1]) % mod + f[y][2]) % mod;
    f[x][2] = (long long) f[x][2] * f[y][0] % mod;
  }
  f[x][1] = (f[x][1] - f[x][2] + mod) % mod;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T --) {
    int n;
    scanf("%d", &n);
    memset(head, 0, sizeof(head));
    cnt = 0;
    for (int i = 1; i < n; ++ i) {
      int x, y;
      scanf("%d%d", &x, &y);
      insert(x, y);
    }

    dfs(1, 0);

    printf("%d\n", (f[1][0] + f[1][1]) % mod);
  }
}
