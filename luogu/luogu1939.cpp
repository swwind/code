#include <bits/stdc++.h>
#define N 3
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct Matrix{
  int num[N][N];
  void clear(){memset(num, 0, sizeof num);}
  Matrix(){clear();}
  Matrix(bool flag){clear();for(int i = 0; i < N; i++)num[i][i]=1;}
  int* operator [] (int i) {return num[i];}
  friend Matrix operator * (Matrix a, Matrix b){
    Matrix c;
    for(int k = 0; k < N; k++)
      for(int i = 0; i < N; i++) if(a[i][k])
        for(int j = 0; j < N; j++) if(b[k][j])
          c[i][j] = (c[i][j]+(ll)a[i][k]*b[k][j])%mod;
    return c;
  }
  friend Matrix operator ^ (Matrix a, ll b){
    Matrix c(true);
    for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
    return c;
  }
  void print(){
    for(int i = 0; i < N; i++, puts(""))
      for(int j = 0; j < N; j++)
        printf("%d ", num[i][j]);
  }
}A;
int main(int argc, char const *argv[]) {
  int T = read();
  A[0][0] = 0; A[0][1] = 0; A[0][2] = 1;
  A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
  A[2][0] = 0; A[2][1] = 1; A[2][2] = 1;
  while (T --) {
    int x = read();
    if (x <= 3) {
      puts("1");
      continue;
    }
    Matrix B = A ^ (x - 1);
    cout << B[2][2] << endl;
    // B.print();
  }
  return 0;
}
/*

ai = ai-3 + ai-1
ai-1 = ai-4 + ai-2

ai = ai-2 + ai-3 + ai-4



*/