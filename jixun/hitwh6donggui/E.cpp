#include <iostream>
using namespace std;

int f[100020];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  // int n = read(), m = read();
  int n, m;
  cin >> n >> m;
  // f[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    // int w = read(), v = read();
    int w, v;
    cin >> w >> v;
    for (int j = m; j >= w; -- j) {
      f[j] = max(f[j], f[j - w] + v);
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++ i) {
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
}
