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
int main(int argc, char const *argv[]) {
  int n = read(), k = read();

  if (k == 1 || k == 2 * n - 1) {
    return puts("No"), 0;
  }

  puts("Yes");

  if (n == 2) {
    return printf("1\n2\n3\n"), 0;
  }

  if (k == 2) {

    for (int i = 1; i <= n - 2; ++ i) {
      printf("%d\n", i + 4);
    }

    printf("3\n2\n1\n4\n");

    for (int i = 1; i <= n - 3; ++ i) {
      printf("%d\n", i + n + 2);
    }

    return 0;

  }

  int cnt = 1;

  for (int i = 1; i <= n - 2; ++ i){
    if (cnt == k - 2) {
      cnt = k + 2;
    }
    printf("%d\n", cnt ++);
  }

  printf("%d\n%d\n%d\n%d\n", k-1, k, k+1, k-2);

  for (int i = 1; i <= n - 3; ++ i) {
    if (cnt == k - 2) {
      cnt = k + 2;
    }
    printf("%d\n", cnt ++);
  }

  return 0;
}
/*

如果 k == 1 || k == 2*n-1 无解（显然）。

    x
   0xx
  00xx0
 000xx00
000000000

如果在中间列出现了两个连续的x，那么最终结果一定是x。

所以只要构造中间四个即可。。

  (x-1) x (x+1) (x-2)

注意如果 x == 2

  (x+1) x (x-1) (x+2)
    3   2   1     4

*/