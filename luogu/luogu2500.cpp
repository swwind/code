// 据说暴力能过。。。

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int b[N]; // 0 -> A, 1 -> B, 2 -> C
struct node {
  int x, y, w;
  friend bool operator < (const node &a, const node &b) {
    return a.w < b.w;
  }
}a[N];
char ch[10];
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    a[i].x = read();
    a[i].y = read();
    a[i].w = read();
  }
  sort(a + 1, a + m + 1);
  int q = read();
  while (q --) {
    scanf("%s", ch + 1);
    if (ch[1] == 'M') { // MoveX
      int x = read();
      b[x] = ch[5] - 'A';
    } else { // AskXY
      int x = ch[4] - 'A', y = ch[5] - 'A';
      int ans = -1;
      for (int i = 1; i <= m; i++) {
        if (b[a[i].x] == x && b[a[i].y] == y ||
            b[a[i].x] == y && b[a[i].y] == x) {
          ans = a[i].w;
          break;
        }
      }
      if (ans == -1) puts("No Found!");
      else printf("%d\n", ans);
    }
  }
  return 0;
}