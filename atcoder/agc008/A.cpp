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
int main(int argc, char const *argv[]) {
  int x = read(), y = read();

  if (abs(x) > abs(y)) {
    printf("%d\n", (x > 0) + (y > 0) + abs(x) - abs(y));
  } else if (abs(x) < abs(y)) {
    printf("%d\n", (x < 0) + (y < 0) + abs(y) - abs(x));
  } else {
    printf("%d\n", x != y);
  }

  return 0;
}