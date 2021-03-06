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
const long long inf = 1ll << 40;
long long a[N], b[N], f[N];
long long calc(int x, int y) {
  return a[x] == b[y] ? inf : abs(a[x] - b[y]);
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    b[i] = read();
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + calc(i, i);
    if (i > 1)
      f[i] = min(f[i], f[i - 2] + calc(i, i - 1) + calc(i - 1, i));
    if (i > 2)
      f[i] = min(f[i], f[i - 3] + calc(i, i - 1) + calc(i - 1, i - 2) + calc(i - 2, i)),
      f[i] = min(f[i], f[i - 3] + calc(i - 1, i) + calc(i - 2, i - 1) + calc(i, i - 2));
  }
  cout << f[n] << endl;
  return 0;
}