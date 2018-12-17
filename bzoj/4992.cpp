#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[102][102][3], g[102][102][3];
int a[102][102];
int dx[] = {1, 0,-1, 0};
int dy[] = {0, 1, 0,-1};
int x[N], y[N], s[N], n, t;
void bfs(int sx, int sy){
	int l = 0, r = 1;
	x[1] = sx; y[1] = sy; s[1] = 0;
	f[sx][sy][0] = 1; g[sx][sy][0] = 0;
	while(l < r){ ++l;
		f[x[l]][y[l]][s[l]] = 0;
		for(int i = 0; i < 4; i++){
			int xx = x[l]+dx[i], yy = y[l]+dy[i], ss = (s[l]+1)%3;
			int sum = ss ? g[x[l]][y[l]][s[l]] : (g[x[l]][y[l]][s[l]]+a[xx][yy]);
			sum += t;
			if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
			if(sum > g[xx][yy][ss]) continue;
			if(!f[xx][yy][ss]){
				x[++r] = xx; y[r] = yy; s[r] = ss;
				f[xx][yy][ss] = r;
			}
			g[xx][yy][ss] = sum;
		}
	}
}
int main(int argc, char const *argv[]){
	n = read(); t = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = read();
	memset(g, 63, sizeof g);
	bfs(1, 1);
	printf("%d\n", min(g[n][n][0], min(g[n][n][1], g[n][n][2])));
	return 0;
}