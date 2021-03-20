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

int n;
int a[N], b[N];

double check(double x) {
  double res = 0;
  for (int i = 1; i <= n; ++ i) {
    res += abs(x - a[i]) * b[i];
  }
  // printf("%.5f -> %.5f\n", x, res);
  return res;
}

int main() {
  n = read();
  int mx = 0;
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    b[i] = read();
    mx = max(mx, a[i]);
  }

  double l = 0, r = mx;

  while (r - l > 1e-6) {
    double mid1 = (l + l + r) / 3;
    double mid2 = (l + r + r) / 3;
    if (check(mid1) > check(mid2)) {
      l = mid1;
    } else {
      r = mid2;
    }
  }

  printf("%.5f\n", l);
}
