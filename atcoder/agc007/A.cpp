#include <bits/stdc++.h>
#define N 10
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char str[N][N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str[i] + 1);
  }
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      if (str[i][j] == '#') {
        if (str[i-1][j] == '#' && str[i][j-1] == '#' ||
            str[i+1][j] == '#' && str[i][j+1] == '#') {
          return puts("Impossible"), 0;
        }
      }
    }
  }
  puts("Possible");
  return 0;
}