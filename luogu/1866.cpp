#include <bits/stdc++.h>
#define N 100020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i)
    a[i] = read();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++ i) {
    if (a[i] < i) {
      puts("0");
      return 0;
    }
  }
  long long ans = 1;
  for (int i = 1; i <= n; ++ i) {
    ans = ans * (a[i] - i + 1) % mod;
  }
  cout << ans << endl;
  return 0;
}