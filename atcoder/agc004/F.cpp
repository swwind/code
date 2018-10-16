#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,s=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(s=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return s?x:-x;
}

int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

// 计算深度
bool dep[N];
void dfs_deep(int x, int fa, bool d) {
  dep[x] = d;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs_deep(to[i], x, d ^ 1);
  }
}

// 根据 f[i] 求 s[i]
int s[N], tx, ty, f[N];
int resolve(int x, int fa) {
  s[x] = f[x];
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    s[x] += resolve(to[i], x);
  }
  return s[x];
}

// 计算 k[i]
int k[N];
int dfs(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    k[x] += dfs(to[i], x);
  }
  return k[x];
}

int fa[N];
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
  fa[find(x)] = find(y);
}

int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; ++ i) {
    int x = read(), y = read();
    if (find(x) == find(y)) {
      tx = x; ty = y;
    } else {
      insert(x, y);
      merge(x, y);
    }
  }
  dfs_deep(1, 0, 0);
  int sum = 0;
  for (int i = 1; i <= n; ++ i) {
    f[i] = dep[i] ? 1 : -1;
    sum += f[i];
  }
  if (m == n - 1) {

    if (sum) {
      puts("-1");
    } else {
      resolve(1, 0);
      int ans = 0;
      for (int i = 1; i <= n; ++ i) {
        ans += abs(s[i]);
      }
      printf("%d\n", ans);
    }

  } else {

    if (dep[tx] == dep[ty]) {

      if (abs(sum) & 1) {
        puts("-1");
      } else {
        f[tx] -= sum / 2;
        f[ty] -= sum / 2;
        int ans = abs(sum) / 2;
        resolve(1, 0);
        for (int i = 1; i <= n; ++ i) {
          ans += abs(s[i]);
        }
        printf("%d\n", ans);
      }

    } else {

      if (sum) {
        puts("-1");
      } else {
        resolve(1, 0);
        k[tx] =  1;
        k[ty] = -1;
        dfs(1, 0);
        vector<int> vec;
        for (int i = 1; i <= n; ++ i) {
          if (k[i]) {
            vec.push_back(- k[i] * s[i]);
          }
        }
        sort(vec.begin(), vec.end());
        int mid = vec[vec.size() / 2];
        int ans = abs(mid);
        for (int i = 1; i <= n; ++ i) {
          ans += abs(k[i] * mid + s[i]);
        }
        printf("%d\n", ans);
      }
    }

  }
  return 0;
}
/*

恶魔妈妈摸妹妹。。。

我们不妨设深度为奇数的点是一个空位，而深度为偶数的点有一个硬币，一次操作相当于将一个硬币移到相邻的空位。
硬币数不等于空位数即为无解。
于是将每个点按深度的奇偶分开，设奇数为 1，偶数为 -1，令 s[x] 为以 x 为根的子树的权值和。
\sigma_{i=1}^{n}\abs{s[i]} 即为答案。

对于环套树（n 个点 n 条边），需要判断加边所在环的奇偶性。

1)

如果是奇环，我们先随便断掉环上的一条边(u,v)。
显然u和v在二分图的同一侧，那么操作(u,v)这条边会使得u和v同时增加一个硬币或同时减少一个硬币。

那么只要求出缺少/多了多少个硬币，用u和v均摊即可。
显然若缺少的硬币数量为奇数则无解。

2)

若环为偶环，同样随便断掉环上的一条边(u,v)。
显然u和v在二分图的不同侧，设(u,v)这条边被操作了x次，就是要在u上加x个硬币，v上减x个硬币。
设 k[i] 表示 i 子树中 x 的系数，显然只能是 1, 0, -1。
那么答案就是 \abs{x}+\sum_{i=1}^{n}\abs{k[i]*x+s[i]}。
可以看成数轴上有很多个点，现在要找一个点使得所有点到该点的距离和最小。
显然取中位数最优。


注意三种情况都要判 -1。


99% 抄自 CSDN（除了最后一句话）

*/