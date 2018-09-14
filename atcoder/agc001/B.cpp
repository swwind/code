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
ll resolve(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return 2 * a - b;
  return 2 * b * (a / b) + resolve(b, a % b);
}
int main(int argc, char const *argv[]) {
  ll n = read(), p = read();
  printf("%lld\n", resolve(p, n - p) + n);
  return 0;
}