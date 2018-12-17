// 倍增求 lca

#include <bits/stdc++.h>
#define ll long long
#define oo 1<<30
#define ESP 1e-9
#define read(a) scanf("%d", &a)
#define write(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define obs(a) a&1
#define mst(a, b) memset(a, b, sizeof a)
#define rep(a, b, c) for(int a = b; a < c; a ++)
#define N 500020

using namespace std;

struct Bilibili{
	int to, next;
} e[N<<1];
int vis[N], f[N][30], m, x, y, z, head[N], dep[N], cnt, n, s;

void insert(int a, int b){
	e[++cnt].to = a;
	e[cnt].next = head[b];
	head[b] = cnt;
}

void dfs(int x){
	vis[x] = 1;
	for(int i = 1; i <= 25 && dep[x]>=(1<<i); i++)
		f[x][i] = f[f[x][i-1]][i-1];
	for(int i = head[x]; i; i = e[i].next){
		if(vis[e[i].to]) continue;
		dep[e[i].to] = dep[x] + 1;
		f[e[i].to][0] = x;
		dfs(e[i].to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y];
	for(int i = 0; i <= 25; i++)
		if(t&(1<<i)) x = f[x][i];
	for(int i = 25; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
}

int main(){
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i < n; i++)
		scanf("%d%d", &x, &y),
		insert(x, y), insert(y, x);
	// puts("Read Done.");
	dfs(s);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}
