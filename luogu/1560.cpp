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
int n, m, ans;
char ch[5];
int mp[150][150];
int px[] = {1, 0, -1, 0};
int py[] = {0, 1, 0, -1};
void pr(){
	for(int i = 0; i <= n+1; i++)
		for(int j = 0; j <= n+1; j++)
			putchar(mp[j][i] ? mp[i][j] == 2 ? '*' : '#' : '.');
}
void dfs(int sx, int sy, int ct){
	bool flag = 0;
	for(int i = 0; i < 4; i++){
		int xx = sx+px[i], yy = sy+py[i];
		if(mp[xx][yy]) continue;
		int cnt = 0; flag = 1;
		while(!mp[xx][yy]){
			mp[xx][yy] = 2;
			xx += px[i]; yy += py[i];
			cnt ++;
		}
		if(mp[xx][yy] == 2) ans = max(ans, ct+cnt);
		else dfs(xx-px[i], yy-py[i], ct+cnt);
		while(xx != sx || yy != sy)
			mp[xx -= px[i]][yy -= py[i]] = 0;
		mp[sx][sy] = 2;
	}
	if(!flag) ans = max(ans, ct);
}
int main(int argc, char const *argv[]){
	n = read(); m = read();
	for(int i = 1; i <= m; i++){
		scanf("%s", ch+1);
		mp[ch[1]-'A'+1][atoi(ch+2)] = 1;
	} mp[1][1] = 2;
	for(int i = 0; i <= n+1; i++)
		mp[0][i] = mp[i][0] = mp[n+1][i] = mp[i][n+1] = 1;
	dfs(1, 1, 1);
	printf("%d\n", ans);
	return 0;
}