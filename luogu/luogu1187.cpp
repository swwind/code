#include <bits/stdc++.h>
using namespace std;
int mp[1020][1020],n, m,ans;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%1d", &mp[i][j]);if(mp[i][j])ans+=2;
			ans += abs(mp[i-1][j]-mp[i][j])+abs(mp[i][j-1]- mp[i][j]);
		}
	for(int i = 1; i <= m; i++)
		ans += mp[n][i];
	for(int i = 1; i <= n; i++)
		ans += mp[i][m];
	printf("%d\n", ans);
}