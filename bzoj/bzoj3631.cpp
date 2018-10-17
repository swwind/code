#include <bits/stdc++.h>
#define N 300020
#define M 20
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<1], nxt[N<<1], head[N], cnt, fa[N][M], dep[N], b[N], a[N];
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void dfs(int x, int f){
	fa[x][0] = f;
	dep[x] = dep[f]+1;
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != f) dfs(to[i], x);
}
void dfs(int x){
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != fa[x][0]) dfs(to[i]), b[x] += b[to[i]];
}
int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = M; i; i--)
		if(dep[fa[a][i-1]] >= dep[b])
			a = fa[a][i-1];
	if(a == b) return a;
	for(int i = M; i; i--)
		if(fa[a][i-1] != fa[b][i-1])
			a = fa[a][i-1], b = fa[b][i-1];
	return fa[a][0];
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i < n; i++) ins(read(), read());
	dfs(1, 0);
	for(int j = 1; j < M; j++)
		for(int i = 1; i <= n; i++)
			if(fa[i][j-1]) fa[i][j] = fa[fa[i][j-1]][j-1];
	for(int i = 1; i < n; i++){
		int lc = lca(a[i], a[i+1]);
		b[a[i]]++; b[fa[a[i+1]][0]]++;
		b[lc]--; b[fa[lc][0]]--;
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
		printf("%d\n", b[i]);
	return 0;
}