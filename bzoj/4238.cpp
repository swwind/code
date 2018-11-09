#include <bits/stdc++.h>
#define N 200020
using namespace std;
struct node{
	int nxt, to;
}e[N<<1];
int head[N], n, m, cnt=1, d[N], fa[N], c[N][2], cnt1, cnt0;
void ins(int x, int y){
	e[++cnt] = (node){head[x], y};
	head[x] = cnt;
}
void dfs(int x, int p){
	for(int i = head[x],y=e[i].to; i; y=e[i=e[i].nxt].to){
		if((i^1)==p)continue;
		if(!d[y]){
			d[y] = d[x]+1;
			fa[y] = x;
			dfs(y, i);
			c[x][0] += c[y][0];
			c[x][1] += c[y][1];
		}
		else if(d[y]<=d[x])
			if(d[x]&1^d[y]&1)
				c[x][0]++, c[y][0]--, cnt0++;
			else
				c[x][1]++, c[y][1]--, cnt1++;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1,x,y; i <= m; i++){
		scanf("%d%d", &x, &y);
		ins(x, y); ins(y, x);
	}
	for(int i = 1; i <= n; i++) if(!d[i])
		d[i] = 1, dfs(i, 0);
	int ans = cnt1==1;
	for(int i = 1; i <= n; i++)
		ans+=(fa[i]&&c[i][1]==cnt1&&!c[i][0]);
	printf("%d\n", ans);
}
