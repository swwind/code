#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char ch[N];
int main(int argc, char const *argv[]) {
  scanf("%s", ch + 1);
  int n = strlen(ch + 1);
  int T = 0, S = 0;
  for (int i = 1; i <= n; ++ i) {
    if (ch[i] == 'T') {
      if (S) -- S;
      else ++ T;
    }
    if (ch[i] == 'S') {
      ++ S;
    }
  }
  printf("%d\n", S + T);
  return 0;
}