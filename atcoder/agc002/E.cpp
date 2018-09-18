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
int a[N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  for (int i = 1; i <= n; ++ i) {
    if (i >= a[i + 1]) {
      bool res = 1;
      for (int j = i+1; j <= n && a[j] == i; ++ j) {
        res ^= 1;
      }
      res &= (a[i]-i+1)&1;
      return puts(res ? "Second" : "First"), 0;
    }
  }
  return 0;
}
/*
排序，将每堆糖果看成一个 ai*1 的矩阵。

x
x x
x x x
-----
3 2 1

每次操作相当于删除最下面一行或者删除最左边一列。

可以发现 (x, y) = (x - 1, y - 1)

于是开局直接往右上角走，有三种情况。
(0-first,1-second)

1)

xxx 1
xxx 0
xx/ 1
x/x 0
/xx 1
  i

ans = !odd(a[i]-i)

2)

010101

xx/xxx
x/xxxx
/xxxxx
  i  j

ans = !odd(j-i)

3)

xxx
xxx
xx/xxx
x/xxxx
/xxxxx
  i  j

ans = !odd(a[i]-i) && !odd(a[i]-i)

*/