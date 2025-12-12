#include <algorithm>
#include <cstdio>

#define N 200030

int a[N];

int vs[N], ps[N], cnt;
int ls[N], rs[N];

long long dfs(int x) {
  if (ls[x] && rs[x]) {
    return std::max(x - ls[x] + dfs(ls[x]), rs[x] - x + dfs(rs[x]));
  }

  if (rs[x]) {
    return rs[x] - x + dfs(rs[x]);
  }

  if (ls[x]) {
    return x - ls[x] + dfs(ls[x]);
  }

  return 0;
}

int main() {
  int n;
  scanf("%d", &n);

  int npos = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] == n)
      npos = i;
  }

  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    while (cnt && vs[cnt] < a[i]) {
      ls[i] = ps[cnt];
      cnt--;
    }
    vs[++cnt] = a[i];
    ps[cnt] = i;
  }

  cnt = 0;
  for (int i = n; i >= 1; --i) {
    while (cnt && vs[cnt] < a[i]) {
      rs[i] = ps[cnt];
      cnt--;
    }
    vs[++cnt] = a[i];
    ps[cnt] = i;
  }

  //   printf("%d\n", std::max(n - npos, npos - 1));

  //   for (int i = 1; i <= n; ++i) {
  //     printf("%d %d\n", ls[i], rs[i]);
  //   }

  long long ans = dfs(npos);
  printf("%lld\n", ans);
}
