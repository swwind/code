#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int DEBUG = false;
const int mod = 1000000007;
int head[N], to[N<<1], nxt[N<<1], _cnt;
void add_edge(int x, int y) {
  // printf("%d %d\n", x, y);
  to[++ _cnt] = y; nxt[_cnt] = head[x]; head[x] = _cnt;
  to[++ _cnt] = x; nxt[_cnt] = head[y]; head[y] = _cnt;
}
int cnt[N];
bool vis[N];
void insert(int x, int y) {
  if (!cnt[x] || !cnt[y]) {
    return;
  }
  add_edge(x, y);
}
/**
 * 建立 dfs 树
 */
int q[N], fa[N];
// 非树边
int qx[N], qy[N], qnt;
bool mark[N];
int bfs(int x) {
  int l = 0, r = 0;
  q[++ r] = x;
  fa[x] = 0;
  vis[x] = 1;
  qnt = 0;
  while (l < r) {
    int x = q[++ l];
    for (int i = head[x]; i; i = nxt[i]) {
      if (to[i] == fa[x]) {
        continue;
      }
      if (vis[to[i]]) {
        qx[++ qnt] = to[i];
        qy[qnt] = x;
        mark[to[i]] = 1;
        mark[x] = 1;
        to[i] = 0;
        continue;
      }
      vis[to[i]] = 1;
      fa[to[i]] = x;
      q[++ r] = to[i];
    }
  }
  return r;
}
int f[N][2], pow2[N];
int must[N];
void tree_dp(int x) {
  // if (DEBUG) printf("tree_dp: %d\n", x);
  if (!x) return;
  f[x][0] = 1;
  f[x][1] = pow2[cnt[x]] - 1;
  if (mark[x]) {
    f[x][must[x]^1] = 0;
  }
  for (int i = head[x]; i; i = nxt[i]) {
    if (!cnt[to[i]] || to[i] == fa[x]) {
      continue;
    }
    tree_dp(to[i]);
    f[x][0] = (ll) f[x][0] * (f[to[i]][0] + f[to[i]][1]) % mod;
    f[x][1] = (ll) f[x][1] * f[to[i]][0] % mod;
  }
}
int marked_qs[N];
int dfs(int now, const int max) {
  if (DEBUG) printf("%d %d\n", now, max);
  if (now > max) {
    for (int i = 1; i <= qnt; ++ i) {
      if (must[qx[i]] && must[qy[i]]) {
        return 0;
      }
    }
    int x = q[1];
    tree_dp(x);
    if (DEBUG) printf("> %d\n", x);
    if (DEBUG) printf("* %d\n", f[x][0]);
    if (mark[x]) return f[x][must[x]];
    else return (f[x][0] + f[x][1]) % mod;
  }
  int res = 0;
  must[marked_qs[now]] = 1;
  res = (res + dfs(now + 1, max)) % mod;
  must[marked_qs[now]] = 0;
  res = (res + dfs(now + 1, max)) % mod;
  return res;
}
int resolve(int x) {
  qnt = 0;
  int max = bfs(x), tot = 0;
  for (int i = 1; i <= max; ++ i) {
    if (mark[q[i]]) {
      marked_qs[++ tot] = q[i];
    }
  }
  // if (x == 20068) DEBUG = true;
  int res = dfs(1, tot);
  // if (x == 20068) DEBUG = false;
  // printf("%d\n", res);
  return res;
}
int main(int argc, char const *argv[]) {
  // freopen("C:\\Users\\SW_Wind\\Desktop\\ass\\1.in", "r", stdin);
  int n = read();
  pow2[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    int x = read();
    ++ cnt[x];
    pow2[i] = (pow2[i - 1] << 1) % mod;
  }
  /**
   * 可以先枚举一个n，m
   * 当n，m不同奇偶且gcd(n,m)==1 时 m^2-n^2 与 2*m*n 构成互质勾股数对
   */
  for (long long i = 1; i * i < N; ++ i) {
    for (long long j = i + 1; 2 * i * j < N; j += 2) {
      if (__gcd(i, j) == 1 && j * j - i * i < N) {
        insert(j * j - i * i, 2 * i * j);
      }
    }
  }
  ll ans = 1;
  for (int i = 1; i < N; ++ i) {
    if (cnt[i] && !vis[i]) {
      ans = ans * resolve(i) % mod;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}