#include <bits/stdc++.h>
#define N 500020
#define M 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct node {
  int l, r;
  friend bool operator < (const node &a, const node &b) {
    return a.r - a.l < b.r - b.l;
  }
}a[N];
int b[N<<1], mx[N<<3], sm[N<<3];
void add(int x, int l, int r, int L, int R, int v) {
  // printf("%d %d %d %d %d %d\n", x, l, r, L, R, v);
  if (l == L && r == R) {
    sm[x] += v;
    mx[x] += v;
    return;
  }
  int mid = L + R >> 1;
  if (r <= mid) add(x << 1, l, r, L, mid, v);
  else if (l > mid) add(x<<1|1, l, r, mid + 1, R, v);
  else add(x << 1, l, mid, L, mid, v), add(x<<1|1, mid + 1, r, mid + 1, R, v);
  mx[x] = max(mx[x << 1], mx[x<<1|1]) + sm[x];
}
int main(int argc, char const *argv[]) {
  // printf("%.5lf\n", (sizeof mx)*2./1024/1024);
  int n = read(), m = read(), cnt = 0;
  for (int i = 1; i <= n; i++) {
    b[++ cnt] = a[i].l = read();
    b[++ cnt] = a[i].r = read();
  }
  sort(b + 1, b + cnt + 1);
  cnt = unique(b + 1, b + cnt + 1) - b - 1;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i].l = lower_bound(b + 1, b + cnt + 1, a[i].l) - b;
    a[i].r = lower_bound(b + 1, b + cnt + 1, a[i].r) - b;
  }
  int ans = 1 << 30;
  for (int l = 1, r = 0; l <= n; l++) {
    while (r < n && mx[1] < m) {
      r ++;
      add(1, a[r].l, a[r].r, 1, cnt, 1);
    }
    if (r == n && mx[1] < m) break;
    ans = min(ans, b[a[r].r] - b[a[r].l] - b[a[l].r] + b[a[l].l]);
    add(1, a[l].l, a[l].r, 1, cnt, -1);
  }
  cout << ((ans == 1 << 30) ? -1 : ans) << endl;
  return 0;
}