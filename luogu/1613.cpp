#include <bits/stdc++.h>
#define N 55
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int mp[N][N];
bool f[N][N][N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	memset(mp, 63, sizeof mp);
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		mp[x][y] = f[0][x][y] = 1;
	}
	for (int i = 1; i <= 32; i++)
		for (int st = 1; st <= n; st++)
			for (int ed = 1; ed <= n; ed++)
				for (int k = 1; k <= n; k++)
					if (f[i-1][st][k] && f[i-1][k][ed]) {
						f[i][st][ed] = 1;
						mp[st][ed] = 1;
					}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
	printf("%d\n", mp[1][n]);
	return 0;
}