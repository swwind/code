#include <bits/stdc++.h>
#define N 25
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
double x[N], a[2][N], b[2][N], ans = 1e60;
int n, c[N];
void dfs(int x) {
  if (x == n + 1) {
    ans = min(ans, calc());
    return;
  }
  c[x] = 0;
  dfs(x + 1);
  c[x] = 1;
  dfs(x + 1);
}
int main(int argc, char const *argv[]) {
  n = read();
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> a[0][i] >> b[0][i] >> a[1][i] >> b[1][i];
  dfs(1);
  return 0;
}