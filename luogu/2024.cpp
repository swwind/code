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
int fa[N];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  fa[x] = y;
}
int nope;
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 0; i < (n * 3); i++)
    fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int op = read(), x = read() - 1, y = read() - 1;
    if (x >= n || y >= n) {
      nope ++;
      continue;
    }
    if (op == 1) { // x は y を食べらない
      if (find(x * 3) == find(y * 3 + 1) ||
          find(x * 3) == find(y * 3 + 2)) {
        nope ++;
        continue;
      }
      merge(x * 3, y * 3);
      merge(x * 3 + 1, y * 3 + 1);
      merge(x * 3 + 2, y * 3 + 2);
    } else { // x は y を食べる
      if (find(x * 3) == find(y * 3) ||
          find(x * 3) == find(y * 3 + 2)) {
        nope ++;
        continue;
      }
      merge(x * 3, y * 3 + 1);
      merge(x * 3 + 1, y * 3 + 2);
      merge(x * 3 + 2, y * 3);
    }
  }
  cout << nope << endl;
  return 0;
}