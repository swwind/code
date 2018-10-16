#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;
int f[10000][2], n, x, y, vis[10000], fa[10000];
vector<int> v[10000];
void dfs(int x){
	vis[x] = 1;
	for(int i = 0; i < v[x].size(); i++){
		int s = v[x][i];
		if(vis[s]) continue;
		dfs(s);
		f[x][0] += max(f[s][1], f[s][0]);
		f[x][1] += f[s][0];
	}
}
int main(){
	while(~scanf("%d", &n)){
		memset(f, 0, sizeof f);
		memset(fa, 0, sizeof fa);
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++)
			v[i].clear(),
			scanf("%d", &f[i][1]);
		while(scanf("%d%d", &x, &y) != EOF && x && y)
			v[y].push_back(x),
			fa[x]++;
		int k = 1;
		while(fa[k])k++;
		dfs(k);
		printf("%d\n", max(f[k][0], f[k][1]));
	}
	return 0;
}

