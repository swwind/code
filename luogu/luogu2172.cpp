#include <bits/stdc++.h>
#define N 100020
#define M 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char str[N];
int n, m, r, c;
inline int id(int x, int y) {
  return (x - 1) * m + y;
}
int to[M<<1], nxt[M<<1], head[N], val[M<<1], dep[N], cnt = 1, st, ed, q[N];
void insert(int x, int y, int z) {
  // printf("%d --> %d\n", x, y);
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
bool mp[55][55];
int out[N];
bool link(int x, int y, int id) {
  if (x < 1 || x > n) return false;
  if (y < 1 || y > m) return false;
  if (!mp[x][y]) return false;
  insert(::id(x, y), id + n * m, 1);
  return true;
}
int main(int argc, char const *argv[]) {
  n = read(); m = read();
  r = read(); c = read();
  st = n * m * 2 + 1; ed = st + 1;
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; ++ j) {
      mp[i][j] = str[j] == '.';
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      if (!mp[i][j]) continue;
      ans ++;
      int _id = id(i, j);
      link(i + r, j - c, _id);
      link(i + r, j + c, _id);
      link(i + c, j - r, _id);
      link(i + c, j + r, _id);
      insert(st, _id, 1);
      insert(_id + n * m, ed, 1);
      // insert(id(i, j), id(i, j) + n * m, 1);
    }
  }
  while (bfs()) {
    ans -= dfs(st, 1 << 30);
  }
  printf("%d\n", ans);
  return 0;
}