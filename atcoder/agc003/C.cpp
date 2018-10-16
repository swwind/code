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
int a[N], b[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    b[i] = a[i] = read();
  }
  sort(b + 1, b + n + 1);
  int *end = unique(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++ i) {
    a[i] = lower_bound(b + 1, end, a[i]) - b;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += (a[i] & 1) ^ (i & 1);
  }
  printf("%d\n", ans >> 1);
  return 0;
}
/*
离散化，奇数必定在奇数位，偶数必定在偶数位。
否则必须使用操作 1 将其调换。
*/