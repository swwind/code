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
int a[N], sum, ans;
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1, flag = 0, l = 0; i <= n; i++) {
    a[i] = read();
    sum += a[i];
    ans += 1;
    if (sum >= 0 && flag) {
      flag = 0;
      ans += (i - l) * 2;
    }
    if (sum < 0 && !flag) {
      flag = 1;
      l = i;
    }
  }
  cout << ans << endl;
  return 0;
}