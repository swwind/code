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
int nxt[N<<1], head[N], to[N<<1], cnt, val[N<<1];
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = w;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = w;
}
int ans, dp[N][3];
void dfs(int x, int f) {
  dp[x][0] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    int y = to[i], w = val[i];
    dfs(y, x);
    for (int j = 0; j < 3; j++)
      ans += dp[x][j] * dp[y][(6 - w - j) % 3];
    for (int j = 0; j < 3; j++)
      dp[x][(j + w)%3] += dp[y][j];
  }
}
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    insert(x, y, read() % 3);
  }
  dfs(1, 0);
  ans = ans * 2 + n;
  int ed = n * n;
  int g = gcd(ans, ed);
  printf("%d/%d\n", ans / g, ed / g);
  return 0;
}