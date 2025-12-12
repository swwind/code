#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<long long> a(n);
  long long max_val = -1;

  // 1. 读入 a 并找到最大值
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > max_val) {
      max_val = a[i];
    }
  }

  // 标记哪些是最大值元素
  vector<bool> is_max(n, false);
  for (int i = 0; i < n; ++i) {
    if (a[i] == max_val) {
      is_max[i] = true;
    }
  }

  vector<long long> c(n);
  long long K = 2e18; // K 是最大值元素中的最小 cost

  // 2. 读入 c 并计算初始 K
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    if (is_max[i]) {
      K = min(K, c[i]);
    }
  }

  // 3. 计算初始的总和 sum = sum(min(c[i], K))
  long long current_sum = 0;
  for (int i = 0; i < n; ++i) {
    current_sum += min(c[i], K);
  }

  // 初始答案
  cout << current_sum - K << " ";

  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];

  bool giant_zeroed = false; // 标记 K 是否已经变成了 0

  // 4. 处理 n 次归零操作
  for (int i = 0; i < n; ++i) {
    int idx = p[i] - 1; // 题目下标从1开始，转为0开始

    if (giant_zeroed) {
      // 如果 K 已经是 0，答案永远是 0
      cout << 0 << " ";
      continue;
    }

    if (is_max[idx]) {
      // 如果这次归零的是最大值元素，K 变为 0
      giant_zeroed = true;
      cout << 0 << " ";
    } else {
      // 如果归零的是非最大值元素
      // 从 sum 中减去该元素的贡献
      current_sum -= min(c[idx], K);
      // 将该元素 c 变为 0 (实际上不需要真改数组，只要更新 sum 即可)
      // 新的 contribution 是 min(0, K) = 0，不需要加回去
      cout << current_sum - K << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}