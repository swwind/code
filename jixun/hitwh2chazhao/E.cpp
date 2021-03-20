#include <cstdio>
#include <iostream>
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

int a[N], n;

int check(int x) {
  if (!x) return 2147483647;
  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += a[i] / x;
  }
  // printf("%d %d\n", x, ans);
  return ans;
}

int main() {
  n = read();
  int k = read();
  int r = 0, sum = 0;
  for (int i = 1; i <= n; ++ i) {
    double x; scanf("%lf", &x);
    a[i] = x * 100;
    r = max(r, a[i]);
    sum += a[i];
  }

  // if (sum < k) {
  //   // printf("%d %d\n", sum, k);
  //   puts("0.00");
  //   return 0;
  // }

  int l = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid) < k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%.2f\n", r / 100.0);
}
