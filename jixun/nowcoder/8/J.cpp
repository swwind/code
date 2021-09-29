#include <bits/stdc++.h>
using namespace std;

const int N = 500020;

int head[N], nxt[N<<1], to[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int n, s, t;
int mx[N];
int fa[N];
int dfs(int x, int f) {
  fa[x] = f;
  bool hasT = x == t;
  mx[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    int val = dfs(to[i], x);
    mx[x] = max(mx[x], val + 1);
    if (!val) {
      hasT = true;
    }
  }
  if (hasT) return 0;
  else return mx[x];
}

int pt[N], ra[N], rb[N], tot;
int mxra[N], mxrb[N];

int emulate_A(int l, int r);
int emulate_B(int l, int r);

int query_max_ra(int l, int r);
int query_max_rb(int l, int r);

int emulate_A(int l, int r) {
  if (l + 1 == r) {
    return ra[l] - rb[r];
  }
  int a1 = ra[l] - query_max_rb(l+1, r);
  int a2 = - emulate_B(l + 1, r);
  return max(a1, a2);
}

int emulate_B(int l, int r) {
  if (l + 1 == r) {
    return rb[r] - ra[l];
  }
  int a1 = rb[r] - query_max_ra(l, r - 1);
  int a2 = - emulate_A(l, r - 1);
  return max(a1, a2);
}

int sta[20][N], stb[20][N], lg[N];

int query_max_ra(int l, int r) {
  int k = lg[r - l + 1];
  return max(sta[k][l], sta[k][r-(1<<k)+1]);
}
int query_max_rb(int l, int r) {
  int k = lg[r - l + 1];
  return max(stb[k][l], stb[k][r-(1<<k)+1]);
}

int main() {
  scanf("%d%d%d", &n, &s, &t);
  for (int i = 1; i < n; ++ i) {
    int x, y;
    scanf("%d%d", &x, &y);
    insert(x, y);
  }

  dfs(s, 0);

  int now = t;
  while (now) {
    pt[++ tot] = now;
    now = fa[now];
  }
  reverse(pt + 1, pt + tot + 1);

  for (int i = 1; i <= tot; ++ i) {
    ra[i] = mx[pt[i]] + i - 1;
    rb[i] = mx[pt[i]] + tot - i;

    sta[0][i] = ra[i];
    stb[0][i] = rb[i];
  }

  for (int k = 1; k < 20; ++ k) {
    for (int i = 1; i+(1<<k)-1 <= n; ++ i) {
      sta[k][i] = max(sta[k-1][i], sta[k-1][i+(1<<(k-1))]);
      stb[k][i] = max(stb[k-1][i], stb[k-1][i+(1<<(k-1))]);
    }
  }

  for (int i = 2; i <= n; ++ i) {
    lg[i] = lg[i >> 1] + 1;
  }

  int ans = emulate_A(1, tot);
  printf("%d\n", ans);
}
