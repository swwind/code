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
int main(int argc, char const *argv[]) {
  ll I = read(), O = read(), T = read(),
    J = read(), L = read(), S = read(), Z = read();
  ll ans = O;
  if (!I || !J || !L) {
    ans += I >> 1 << 1;
    ans += L >> 1 << 1;
    ans += J >> 1 << 1;
  } else if ((J & 1) == (L & 1) && (L & 1) == (I & 1)) {
    ans += I + J + L;
  } else {
    ans += I + J + L - 1;
  }
  printf("%lld\n", ans);
  return 0;
}
/*

OO | J IIII L | iiii | J jjj | LLL l
OO | JJJ  LLL | IIII | JJJ j | L lll


*/