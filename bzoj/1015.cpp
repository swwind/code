#include <bits/stdc++.h>
#define N 400020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct edge{
	int to, nxt;
}e[N];
int fa[N], num, a[N], ans[N], head[N], cnt;
bool vis[N];
void ins(int x, int y){
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y]}; head[y] = cnt;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) ins(read()+1, read()+1);
	int k = read();
	for(int i = 1; i <= k; i++){
		a[i] = read()+1;
		vis[a[i]] = 1;
	}num=n-k;
	for(int s = 1; s <= n; s++)if(!vis[s]){
		for(int i = head[s]; i; i = e[i].nxt){
			if(vis[e[i].to])continue;
			int fx = find(s);
			int fy = find(e[i].to);
			if(fx == fy) continue;
			fa[fx] = fy; num--;
		}
	}
	for(int kk = k; kk; kk--){
		ans[kk+1] = num++; vis[a[kk]] = 0;
		for(int i = head[a[kk]]; i; i = e[i].nxt){
			if(vis[e[i].to])continue;
			int fx = find(a[kk]);
			int fy = find(e[i].to);
			if(fx == fy) continue;
			fa[fx] = fy; num--;
		}
	}
	ans[1] = num;
	for(int i = 1; i <= k+1; i++) printf("%d\n", ans[i]);
}
