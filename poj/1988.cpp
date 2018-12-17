#include <cstdio>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int fa[N], w[N], sz[N];
int find(int x) {
  if (x == fa[x]) return x;
  int fx = find(fa[x]);
  w[x] += w[fa[x]];
  return fa[x] = fx;
}
int query(int x) {
  int fx = find(x);
  return w[x];
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  fa[fx] = fy;
  w[fx] = sz[fy];
  sz[fy] += sz[fx];
}
char str[2];
int main(int argc, char const *argv[]) {
  int p = read(), n = 3e4;
  for (int i = 1; i <= n; ++ i) fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= p; ++ i) {
    scanf("%s", str);
    if (str[0] == 'M') {
      int x = read(), y = read();
      merge(x, y);
    } else {
      int x = read();
      printf("%d\n", query(x));
    }
  }
  return 0;
}