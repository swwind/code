#include <bits/stdc++.h>
#define zyy 100000000
using namespace std;
int f[2][5020], g[2][5020];
char s1[5020], s2[5020];
int main(){
	scanf("%s%s", s1+1, s2+1);
	int n = strlen(s1+1)-1, m = strlen(s2+1)-1;
	for(int i = 0; i <= m; i++)
		g[0][i] = 1;
	g[1][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1, k=i&1, l = !k; j <= m; j++)
			if(s1[i] == s2[j]){
				f[k][j] = f[l][j-1]+1;
				g[k][j] = g[l][j-1];
				if(f[k][j] == f[l][j]) g[k][j] = (g[k][j]+g[l][j])%zyy;
				if(f[k][j] == f[k][j-1]) g[k][j] = (g[k][j]+g[k][j-1])%zyy;
			}
			else{
				f[k][j] = max(f[l][j], f[k][j-1]);
				g[k][j] = 0;
				if(f[k][j] == f[l][j]) g[k][j] = (g[k][j]+g[l][j])%zyy;
				if(f[k][j] == f[k][j-1]) g[k][j] = (g[k][j]+g[k][j-1])%zyy;
				if(f[k][j] == f[l][j-1]) g[k][j] = (g[k][j]-g[l][j-1])%zyy;
			}
	}
	return printf("%d\n%d\n", f[n&1][m], (g[n&1][m]+zyy)%zyy)&0;
}