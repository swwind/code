#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int _fa[N], sz[N];
int find(int x) {
  return x == _fa[x] ? x : _fa[x] = find(_fa[x]);
}
int fa[N][20];
int val[N];
int climb(int x, int mx) {
  for (int i = 19; ~i; -- i) {
    if (fa[x][i] && val[fa[x][i]] <= mx) {
      x = fa[x][i];
    }
  }
  return x;
}

int check(int x, int y, int mx) {
  int tx = climb(x, mx);
  int ty = climb(y, mx);
  if (tx == ty) return sz[tx];
  else return sz[tx] + sz[ty];
}

int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    _fa[i] = i;
    sz[i] = 1;
  }
  int tot = n;
  for (int i = 1; i <= m; ++ i) {
    int x = read(), y = read();
    int fx = find(x), fy = find(y);
    if (fx == fy) continue;
    _fa[fx] = _fa[fy] = fa[fx][0] = fa[fy][0] = ++ tot;
    sz[tot] = sz[fx] + sz[fy];
    val[tot] = i;
    _fa[tot] = tot;
  }
  for (int i = 1; i < 20; ++ i) {
    for (int j = 1; j <= tot; ++ j) {
      fa[j][i] = fa[fa[j][i - 1]][i - 1];
    }
  }
  int q = read();
  while (q --) {
    int x = read(), y = read(), z = read();
    int l = 1, r = m;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(x, y, mid) >= z) r = mid - 1;
      else l = mid + 1;
    }
    printf("%d\n", r + 1);
  }
  return 0;
}
/*
显然可以将非最小生成树边删去。

剩下的每条边建一个点，向它合并的两个集合的 father 连边，记录 size 大小。

样例如此连边形成的树：
（每个叶子节点为点编号，其余为边编号）

      (5)
    _/   \__
  (3)       \
 /   \_      \_
 |    (1)     (2)
 |   /   \   /   \
[1] [2] [3] [4] [5]

发现边编号大小与深度大小有关系。
于是可以用倍增直接跳。

每次询问二分最大的边编号，利用倍增跳到最高点，该点 size 大小即为可以到达的联通块的大小。

复杂度 O(nlog^2n)

*/