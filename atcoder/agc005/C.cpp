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
int cnt[N], a[N];
int main(int argc, char const *argv[]) {
  int n = read();
  int r = 1 << 30, d = 0;
  for (int i = 1; i <= n; ++ i){
    a[i] = read();
    cnt[a[i]] ++;
    r = min(a[i], r);
    d = max(a[i], d);
  }
  if (r != (d + 1) / 2 || cnt[r] > 1 + (d & 1)) {
    return puts("Impossible"), 0;
  }
  for (int i = r + 1; i <= d; ++ i) {
    if (cnt[i] < 2) {
      return puts("Impossible"), 0;
    }
  }
  puts("Possible");
  return 0;
}
/*
显然 max{a[i]} 即为树的直径。

显然 [直径/2,直径] 必须都存在。

除半径外所有值都应该>=2

半径分情况讨论

*/