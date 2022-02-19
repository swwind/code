#include <bits/stdc++.h>
#define N 120
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int a[N];

int main() {
  int t = read();
  while (t --) {
    int n = read(), l = read();
    for (int i = 0; i < l; ++ i) {
      a[i] = 0;
    }
    for (int i = 1; i <= n; ++ i) {
      int x = read();
      for (int j = 0; j < l; ++ j) {
        if ((x >> j) & 1) {
          a[j] ++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < l; ++ i) {
      if (a[i] > n - a[i]) {
        ans ^= (1 << i);
      }
    }
    printf("%d\n", ans);
  }
}