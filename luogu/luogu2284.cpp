#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline long long read(){
  long long x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}
long long a[N], k[N];
int main(int argc, char const *argv[]) {
  long long T = read();
  while (T --) {
    long long n = read();
    for (long long i = 1; i <= n; i++)
      a[i] = read(), k[i] = a[i] - read();
    bool flag = false;
    for (long long i = 1; i <= n && !flag; i++)
      for (long long j = i + 1; j <= n && !flag; j++)
        if ((k[i] - k[j]) % gcd(a[i], a[j]))
          flag = true;
    puts(flag ? "impossible" : "possible");
  }
  return 0;
}
