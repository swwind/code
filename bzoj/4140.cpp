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
struct node {
  double x, y;
  friend bool operator < (const node &a, const node &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  }
  friend double operator * (const node &a, const node &b) {
    return a.x * b.y - a.y * b.x;
  }
  friend node operator - (const node &a, const node &b) {
    return (node) {a.x - b.x, a.y - b.y};
  }
}a[N],q[N];
int top, l[N], r[N], cnt;
int find(int l, int r, double k) {
  int h = l;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (m == h || k > (q[m].y - q[m-1].y) / (q[m].x - q[m-1].x))
      l = m + 1;
    else
      r = m - 1;
  }
  return l - 1;
}
bool query(double x, double y) {
  if (!top) return 0;
  double k = -x/y, b = (x*x+y*y)/(2*y);
  for (int i = 1; i <= top; i++) {
    int m = find(l[i], r[i], k);
    if (q[m].x * k + b > q[m].y)
      return false;
  }
  return true;
}
void insert(double x, double y) {
  a[++ cnt] = (node) {x, y};
  l[++ top] = cnt;
  while (top > 1 && cnt - l[top] + 1 == l[top] - l[top - 1])
    -- top;
  sort(a + l[top], a + cnt + 1);
  int nw = l[top]; q[nw] = a[nw];
  for (int i = l[top] + 1; i <= cnt; ++ i) {
    while (nw > l[top] && (q[nw] - q[nw-1]) * (a[i] - q[nw-1]) <= 0)
      -- nw;
    q[++ nw] = a[i];
  }
  r[top] = nw;
}
int main(int argc, char const *argv[]) {
  int n = read(), ans = 0;
  while (n --) {
    int op = read();
    double x, y;
    scanf("%lf%lf", &x, &y);
    x += ans, y += ans;
    if (!op) insert(x, y);
    else puts(query(x, y) ? ++ ans, "Yes" : "No");
  }
  return 0;
}