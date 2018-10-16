#include <bits/stdc++.h>
#define N 300020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
typedef std::complex<double> cp;
const double PI = acos(-1);
struct FFT {
  int rev[N<<1], n, l;
  cp wn[N<<1][2], w[N<<1];
  void init(int m) {
    for (n = 1; n <= m; n <<= 1, l++);
    for (int i = 0; i < n; i++)
      rev[i] = rev[i >> 1] >> 1 | ((i & 1) << l - 1);
    double t = PI / n;
    for (int i = 0; i < n; i += 2) {
      wn[i][0] = cp(cos(t * i), sin( t * i));
      wn[i][1] = cp(cos(t * i), sin(-t * i));
    }
  }
  void dft(cp *x, int f) {
    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(x[i], x[rev[i]]);
    w[0] = cp(1, 0);
    for (int d = 1; d < n; d <<= 1) {
      for (int i = 1; i <= d; i++)
        w[i] = wn[n / d * i][f];
      for (int i = 0; i < n; i += d << 1) {
        for (int k = 0, l = i, r = i + d; k < d; ++ k, ++ l, ++ r) {
          cp tmp = x[r] * w[k];
          x[r] = x[l] - tmp;
          x[l] = x[l] + tmp;
        }
      }
    }
    if (f)
      for (int i = 0; i < n; i++)
        x[i] /= n;
  }
}fft;
cp q[N<<1], p[N<<1], g[N<<1];
int main(int argc, char const *argv[]) {
  int n = read(); double x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    q[i] = x;
    p[n - i] = x;
    g[i] = i ? 1. / i / i : 0;
  }
  fft.init(2 * n - 1);
  fft.dft(q, 0);
  fft.dft(p, 0);
  fft.dft(g, 0);
  for (int i = 0; i < fft.n; i++) {
    q[i] = q[i] * g[i];
    p[i] = p[i] * g[i];
  }
  fft.dft(q, 1);
  fft.dft(p, 1);
  for (int i = 0; i < n; i++) {
    printf("%.5lf\n", q[i].real() - p[n - i].real());
  }

  return 0;
}