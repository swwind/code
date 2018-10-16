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
int a[N], b[N];
int min5(int x) {
  return min(min(min(min(a[x], a[x-1]), a[x-2]), a[x-3]), a[x-4]);
}
int max5(int x) {
  return max(max(max(max(a[x], a[x-1]), a[x-2]), a[x-3]), a[x-4]);
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= n; i++)
    scanf("%1d", b + i);
  int mnl = -1e9, mxl = 1e9;
  int mnr = -1e9, mxr = 1e9;
  for (int i = 5; i <= n; i++) {
    if (!b[i-1]&&!b[i-2]&&!b[i-3]&&!b[i-4]) { // all 0000
      if (b[i]) { // 00001 -> max5(i) < l
        mnl = max(mnl, max5(i));
      } else { // 00000 -> max5(i) >= l
        mxl = min(mxl, max5(i));
      }
    }
    if (b[i-1]&&b[i-2]&&b[i-3]&&b[i-4]) { // all 1111
      if (!b[i]) { // 11110 -> min5(i) > r
        mxr = min(mxr, min5(i));
      } else { // 11111 -> min5(i) <= r
        mnr = max(mnr, min5(i));
      }
    }
  }
  cout << mnl + 1 << " " << mxr - 1 << endl;
  // cout << mnl << " " << mxl << endl;
  // cout << mnr << " " << mxr << endl;
  return 0;
}