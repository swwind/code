#include <bits/stdc++.h>
using namespace std;
int mp[20][20], cnt, n, m, stx, sty, edx, edy, vis[20][20], flag;
int a[4] = {0, -1, 0, 1}, b[4] = {-1, 0, 1, 0};
struct node{
	int x, y;
	void print(){
		printf("(%d,%d)->", x, y);
	}
	void pr(){
		printf("(%d,%d)\n", x, y);
	}
}ans[500];
void dfs(int x, int y){
	if(x == edx && y == edy){
		flag = 1;
		for(int i = 1; i < cnt; i++)
			ans[i].print();
		ans[cnt].pr();
		return;
	}
	for(int i = 0; i < 4; i++){
		int xx = x+a[i], yy = y+b[i];
		if(mp[xx][yy]&&!vis[xx][yy]){
			vis[xx][yy] = 1;
			ans[++cnt] = (node){xx, yy};
			dfs(xx, yy);
			--cnt;
			vis[xx][yy] = 0;
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &mp[i][j]);
	scanf("%d%d%d%d", &stx, &sty, &edx, &edy);
	vis[stx][sty] = 1;
	ans[++cnt] = (node){stx, sty};
	dfs(stx, sty);
	if(!flag) puts("-1");
	return 0;
}