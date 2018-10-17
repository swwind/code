#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, mp[502][502], a[4]={0,1,0,-1}, sx, sy, ex, ey, ans[505][505];
char c[505];
struct node{
	int x, y, time;
};
queue<node> q;
void dfs(){
	node s;
	while(!q.empty()){
		s = q.front();q.pop();
		if(ans[s.x][s.y] <= s.time) continue;
		ans[s.x][s.y] = s.time;
		for(int i = 0; i < 4; i++){
			if(s.x+a[i]>n||s.x+a[i]<1||s.y+a[3-i]>m||s.y+a[3-i]<1)continue;
			if(mp[s.x][s.y] == mp[s.x+a[i]][s.y+a[3-i]])
				q.push((node){s.x+a[i], s.y+a[3-i], s.time});
			else q.push((node){s.x+a[i], s.y+a[3-i], s.time+1});
		}
	}
	printf("%d\n", ans[ex][ey]);
}
int main(){
	while(~scanf("%d%d", &n, &m) && n && m){
		memset(mp, 0, sizeof mp);
		memset(ans, 127/3, sizeof ans);
		for(int i = 1; i <= n; i++){
			scanf("%s", c);
			for(int j = 0; j < m; j++)
				mp[i][j+1] = (c[j] == '@');
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		ex++,ey++;
		q.push((node){sx+1, sy+1, 0});
		dfs();
	}
	return 0;
}

