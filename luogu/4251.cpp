#include <bits/stdc++.h>
#define N 1020
#define M 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[255][255];

int to[M], nxt[M], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

bool vis[N];
int match[N];
bool find(int x) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (!vis[to[i]]) {
      vis[to[i]] = 1;
      if (!match[to[i]] || find(match[to[i]])) {
        match[to[i]] = x;
        return 1;
      }
    }
  }
  return 0;
}

int check(int n, int m, int mid) {
  cnt = 1;
  memset(head, 0, sizeof head);
  memset(match, 0, sizeof match);
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      if (a[i][j] <= mid) {
        insert(i, j + n);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++ i) {
    memset(vis, 0, sizeof vis);
    res += find(i);
  }
  return res;
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  int n = read(), m = read(), k = read();
  int mx = - (1 << 30), mn = 1 << 30;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      a[i][j] = read();
      mx = max(mx, a[i][j]);
      mn = min(mn, a[i][j]);
    }
  }
  int l = mn, r = mx;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(n, m, mid) >= n - k + 1) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", r + 1);
  return 0;
}