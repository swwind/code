// 搞死小圆（划掉
// 高斯消元

#include <bits/stdc++.h>
#define N 120
double a[N][N];
int n;
bool gauss() {
  for (int i = 1; i <= n; i++){
    int mxr = i;
    for (int j = i + 1; j <= n; j++)
      if (abs(a[j][i]) > abs(a[mxr][i]))
        mxr = j;
    std::swap(a[mxr], a[i]);
    if (a[i][i] == 0) return false;
    for (int j = i + 1; j <= n + 1; j++)
      a[i][j] /= a[i][i];
    for (int k = i == 1 ? 2 : 1; k <= n; k++, k == i && ++ k)
      for (int j = i + 1; j <= n + 1; j++)
        a[k][j] -= a[k][i] * a[i][j];
  }
  return true;
}
int main(int argc, char const *argv[]) {
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n + 1; j++)
      std::cin >> a[i][j];
  if (!gauss()) {
    std::cout << "No Solution" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 1; i <= n; i++)
      std::cout << a[i][n + 1] << std::endl;
  }
  return 0;
}
// luogu3389
