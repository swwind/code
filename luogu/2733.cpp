#include <bits/stdc++.h>

int n, f[251][251];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%1d", &f[i][j]),
			f[i][j] = f[i][j] + f[i][j-1]
				+ f[i-1][j] - f[i-1][j-1];
	for(int i = 2; i <= n; i++){
		int ans = 0;
		for(int j = 1; j <= n-i+1; j++)
			for(int k = 1; k <= n-i+1; k++)
				if(f[j+i-1][k+i-1] + f[j-1][k-1] - f[j+i-1][k-1] - f[j-1][k+i-1] == i*i)
					ans++;
		if(ans)
			printf("%d %d\n", i, ans);
	}
	return 0;
}

