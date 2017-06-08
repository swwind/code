#include <bits/stdc++.h>
#define ll long long
#define N 30010
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int c[N][2], fa[N], rev[N], st[N], sum[N], val[N];
bool isroot(int x){
	return c[fa[x]][0] != x && c[fa[x]][1] != x;
}
void push_up(int x){
	sum[x] = sum[c[x][0]]+sum[c[x][1]]+val[x];
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
		push_up(x);
		t = x; x = fa[x];
	}
}
void rever(int x){
	access(x); splay(x);
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
int ask(int x, int y){
	rever(x); access(y); splay(y);
	return sum[y];
}
void change(int x, int v){
	rever(x);
	val[x] = v;
	push_up(x);
}
int find(int x){
	access(x); splay(x);
	while(c[x][0]) x = c[x][0];
	return x;
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++)
		val[i] = sum[i] = read();
	int m = read(); char ch[40];
	for(int i = 1, op, x, y; i <= m; i++){
		scanf("%s", ch); x = read(); y = read();
		if(ch[0] == 'b')
			if(find(x) == find(y)) puts("no");
			else puts("yes"), link(x, y);
		if(ch[0] == 'p')
			change(x, y);
		if(ch[0] == 'e')
			if(find(x) != find(y)) puts("impossible");
			else printf("%d\n", ask(x, y));
	}
	return 0;
}