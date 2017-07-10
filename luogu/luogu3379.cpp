#include <cstdio>
#include <algorithm>
using namespace std;
const int maxx = 500000 + 100;
int head[maxx], depth[maxx];
int n, m, x, y, root, num;
int grand[maxx][20+2], done[maxx];
struct edge{
	int next, to;
}Edges[maxx<<1];
inline int Read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
	return x*f;
}
void Add(int x,int y){
	Edges[++num].to=y;
	Edges[num].next=head[x];
	head[x]=num;
}
void Dfs(int x){
	done[x]=true;
	for(int i=1;i<=20;i++){
		if(depth[x] < (1<<i)) break;
		grand[x][i]=grand[grand[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=Edges[i].next){
		int now=Edges[i].to;
		if(done[now]) continue;
		depth[now]=depth[x]+1;
		grand[now][0]=x;
		Dfs(now);
	}
}
void Lca(int x,int y){
	if(depth[x]>depth[y]) swap(x,y);
	int d=depth[y]-depth[x];
	for(int i=0;i<=20;i++){
		if((1<<i) & d)
		y=grand[y][i];
	}
	for(int i=20;i>=0;i--){
		if(grand[x][i]!=grand[y][i]){
			x=grand[x][i];
			y=grand[y][i];
		}
	}
	printf("%d\n",x==y? x:grand[x][0]);
}
int main(){
	n=Read();m=Read();root=Read();
	for(int i=1;i<n;i++){
		x=Read();y=Read();
		Add(x,y);
		Add(y,x);
	}
	Dfs(root);
	while( m-- ){
		x=Read();y=Read();
		Lca(x,y);
	}
	return 0;
}
