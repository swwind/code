#include <bits/stdc++.h>
#define N 100020
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
#include <cmath>
inline int sum_of_squares(int n) {
  while (n % 4 == 0) n /= 4;
  if (n % 8 == 7) return 4;
  for (int i = 0; i * i <= n; i++) {
    int j = std::sqrt(n - i * i);
    if (i * i + j * j == n)
      return !!i + !!j;
  }
  return 3;
}
int main(int argc, char const *argv[]) {
  std::printf("%d\n", sum_of_squares(read()));
  return 0;
}