#include <bits/stdc++.h>
#define N 100020
#define mod 100000000
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

struct Matrix{
  #define MSZ 2
  int num[MSZ][MSZ];
  void clear(){memset(num, 0, sizeof num);}
  Matrix(){clear();}
  Matrix(bool flag){clear();for(int i = 0; i < MSZ; i++)num[i][i]=1;}
  int* operator [] (int i) {return num[i];}
  friend Matrix operator * (Matrix &a, Matrix &b){
    Matrix c;
    for(int k = 0; k < MSZ; k++)
      for(int i = 0; i < MSZ; i++) if(a[i][k])
        for(int j = 0; j < MSZ; j++) if(b[k][j])
          c[i][j] = (c[i][j]+1ll*a[i][k]*b[k][j])%mod;
    return c;
  }
  friend Matrix operator ^ (Matrix a, ll b){
    Matrix c(true);
    for(;b;b/=2,a=a*a)if(b&1)c=c*a;
    return c;
  }
};

int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  int k = gcd(n, m);
  Matrix A;
  A[0][0] = A[0][1] = A[1][0] = 1;
  A = A ^ (k - 1);
  printf("%d\n", A[0][0]);
  return 0;
}