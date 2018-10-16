#include <bits/stdc++.h>
#define N 20020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int p[N], a[N], b[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    p[i] = read();
    a[i] = i           * N;
    b[i] = (n - i + 1) * N;
  }

  for (int i = 1; i <= n; ++ i) {
    a[p[i]] += i;
  }


  for (int i = 1; i <= n; ++ i) {
    printf("%d ", a[i]);
  } puts("");
  for (int i = 1; i <= n; ++ i) {
    printf("%d ", b[i]);
  } puts("");

  return 0;
}