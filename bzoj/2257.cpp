#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
map<int, int> mmp;
int main(int argc, char const *argv[]) {
  int n = read(), k = read();
  for (int i = 1; i <= n; ++ i) {
    int x = read();
    for (int j = 1; j * j <= x; ++ j) {
      if (x % j == 0) {
        ++ mmp[j];
        if (j * j != x) {
          ++ mmp[x / j];
        }
      }
    }
  }
  int ans = 0;
  for (map<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++ it) {
    if (it -> second >= k) {
      ans = max(ans, it -> first);
    }
  }
  printf("%d\n", ans);
  return 0;
}