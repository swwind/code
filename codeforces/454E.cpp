#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int n, m, x, y, s;
int vis[N], c[N], ans[N<<2];
vector<int> g[N];
void add(int x){
	c[x] ^= 1;
	ans[++ans[0]] = x;
}
void dfs(int x){
	add(x);
	vis[x] = 1;
	for(int i = 0; i < g[x].size(); i++){
		if(vis[g[x][i]]) continue;
		dfs(g[x][i]);
		add(x);
		if(c[g[x][i]]){
			add(g[x][i]);
			add(x);
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", c+i);
		if(c[i]) s = i;
	}
	dfs(s);
	if(c[s]) c[s] = 0, ans[0]--;
	for(int i = 1; i <= n; i++) if(c[i]) return puts("-1")*0;
	printf("%d\n", ans[0]);
	for(int i = 1; i <= ans[0]; i++) printf("%d ", ans[i]);
	return 0;
}

