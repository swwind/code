#include <bits/stdc++.h>
using namespace std;
inline long long read(){
  long long x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int num[20];
long long f[20][220][220];
long long calc(int len, int x, int y, bool flag, int mod) {
  // printf("%d %d %d %d %d\n", len, x, y, flag, mod);
  if (!len) {
    return x == mod && !y;
  }
  long long& fs = f[len][x][y];
  if (!flag && ~fs) {
    return fs;
  }
  int c = flag ? num[len] : 9;
  long long ans = 0;
  for (int i = 0; i <= c; ++ i) {
    ans += calc(len - 1, x + i, (y * 10 + i) % mod, flag && i == c, mod);
  }
  if (!flag) {
    fs = ans;
  }
  return ans;
}
long long query(long long x) {
  if (!x) return 0;
  int top = 0;
  while (x) {
    num[++ top] = x % 10;
    x /= 10;
  }
  long long ans = 0;
  for (int i = 1; i <= top * 9; ++ i) {
    memset(f, -1, sizeof f);
    ans += calc(top, 0, 0, true, i);
    // printf("+ %lld\n", ans);
  }
  // printf("= %lld\n", ans);
  return ans;
}
int main(int argc, char const *argv[]) {
  long long a = read(), b = read();
  printf("%lld\n", query(b) - query(a - 1));
  return 0;
}