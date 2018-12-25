#include <bits/stdc++.h>
#define N 50020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

struct line {
  int k, b, id;
} ls[N], st[N];
struct point {
  double x, y;
  point() { }
  point(double x, double y)
    :x(x), y(y) { }
};
inline bool cmp(const line &a, const line &b) {
  return a.k == b.k ? a.b < b.b : a.k < b.k;
}

inline point intersect(const line &a, const line &b) {
  double x = 1.0 * (b.b - a.b) / (a.k - b.k);
  double y = a.k * x + a.b;
  return point(x, y);
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int n = read(), top = 0;
  for (int i = 1; i <= n; ++ i) {
    ls[i].k = read();
    ls[i].b = read();
    ls[i].id = i;
  }

  sort(ls + 1, ls + n + 1, cmp);
  for (int i = 1; i <= n; ++ i) {
    while (top && ls[i].k == st[top].k) {
      -- top;
    }
    while (top > 1 && intersect(ls[i], st[top]).x <= intersect(st[top], st[top - 1]).x) {
      -- top;
    }
    st[++ top] = ls[i];
  }
  vector<int> ans;
  for (int i = 1; i <= top; ++ i) {
    ans.push_back(st[i].id);
  }
  sort(ans.begin(), ans.end());
  for (int i = 1; i <= top; ++ i) {
    printf("%d%c", ans[i - 1], i == top ? '\n' : ' ');
  }
  return 0;
}