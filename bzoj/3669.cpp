#include <bits/stdc++.h>
#define N 150020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x, y, a, b;
	bool operator < (const node &c) const {
		return a == c.a ? b < c.b : a < c.a;
	}
}e[N];
int c[N][2], fa[N], rev[N], st[N], mx[N], val[N];
bool isroot(int x){
	return c[fa[x]][0] != x && c[fa[x]][1] != x;
}
void push_up(int x){
	if(!x) return;
	mx[x] = x;
	if(c[x][0] && val[mx[c[x][0]]] > val[mx[x]]) mx[x] = mx[c[x][0]];
	if(c[x][1] && val[mx[c[x][1]]] > val[mx[x]]) mx[x] = mx[c[x][1]];
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
int find(int x){
	access(x); splay(x);
	while(c[x][0]) x = c[x][0];
	return x;
}
int ask(int x, int y){
	if(find(x) != find(y)) return -1;
	rever(x);
	access(y);
	splay(y);
	return mx[y];
}
int main(){
	int n = read(), m = read(), ans = 1<<30;
	for(int i = 1; i <= m; i++){
		e[i].x = read(); e[i].y = read();
		e[i].a = read(); e[i].b = read();
	}
	for(int i = 1; i <= n+m; i++) mx[i] = i;
	sort(e+1, e+m+1);
	for(int i = 1; i <= m; i++){
		int x = e[i].x, y = e[i].y;
		if(x == y) continue;
		if(find(x) != find(y)){
			val[i+n] = e[i].b;
			link(x, i+n); link(i+n, y);
		}
		else{
			int t = ask(x, y);
			if(e[i].b < val[t]){
				val[i+n] = e[i].b;
				cut(e[t-n].x, t); cut(t, e[t-n].y);
				link(x, i+n); link(i+n, y);
			}
		}
		int t = ask(1, n);
		if(t != -1)
			ans = min(ans, e[i].a+val[t]);
	}
	if(ans == 1<<30) puts("-1");
	else printf("%d\n", ans);
	return 0;
}