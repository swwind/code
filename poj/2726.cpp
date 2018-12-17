#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 10020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct __timber {
  int d, c, id;
}p[N];
bool cmp(const __timber &a, const __timber &b) {
  if (a.d != b.d) return a.d < b.d;
  else return a.c < b.c;
}
int main(int argc, char const *argv[]) {
  while (int n = read()) {
    for (int i = 1; i <= n; ++ i) {
      p[i].d = read();
      p[i].c = read();
      p[i].id = i;
    }
    sort(p + 1, p + n + 1, cmp);
    int mxr = 1 << 30, ans = 0;
    for (int i = 1; i <= n; ++ i) {
      if (p[i].d != p[i - 1].d) {
        if (mxr > p[i].c) {
          mxr = p[i].c;
          ++ ans;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}