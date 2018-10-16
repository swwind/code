#include <bits/stdc++.h>
#define N 10200
#define M 100200
using namespace std;
struct node{
	int to, nxt;
	double val;
}e[M];
int vis[N], cnt, head[N];
double f[N], eps = 1e-8;
void ins(int x, int y, double z){
	e[++cnt] = (node){y, head[x], z};
	head[x] = cnt;
}
bool dfs(int x){
	vis[x] = 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if(!vis[y]){f[y] = f[x]*e[i].val; if(!dfs(y))return 0;}
		else if(f[x]*e[i].val-f[y]>eps) return 0;
	}
	return 1;
}
int main(){
	int T, n, m, c = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m); cnt = 0;
		for(int i = 1; i <= n; i++) f[i] = head[i] = vis[i] = 0;
		for(int i = 1,u,v,x,y; i <= m; i++){
			scanf("%d%d%d%d", &u, &v, &x, &y);
			ins(u, v, (double)x/y);
			ins(v, u, (double)y/x);
		}
		int ok = 1;
		for(int i = 1; i <= n && ok; i++)
			if(!vis[i]){
				f[i] = 1;
				ok = dfs(i);
			}
		printf("Case #%d: ", ++c);
		puts(ok?"Yes":"No");
	}
}