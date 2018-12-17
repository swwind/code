// FFT
// 递归版

#include <bits/stdc++.h>
#define N 100020
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
void fft(cp *a, int n, int flag) {
  if (n == 1) return;
  int m = n >> 1;
  cp a0[m + 1], a1[m + 1];
  for (int i = 0; i < m; i++)
    a0[i] = a[i << 1], a1[i] = a[i<<1|1];
  fft(a0, m, flag);
  fft(a1, m, flag);
  cp wn(cos(2 * PI / n), sin(flag * 2 * PI / n)), w(1, 0);
  for (int i = 0; i < m; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + m] = a0[i] - w * a1[i];
    w = w * wn;
  }
}
cp x[N<<1], y[N<<1];
int ans[N<<1];
char str[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = n * 2 - 1;
  scanf("%s", str);
  for (int i = 0; i < n; i++)
    x[i].real(str[i] - '0');
  scanf("%s", str);
  for (int i = 0; i < n; i++)
    y[i].real(str[i] - '0');
  for (n = 1; n <= m; n <<= 1);
  fft(x, n, 1);
  fft(y, n, 1);
  for (int i = 0; i < n; i++)
    x[i] = x[i] * y[i];
  fft(x, n, -1);
  for (int i = 0; i < m; i++)
    ans[i] = (int) round(x[i].real() / n);
  for (int i = m - 1; i; i--) {
    ans[i - 1] += ans[i] / 10;
    ans[i] %= 10;
  }
  int st = 0;
  while (st < m && !ans[st])
    st ++;
  if (st == m) putchar('0');
  for (; st < m; st++)
    printf("%d", ans[st]); puts("");
  return 0;
}