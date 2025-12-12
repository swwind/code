#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

#define N 100020

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  std::set<std::pair<int, int>> pr;

  int ans = n;
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);

    auto L = pr.lower_bound({l, 0});
    auto R = pr.lower_bound({r + 1, 0});

    if (L != pr.begin()) {
      --L;
      if (L->second < l) {
        ++L;
      }
    }

    // if (L == R)
    //   continue;

    int left = l;
    int right = r;
    int cnt = 0;
    std::vector<std::pair<int, int>> rm;
    for (auto it = L; it != R; ++it) {
      //   printf("looking %d %d\n", it->first, it->second);
      left = std::min(left, it->first);
      right = std::max(right, it->second);

      cnt += it->second - it->first + 1;
      rm.push_back(*it);
    }

    for (auto range : rm) {
      //   printf("remove [%d, %d]\n", range.first, range.second);
      pr.erase(range);
    }
    // printf("insert [%d, %d]\n", left, right);

    pr.insert({left, right});
    ans += cnt;
    ans -= right - left + 1;
    printf("%d\n", ans);
  }
}
