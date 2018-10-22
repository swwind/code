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

struct data {
  int l, r, sz, rt, val;
} tr[N];
int top;

namespace __leftist_tree {

int npl[N], ch[N][2], val[N];

int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (val[x] < val[y]) swap(x, y);
  ch[x][1] = merge(y, ch[x][1]);
  if (npl[ch[x][1]] > npl[ch[x][0]]) {
    swap(ch[x][0], ch[x][1]);
  }
  npl[x] = npl[ch[x][1]] + 1;
  return x;
}

int erase(int x) {
  return merge(ch[x][0], ch[x][1]);
}

} // namespace __leftist_tree

using namespace __leftist_tree;

int main(int argc, char const *argv[]) {
# ifndef ONLINE_JUDGE
  freopen("../tmp/.in", "r", stdin);
# endif

  int n = read();
  for (int i = 1; i <= n; ++ i) {
    val[i] = read() - i;
  }

  tr[top = 1] = (data) { 1, 1, 1, 1, val[1] };

  for (int i = 2; i <= n; ++ i) {
    tr[++ top] = (data) { i, i, 1, i, val[i] };
    while (top > 1 && tr[top - 1].val > tr[top].val) {
      -- top;
      tr[top].rt = merge(tr[top].rt, tr[top + 1].rt);
      tr[top].sz += tr[top + 1].sz;
      tr[top].r = tr[top + 1].r;
      while (tr[top].sz > (tr[top].r - tr[top].l + 2) / 2) {
        -- tr[top].sz;
        tr[top].rt = erase(tr[top].rt);
      }
      tr[top].val = val[tr[top].rt];
    }
  }

  long long ans = 0;

  for (int i = 1, j = 1; i <= n; ++ i) {
    if (i > tr[j].r) ++ j;
    ans += llabs(tr[j].val - val[i]);
  }

  printf("%lld\n", ans);
  for (int i = 1, j = 1; i <= n; ++ i) {
    if (i > tr[j].r) ++ j;
    printf("%d%c", tr[j].val + i, " \n"[i == n]);
  }

  return 0;
}