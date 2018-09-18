#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int ins[N];
int p[N], q[N];
int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  printf("%d(%d) --> %d(%d)\n", x, q[x], y, q[y]);
  ++ ins[x];
  to[++ cnt] = x;
  nxt[cnt] = head[y];
  head[y] = cnt;
}

// 单点加，查询区间max
namespace sgt {
  int mx[N<<2];
  void update(int x, int k, int L, int R, int v) {
    if (L == R) {
      mx[x] = max(mx[x], v);
      return;
    }
    int mid = L + R >> 1;
    if (k <= mid) update(x << 1, k, L, mid, v);
    else update(x<<1|1, k, mid + 1, R, v);
    mx[x] = max(mx[x << 1], mx[x<<1|1]);
  }
  int query(int x, int l, int r, int L, int R) {
    if (l > r) return 0;
    if (l == L && r == R)
      return mx[x];
    int mid = L + R >> 1;
    if (r <= mid) return query(x << 1, l, r, L, mid);
    else if (l > mid) return query(x<<1|1, l, r, mid + 1, R);
    return max(query(x << 1, l, mid, L, mid), query(x<<1|1, mid + 1, r, mid + 1, R));
  }
}

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> que;

int main(int argc, char const *argv[]) {
  int n = read(), k = read();
  for (int i = 1; i <= n; ++ i) {
    q[p[i] = read()] = i;
  }
  for (int i = 1; i <= n; ++ i) {
    printf("%d ", q[i]);
  } puts("");
  for (int i = 1; i <= n; ++ i) {
    int ql = max(1, q[i] - k + 1);
    int qr = min(n, q[i] + k - 1);
    int mn = sgt::query(1, ql, qr, 1, n);
    if (mn) {
      insert(i, mn);
    }
    sgt::update(1, q[i], 1, n, i);
  }
  for (int i = 1; i <= n; ++ i) {
    if (!ins[i]) {
      que.push({ q[i], i });
    }
  }
  vector<int> res;
  while (!que.empty()) {
    int x = que.top().second;
    que.pop();
    for (int i = head[x]; i; i = nxt[i]) {
      if (!-- ins[to[i]]) {
        que.push({ q[to[i]], to[i] });
      }
    }
    res.push_back(x);
  }
  for (int i = 0; i < n; ++ i) {
    printf("%d\n", q[res[i]]);
  } puts("====");
  for (size_t i = 0; i < res.size(); ++ i) {
    p[q[res[i]]] = i + 1;
  }
  for (int i = 1; i <= n; ++ i) {
    printf("%d\n", p[i]);
  }
  return 0;
}
/*
先求原序列的逆序q（q[p[i]]=i）

发现原序列中的操作在逆序中即为交换两个相邻的差值>=k的元素。

不难发现逆序中的最小字典序即为原序列的最小字典序。（猜的

发现所有差值<k的元素的相对位置不会发生变化。

例如第 3 个样例，逆序为

6 7 5 1 2 8 3 4
+
^-+
^-^-+
      +
      ^-+
^-^-------+
    ^-^-^---+
^---^---^---^-+

（图为每个点不能越过的元素的限制）

直接求拓扑序即可。

但是直接做是 n^2 的，于是只要将每个点与前面最后一个限制连线即可。

6 7 5 1 2 8 3 4
+
^-+
  ^-+
      +
      ^-+
  ^-------+
    ^-------+
^-------------+

总复杂度 O(nlogn)
*/