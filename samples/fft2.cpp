// FFT
// 迭代版

#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"

#include <bits/stdc++.h>
#define N 3000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
const double PI = acos(-1);
// typedef std::complex<double> cp;
struct cp { // complex
  double a, b;
  cp(double a = 0, double b = 0)
    :a(a), b(b) {}
  double real() { return a; }
  void real(double x) { a = x; b = 0; }
  friend cp operator + (const cp &a, const cp &b) {
    return (cp){a.a + b.a, a.b + b.b};
  }
  friend cp operator - (const cp &a, const cp &b) {
    return (cp){a.a - b.a, a.b - b.b};
  }
  friend cp operator * (const cp &a, const cp &b) {
    return (cp){a.a * b.a - a.b * b.b, a.b * b.a + a.a * b.b};
  }
  friend cp operator * (const cp &a, const ll b) {
    return (cp){a.a * b, a.b * b};
  }
  friend cp operator / (const cp &a, const ll b) {
    return (cp){a.a / b, a.b / b};
  }
};
struct FFT {
  int rev[N << 1];
  int n, len;
  cp wn[N << 1][2], w[N << 1];
  void init(int m) {
    for (n = 1; n <= m; n <<= 1, ++ len);
    double t = PI / n;
    for (int i = 0; i < n; i++)
      rev[i] = rev[i >> 1] >> 1
             | ((i & 1) << len - 1);
    for (int i = 0; i < n; i += 2) {
      wn[i][0] = cp(cos(t * i), sin(t * i));
      wn[i][1] = cp(cos(t * i), - sin(t * i));
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
  }
}fft;
cp x[N << 1], y[N << 1];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 0; i <= n; i++)
    x[i].real(read());
  for (int i = 0; i <= m; i++)
    y[i].real(read());
  fft.init(n + m);
  fft.dft(x, 0);
  fft.dft(y, 0);
  for (int i = 0; i < fft.n; i++)
    x[i] = x[i] * y[i];
  fft.dft(x, 1);
  for (int i = 0; i <= n + m; i++)
    printf("%d ", int(x[i].real() / fft.n + .5));
  return 0;
}