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

int a[N], f[N];

int main() {

  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
      f[i] = 1;

      for (int j = 1; j < i; ++ j) {
        if (a[i] > a[j]) {
          f[i] = max(f[i], f[j] + 1);
        }
      }

      ans = max(ans, f[i]);
    }
    printf("%d\n", ans);

    // f[i] = f[i-1]
  }

}