#include <bits/stdc++.h>
#define N 10020
#define M 50020
#define Q 30020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct road {
	int x, y, z;
	friend bool operator < (const road &a, const road &b) {
		return a.z > b.z;
	}
} r[M];
struct ask {
	int x, y;
} a[Q];
int nxt[N<<1], to[N<<1], head[N], cnt, val[N<<1];
void ins(int x, int y, int z) {
	// printf("edge : (%d, %d) = %d\n", x, y, z);
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = z;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = z;
}
int fa[N][20], mn[N][20], dep[N], _fa[N];
void dfs(int x, int f, int l) {
	fa[x][0] = f;
	dep[x] = dep[f]+1;
	if (mn[x][0]) {
		mn[x][0] = max(mn[x][0], l);
		return;
	}
	mn[x][0] = l;
	for (int i = head[x]; i; i = nxt[i])
		if (to[i] != f) dfs(to[i], x, val[i]);
}
int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 15; ~i; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y) return x;
	for (int i = 15; ~i; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int find(int x){return _fa[x]==x?x:_fa[x]=find(_fa[x]);}
int dis(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	int t = dep[x]-dep[y], ans = 1<<30;
	// printf("%d -> %d: ", x, y, t);
	for (int i = 15; ~i; i--)
		if (t>>i&1) {
			ans = min(ans, mn[x][i]);
			x = fa[x][i];
		}
	// printf("%d\n", ans);
	return ans;
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) _fa[i] = i;
	for (int i = 1; i <= m; i++) {
		r[i].x = read();
		r[i].y = read();
		r[i].z = read();
	}
	sort(r+1, r+m+1);
	for (int i = 1; i <= m; i++) {
		int x = find(r[i].x), y = find(r[i].y);
		if (x == y) continue;
		_fa[x] = y;
		ins(r[i].x, r[i].y, r[i].z);
	}
	for (int i = 1; i <= n; i++)
		dfs(1, 0, 0);
	for (int i = 1; i <= 15; i++)
		for (int j = 1; j <= n; j++) {
			fa[j][i] = fa[fa[j][i-1]][i-1];
			mn[j][i] = min(mn[j][i-1], mn[fa[j][i-1]][i-1]);
		}
	int q = read();
	for (int i = 1; i <= q; i++) {
		int x = read(), y = read();
		if (find(x) != find(y)) {
			puts("-1");
			continue;
		}
		int z = lca(x, y);
		// printf("LCA:%d\n", z);
		printf("%d\n", min(dis(x, z), dis(y, z)));
	}
	// printf("[%d]\n", mn[3][1]);
	return 0;
}