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
struct node {
  int min, max;
  friend bool operator < (const node &a, const node &b) {
    return a.max < b.max;
  }
}a[N];
int b[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    a[i].min = read();
    a[i].max = read();
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    int c = read(), f = read();
    b[c] += f;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i].min; j <= a[i].max; j++) {
      if (b[j]) {
        b[j] --;
        ans ++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}