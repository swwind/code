#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int transform(int x) {
  int ans = 0;
  while (x) {
    int s = x % 10;
    ans += s * s;
    x /= 10;
  }
  return ans;
}

int gugugu(int x) {
  if (x == 1) return true;
  for (int i = 1; i <= 500; ++ i) {
    x = transform(x);
    if (x == 1) return true;
  }
  return false;
}

int a[N], suck[1020];

int main() {
  int cnt = 0;
  for (int i = 1; i <= 1000; ++ i) {
    suck[i] = gugugu(i);
    if (suck[i]) a[++ cnt] = i;
  }
  for (int i = 1001; cnt <= 150000; ++ i) {
    if (suck[transform(i)]) {
      a[++ cnt] = i;
    }
  }
  int q = read();
  while (q --) {
    printf("%d\n", a[read()]);
  }
}