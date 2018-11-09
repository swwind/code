#include <bits/stdc++.h>
#define N 420
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N];
int f[N][N<<1];
int g[N][N<<1];
int h[N][N<<1];
struct friends {
  int l, r, f, id;
  friend bool operator < (const friends &a, const friends &b) {
    return a.f < b.f;
  }
}fs[N];
std::vector<int> res[N];
int main(int argc, char const *argv[]) {
  #ifdef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n = read(), v = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  int m = read();
  for (int i = 1; i <= m; i++) {
    fs[i].l = read();
    fs[i].r = read();
    fs[i].f = read();
    fs[i].id = i;
  }
  sort(fs + 1, fs + m + 1);
  fs[0].l = 1; fs[0].r = n;
  int lst, mn;
  memset(f, -63, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int sum = -1, sf = 0;
    for (int k = 0; k <= m; k++) {
      if (fs[k].l <= i && i <= fs[k].r) {
        ++ sum; sf += fs[k].f;
        for (int j = 0; j <= a[i - 1]; j++) {
          if (f[i - 1][j] >= 0 &&
              (lst = j + a[i] - v - sf) >= 0 &&
              f[i][mn = min(lst, a[i])] < f[i - 1][j] + sum) {
            f[i][mn] = f[i - 1][j] + sum;
            g[i][mn] = j;
            h[i][mn] = k;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= a[n]; i++)
    if (f[n][i] > f[n][ans]) ans = i;
  cout << f[n][ans] << endl;
  for (int i = n; i; i--) {
    for (int j = h[i][ans]; j; j--)
      if (fs[j].l <= i && i <= fs[j].r)
        res[i].push_back(fs[j].id);
    ans = g[i][ans];
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i].size();
    for (int gg : res[i])
      cout << " " << gg;
    cout << endl;
  }
  return 0;
}