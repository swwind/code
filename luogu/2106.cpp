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
  int a[10][10];
  void clear(){memset(a,0,sizeof a);}
  Matrix(){clear();}
  Matrix(bool f){clear();for(int i=0;i<10;i++)a[i][i]=1;}
  int* operator [] (int i) { return a[i]; }
  friend Matrix operator * (Matrix a, Matrix b) {
    Matrix c;
    for (int k = 0; k < 10; ++ k)
      for (int i = 0; i < 10; ++ i)
        for (int j = 0; j < 10; ++ j)
          c[i][j] = (c[i][j] + (ll) a[i][k] * b[k][j] % mod) % mod;
    return c;
  }
  friend Matrix operator ^ (Matrix a, ll b) {
    Matrix c(1);
    for (; b; b >>= 1, a = a * a)
      if (b & 1) c = c * a;
    return c;
  }
};
int main(int argc, char const *argv[]) {
  ll k = read();
  if (k == 1) return puts("10"), 0;
  Matrix res, ans;
  for (int i = 0; i < 10; ++ i) {
    for (int j = max(i - 2, 0); j <= min(i + 2, 9); ++ j)
      res[j][i] = 1;
  }
  res = res ^ (k - 1);
  for (int i = 0; i < 10; ++ i) ans[0][i] = 1;
  ans = ans * res;
  int answ = 0;
  for (int i = 1; i < 10; ++ i)
    answ = (answ + ans[0][i]) % mod;
  cout << answ << endl;
  return 0;
}