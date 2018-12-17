// 二维 kdtree - 可加点，询问最近

#include <bits/stdc++.h>
#define N 300020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int n, m, szb;
const int inf = 1 << 30;
struct node {
  int l, r, mn[2], mx[2], d[2];
  int& operator [] (const int a) {
    return d[a];
  }
  friend bool operator < (const node &a, const node &b) {
    return a.d[szb] < b.d[szb];
  }
}p[N];
int dis(node a, node b) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
// struct kdtree {
  int rt, ans;
  node t[N << 1], _;
  void update(int x) {
    int l = t[x].l, r = t[x].r;
    if (l) {
      t[x].mn[0] = min(t[x].mn[0], t[l].mn[0]);
      t[x].mn[1] = min(t[x].mn[1], t[l].mn[1]);
      t[x].mx[0] = max(t[x].mx[0], t[l].mx[0]);
      t[x].mx[1] = max(t[x].mx[1], t[l].mx[1]);
    }
    if (r) {
      t[x].mn[0] = min(t[x].mn[0], t[r].mn[0]);
      t[x].mn[1] = min(t[x].mn[1], t[r].mn[1]);
      t[x].mx[0] = max(t[x].mx[0], t[r].mx[0]);
      t[x].mx[1] = max(t[x].mx[1], t[r].mx[1]);
    }
  }
  int build(int l, int r, int now) {
    szb = now;
    int mid = (l + r) >> 1;
    nth_element(p + l, p + mid, p + r + 1);
    t[mid][0] = t[mid].mn[0] = t[mid].mx[0] = p[mid][0];
    t[mid][1] = t[mid].mn[1] = t[mid].mx[1] = p[mid][1];
    if (l < mid) t[mid].l = build(l, mid - 1, now ^ 1);
    if (mid < r) t[mid].r = build(mid + 1, r, now ^ 1);
    update(mid);
    return mid;
  }
  void init(int n) {
    rt = build(1, n, 0);
  }
  int dist(node a) {
    return
      max(_[0] - a.mx[0], 0) + max(a.mn[0] - _[0], 0)+
      max(_[1] - a.mx[1], 0) + max(a.mn[1] - _[1], 0);
  }
  void askmn(int x) {
    ans = min(ans, dis(t[x], _));
    int l = t[x].l, r = t[x].r;
    int dl = l ? dist(t[l]) : inf;
    int dr = r ? dist(t[r]) : inf;
    if (dl < dr) {
      if (dl < ans) askmn(l);
      if (dr < ans) askmn(r);
    } else {
      if (dr < ans) askmn(r);
      if (dl < ans) askmn(l);
    }
  }
  int ask(int x, int y) {
    _[0] = x; _[1] = y;
    ans = inf;
    askmn(rt);
    return ans;
  }
  void insert(int x, int now) {
    if (_[now] > t[x][now]) { // add to right
      if (t[x].r) {
        insert(t[x].r, now ^ 1);
      } else {
        t[x].r = ++ n;
        t[n][0] = t[n].mn[0] = t[n].mx[0] = _[0];
        t[n][1] = t[n].mn[1] = t[n].mx[1] = _[1];
      }
    } else { // add to left
      if (t[x].l) {
        insert(t[x].l, now ^ 1);
      } else {
        t[x].l = ++ n;
        t[n][0] = t[n].mn[0] = t[n].mx[0] = _[0];
        t[n][1] = t[n].mn[1] = t[n].mx[1] = _[1];
      }
    }
    update(x);
  }
  void add(int x, int y) {
    _[0] = x; _[1] = y;
    insert(rt, 0);
  }
// }kdt;
int main(int argc, char const *argv[]) {
  n = read(); m = read();
  for (int i = 1; i <= n; i++)
    p[i][0] = read(), p[i][1] = read();
  init(n);
  for (int i = 1; i <= m; i++) {
    int op = read(), x = read(), y = read();
    if (op == 1) {
      add(x, y);
    } else {
      printf("%d\n", ask(x, y));
    }
  }
  return 0;
}