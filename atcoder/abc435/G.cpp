#include <cstdio>
#include <vector>

#define N 500020

int ls[N], rs[N];

int dp[202][202];
int sum[N], fk[N], cache[N];

std::vector<int> ent[N], ext[N];

int get(int x, int i) {}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", ls + i, rs + i);
    if (ls[i] + 1 <= rs[i]) {
      ent[ls[i] + 1].push_back(i);
      ext[rs[i]].push_back(i);
    }
  }

  dp[0][0] = 1;
  sum[0] = 1;
  int total_sum = 0;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1];
    fk[i] = sum[i - 1];
    if (i >= 3) {
      fk[i] = fk[i] - sum[i - 3];
    }

    for (auto x : ent[i]) {
      cnt += 1;
    }

    if (i >= 2) {
      cache[i] = cnt * sum[i - 2] - cache[i - 2];
    }

    sum[i] += cache[i];

    for (auto x : ext[i]) {
      cnt -= 1;
      cache[i] -= get(x, i);
      cache[i - 1] -= get(x, i - 1);
    }
  }

  printf("%d\n", sum[n]);
}
