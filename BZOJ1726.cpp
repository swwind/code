#include <bits/stdc++.h>
#define N 5010
#define M 100010
#define inf 1000000000
using namespace std;
int disa[N], disb[N], to[M<<1], len[M<<1], next[M<<1], head[N], q[N], vis[N];
int n, m, num, x, y, z;
void addedge(int x, int y, int z){
	to[++num] = y;
	len[num] = z;
	next[num] = head[x];
	head[x] = num;
}
void spfa(){
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i++)
		disa[i] = disb[i] = inf;
	queue<int> q;
	disa[1] = 0;
	vis[1] = 1;
	q.push(1);
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = head[x]; i; i = next[i]){
			if(disa[x]+len[i]<disa[to[i]])
				disb[to[i]] = min(disa[to[i]], disb[x]+len[i]),
				disa[to[i]] = disa[x]+len[i];
			else if(disa[x]+len[i] > disa[to[i]] && disa[x]+len[i] < disb[to[i]])
				disb[to[i]] = disa[x]+len[i];
			else if(disa[x]+len[i] == disa[to[i]] && disb[x]+len[i] < disb[to[i]])
				disb[to[i]] = disb[x]+len[i];
			else continue;
			if(!vis[to[i]])
				vis[to[i]] = 1,
				q.push(to[i]);
		}
		vis[x] = 0;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
		addedge(y, x, z);
	}
	spfa();
	printf("%d\n", disb[n]);
	return 0;
} 
