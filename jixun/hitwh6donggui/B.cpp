#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int a[252000];
int f[252000];

int main() {
  int n;
  while (~scanf("%d", &n) && n >= 0) {
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++ i) {
      int w = read();
      int v = read();
      for (int j = 1; j <= v; ++ j) {
        a[++ cnt] = w;
      }
      sum += w * v;
    }
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int i = 1; i <= cnt; ++ i) {
      for (int v = sum; v >= a[i]; -- v) {
        f[v] |= f[v - a[i]];
      }
    }

    for (int i = sum/2; ~i; -- i) {
      if (f[i]) {
        printf("%d %d\n", sum-i, i);
        break;
      }
    }
  }
}

