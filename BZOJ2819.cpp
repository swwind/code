#include <bits/stdc++.h>
#define N 500020
#define M 20
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<1], nxt[N<<1], head[N], cnt, ls[N], rs[N], tot, fa[N][M], c[N], dep[N], a[N];
char ch[5];
void add(int x, int v){
	for(;x<N;x+=x&-x)c[x]^=v;
}
int ask(int x){
	int ans = 0;
	for(;x;x^=x&-x)ans^=c[x];
	return ans;
}
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void dfs(int x, int f){
	ls[x] = ++tot;
	dep[x] = dep[f]+1;
	fa[x][0] = f;
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != f) dfs(to[i], x);
	rs[x] = tot;
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = M-1; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if(x == y) return x;
	for(int i = M-1; i >= 0; i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i < n; i++) ins(read(), read());
	dfs(1, 0);
	for(int j = 1; j < M; j++)
		for(int i = 1; i <= n; i++)
			if(fa[i][j-1]) fa[i][j] = fa[fa[i][j-1]][j-1];
	int m = read();
	for(int i = 1; i <= n; i++)
		add(ls[i], a[i]), add(rs[i]+1, a[i]);
	for(int i = 1; i <= m; i++){
		scanf("%s", ch);int x = read(), y = read();
		if(ch[0] == 'Q')
			puts(ask(ls[x])^ask(ls[y])^a[lca(x, y)] ? "Yes":"No");
		else{
			add(ls[x], a[x]), add(rs[x]+1, a[x]);
			a[x] = y;
			add(ls[x], a[x]), add(rs[x]+1, a[x]);
		}
	}
	return 0;
}