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
  int n = read();
  double ans = 0, x = read(), d = read();

  int m = 2 * n;
  while (m) {
    ans += x+(m-1)*d/2.0;
    x = (2.0*x+5.0*d)/m+x;
    d = (m+4.0)*d/m;
    m -= 2;
  }

  printf("%.15lf\n", ans);

  return 0;
}
/*

转化题面：

  有 2*n+1 个点，每次随机选择两个当前相邻的点删去，答案加上他们的距离，问答案的期望。
  每两个点之间的距离是个等差数列。

我们有结论：

  操作一次后的期望序列相邻点之间的距离仍然是等差数列。

考虑如何计算。

假设距离为 { x, x+d, x+2d, x+3d, ..., x+(m-1)d }

我们要删除的边的期望为：

  ans = (mx+(m-1)md/2)/m
      = x+(m-1)d/2

设删除之后首项变为 x'。

- 如果选的是最左边的两条边，x' = x+2d
- 如果选的是左边的三四条边，x' = 3x+3d
- 其余情况，x' = x

  x' = (x+2d)/m + (3x+3d)/m + x*(m-2)/m
     = (2x+5d)/m+x

然后根据期望守恒算出 d'。

  d' = (m+4)d/m  (???)

如此迭代计算即可。

*/