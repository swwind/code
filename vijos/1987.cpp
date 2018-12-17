#include <bits/stdc++.h>
#define N 75020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
bitset<N> f[300];
int arr[N], fst[N], cnt;
int main(int argc, char const *argv[]) {
  int n = read(), k = read(), a = read(), b = read();
  for (int i = 1; i <= n; ++ i)
    arr[i] = read();
  f[0][0] = 1;
  for (int i = 1; i <= n; ++ i) {
    for (int j = k; j; -- j) {
      f[j] |= (f[j - 1] << arr[i]);
    }
  }
  int mxia = 1 << 30, pa;
  for (int i = 0; i <= 75000; ++ i) {
    if (f[k][i]) {
      fst[++ cnt] = i;
      if (abs(i - a) < mxia) {
        mxia = abs(i - a);
        pa = cnt;
      }
    }
  }
  int ans = 0;
  for (int i = a; i <= b; ++ i) {
    int res = abs(fst[pa] - i);
    if (pa != 1)   res = min(res, abs(fst[pa - 1] - i));
    if (pa != cnt && abs(fst[pa + 1] - i) < res) {
      res = abs(fst[pa + 1] - i);
      pa ++;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}