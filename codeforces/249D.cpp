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
int id[N];
ll xs[N], ys[N];
bool cmp(const int &a, const int &b) {
  return xs[a] == xs[b] ? ys[a] > ys[b] : xs[a] < xs[b];
}
ll mx[N], len;
int main(int argc, char const *argv[]) {
  int n = read();
  ll a = read(), b = read(), c = read(), d = read();
  for (int i = 1; i <= n; ++ i) {
    ll x = read(), y = read();
    // rotate a1°
    xs[i] = c * x - d * y;
    ys[i] = b * y - a * x;
    id[i] = i;
    if (xs[i] <= 0 || ys[i] <= 0)
      -- n, -- i;
  }
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    ll y = ys[id[i]];
    if (y > mx[len]) mx[++ len] = y;
    else *lower_bound(mx + 1, mx + len + 1, y) = y;
  }
  cout << len << endl;
  return 0;
}
