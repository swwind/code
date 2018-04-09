#include <bits/stdc++.h>
#define N 100020
#define mod 998244353
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int main(int argc, char const *argv[]) {
  int p = read();
  ll res = 1;
  for (int i = 1; i <= p; i++)
    res = res * i % mod;
  res = res * res % mod * 2 % mod;
  cout << res << endl;
  return 0;
}