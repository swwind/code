#include <bits/stdc++.h>
#define N 200100
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}

double f[55][5005];
int a[55], b[55];
double p[55];

int n, m;

inline bool check(double k) {
  // printf("%.10lf ", k);
  for (int i = n; i; -- i) {
    for (int j = m + 1; j < 5005; ++ j) {
      f[i + 1][j] = k;
    }
    for (int j = 0; j <= m; ++ j) {
      f[i][j] = min((f[i + 1][j + a[i]] + a[i]) * p[i] + (f[i + 1][j + b[i]] + b[i]) * (1 - p[i]), k);
    }
  }

  // printf("%.10lf\n", f[1][0]);
  return f[1][0] < k;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  n = read(); m = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    b[i] = read();
    p[i] = read() / 100.0;
  }

  double l = 0, r = 1e9;
  while (r - l > 1e-10) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  printf("%.10lf\n", r);

  return 0;
}
