#include <bits/stdc++.h>
#define N 15020
using namespace std;
const int inf = 1 << 30;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct edge{
	int x, y, c;
	bool operator < (const edge &b) const {
		return c < b.c;
	}
}e[N<<1];
int fa[N][20], fm[N][20], _fa[N], to[N<<1], nxt[N<<1], head[N], val[N<<1], dep[N], cnt;
int find(int x){return _fa[x]==x?x:_fa[x]=find(_fa[x]);}
void add(int x){
	to[++cnt] = e[x].x; nxt[cnt] = head[e[x].y]; head[e[x].y] = cnt; val[cnt] = e[x].c;
	to[++cnt] = e[x].y; nxt[cnt] = head[e[x].x]; head[e[x].x] = cnt; val[cnt] = e[x].c;
}
void dfs(int x, int f){
	fa[x][0] = f; dep[x] = dep[f]+1;
	for(int i = head[x]; i; i = nxt[i])if(to[i]!=f){
		fm[to[i]][0] = val[i];
		dfs(to[i], x);
	}
}
int ask(int x, int y){
	int ans = 0;
	if(dep[x] < dep[y]) swap(x, y);
	for(int j = 14; ~j; j--)
		if(dep[fa[x][j]] >= dep[y])
			ans = max(ans, fm[x][j]), x = fa[x][j];
	if(x == y) return ans;
	for(int j = 14; ~j; j--)
		if(fa[x][j] != fa[y][j]){
			ans = max(ans, fm[x][j]);
			ans = max(ans, fm[y][j]);
			x = fa[x][j]; y = fa[y][j];
		}
	ans = max(ans, fm[x][0]);
	ans = max(ans, fm[y][0]);
	return ans;
}
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) _fa[i] = i;
	for(int i = 1; i <= m; i++)
		e[i].x = read(), e[i].y = read(), e[i].c = read();
	sort(e+1, e+m+1);
	for(int i = 1; i <= m; i++){
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		_fa[x] = y; add(i);
	}
	dfs(1, 0);
	for(int j = 1; j <= 14; j++) for(int i = 1; i <= n; i++){
		fa[i][j] = fa[fa[i][j-1]][j-1];
		fm[i][j] = max(fm[i][j-1], fm[fa[i][j-1]][j-1]);
	}
	for(int i = 1; i <= k; i++)
		printf("%d\n", ask(read(), read()));
}