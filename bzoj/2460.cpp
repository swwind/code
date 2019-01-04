#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0;bool f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

struct node {
  ll id, val;
  friend bool operator < (const node &a, const node &b) {
    return a.val > b.val;
  }
} a[N];
ll b[64];
bool insert(ll x) {
  for (int i = 63; ~i; -- i) {
    if (x >> i & 1) {
      if (!b[i]) {
        b[i] = x;
        return true;
      }
      x ^= b[i];
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  freopen("../tmp/.in", "r", stdin);

  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i].id = read();
    a[i].val = read();
  }
  sort(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    if (insert(a[i].id)) {
      ans += a[i].val;
    }
  }
  printf("%lld\n", ans);

  return 0;
}