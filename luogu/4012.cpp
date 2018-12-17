#include <bits/stdc++.h>
#define N 100020
#define M 4000001
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
namespace mcmf {
  const int inf = 1e8;
  int to[M], nxt[M], head[N], val[M], cst[M];
  int S, T, cnt = 1, ans;
  void insert(int x, int y, int v, int c) {
    // printf("%d -> %d (%d, %d)\n", x, y, v, c);
    to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = v; cst[cnt] = c;
    to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = 0; cst[cnt] = -c;
  }
  int dis[M], pre[M];
  bool vis[M];
  int ek() {
    int res = 0;
    while (1) {
      queue<int> qu;
      qu.push(S);
      memset(dis, 127, sizeof dis);
      dis[S] = 0;
      while (!qu.empty()) {
        // puts("ass");
        int tt = qu.front();
        qu.pop();
        vis[tt] = 0;
        for (int i = head[tt]; i; i = nxt[i]) {
          if (dis[to[i]] > dis[tt] + cst[i] && val[i]) {
            dis[to[i]] = dis[tt] + cst[i];
            pre[to[i]] = i;
            if (!vis[to[i]]) {
              vis[to[i]] = 1;
              qu.push(to[i]);
            }
          }
        }
      }
      if (dis[T] > 1e7)
        return res;
      int hh = T, sum = 1e9;
      while (pre[hh]) {
        int l = pre[hh];
        sum = min(sum, val[l]);
        hh = to[l ^ 1];
      }
      hh = T;
      while (pre[hh]) {
        int l = pre[hh];
        val[l] -= sum;
        val[l ^ 1] += sum;
        res += sum * cst[l];
        hh = to[l ^ 1];
      }
    }
  }
}
int a, b, n, m;
inline int id(int x, int y) {
  return (x - 1) * m + y;
}
int main(int argc, char const *argv[]) {
  a = read(), b = read();
  n = read() + 1, m = read() + 1;
  mcmf::S = id(n, m) + 1;
  mcmf::T = mcmf::S + 1;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j < m; ++ j) {
      int x = read();
      int fid = id(i, j);
      int tid = fid + 1;
      mcmf::insert(fid, tid, 1, -x);
      mcmf::insert(fid, tid, mcmf::inf, 0);
    }
  }
  for (int j = 1; j <= m; ++ j) {
    for (int i = 1; i < n; ++ i) {
      int x = read();
      int fid = id(i, j);
      int tid = fid + m;
      mcmf::insert(fid, tid, 1, -x);
      mcmf::insert(fid, tid, mcmf::inf, 0);
    }
  }
  for (int i = 1; i <= a; ++ i) {
    int k = read(), x = read(), y = read();
    mcmf::insert(mcmf::S, id(x + 1, y + 1), k, 0);
  }
  for (int i = 1; i <= b; ++ i) {
    int k = read(), x = read(), y = read();
    mcmf::insert(id(x + 1, y + 1), mcmf::T, k, 0);
  }
  auto res = mcmf::ek();
  cout << - res << endl;
  return 0;
}