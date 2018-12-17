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
  int n = read(), l = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  int flag = 0;
  for (int i = 1; i < n; ++ i) {
    if (a[i] + a[i + 1] >= l) {
      flag = i;
      break;
    }
  }
  if (!flag) {
    return puts("Impossible"), 0;
  }
  puts("Possible");
  for (int i = 1; i < flag; ++ i) {
    printf("%d\n", i);
  }
  for (int i = n - 1; i > flag; -- i) {
    printf("%d\n", i);
  }
  printf("%d\n", flag);
  return 0;
}