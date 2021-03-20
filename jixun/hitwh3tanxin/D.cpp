#include <cstdio>
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

int a[N];

int main() {
  int n = read();
  int sum = 0;
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    sum += a[i];
  }
  sort(a + 1, a + n + 1);

  int ans = 0;
  for (int i = 2; i <= n; ++ i) {
    for (int d = 2; d <= 10; ++ d) {
      if (a[i] % d == 0) {
        ans = min(ans, a[i]/d+d*a[1] - a[i]-a[1]);
        ans = min(ans, d+(a[i]/d)*a[1] - a[i]-a[1]);
      }
    }
  }
  printf("%d\n", sum + ans);
}