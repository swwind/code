#include <bits/stdc++.h>
#define N 150020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int a[N], last[N];

int main() {
  int t = read();
  while (t --) {
    int n = read(), ans = -1;
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
    }

    for (int i = n; i; -- i) {
      last[a[i]] = 0;
    }

    for (int i = 1; i <= n; ++ i) {
      if (last[a[i]]) {
        ans = max(ans, last[a[i]] + n - i);
      }
      last[a[i]] = i;
    }

    printf("%d\n", ans);
  }
}