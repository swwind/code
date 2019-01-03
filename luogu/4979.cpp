#include <bits/stdc++.h>
#define N 500020
#define mod 998244353
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N];
int status[N<<2], tg[N<<2];
void push_down(int x) {
  int ls = x << 1, rs = x << 1 | 1;
  if (tg[x]) {
    status[ls] = status[rs] = status[x];
    tg[ls] = tg[rs] = true;
    tg[x] = false;
  }
}
void push_up(int x) {
  int ls = x << 1, rs = x << 1 | 1;
  status[x] = status[ls] | status[rs];
}
void build(int x, int l, int r) {
  if (l == r) {
    status[x] = (1 << a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  push_up(x);
}
void update(int x, int l, int r, int L, int R, int v) {
  if (l == L && r == R) {
    status[x] = (1 << v);
    tg[x] = true;
    return;
  }
  push_down(x);
  int mid = (L + R) >> 1;
  if (r <= mid) update(x << 1, l, r, L, mid, v);
  else if (l > mid) update(x << 1 | 1, l, r, mid + 1, R, v);
  else update(x << 1, l, mid, L, mid, v), update(x << 1 | 1, mid + 1, r, mid + 1, R, v);
  push_up(x);
}
int query(int x, int k, int l, int r) {
  if (l == r) return status[x];
  push_down(x);
  int mid = (l + r) >> 1;
  if (k <= mid) return query(x << 1, k, l, mid);
  else return query(x << 1 | 1, k, mid + 1, r);
}
int query(int x, int l, int r, int L, int R) {
  if (l == L && r == R) return status[x];
  push_down(x);
  int mid = (L + R) >> 1;
  if (r <= mid) return query(x << 1, l, r, L, mid);
  if (l > mid) return query(x << 1 | 1, l, r, mid + 1, R);
  return query(x << 1, l, mid, L, mid) | query(x << 1 | 1, mid + 1, r, mid + 1, R);
}

char str[N];

int main(int argc, char const *argv[]) {

  int n = read();

  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++ i) {
    a[i] = str[i] - 'A';
  }
  build(1, 1, n);

  int m = read();
  while (m --) {
    scanf("%s", str);
    int x = read(), y = read();
    if (str[0] == 'A') {
      scanf("%s", str);
      update(1, x, y, 1, n, str[0] - 'A');
    } else {
      int res = query(1, x, y, 1, n);
      bool check = true;
      if (x > 1 && y < n) {
        int ls = query(1, x - 1, 1, n);
        int rs = query(1, y + 1, 1, n);
        check = ls != rs;
      }
      // printf("%d %d %d\n", res, ls, rs);
      puts(__builtin_popcount(res) == 1 && check ? "Yes" : "No");
    }
  }

  return 0;
}
