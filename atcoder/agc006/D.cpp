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
int a[N];
bool b[N];
int n, sz;
bool check(int x) {
  for (int i = 1; i <= sz; ++ i) {
    b[i] = a[i] <= x;
  }

  int rp = 0;
  for (int i = n + 1; i <= sz; ++ i) {
    if (b[i] == b[i - 1]) {
      rp = i - n;
      break;
    }
  }

  int lp = 0;
  for (int i = n - 1; i; -- i) {
    if (b[i] == b[i + 1]) {
      lp = n - i;
      break;
    }
  }

  if (!rp && !lp) return b[1];

  if (!rp) return b[n - lp];
  if (!lp) return b[n + rp];

  if (rp == lp) return b[n - lp];

  // printf("%d %d\n", lp, rp);
  if (rp < lp) {
    return b[n + rp];
  } else {
    return b[n - lp];
  }

}

int main(int argc, char const *argv[]) {

  n = read(); sz = 2 * n - 1;
  for (int i = 1; i <= sz; ++ i) {
    a[i] = read();
  }

  int l = 1, r = sz;

  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid - 1;
    else l = mid + 1;
  }

  printf("%d\n", r + 1);

  return 0;
}
/*

二分答案，将每个小于等于 mid 的都看成 1，其余看成 0。

与 B 题同样的思想，有两个相邻的 0 或者相邻的 1，会一直冲到最顶上。
判断离中线最近的一根柱子即可。

    1 6 3 7 4 5 2
    
1:  1 0 0 0 0 0 0 false
2:  1 0 0 0 0 0 1 false
3:  1 0 1 0 0 0 1 false
4:  1 0 1 0 1 0 1 true
5:  1 0 1 0 1 1 1 true
6:  1 1 1 0 1 1 1 true
7:  1 1 1 1 1 1 1 true

如果没有相邻的数字，那么答案就是第一个元素。

      1
    1 0 1
  1 0 1 0 1
1 0 1 0 1 0 1

复杂度 O(nlogn)

*/