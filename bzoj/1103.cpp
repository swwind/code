#include <bits/stdc++.h>
#define N 250020
using namespace std;
struct node{
	int to, nxt;
}e[N<<1];
char s[5];
int c[N], dep[N], st[N], ed[N], n, cnt, head[N], tot;
inline int read(){
	int x = 0; char ch = getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
void add(int x, int v){
	for(;x<=n;x+=x&-x)c[x]+=v;
}
int ask(int x){
	int ans = 0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
void dfs(int x, int fa){
	st[x] = ++tot;
	for(int i = head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dep[e[i].to] = dep[x]+1, dfs(e[i].to, x);
	ed[x] = tot;
}
void ins(int x, int y){
	e[++cnt] = (node){y, head[x]}; head[x] = cnt;
	e[++cnt] = (node){x, head[y]}; head[y] = cnt;
}
int main(){
	n = read();
	for(int i = 1; i < n; i++)
		ins(read(), read());
	int m = read();
	dfs(1, 0);
	for(int i = 1, x, y; i < m+n; i++){
		scanf("%s", s); x = read();
		if(s[0] == 'W') printf("%d\n", ask(st[x])+dep[x]);
		else{
			y = read();
			if(dep[x] < dep[y]) swap(x, y);
			add(st[x], -1);
			add(ed[x]+1, 1);
		}
	}
}