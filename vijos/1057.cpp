#include <bits/stdc++.h>
#define ll long long
#define mins(a, b, c) min(a, min(b, c));
using namespace std;
int f[1050][1050], n, m, ans;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d", &f[i][j]);
			if(f[i][j])
				f[i][j] += mins(f[i-1][j-1], f[i-1][j], f[i][j-1]);
			ans = max(ans, f[i][j]);
		}
	printf("%d", ans);
	return 0;
}

