#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define M 1000005
using namespace std;
struct edge{
	int to, next;}
e[M<<1];
int n, tot = 1, v[M], to, vis[M], head[M], U, V, E;
ll f[M][2], ans;
void add(int u, int v){
	e[++tot].to = v;
	e[tot].next = head[u];
	head[u] = tot;}
void dfs(int x, int fa){
	vis[x] = 1;
	for(int i = head[x]; i; i = e[i].next)
		if(e[i].to == fa) continue;
		else if(!vis[e[i].to]) dfs(e[i].to, x);
		else U = x, V = e[i].to, E = i;}
void tree_dp(int x, int fa){
	f[x][1] = v[x]; f[x][0] = 0;
	for(int i = head[x]; i; i = e[i].next){
		int to = e[i].to;
		if((i>>1) == (E>>1) || to == fa) continue;
		tree_dp(to, x);
		f[x][1] += f[to][0];
		f[x][0] += max(f[to][0], f[to][1]);}}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &v[i], &to),
		add(i, to), add(to, i);
	for(int i = 1; i <= n; i++)
		if (!vis[i]){
			dfs(i, -1);
			tree_dp(U, -1);
			ll temp = f[U][0];
			tree_dp(V, -1);
			temp = max(f[V][0], temp);
			ans += temp;}
	return printf("%lld", ans)*0;}
