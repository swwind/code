#include <bits/stdc++.h>
#define N 12138
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), S = read();
  for (int i = 1; i <= n; i++) {
    w[i] = read();
    v[i] = read();
  }
  for (int i = 1; i <= m; i++) {
    l[i] = read();
    r[i] = read();
  }
  return 0;
}