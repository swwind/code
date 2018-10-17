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
long long a[N], b[N], ans;
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    b[i] = read();
  }
  for (int i = n; i; -- i) {
    a[i] += ans;
    ans += (b[i] - a[i] % b[i]) % b[i];
  }
  printf("%lld\n", ans);
  return 0;
}