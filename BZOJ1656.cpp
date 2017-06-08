#include <bits/stdc++.h>
using namespace std;
int n, m, mp[60][60], sx, sy;
int a[8]={0, 1, 1, 1, 0,-1,-1,-1};
int b[8]={1, 1,-1, 0,-1, 0, 1,-1};
struct node{
	node(){}
	node(int a, int b):x(a),y(b){}
	int x, y;
};
queue<node> q;
int main(){
	scanf("%d%d", &n, &m);
	char ch = getchar();
	for(int i = 1; i <= n; i++, ch=getchar())
		for(int j = 1; j <= m; j++){
			mp[i][j] = getchar();
			if(mp[i][j] == '.') mp[i][j] = 0;
			else if(mp[i][j] == 'X') mp[i][j] = -1;
			else if(mp[i][j] == '*') mp[sx=i][sy=j] = 0;
		}
	int x = rand()%n+1, y = rand()%m+1;
	while(mp[x][y]!=-1)
		x = rand()%n+1, y = rand()%m+1;
	int yy = y*2+1;
	q.push(node(sx, sy));
	while(!q.empty()){
		node t = q.front(); q.pop();
		for(int i = 0; i < 8; i++){
			if(t.x+a[i] && t.x+a[i]<=n && t.y+b[i] && t.y+b[i]<=m
					&& mp[t.x+a[i]][t.y+b[i]]==0 && (t.y*2+b[i]!=yy || t.x>x)){
				mp[t.x+a[i]][t.y+b[i]] = mp[t.x][t.y]+1;
				q.push(node(t.x+a[i], t.y+b[i]));
			}
		}
	}
	int ans = 1<<30;
	for(int i = x; i; i--) if(mp[i][y]>0)
		for(int j = -1; j < 2; j++)
			if(mp[i+j][y+1]>0) ans = min(ans, mp[i][y]+mp[i+j][y+1]);
	printf("%d\n", ans+1);
}
1656: [Usaco2006 Jan] The Grove 树木