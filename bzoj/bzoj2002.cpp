#include "bits/stdc++.h"
#define N 200020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int c[N][2], fa[N], rev[N], st[N], sz[N], nxt[N];
bool isroot(int x){
	return c[fa[x]][0] != x && c[fa[x]][1] != x;
}
void push_down(int x){
	if(!rev[x])return;
	rev[x] ^= 1;
	rev[c[x][0]] ^= 1;
	rev[c[x][1]] ^= 1;
	swap(c[x][0], c[x][1]);
}
void push_up(int x){
	sz[x] = sz[c[x][0]]+sz[c[x][1]]+1;
}
void rotate(int x){
	int y = fa[x], z = fa[y];
	int r = c[y][0] == x, l = r^1;
	if(!isroot(y)) c[z][c[z][0]!=y] = x;
	fa[x] = z; fa[y] = x; fa[c[x][r]] = y;
	c[y][l] = c[x][r]; c[x][r] = y;
	push_up(y); push_up(x);
}
void splay(int x){
	int top = 0; st[++top]=x;
	for(int i = x; !isroot(i); i=fa[i])
		st[++top] = fa[i];
	for(int i = top; i; i--)
		push_down(st[i]);
	while(!isroot(x)){
		int y = fa[x], z = fa[y];
		if(!isroot(y))if(c[y][0]==x^c[z][0]==y)rotate(x);
		else rotate(y);
		rotate(x);
	}
}
void access(int x){
	int t = 0;
	while(x){
		splay(x);
		c[x][1] = t;
		t = x; x = fa[x];
	}
}
void rever(int x){
	access(x);splay(x);
	rev[x]^=1;
}
void link(int x, int y){
	rever(x);
	fa[x] = y;
	splay(x);
}
void cut(int x, int y){
	rever(x); access(y); splay(y);
	c[y][0] = fa[x] = 0;
}
int find(int x){
	access(x); splay(x);
	int y = x;
	while(c[y][0])y=c[y][0];
	return y;
}
int main(){
	int n = read();
	for(int i = 1,x; i <= n; i++){
		nxt[i] = (x=read())+i;
		sz[i] = 1;
		if(nxt[i] > n) nxt[i] = n+1;
		fa[i] = nxt[i];
	}
	sz[n+1] = 1;
	int m = read();
	for(int i = 1; i <= m; i++){
		if(read()==1){
			int x = read()+1;
			rever(n+1); access(x); splay(x);
			printf("%d\n", sz[c[x][0]]);
		}
		else{
			int x = read()+1, y = read();
			int t = min(x+y, n+1);
			cut(x, nxt[x]); link(x, nxt[x]=t);
		}
	}
}