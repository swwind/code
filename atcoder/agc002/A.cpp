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
  int a = read(), b = read();
  if (a <= 0 && b >= 0) {
    // - +
    puts("Zero");
  } else if (b < 0) {
    // - -
    puts(((b-a)&1) ? "Positive" : "Negative");
  } else {
    // + +
    puts("Positive");
  }
  return 0;
}