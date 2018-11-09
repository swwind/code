#include <bits/stdc++.h>
#define N 220
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int mat[N][N], val[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    int x = read();
    for (int j = 1; j <= x; ++ j) {
      mat[i][read()] = 1;
    }
    if (x & 1) {
      mat[i][i] = 1;
      val[i] = 1;
    }
  }

#ifdef LOCAL
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      printf("%d ", mat[i][j]);
    }
    printf(" = %d\n", val[i]);
  }
#endif

  for (int p = 1; p <= n; ++ p) {
    int sw = 0;
    for (int i = p; i <= n; ++ i) {
      if (mat[i][p]) {
        sw = i;
        break;
      }
    }
    if (sw) {
      for (int i = 1; i <= n; ++ i) {
        swap(mat[p][i], mat[sw][i]);
      }
      swap(val[p], val[sw]);
    }
    for (int i = p + 1; i <= n; ++ i) {
      if (mat[i][p]) {
        for (int j = 1; j <= n; ++ j) {
          mat[i][j] ^= mat[p][j];
        }
        val[i] ^= val[p];
      }
    }
  }
  
#ifdef LOCAL
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      printf("%d ", mat[i][j]);
    }
    printf(" = %d\n", val[i]);
  }
#endif

  mat[n][n] = 1;
  for (int i = n - 1; i; -- i) {
    for (int j = i + 1; j <= n; ++ j) {
      if (mat[i][j]) {
        for (int k = 1; k <= n; ++ k) {
          mat[i][k] ^= mat[j][k];
        }
        val[i] ^= val[j];
      }
    }
    mat[i][i] = 1;
  }

#ifdef LOCAL
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      printf("%d ", mat[i][j]);
    }
    printf(" = %d\n", val[i]);
  }
#endif

  int sum = 0;
  for (int i = 1; i <= n; ++ i) {
    sum += val[i];
  }
  printf("%d\n", sum);
  for (int i = 1; i <= n; ++ i) {
    if (val[i]) {
      printf("%d ", i);
    }
  }
  puts("");
  return 0;
}