#include <bits/stdc++.h>
#define N 100
#define mod 2009
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int maxn = 0;
struct Matrix {
  int n, num[N][N];
  void clear() {
    memset(num, 0, sizeof num);
  }
  Matrix() {
    clear();
  }
  Matrix(bool flag) {
    clear();
    for (int i = 0; i < maxn; ++ i) {
      num[i][i] = 1;
    }
  }
  int* operator [] (int i) {
    return num[i];
  }
  friend Matrix operator * (Matrix a, Matrix b) {
    Matrix c;
    for (int k = 0; k < maxn; ++ k) {
      for (int i = 0; i < maxn; ++ i) if (a[i][k]) {
        for (int j = 0; j < maxn; ++ j) if (b[k][j]) {
          c[i][j] = (c[i][j] + (ll) a[i][k] * b[k][j]) % mod;
        }
      }
    }
    return c;
  }
  friend Matrix operator ^ (Matrix a, ll b) {
    Matrix c(true);
    for (; b; b >>= 1, a = a * a) {
      if (b & 1) {
        c = c * a;
      }
    }
    return c;
  }
  void debug_print() {
    for (int i = 0; i < N; ++ i) {
      printf("| ");
      for (int j = 0; j < N; ++ j) {
        printf("%d ", num[i][j]);
      }
      printf("|\n");
    }
  }
};
int n, t;
int pos(int i, int j) {
  return i + j * n;
}
int main(int argc, char const *argv[]) {
  n = read(); t = read();
  maxn = n * 9;
  Matrix mtx;
  for (int i = 0; i < n; ++ i) {
    for (int j = 1; j <= 9; ++ j) {
      mtx[pos(i, j)][pos(i, j - 1)] = 1;
    }
    ll x = read();
    for (int j = n - 1; ~ j; -- j) {
      mtx[i][pos(j, x % 10 - 1)] = 1;
      x /= 10;
    }
  }
  mtx = mtx ^ t;
  printf("%d\n", mtx[0][n - 1]);
  return 0;
}