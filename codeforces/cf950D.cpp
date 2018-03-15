#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int main(int argc, char const *argv[]) {
  ll n = read(), m = read();
  while (m --) {
    ll x = read();
    while (x % 2 == 0)
      x = (x >> 1) + n;
    printf("%lld\n", x + 1 >> 1);
  }
  return 0;
}