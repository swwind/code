#include <bits/stdc++.h>
#define N 520
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N*N], x[N], id[N*N], top, but = 1;
pair<int, int> que[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = n * n;
  for (int i = 1; i <= n; ++ i) {
    x[i] = read();
    id[x[i]] = a[x[i]] = i;
  }
  for (int i = 1; i <= m; ++ i) {
    if (id[i] > 1) {
      que[++ top] = make_pair(id[i], id[i] - 1);
    }
  }
  but = 1;
  for (int i = 1; i <= m && but <= top; ++ i) {
    if (!a[i]) {
      a[i] = que[but].first;
      if (!--que[but].second) {
        ++ but;
      }
    }
    if (id[i] && que[but].first == id[i]) {
      return puts("No"), 0;
    }
  }

  top = 0;
  for (int i = m; i; -- i) {
    if (id[i] && id[i] != n) {
      que[++ top] = make_pair(id[i], n - id[i]);
    }
  }

  but = 1;
  for (int i = m; i && but <= top; -- i) {
    if (!a[i]) {
      a[i] = que[but].first;
      if (!--que[but].second) {
        ++ but;
      }
    }
    if (id[i] && que[but].first == id[i]) {
      return puts("No"), 0;
    }
  }

  puts("Yes");
  for (int i = 1; i <= m; ++ i) {
    printf("%d ", a[i]);
  } puts("");

  return 0;
}
/*

把左边的尽可能往左边放，右边的尽可能往右边放即可。

3
1 8 6

1         3   2  
1 3 3 2   3   2  
1 3 3 2 1 3 1 2 2

*/