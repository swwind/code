#include <bits/stdc++.h>
using namespace std;
int a[250], s[250][250], n, f[250][250];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			s[i][j] = s[i][j-1]+a[j];
	for(int i = n; i; i--)
		for(int j = 1; j <= n; j++)
			f[i][j] = max(s[i][j]-f[i+1][j], s[i][j]-f[i][j-1]);
	printf("%d %d", f[1][n], s[1][n]-f[1][n]);
}