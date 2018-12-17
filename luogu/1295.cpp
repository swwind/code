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
int f[N], a[N][20];
int ask(int l, int r) {
  int k = log2(r - l + 1);
  return max(a[l][k], a[r - (1 << k) + 1][k]);
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i][0] = read();
  for (int i = 1; i < 20; i++)
    for (int j = 1; j + (1 << i - 1) <= n; j++)
      a[j][i] = max(a[j][i - 1], a[j + (1 << i - 1)][i - 1]);
  
  return 0;
}