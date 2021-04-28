#include <bits/stdc++.h>
using namespace std;

inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int f[520][520];

void work(int x, int s) {
  int nx = x, ny = x;
  f[nx][ny] = s;
  for (int i = 2; i <= s; ++ i) {
    if (ny > 1 && !f[nx][ny-1]) {
      --ny;
    } else {
      ++nx;
    }
    f[nx][ny] = s;
  }
}

int main() {
  int n = read();
  for (int i = 1; i <= n; ++ i) work(i, read());

  for (int i = 1; i <= n; ++ i) for (int j = 1; j <= i; ++ j) {
    printf("%d%c", f[i][j], " \n"[i==j]);
  }
}
