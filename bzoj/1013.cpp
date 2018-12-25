#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
double p[12][12], a[12][12];
bool gauss(int n) {
  for (int i = 1; i <= n; i++){
    int mxr = i;
    for (int j = i + 1; j <= n; j++)
      if (fabs(a[j][i]) > fabs(a[mxr][i]))
        mxr = j;
    std::swap(a[mxr], a[i]);
    if (a[i][i] == 0) return false;
    for (int j = i + 1; j <= n + 1; j++)
      a[i][j] /= a[i][i];
    for (int k = i == 1 ? 2 : 1; k <= n; ++ k == i && ++ k)
      for (int j = i + 1; j <= n + 1; j++)
        a[k][j] -= a[k][i] * a[i][j];
  }
  return true;
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read();
  for (int i = 1; i <= n + 1; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      scanf("%lf", &p[i][j]);
    }
  }
  for (int i = 1; i <= n; ++ i) {
    for (int k = 1; k <= n; ++ k) {
      a[i][k] = 2 * (p[i][k] - p[n + 1][k]);
      a[i][n + 1] += p[i][k] * p[i][k] - p[n + 1][k] * p[n + 1][k];
    }
  }
  gauss(n);
  for (int i = 1; i <= n; ++ i) {
    printf("%.3lf%c", a[i][n + 1], i == n ? '\n' : ' ');
  }
  return 0;
}