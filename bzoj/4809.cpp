#include <bits/stdc++.h>
#define N 20
using namespace std;
int mp[N][N], ans, n;
bool x[N<<1], y[N<<1], r[N];
void dfs(int k){
	if(k == n+1){ans++;return;}
	for(int i = 1; i <= n; i++){
		if(mp[k][i]||r[i]||x[k-i+n]||y[k+i]) continue;
		r[i] = x[k-i+n] = y[k+i] = 1;
		dfs(k+1);
		r[i] = x[k-i+n] = y[k+i] = 0;
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &mp[i][j]);
	dfs(1);
	printf("%d\n", ans);
}
