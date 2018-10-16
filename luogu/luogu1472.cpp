#include <bits/stdc++.h>
#define MOD 9901
using namespace std;

int n, m, dp[200][100];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		dp[1][i] = 1;
	for(int j = 1; j <= m; j++)
		for(int i = 1; i <= n; i += 2)
			for(int k = 1; k < i - 1; k++)
				dp[i][j] = (dp[i][j] + dp[k][j-1] * dp[i-1-k][j-1]) % MOD;
	printf("%d", (dp[n][m] + MOD - dp[n][m-1]) % MOD);
	return 0;
}
