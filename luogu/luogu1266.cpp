#include <bits/stdc++.h>
#define N 200
#define M 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int n, m, ed;
int head[N], to[M<<1], nxt[M<<1], cnt, val[M<<1];
double len[M<<1];
void insert(int x, int y, int v, int l) {
  to[++ cnt] = y; nxt[cnt] = head[x];
  head[x] = cnt; val[cnt] = v; len[cnt] = l;
}
template <class T, class A, class K>
struct tree {
  T first;
  A second;
  K third;
};
double dis[N][N]; // 当前为 j, 之前为 i 的最短时间
queue<tree<int, int, int>> q;
int ans[N][N];
bool flag[N][N];
int ass[N], top;
int main(int argc, char const *argv[]) {
  n = read(); m = read(); ed = read() + 1;
  for (int i = 1; i <= m; i++) {
    int x = read() + 1, y = read() + 1;
    int v = read(), l = read();
    insert(x, y, v, l);
    // 冷静
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dis[i][j] = 1e60;
  dis[1][1] = 0;
  q.push({n + 1, 1, 70});
  while (!q.empty()) {
    auto fx = q.front(); q.pop();
    int f = fx.first;
    int x = fx.second;
    flag[f][x] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
      int v = val[i] ? val[i] : fx.third;
      if (dis[f][x] + len[i] / v < dis[x][to[i]]) {
        dis[x][to[i]] = dis[f][x] + len[i] / v;
        ans[x][to[i]] = f;
        if (!flag[x][to[i]]) {
          q.push({x, to[i], v});
          flag[x][to[i]] = 1;
        }
      }
    }
  }
  int res = 1;
  for (int i = 2; i <= n; i++)
    if (dis[i][ed] < dis[res][ed]) res = i;
  ass[++ top] = ed; ass[++ top] = res;
  while (ass[top]) {
    ++ top;
    ass[top] = ans[ass[top - 1]][ass[top - 2]];
  }
  top -= 2;
  while (top)
    printf("%d ", ass[top --] - 1);
  return 0;
}