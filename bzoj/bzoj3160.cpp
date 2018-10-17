#include <bits/stdc++.h>
#define N 300020
#define ll long long
#define mod 1000000007
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
// fast_pow
ll fast_pow(ll x, ll y) {
  ll c = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) c = c * x % mod;
  return c;
}

// fft
typedef complex<double> cp;
const double PI = acos(-1);
struct FFT {
  int rev[N<<1], n, l;
  cp wn[N<<1][2], w[N<<1];
  void init(int len) {
    for (n = 1; n <= len; n <<= 1, ++l);
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

// manacher
struct Manacher {
  int rl[N<<1];
  char val[N<<1];
  int manacher(char *s) {
    int res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      val[i << 1] = '#';
      val[i<<1|1] = s[i];
    }
    val[len << 1] = '#';
    int mxr = -1, pos = 0;
    len = len << 1 | 1;
    for (int i = 0; i < len; i++) {
      rl[i] = i < mxr ?
        min(rl[2 * pos - i], mxr - i) : 1;
      while (i - rl[i] >= 0 && i + rl[i] < len && val[i - rl[i]] == val[i + rl[i]])
        rl[i] ++;
      if (i + rl[i] - 1 > mxr) {
        mxr = i + rl[i] - 1;
        pos = i;
      }
      res = (res + rl[i] / 2) % mod;
    }
    return res;
  }
}mnc;
char ch[N];
cp x[N << 1], y[N << 1];
int main(int argc, char const *argv[]) {
  scanf("%s", ch);
  int n = strlen(ch);
  fft.init(n * 2 - 1);
  
  for (int i = 0; i < n; i++)
    x[i] = cp(ch[i] == 'a', 0);
  fft.dft(x, 0);
  for (int i = 0; i < fft.n; i++)
    x[i] = x[i] * x[i];
  fft.dft(x, 1);

  for (int i = 0; i < n; i++)
    y[i] = cp(ch[i] == 'b', 0);
  fft.dft(y, 0);
  for (int i = 0; i < fft.n; i++)
    y[i] = y[i] * y[i];
  fft.dft(y, 1);

  ll ans = 0;
  for (int i = 0; i < fft.n; i++) {
    int t = int(x[i].real() + y[i].real() + .5);
    t = (t + 1) >> 1;
    ans = (ans + fast_pow(2, t) - 1) % mod;
  }
  // cout << ans << endl;
  ans = ((ans - mnc.manacher(ch)) % mod + mod) % mod;
  cout << ans << endl;

  return 0;
}