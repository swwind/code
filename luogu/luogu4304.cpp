#include <bits/stdc++.h>
#define N 220
#define M 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int to[M<<1], nxt[M<<1], head[N*N], val[M<<1], dep[N*N], cnt = 1, st, ed, q[N*N];
void insert(int x, int y, int z) {
  to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
  to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = 0; head[y] = cnt;
}
int bfs() {
  memset(dep, 0, sizeof dep);
  int l = 0, r = 1; q[1] = st; dep[st] = 1;
  while (l < r){
    int x = q[++l];
    for (int i = head[x]; i; i = nxt[i])
      if (val[i] && !dep[to[i]]){
        q[++r] = to[i];
        dep[to[i]] = dep[x]+1;
      }
  }
  return dep[ed];
}
int dfs(int x, int f) {
  if (x == ed) return f;
  int sum = 0;
  for (int i = head[x]; i; i = nxt[i]){
    if (val[i] && dep[to[i]] == dep[x]+1){
      int w = dfs(to[i], min(f-sum, val[i]));
      val[i] -= w; val[i^1] += w;
      sum += w; if(sum == f) return f;
    }
  }
  if (!sum) dep[x] = 0;
  return sum;
}
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int mp[210][210];
int n;
inline int calc(int x, int y) {
  return (x - 1) * n + y;
}
int main(int argc, char const *argv[]) {
  n = read();
  st = n * n + 1, ed = st + 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%1d", &mp[i][j]);
      if ((i + j) & 1) insert(st, calc(i, j), 1);
      else             insert(calc(i, j), ed, 1);
      ans += !mp[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!mp[i][j] && (i + j) & 1) {
        for (int k = 0; k < 8; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x > n || y > n || x < 1 || y < 1)
            continue;
          if (mp[x][y])
            continue;
          insert(calc(i, j), calc(x, y), 1);
        }
      }
    }
  }
  while (bfs())
    ans -= dfs(st, 1 << 30);
  printf("%d\n", ans);
  return 0;
}