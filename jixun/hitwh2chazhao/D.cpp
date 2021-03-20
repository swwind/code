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

int a[N], last, n, m;

int check(int x) {
  int now = 0, cnt = 0;
  for (int i = 1; i <= n; ++ i) {
    if (a[i] - now < x) {
      ++ cnt;
    } else {
      now = a[i];
    }
  }
  if (last - now < x) ++ cnt;
  // printf("%d %d\n", x, cnt);
  return cnt;
}

int main() {
  last = read();
  n = read();
  m = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  // sort(a + 1, a + n + 1);
  int l = 0, r = last+1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid) > m) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  printf("%d\n", r-1);
}
