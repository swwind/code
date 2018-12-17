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
int f[25][20][20][20][20][20];
void print_ans(int i, int j, int a, int b, int c, int d, int e) {
  long long res =
    i * 0x1000000ll +
    j * 0x100000ll  +
    a * 0x10000ll   +
    b * 0x1000ll    +
    c * 0x100ll     +
    d * 0x10ll      +
    e * 0x1ll       ;
  printf("%07x\n", res);
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 0; i < 16; ++ i)
  for (int j = 0; j < 16; ++ j)
  for (int a = 0; a < 16; ++ a)
  for (int b = 0; b < 16; ++ b)
  for (int c = 0; c < 16; ++ c)
  for (int d = 0; d < 16; ++ d)
  for (int e = 0; e < 16; ++ e) {
    if(
      !f[ 1][a][b][c][d][e] &&
      !f[ 2][j][b][c][d][e] &&
      !f[ 3][j][a][c][d][e] &&
      !f[ 4][j][a][b][d][e] &&
      !f[ 5][j][a][b][c][e] &&
      !f[ 6][j][a][b][c][d] &&
      !f[ 7][i][b][c][d][e] &&
      !f[ 8][i][a][c][d][e] &&
      !f[ 9][i][a][b][d][e] &&
      !f[10][i][a][b][c][e] &&
      !f[11][i][a][b][c][d] &&
      !f[12][i][j][c][d][e] &&
      !f[13][i][j][b][d][e] &&
      !f[14][i][j][b][c][e] &&
      !f[15][i][j][b][c][d] &&
      !f[16][i][j][a][d][e] &&
      !f[17][i][j][a][c][e] &&
      !f[18][i][j][a][c][d] &&
      !f[19][i][j][a][b][e] &&
      !f[20][i][j][a][b][d] &&
      !f[21][i][j][a][b][c]) {
      if (!-- n) {
        print_ans(i, j, a, b, c, d, e);
        return 0;
      }
      f[ 1][a][b][c][d][e] = f[ 2][j][b][c][d][e] = f[ 3][j][a][c][d][e] = 1;
      f[ 4][j][a][b][d][e] = f[ 5][j][a][b][c][e] = f[ 6][j][a][b][c][d] = 1;
      f[ 7][i][b][c][d][e] = f[ 8][i][a][c][d][e] = f[ 9][i][a][b][d][e] = 1;
      f[10][i][a][b][c][e] = f[11][i][a][b][c][d] = f[12][i][j][c][d][e] = 1;
      f[13][i][j][b][d][e] = f[14][i][j][b][c][e] = f[15][i][j][b][c][d] = 1;
      f[16][i][j][a][d][e] = f[17][i][j][a][c][e] = f[18][i][j][a][c][d] = 1;
      f[19][i][j][a][b][e] = f[20][i][j][a][b][d] = f[21][i][j][a][b][c] = 1;
    }
  }
  return 0;
}