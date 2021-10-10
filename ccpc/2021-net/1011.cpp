#include <bits/stdc++.h>
#define N 100020

using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int a[N], b[N];

int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int fa[N];

int find(int x) {
  return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int head2[N], to2[N], nxt2[N], cnt2;
void insert2(int x, int y) {
  to2[++ cnt2] = y; nxt2[cnt2] = head2[x]; head2[x] = cnt2;
}

int ans[N];
void dfs(int x, int dep) {
  ans[x] = dep;
  for (int i = head2[x]; i; i = nxt2[i]) {
    dfs(to2[i], dep + 1);
  }
}

int main() {
  int T = read();
  while (T --) {
    int n = read();
    cnt = 0; cnt2 = 0;
    for (int i = 1; i <= n; ++ i) {
      head[i] = 0;
      head2[i] = 0;
      b[i] = i;
      fa[i] = i;
    }
    for (int i = 1; i < n; ++ i) {
      insert(read(), read());
    }
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
    }
    sort(b + 1, b + n + 1, [&] (const int &A, const int &B) {
      return a[A] < a[B];
    });
    for (int i = 1; i <= n; ++ i) {
      // adding node b[i]
      int x = b[i];
      // printf("adding %d\n", x);
      for (int j = head[x]; j; j = nxt[j]) {
        if (a[to[j]] > a[x]) continue;
        int y = find(to[j]);
        insert2(x, y);
        // printf("%d -> %d\n", x, y);
        fa[y] = x;
      }
    }
    int rt = find(1);
    dfs(rt, 1);

    for (int i = 1; i <= n; ++ i) {
      printf("%d\n", ans[i]);
    }
  }
}