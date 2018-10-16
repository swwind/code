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
int to[N<<1], nxt[N<<1], val[N<<1], head[N], cnt;
void insert(int x, int y, int w) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = w;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = - w;
}

int vis[N], col[N], failed;
int points, edges, a[3];

inline int mod3(int x) {
  return (x + 3) % 3;
}

int dfs(int x) {
  a[col[x]] ++;
  vis[x] = 1; points ++;
  for (int i = head[x]; i; i = nxt[i]) {
    edges += val[i] == 1;
  }
  for (int i = head[x]; i; i = nxt[i]) {
    if (!vis[to[i]]) {
      col[to[i]] = mod3(col[x] + val[i]);
      dfs(to[i]);
    } else if (col[to[i]] != mod3(col[x] + val[i])) {
      failed = true;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  int n = read(), m = read();

  for (int i = 1; i <= m; ++ i) {
    int x = read(), y = read();
    insert(x, y, 1);
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    if (vis[i]) {
      continue;
    }
    failed = false;
    edges = points = 0;
    memset(a, 0, sizeof a);
    dfs(i);
    if (failed) {
      ans += (ll) points * points;
    } else if (a[0] && a[1] && a[2]) {
      ans += (ll) a[0] * a[1] + (ll) a[1] * a[2] + (ll) a[2] * a[0];
    } else {
      ans += edges;
    }
  }

  printf("%lld\n", ans);

  return 0;
}

/*

FROM CSDN:

  不妨把黑格子 (x, y) 看成一条有向边，那么就变成了一个图上的问题。
  对于每一个弱连通块进行三染色，然后分三种情况讨论：

    若三种颜色中只出现了两种或以下，则不会增加新的边。
    若三种颜色都存在且染色成功，则每种颜色的点都可以向它的下一种颜色的点连边。
    若三种颜色都不存在且染色失败，则任意点两两之间都有连边，包括自环。

  证明不存在的，反正结论题。。。

*/