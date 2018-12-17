#include <bits/stdc++.h>
#define N 140020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int ls[N], rs[N], val[N];

typedef pair<int, int> prpr;
vector<prpr> f[N];

inline bool cmpx(prpr a, prpr b) {
  return a.first < b.first;
}
inline bool cmpy(prpr a, prpr b) {
  return a.second < b.second;
}

int MID, mn[N<<1];

void work(int x) {
  vector<prpr> &f = ::f[x], &ls = ::f[::ls[x]], &rs = ::f[::rs[x]];

  if (ls.size() > rs.size()) {
    swap(ls, rs);
  }

  sort(ls.begin(), ls.end(), cmpy);
  sort(rs.begin(), rs.end(), cmpx);

  mn[0] = rs[0].second;
  for (size_t i = 1; i < rs.size(); ++ i) {
    mn[i] = min(mn[i - 1], rs[i].second);
  }

  for (size_t i = 0, j = rs.size() - 1; i < ls.size(); ++ i) {
    while (~j && ls[i].second + rs[j].first > MID) -- j;
    if (~j) f.push_back(prpr(ls[i].first, mn[j]));
  }

  sort(ls.begin(), ls.end(), cmpx);
  sort(rs.begin(), rs.end(), cmpy);

  mn[0] = rs[0].first;
  for (size_t i = 1; i < rs.size(); ++ i) {
    mn[i] = min(mn[i - 1], rs[i].first);
  }

  for (size_t i = 0, j = rs.size() - 1; i < ls.size(); ++ i) {
    while (~j && ls[i].first + rs[j].second > MID) -- j;
    if (~j) f.push_back(prpr(mn[j], ls[i].second));
  }

}

void dfs(int x) {
  f[x].clear();
  if (!ls[x]) {
    f[x].push_back(prpr(0, 0));
    return;
  }

  dfs(ls[x]);
  dfs(rs[x]);

  for (prpr &pr : f[ls[x]]) {
    pr.first += val[ls[x]];
    pr.second += val[ls[x]];
  }
  for (prpr &pr : f[rs[x]]) {
    pr.first += val[rs[x]];
    pr.second += val[rs[x]];
  }

  work(x);
}

int main(int argc, char const *argv[]) {
  
  int n = read();
  for (int i = 2; i <= n; ++ i) {
    int f = read();
    val[i] = read();
    if (ls[f]) rs[f] = i;
    else ls[f] = i;
  }

  int l = 0, r = 1e9;

  while (l <= r) {
    MID = (l + r) >> 1;
    dfs(1);
    // printf("%d %d\n", MID, f[1].empty());
    if (!f[1].empty()) {
      r = MID - 1;
    } else {
      l = MID + 1;
    }
  }

  printf("%d\n", r + 1);

  return 0;
}
/*

二分答案，判断是否有解即可。

f[x] 为以 x 为根的子树中，可能的 (入边长度, 出边长度) 总集。

转移的时候只需要枚举左右儿子的集合，合并的时候判断是否超过二分的长度即可。

我们发现，如果入边长度相同，我们只需要最小的出边长度。
同样如果出边长度相同，我们只需要最小的入边长度。

这样就能保证根节点的方案数不会超过 2n 了。

复杂度 O(nlog^2n)

*/