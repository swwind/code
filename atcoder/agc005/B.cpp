#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int a[N], b[N], c[N];
int l[N], r[N];

int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }

  int top = 0;
  for (int i = 1; i <= n; ++ i) {
    while (top && b[top] > a[i]) {
      -- top;
    }
    l[i] = c[top];
    b[++ top] = a[i];
    c[top] = i;
  }

  top = 0;
  c[0] = n + 1;
  for (int i = n; i; -- i) {
    while (top && b[top] > a[i]) {
      -- top;
    }
    r[i] = c[top];
    b[++ top] = a[i];
    c[top] = i;
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += (ll) a[i] * (i - l[i]) * (r[i] - i);
  }
  printf("%lld\n", ans);
  return 0;
}