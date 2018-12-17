#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

struct node {
  int l, r, v;
  friend bool operator != (const node &a, const node &b) {
    return a.l != b.l || a.r != b.r;
  }
} a[N], b[N];

int f[N];

int findx(int l, int r, int val) {
  while (l <= r) {
    int mid = l + r >> 1;
    if (a[mid].r < val)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return r;
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);
  int n = read(); int fuck_n = n;

  for (int i = 1; i <= n; ++ i) {
    a[i].l = read() + 1;
    a[i].r = n - read();
  }

  sort(a + 1, a + n + 1, [&](const node &a, const node &b) {
    return a.l == b.l ? a.r < b.r : a.l < b.l;
  });

  int m = 0;
  for (int i = 1; i <= n; ++ i) {
    if (a[i].l <= a[i].r) {
      b[++ m] = a[i];
    }
  }

  n = 0;
  for (int i = 1; i <= m; ++ i) {
    if (i == 1 || b[i] != b[i - 1]) {
      a[++ n] = b[i], a[n].v = 1;
    } else if (a[n].v < a[n].r - a[n].l + 1) {
      ++ a[n].v;
    }
  }

  sort(a + 1, a + n + 1, [&] (const node &a, const node &b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
  });

  f[1] = a[1].v;
  for (int i = 2; i <= n; ++ i) {
    int nxt = findx(1, i - 1, a[i].l);
    f[i] = max(f[i - 1], f[nxt] + a[i].v);
  }

  printf("%d\n", fuck_n - f[n]);

  return 0;
}
