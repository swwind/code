#include <bits/stdc++.h>
#define N 12
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int mp[N][N], f[N][N][N][N];
int n = read(), x, y, z;
int main(int argc, char const *argv[]) {
	while (~scanf("%d%d%d", &x, &y, &z))
		mp[x][y] = z;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) {
				int l = i+j-k;
				if (l <= 0)
					continue;
				f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k-1][l]);
				f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l-1]);
				f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k-1][l]);
				f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l-1]);
				f[i][j][k][l] += (i == k && j == l ? mp[i][j] : (mp[i][j]+mp[k][l]));
			}
	printf("%d\n", f[n][n][n][n]);
	return 0;
}
