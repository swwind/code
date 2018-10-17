#include <bits/stdc++.h>
#define zyy 12345678
using namespace std;
int n, m, k;
int f[320][155][22][22];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	f[0][0][0][0] = 1;
	for(int i = 0; i < n+m; ++i) for(int j = 0; j <= n; ++j)
	for(int x = 0; x <= k; ++x) for(int y = 0; y <= k; ++y){
		if(x < k && j < n)
			(f[i+1][j+1][x+1][max(y-1, 0)] += f[i][j][x][y]) %= zyy;
		if(y < k && i-j < m)
			(f[i+1][j][max(x-1, 0)][y+1] += f[i][j][x][y]) %= zyy;
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i)
	for(int x = 0; x <= k; ++x)
	for(int y = 0; y <= k; ++y)
		(ans += f[n+m][i][x][y]) %= zyy;
	printf("%d\n", ans);
}