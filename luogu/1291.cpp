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
ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}
void add(ll &fz, ll &fm, ll a, ll b) {
  // printf("%d %d %d %d\n", fz, fm, a, b);
  fz = fz * b + fm * a;
  fm = fm * b;
  ll g = gcd(fz, fm);
  fz /= g;
  fm /= g;
  // printf("%d %d\n", fz, fm);
}
ll len(ll x) {
  return max(1ll, (ll) floor(log10(x) + 1));
}
int main(int argc, char const *argv[]) {
  ll n = read();
  ll fz = 0, fm = 1;
  for (int i = 1; i <= n; i++)
    add(fz, fm, n, i);
  if (fz % fm) {
    cout << string(len(fz / fm), ' ') << fz % fm << endl;
    cout << fz / fm << string(max(len(fz % fm), len(fm)), '-') << endl;
    cout << string(len(fz / fm), ' ') << fm << endl;
  } else {
    cout << fz / fm << endl;
  }
  return 0;
}