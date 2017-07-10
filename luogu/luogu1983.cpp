#include<bits/stdc++.h>
#define N 2005
using namespace std;
int n, m, ans, a[N], s, vis[N], f[N];
vector<int> to[N];
void dfs(int u){
	if(f[u]) return;
	f[u] = 1;
	for(int i = 0; i < to[u].size(); i++) {
		if(!f[to[u][i]])
			dfs(to[u][i]);
		f[u] = max(f[u], f[to[u][i]] + 1);
	}
	if(u>n) f[u]--;
	ans = max(ans, f[u]);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", &s);
		memset(vis, 0, sizeof vis);
		for(int j = 1; j <= s; j++)
			scanf("%d", &a[j]),
			vis[a[j]] = 1,
			to[n+i].push_back(a[j]);
		for(int j = a[1]+1; j < a[s]; j++)
			if(!vis[j])
				to[j].push_back(n+i);
	}
	for(int i = 1; i <= n; i++)
		if(!f[i])
			dfs(i);
	printf("%d", ans);
	return 0;
}

