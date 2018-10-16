#include <bits/stdc++.h>
#define ll long long
#define N 505
#define MOD 1024523
using namespace std;
int f[2][N][N], n, m, a[N], b[N];
char s1[N], s2[N];
int main(){
	scanf("%d%d%s%s", &n, &m, s1, s2);
	for(int i = 0; i < n; i++)
		a[n-i] = s1[i] - 'A';
	for(int i = 0; i < m; i++)
		b[m-i] = s2[i] - 'A';
	f[0][0][0] = 1;
	for(int i = 0; i < n+m; i++){
		int t = i&1;
		for(int j = 0; j <= n && j <= i; j++)
		for(int k = 0; k <= n && j <= i; k++)
		if(f[t][j][k]){
			if(a[j+1] == b[i-k+1]) (f[!t][j+1][k] += f[t][j][k]) %= MOD;
			if(b[i-j+1] == a[k+1]) (f[!t][j][k+1] += f[t][j][k]) %= MOD;
			if(b[i-j+1] == b[i-k+1]) (f[!t][j][k] += f[t][j][k]) %= MOD;
			if(a[j+1] == a[k+1]) (f[!t][j+1][k+1] += f[t][j][k]) %= MOD;
			f[t][j][k] = 0;
		}
	}
	printf("%d\n", f[(n+m)&1][n][n]);
	return 0;
}
