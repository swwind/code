// 最小费用最大流

#include <bits/stdc++.h>
#define N 5020
#define M 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=0;char ch=getchar();
  while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
  while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
  return f?-x:x;
}
namespace MCMF {
  #ifndef inf
  #define inf 707406378
  #endif
  int to[M], nxt[M], head[N], val[M], cst[M];
  int st, ed, cnt = 1, ans;
  void insert(int x, int y, int v, int c) {
    to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = v; cst[cnt] = c;
    to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = 0; cst[cnt] = -c;
  }
  bool vis[N];
  int dis[N], q[M];
  bool spfa() {
    memset(vis, 0, sizeof(bool)*N);
    memset(dis, 127/3, sizeof(int)*N);
    int l = 0, r = 1;
    q[1] = ed; dis[ed] = 0; vis[ed] = 1;
    while(l < r){
      int x = q[++l];
      for(int i = head[x]; i; i = nxt[i])
        if(val[i^1] && dis[to[i]] > dis[x]-cst[i]){
          dis[to[i]] = dis[x]-cst[i];
          if(!vis[to[i]]){
            vis[to[i]] = 1;
            q[++r] = to[i];
          }
        }
      vis[x] = 0;
    }
    return dis[st] != inf;
  }
  int dfs(int x, int f) {
    vis[x] = 1; if(x == ed) return f;
    int used = 0;
    for(int i = head[x]; i; i = nxt[i])
      if(!vis[to[i]] && val[i] && dis[to[i]] == dis[x]-cst[i]){
        int w = dfs(to[i], min(val[i], f-used));
        ans += w*cst[i];
        val[i] -= w; val[i^1] += w;
        used += w; if(used == f) return f;
      }
    return used;
  }
  // return {最大流量, 最小费用}
  pair<int, int> zkw() {
    int res = 0;
    while (spfa() && (vis[ed] = 1)) {
      while (vis[ed]) {
        memset(vis, 0, sizeof(bool)*N);
        res += dfs(st, 1<<30);
      }
    }
    return {res, ans};
  }
};
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), s = read(), t = read();
  MCMF::st = s;
  MCMF::ed = t;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    int w = read(), v = read();
    MCMF::insert(x, y, w, v);
  }
  pair<int, int> res = MCMF::zkw();
  cout << res.first << " " << res.second << endl;
  return 0;
}
