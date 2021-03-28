#include <cstdio>
#include <cstring>
#include <algorithm>
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

int head[N], nxt[N<<1], to[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int f[2][N];

void dfs(int x, int fa) {
  f[1][x] = a[x];
  f[0][x] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    if (fa == to[i]) continue;
    dfs(to[i], x);
    f[0][x] = max(f[0][x], f[0][x] + max(f[1][to[i]], f[0][to[i]]));
    f[1][x] = max(f[1][x], f[1][x] + f[0][to[i]]);
  }
}

int main() {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  for (int i = 1; i < n; ++ i) {
    int x = read(), y = read();
    insert(x, y);
  }

  dfs(1, 1);
  printf("%d\n", max(f[0][1], f[1][1]));
}

