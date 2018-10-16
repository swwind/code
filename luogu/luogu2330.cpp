#include <bits/stdc++.h>
#define INF 100000000

using namespace std;

int f[310][310], n, m, u, v, ans;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) f[i][j] = INF;
			else f[i][j] = 0;
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &u, &v),
		scanf("%d", &f[u][v]),
		f[v][u] = f[u][v];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i != k && k != j && i != j)
					if(f[i][j] > max(f[i][k], f[k][j]))
						f[i][j] = max(f[i][k], f[k][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(f[i][j] > ans)
				ans = f[i][j];
	printf("%d %d\n", n - 1, ans);
	return 0;
}

