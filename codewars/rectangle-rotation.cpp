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
long long rectangle_rotation(int a, int b) {
  double sqrt2 = sqrt(2);
  int s = floor(b * 0.5 / sqrt2) * 2 + 1;
  int k = floor(b * 0.5 / sqrt2 + 0.5) * 2;
  int f = floor(a * 0.5 / sqrt2) * 2 + 1;
  int g = floor(a * 0.5 / sqrt2 + 0.5) * 2;
  return (ll) s * f + (ll) k * g;
}
int main(int argc, char const *argv[]) {
  // freopen("zack.in", "r", stdin);
  // freopen("zack.out", "w", stdout);
  int n = read(), m = read();
  cout << rectangle_rotation(n, m) << endl;
  return 0;
}
