#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int f[N][N*6]; // i-th block, val of top is j
int a[N], b[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read(), b[i] = read();
  int min_sum = 0, max_sum = 0;
  for (int i = 1; i <= n; i++) {
    memset(f[i], 63, sizeof f[i]);
    for (int j = min_sum; j <= max_sum; j++) {
      f[i][j + a[i]] = min(f[i][j + a[i]], f[i - 1][j]);
      f[i][j + b[i]] = min(f[i][j + b[i]], f[i - 1][j] + 1);
    }
    min_sum += min(a[i], b[i]);
    max_sum += max(a[i], b[i]);
  }
  int bst = 1 << 30, ans = 0;
  for (int i = min_sum; i <= max_sum; i++) {
    if (abs(i - min_sum - max_sum + i) < bst) {
      ans = f[n][i];
      bst = abs(i - min_sum - max_sum + i);
    } else if (abs(i - min_sum - max_sum + i) == bst) {
      ans = min(ans, f[n][i]);
    }
  }
  // cout << f[4][10] << endl;
  // cout << bst << " " << ans << endl;
  cout << ans << endl;
  return 0;
}