#include <bits/stdc++.h>
using namespace std;

int v[4][3] = {
  {10,8,12},
  {20,21,30},
  {40,42,30},
  {30,60,45},
};

int w[4][3] = {
  {5,6,4},
  {8,10,5},
  {5,4,10},
  {20,10,15},
};

int ans = INT_MAX;
vector<int> res(4), a(4);

void dfs(int x, int v, int w) {
  if (x == 4) {
    if (v <= 120 && w < ans) {
      ans = w;
      res = a;
    }
    return;
  }

  for (int i = 0; i < 3; ++i) {
    a[x] = i;
    dfs(x + 1, v + ::v[x][i], w + ::w[x][i]);
  }
}

int main() {
  dfs(0, 0, 0);
  printf("%d\n", ans);
  for (size_t i = 0; i < res.size(); ++i) {
    printf("%d%c", res[i], " \n"[i == res.size() - 1]);
  }
}