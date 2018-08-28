// 亦或方程组
// 求一组可行解

// luogu 3429
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

/*
整体思想与普通方程组的高斯消元解法类似。

第一阶段（消元）：
  设置一个变量p，一开始p=1，然后，i从1到n，每次执行：<1> 若在第p个及以后的方程中，
  至少有一个方程的xi系数为1，设为第q个方程，则先将第p、q个方程交换，然后用第p个方程去XOR后面剩下的所
  有xi系数为1的方程（各系数包括b都对应进行XOR运算，实际上就是矩阵初等行变换），将它们的xi系数均变成0，
  最后p加1；<2>否则（第p个及以后的方程中xi系数均为0），xi是自由元（xi不管是取0还是1，都能导出整个方
  程组的一个解），按照自由元处理（随便定值，然后将前面所有xi系数为1的方程全部代入xi的值XOR掉），p值不变。

第二阶段（回代求解）：
  在第一阶段结束后，若出现了S个自由元，则会在整个方程组的最后出现S个多余方程，
  它们的等号左边所有系数均为0（显然值也为0）。对于这些多余方程，如果有等号右边为1的，
  则整个方程组无解。否则，如果所有多余方程的等号右边均为0，则整个方程组有2S个解（因为
  S个自由元可以随便取值，都能导出解）。如果要求具体的解，则从第(m-S)个方程开始，往回代，
  设立变量p，初始p=m-S，逆序枚举每个未知数（自由元除外），对于未知数xi，可以从第p个
  方程中直接得到其值（因为此时第p个方程等号左边必然只有xi系数为1，等号右边是几，xi值就
  是几），然后，将之前的所有xi系数为1的方程全部用第p个方程XOR掉，p--。
*/
