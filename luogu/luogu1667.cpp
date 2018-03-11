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
ll a[N], b[N], c[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    b[i] = a[i] = a[i - 1] + read();
  sort(b + 1, b + n + 1);
  int m = unique(b, b + n + 1) - b - 1;
  if (n != m) return puts("-1"), 0;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(b, b + n + 1, a[i]) - b;
  for (int i = 1; i <= n; i++)
    c[a[i]] = i; // i is in the position c[i]
  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      // int x = c[i]; // position of i
      a[c[i]] = a[i];
      c[a[i]] = c[i];
      a[i] = i;
      c[i] = i;
    } else {
      ans --;
    }
  }
  cout << ans << endl;
  return 0;
}