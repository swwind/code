#include <bits/stdc++.h>
#define N 400020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int to[N], head[N], nxt[N], init[N], cnt, q[N];
void insert(int x, int y) {
	// printf("%d -> %d\n", x, y);
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	init[y]++;
}
int fa[N], wt[N], used[N], ans;
std::vector<int> son[N];
void dfs(int x) {
	int y = fa[x], z = wt[y];
	if (y) {
		if (wt[x] != z && wt[x] != y && wt[x] != x)
			exit(puts("-1") & 0);
		if (wt[x] == y)
			insert(y, x);
		else if (wt[x] == z)
			insert(z, x);
		else if (wt[x] == x)
			insert(x, z);
	} else {
		if (wt[x] != x)
			exit(puts("-1") & 0);
	}
	for (auto s : son[x])
		dfs(s);
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		son[x].push_back(y);
		fa[y] = x;
	}
	for (int i = 1; i <= n; i++) {
		wt[i] = read();
		if (!used[wt[i]]) {
			ans ++;
			used[wt[i]] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!fa[i]) dfs(i);
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
		if (!init[i]) q[++r] = i;
	printf("%d\n", ans);
	while (l < r) {
		int x = q[++l];
		if (used[x])
			printf("%d\n", x);
		for (int i = head[x]; i; i = nxt[i])
			if (!--init[to[i]]) q[++r] = to[i];
	}
	return 0;
}
