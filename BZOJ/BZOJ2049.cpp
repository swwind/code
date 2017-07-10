#include <bits/stdc++.h>
#define N 10020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int c[N][2], fa[N], rev[N], st[N];
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
void rotate(int x){
	int y = fa[x], z = fa[y];
	int r = c[y][0] == x, l = r^1;
	if(!isroot(y)) c[z][c[z][0]!=y] = x;
	fa[x] = z; fa[y] = x; fa[c[x][r]] = y;
	c[y][l] = c[x][r]; c[x][r] = y;
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
	int n = read(), m = read();
	char str[50];
	for(int i = 1,x,y; i <= m; i++){
		scanf("%s", str);
		x=read(); y=read();
		if(str[0] == 'D')cut(x, y);
		if(str[0] == 'C')link(x, y);
		if(str[0] == 'Q')puts(find(x)==find(y)?"Yes":"No");
	}
}