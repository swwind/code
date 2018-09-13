#include <bits/stdc++.h>
#define N 30
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char a[N];
bool isGreater(int x, int y) {
  printf("? %d %d\n", x, y);
  char c;
  scanf("%c", &c);
  return c == '>';
}
void f(int l, int r) {
  if (l >= r) return;
  
}
int main(int argc, char const *argv[]) {
  int n = read(), q = read();
  for (int i = 0; i < n; ++ i) {
    a[i] = 'A' + i;
  }

  return 0;
}