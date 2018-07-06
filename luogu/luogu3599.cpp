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
void work1(int n) {
  if ((n & 1) && (n > 1)) {
    puts("0");
    return;
  }
  printf("2");
  for (int i = 1; i <= n; ++ i) {
    if (i & 1) printf(" %d", n - i + 1);
    else       printf(" %d", i - 1);
  }
  puts("");
}
bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++ i)
    if (x % i == 0) return false;
  return true;
}
ll fast_pow(ll x, ll y, int p) {
  ll z = 1;
  for (; y; y >>= 1, x = x * x % p)
    if (y & 1) z = z * x % p;
  return z;
}
ll inv(ll x, int p) {
  return fast_pow(x, p - 2, p);
}
void work2(int n) {
  if (n == 4) {
    puts("2 1 3 2 4");
    return;
  }
  if (!isPrime(n)) {
    puts("0");
    return;
  }
  printf("2 1");
  for (int i = 2; i <= n; ++ i) {
    int res = i * inv(i - 1, n) % n;
    if (!res) res = n;
    printf(" %d", res);
  }
  puts("");
}
int main(int argc, char const *argv[]) {
  int t = read(), n = read();
  for (int i = 1; i <= n; ++ i) {
    if (t == 1) work1(read());
    else        work2(read());
  }
  return 0;
}