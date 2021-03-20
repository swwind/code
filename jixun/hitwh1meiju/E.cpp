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

int a[22], ans[22];

int main() {
  int T = read();
  while (T --) {
    int n = read();
    int sum = 0;
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
      sum += a[i];
      ans[i] = 0;
    }
    for (int s = 1; s < (1 << n); ++ s) {
      int total = 0;
      for (int i = 1; i <= n; ++ i) {
        if ((s >> (i - 1)) & 1) {
          total += a[i];
        }
      }

      if (total * 2 > sum) {
        for (int i = 1; i <= n; ++ i) {
          if ((s >> (i - 1)) & 1) {
            if ((total - a[i]) * 2 <= sum) {
              ++ ans[i];
            }
          }
        }
      }
    }

    for (int i = 1; i <= n; ++ i) {
      printf("%d%c", ans[i], " \n"[i == n]);
    }
  }
}