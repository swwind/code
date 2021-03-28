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

char a[N], b[N];
int n, m;
int f[N], g[N];

int main() {
  while (~scanf("%s%s", a+1, b+1)) {
    n = strlen(a+1);
    m = strlen(b+1);

    memset(f, 0, sizeof f);
    // memset(g, 0, sizeof g);
    for (int i = 1; i <= n; ++ i) {
      swap(f, g);
      // memset(f, 0, sizeof f);
      for (int j = 1; j <= m; ++ j) {
        f[j] = max(g[j], f[j-1]);
        if (a[i] == b[j]) {
          f[j] = max(f[j], g[j-1] + 1);
        }
      }
    }
    printf("%d\n", f[m]);
  }
}