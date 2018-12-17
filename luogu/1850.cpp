#include <bits/stdc++.h>
#define N 2020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int c[N], d[N];
double k[N];
int dis[320][320];
double f[N][N][2];
int main(int argc, char const *argv[]){
	int n = read(), m = read(), v = read(), e = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 1; i <= n; i++) d[i] = read();
	for(int i = 1; i <= n; i++) scanf("%lf", k+i);
	memset(dis, 63, sizeof(int)*320*320);
	for(int i = 1; i <= v; i++) dis[i][i] = 0;
	for(int i = 1; i <= e; i++){
		int x = read(), y = read();
		dis[x][y] = dis[y][x] = min(dis[x][y], read());
	}
	for(int k = 1; k <= v; k++)
		for(int i = 1; i <= v; i++)
			for(int j = 1; j <= v; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			f[i][j][0] = f[i][j][1] = 1e60;
	f[1][0][0] = f[1][1][1] = 0;
	for(int i = 2; i <= n; i++){
		f[i][0][0] = f[i-1][0][0]+dis[c[i-1]][c[i]];
		for(int j = 1; j <= min(m, i); j++){
			f[i][j][0] = min(f[i-1][j][0]+dis[c[i-1]][c[i]],
				f[i-1][j][1]+dis[c[i-1]][c[i]]*(1-k[i-1])+dis[d[i-1]][c[i]]*k[i-1]);
			f[i][j][1] = min(f[i-1][j-1][0]+dis[c[i-1]][d[i]]*k[i]+dis[c[i-1]][c[i]]*(1-k[i]),
				f[i-1][j-1][1]
				+ dis[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])
				+ dis[c[i-1]][d[i]]*(1-k[i-1])*k[i]
				+ dis[d[i-1]][c[i]]*k[i-1]*(1-k[i])
				+ dis[d[i-1]][d[i]]*k[i-1]*k[i]);
		}
	}
	double ans = 1e60;
	for(int i = 0; i <= m; i++)
		ans = min(ans, min(f[n][i][0], f[n][i][1]));
	printf("%.2lf\n", ans);
	return 0;
}