#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mod 10007
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char str[N];
int main(int argc, char const *argv[]) {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  ll x = 0;
  for (int i = 1; i <= len; i++)
    x = (x * 10 + str[i] - '0') % mod;
  x = x * (x + 1) % mod * (x + 2) % mod * 1668 % mod;
  x = (x + mod) % mod;
  printf("%lld\n", x);
  return 0;
}