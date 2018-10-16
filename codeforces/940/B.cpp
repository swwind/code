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
ll n, k, a, b;
ll work(ll x) {
  if (x == 1) return 0;
  if (x < k) return (x-1)*a;
  return min(x%k*a+work(x/k)+b, (x-1)*a);
}
int main(int argc, char const *argv[]) {
  n = read(); k = read(); a = read(); b = read();
  if (k == 1) cout << (n-1)*a << endl;
  else cout << work(n) << endl;
  return 0;
}