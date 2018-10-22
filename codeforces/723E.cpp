#include <bits/stdc++.h>
#define N 205
#define M 160020
using namespace std;

inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int to[M], nxt[M], head[N], vis[M], cnt;
int inq[M];

void insert(int x, int y) {
  ++ inq[x]; ++ inq[y];
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

void dfs(int x) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (vis[i]) continue;
    if (x && to[i]) printf("%d %d\n", x, to[i]);
    vis[i] = vis[i ^ 1] = true;
    dfs(to[i]);
  }
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int T = read();

  while (T --) {
    int n = read(), m = read();

    memset(head, 0, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(inq, 0, sizeof inq);
    cnt = 1;

    for (int i = 1; i <= m; ++ i) {
      int x = read(), y = read();
      insert(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
      if (inq[i] % 2) {
        insert(0, i);
      } else {
        ++ ans;
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i <= n; ++ i) {
      dfs(i);
    }

  }
  return 0;
}