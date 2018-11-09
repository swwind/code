#include <bits/stdc++.h>
#define N 20020
#define fuck 5000
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int n, s, ans, a[N];
ll f[101][10002];
void dfs_ans(int i, int j) {
  if (ans >= 100)
    return;
  if (i == n) {
    ++ ans;
    int sum = 0;
    for (int i = 1; i <= n; i++)
      printf("%d ", sum += a[i]);
    puts("");
    return;
  }
  int k = n - i;
  if (j > k && f[i + 1][j - k]) {
    a[i + 1] = -1;
    dfs_ans(i + 1, j - k);
  }
  if (f[i + 1][j + k]) {
    a[i + 1] = 1;
    dfs_ans(i + 1, j + k);
  }
}
int main(int argc, char const *argv[]) {
  n = read();
  s = read() + fuck;
  f[n][s] = 1;
  for (int i = n; i >= 2; i--) {
    for (int j = 1; j <= fuck << 1; j++) {
      if (f[i][j]) {
        int k = n - i + 1;
        if (j > k)
          f[i - 1][j - k] += f[i][j];
        f[i - 1][j + k] += f[i][j];
      }
    }
  }
  cout << f[1][fuck] << endl;
  dfs_ans(1,fuck);
  return 0;
}