#include <bits/stdc++.h>
#define N 400020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct person {
  int st, ed, id;
  friend bool operator < (const person &a, const person &b) {
    return a.st < b.st;
  }
} a[N];
int find(int x, int l, int r) {
  int ans = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (a[mid].st <= x) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  return ans;
}
int ans[N], f[N][31];
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), _n = n;
  for (int i = 1; i <= n; ++ i) {
    a[i].st = read();
    a[i].ed = read();
    a[i].id = i;
    if (a[i].ed < a[i].st) {
      a[i].ed += m;
    } else {
      a[++ _n].st = a[i].st + m;
      a[   _n].ed = a[i].ed + m;
    }
  }
  sort(a + 1, a + _n + 1);
  a[_n + 1].ed = 2e9;
  for (int i = 1; i <= _n + 1; ++ i) {
    for (int j = 0; j <= 30; ++ j) {
      f[i][j] = _n + 1;
    }
  }
  for (int i = 1; i <= _n; ++ i) {
    f[i][0] = find(a[i].ed, i + 1, _n + 1);
  }
  for (int i = 1; i <= 30; ++ i) {
    for (int j = 1; j <= _n; ++ j) {
      f[j][i] = f[f[j][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= _n; ++ i) {
    if (a[i].id && !ans[a[i].id]) {
      int now = i, to = a[i].st + m;
      for (int j = 30; ~j; -- j) {
        if (a[f[now][j]].ed < to) {
          now = f[now][j];
          ans[a[i].id] += 1 << j;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++ i) {
    printf("%d ", ans[i] + 2);
  }
  return 0;
}
