#include <bits/stdc++.h>

using namespace std;

int a[100020];
int b[100020];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d, k;
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 1; i <= n; ++i)
      a[i] = b[i] = 0;
    for (int i = 0; i < k; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x + 1]++;
      a[y + 1]--;
      b[x]++;
    }
    for (int i = 1; i <= n; ++i) {
      a[i] += a[i - 1];
      b[i] += b[i - 1];
      // printf("%d, %d\n", a[i], b[i]);
    }
    int bro = 0, vbro = 0;
    int mother = 0, vmother = 0;
    for (int i = 1; i <= n - d + 1; ++i) {
      int takes = a[i] + b[i + d - 1] - b[i - 1];
      // printf("t[%d] = %d\n", i, takes);
      if (!bro || takes > vbro)
        bro = i, vbro = takes;
      if (!mother || takes < vmother)
        mother = i, vmother = takes;
    }
    printf("%d %d\n", bro, mother);
  }
}
