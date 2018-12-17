#include <bits/stdc++.h>
#define ll long long
#define N 100050
using namespace std; 
int T,n,m,cnt,top,x,y; 
int last[N],d[N],ans[N]; 
priority_queue<int,vector<int> > q; 
struct edge{
	int to,next; 
}e[N]; 
void insert(int u,int v){
	e[++cnt].to=v; 
	e[cnt].next=last[u]; 
	last[u]=cnt; 
}
void dfs(int x){
	q.pop(); 
	ans[++top]=x; 
	for(int i=last[x];i;i=e[i].next){
		d[e[i].to]--; 
		if(!d[e[i].to])
			q.push(e[i].to); 
	}
}
int main(){
	scanf("%d", &T); 
	for(int i = 0; i < T; i++){
		cnt = top = 0;
		memset(d, 0, sizeof d);
		memset(last, 0, sizeof last);
		memset(ans, 0, sizeof ans);
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m; i++){
			scanf("%d%d", &x, &y);
			insert(y, x);
			d[x]++;
		}
		for(int i = 1;i <= n; i++)
			if(!d[i]) q.push(i); 
		while(!q.empty())
			dfs(q.top()); 
		if(top != n)
			puts("Impossible!"); 
		else{
			for(int i = n; i; i--)
				printf("%d ", ans[i]);
			puts("");
		}
	}
	return 0;
}

