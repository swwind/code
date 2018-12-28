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

int a[N], s[N];
int n, m;
bool check(int mid) {
  int tot = 0, now = 0;
  for (int i = 1; i <= n; ++ i) {
    now += a[i];
    if (now > mid) {
      ++ tot;
      now = a[i];
    }
    if (now > mid) {
      return 0;
    }
  }
  return tot + 1 <= m;
}
int f[2][N];
int solve(int mx) {
  int now = 0, pre = 1;
  f[now][0] = 1;
  int ans = 0;
  for (int i = 1; i <= m + 1; ++ i) {
    swap(now, pre);
    for (int j = 1; j <= n; ++ j) {
      f[pre][j] += f[pre][j - 1];
    }
    f[now][0] = 0;
    for (int j = i, k = 0; j <= n; ++ j) {
      while (s[j] - s[k] > mx) ++ k;
      f[now][j] = f[pre][j - 1] - (k ? f[pre][k - 1] : 0);
    }
    ans += f[now][n];
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  n = read(); m = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    s[i] = s[i - 1] + a[i];
  }
  int l = 1, r = s[n];
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  int ans = r + 1;
  printf("%d %d\n", ans, solve(ans));

  return 0;
}