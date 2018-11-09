#include <bits/stdc++.h>
#define N 100020
#define mod 1000000007
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct Matrix {
  int a[32][32];
  void clear() {
    memset(a, 0, sizeof a);
  }
  Matrix(){clear();}
  Matrix(bool _){clear();for (int i = 0; i < 32; ++ i) a[i][i] = 1;}
  int* operator [] (int i) {
    return a[i];
  }
  Matrix operator * (Matrix b) {
    Matrix c;
    for (int k = 0; k < 32; ++ k) {
      for (int i = 0; i < 32; ++ i) {
        for (int j = 0; j < 32; ++ j) {
          c[i][j] = (c[i][j] + (ll) a[i][k] * b[k][j] % mod) % mod;
        }
      }
    }
    return c;
  }
  friend Matrix operator ^ (Matrix a, ll y) {
    Matrix c(true);
    for (; y; y >>= 1, a = a * a)
      if (y & 1) c = c * a;
    return c;
  }
};
int bits[40];
int main(int argc, char const *argv[]) {
  long long n = read(), m = read(), k = read();
  int nn = 1 << m;
  for (int i = 1; i <= nn; ++ i) {
    bits[i] = bits[i >> 1] + (i & 1);
  }
  Matrix shit;
  for (int i = 0; i < nn; ++ i) {
    for (int j = 0; j < nn; ++ j) {
      if (bits[i] > k || bits[j] > k) continue;
      if ((i & ((1 << (m - 1)) - 1)) != (j >> 1)) continue;
      // printf("%d %d\n", i, j);
      ++ shit[i][j];
    }
  }
  shit = shit ^ n;
  int ans = 0;
  for (int i = 0; i < nn; ++ i) {
    ans = (ans + shit[i][i]) % mod;
  }
  cout << ans << endl;
  return 0;
}