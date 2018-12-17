#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
char nextchar(){
	char ch = getchar();
	while(ch != '|' && ch != '+' && ch != ' ' && ch != '-') ch=getchar();
	return ch;
}
char mp[250][250];
int f[250][250], ans;
int qx[N], qy[N], n, m;
int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};
void bfs(int sx, int sy){
	int l = 0, r = 1;
	qx[1] = sx; qy[1] = sy;
	f[sx][sy] = 0;
	while(l < r){
		int tx = qx[++l], ty = qy[l];
		for(int i = 0; i < 4; i++){
			int xx = tx+px[i], yy = ty+py[i];
			if(mp[xx][yy] != ' ' || xx > m || xx < 1 || yy > n || yy < 1) continue;
			xx += px[i]; yy += py[i];
			if(f[tx][ty]+1 < f[xx][yy]){
				f[xx][yy] = f[tx][ty]+1;
				qx[++r] = xx; qy[r] = yy;
			}
		}
	}
}
int main(int argc, char const *argv[]){
	n = read()<<1|1; m = read()<<1|1;
	memset(f, 63, sizeof(int)*62500);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++) mp[i][j] = nextchar();
	for(int i = 2; i <= m; i += 2){
		if(mp[i][1] == ' ') bfs(i, 0);
		if(mp[i][n] == ' ') bfs(i, n+1);
	}
	for(int i = 2; i <= n; i += 2){
		if(mp[1][i] == ' ') bfs(0, i);
		if(mp[m][i] == ' ') bfs(m+1, i);
	}
	for(int i = 2; i <= m; i += 2)
		for(int j = 2; j <= n; j += 2)
			ans = max(ans, f[i][j]);
	printf("%d\n", ans);
	return 0;
}