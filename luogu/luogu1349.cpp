#include <bits/stdc++.h>
#define N 100020
#define mod m
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int p, q, a, b, n, m;
struct Matrix {
  #define M_SZ 2
  #define value long long
  #define M_MOD m
  value num[M_SZ][M_SZ];
  void clean() { memset(num, 0, sizeof num); }
  Matrix() { clean(); }
  Matrix(bool flag) {
    clean();
    for (int i = 0; i < M_SZ; i++)
      num[i][i] = 1;
  }
  value* operator [] (int a) { return num[a]; }
  friend Matrix operator * (Matrix a, Matrix b) {
    Matrix c;
    for (int k = 0; k < M_SZ; k++)
      for (int i = 0; i < M_SZ; i++)
        for (int j = 0; j < M_SZ; j++)
          c[i][j] = (c[i][j] + a[i][k] * b[k][j] % M_MOD) % M_MOD;
    return c;
  }
  friend Matrix operator ^ (Matrix a, long long b) {
    Matrix c(true);
    for (; b; b >>= 1, a = a * a)
      if (b & 1) c = c * a;
    return c;
  }
};
int main(int argc, char const *argv[]) {
  p = read(), q = read();
  a = read(), b = read();
  n = read(), m = read();
  if (n == 1) return printf("%d\n", a % m), 0;
  if (n == 2) return printf("%d\n", b % m), 0;
  Matrix A;
  A[0][0] = p;
  A[1][0] = q;
  A[0][1] = 1;
  A = A ^ (n - 2);
  // cout << A[0][0] << " " << A[0][1] << endl;
  // cout << A[1][0] << " " << A[1][1] << endl;
  Matrix B;
  B[0][0] = b;
  B[0][1] = a;
  // cout << B[0][0] << " " << B[0][1] << endl;
  // cout << B[1][0] << " " << B[1][1] << endl;
  B = B * A;
  cout << B[0][0] << endl;
  return 0;
}

/*

an = p*a(n-1)+q*a(n-2)

an = p*(p*a(n-2)+q*a(n-3))+q*a(n-2)
an = (p^2+q)*a(n-2)+p*q*a(n-3)

|1 1|
|   |
|1 0|

|p 1|
|   |
|q 0|

|p^2+q p|
|       |
|p*q   0|


*/