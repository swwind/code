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
int a[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 2; i <= n; i++) {
    if (abs(a[i] - a[i - 1]) > 1)
      return puts("NO"), 0;
  }
  puts("YES");
  return 0;
}