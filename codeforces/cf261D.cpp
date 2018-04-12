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
int b[N], f[N];
int k = read(), n = read(), maxb = read(), t = read();
void update(int x, int v) {
  for (; x <= maxb; x += x & -x)
    f[x] = max(f[x], v);
}
int query(int x) {
  int res = 0;
  for (; x; x ^= x & -x)
    res = max(res, f[x]);
  return res;
}
int ans[N];
int main(int argc, char const *argv[]) {
  t = min(min(n, maxb), t);
  while (k --) {
    for (int i = 1; i <= n; i++)
      b[i] = read();
    memset(f, 0, sizeof f);
    memset(ans, 0, sizeof ans);
    for (int j = 1; j <= t; j++) {
      for (int i = 1; i <= n; i++) {
        int res = query(b[i] - 1) + 1;
        if (ans[b[i]] < res) {
          ans[b[i]] = res;
          update(b[i], res);
        }
      }
    }
    cout << query(maxb) << endl;
  }
  return 0;
}