#include <bits/stdc++.h>
#define N 200020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], to[N << 1], nxt[N << 1], cnt = 1;
void link(int x, int y) {
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int dfn[N], low[N], tot, que[N], qnt, blo[N], bnt, blk, block[N];
int vis[N << 1], in[N];
int tarjan(int x) {
	dfn[x] = low[x] = ++tot;
	que[++qnt] = x; block[x] = blk;
	in[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		if (vis[i]) continue;
		if (!dfn[to[i]]) {
			vis[i] = vis[i ^ 1] = 1;
			tarjan(to[i]);
			low[x] = min(low[x], low[to[i]]);
		} else if (in[to[i]]) low[x] = min(low[x], dfn[to[i]]);
	}
	if (dfn[x] == low[x] && ++bnt)
		while (que[qnt + 1] != x)
			blo[que[qnt]] = bnt, in[que[qnt--]] = 0;
}
int fa[N][20], dep[N];
void dfs(int x, int f) {
	vis[x] = 1;
	dep[x] = dep[f] + 1;
	fa[x][0] = f;
	for (int i = head[x]; i; i = nxt[i])
		if (f != to[i]) dfs(to[i], x);
}
int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	int t = dep[x] - dep[y];
	for (int i = 19; ~i; i--)
		if (t >> i & 1)
			x = fa[x][i];
	for (int i = 19; ~i; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return x == y ? x : fa[x][0];
}
int x[N], y[N], f[N], g[N];
void get(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa[x][0])
			continue;
		get(to[i]);
		f[x] += f[to[i]];
		g[x] += g[to[i]];
	}
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read(), q = read();
	for (int i = 1; i <= m; i++) {
		x[i] = read();
		y[i] = read();
		link(x[i], y[i]);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) blk++, tarjan(i);
	memset(vis, 0, sizeof vis);
	memset(head, 0, sizeof head);
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		int xx = blo[x[i]], yy = blo[y[i]];
		if (xx != yy)
			link(xx, yy);
	}
	for (int i = 1; i <= bnt; i++)
		if (!vis[i]) dfs(i, 0);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= bnt; j++)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 1; i <= q; i++) {
		int x = read(), y = read();
		if (block[x] != block[y])
			return puts("No") & 0;
		x = blo[x], y = blo[y];
		int z = lca(x, y);
		// printf("lca(%d, %d) => %d\n", x, y, z);
		f[z]--; f[x]++;
		g[z]--; g[y]++;
	}
	for (int i = 1; i <= bnt; i++)
		if (!vis[i]) get(i);
	for (int i = 1; i <= bnt; i++)
		if (f[i] && g[i]) return puts("No") & 0;
	puts("Yes");
	return 0;
}