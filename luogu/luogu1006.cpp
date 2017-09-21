#include <bits/stdc++.h>
#define N 52
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int mp[N][N], f[N][N][N][N];
int n = read(), m = read();
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mp[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= n; k++) {
				int l = i+j-k;
				if (l <= 0)
					continue;
				f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k-1][l]);
				f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l-1]);
				f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k-1][l]);
				f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l-1]);
				if (i == k && j == l)
					continue;
				f[i][j][k][l] += mp[i][j]+mp[k][l];
			}
	printf("%d\n", f[n][m][n][m]);
	return 0;
}
