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
void work1(int n) {
  if (n < 6) {
    puts("-1");
    return;
  }
  int x = (n-2)/2, y = n-2-x;
  puts("1 2");
  for (int i = 1; i <= x; i++)
    printf("1 %d\n", i + 2);
  for (int i = 1; i <= y; i++)
    printf("2 %d\n", i + x + 2);
}
void work2(int n) {
  for (int i = 2; i <= n; i++)
    printf("1 %d\n", i);
}
int main(int argc, char const *argv[]) {
  int n = read();
  work1(n);
  work2(n);
  return 0;
}