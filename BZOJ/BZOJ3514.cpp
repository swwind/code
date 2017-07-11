// Oh my fucking shit.
// This problem smells like shit.
// 勾股♂定理
#include <bits/stdc++.h>
#define N 4000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int c[N][2], fa[N], rev[N], st[N], val[N], mn[N];
bool isroot(int x){
	// printf("isroot: %d\n", x);
	return c[fa[x]][0] != x && c[fa[x]][1] != x;
}
void push_up(int x){
	// printf("push_up: %d\n", x);
	int l = c[x][0], r = c[x][1]; mn[x] = x;
	if(val[mn[l]] < val[mn[x]]) mn[x] = mn[l];
	if(val[mn[r]] < val[mn[x]]) mn[x] = mn[r];
}
void push_down(int x){
	// printf("push_down: %d\n", x);
	if(!rev[x])return;
	rev[x] ^= 1;
	rev[c[x][0]] ^= 1;
	rev[c[x][1]] ^= 1;
	swap(c[x][0], c[x][1]);
}
void rotate(int x){
	// printf("rotate: %d\n", x);
	int y = fa[x], z = fa[y];
	int r = c[y][0] == x, l = r^1;
	if(!isroot(y)) c[z][c[z][0]!=y] = x;
	fa[x] = z; fa[y] = x; fa[c[x][r]] = y;
	c[y][l] = c[x][r]; c[x][r] = y;
	push_up(y); push_up(x);
}
void splay(int x){
	// printf("splay: %d\n", x);
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
	// printf("access: %d\n", x);
	int t = 0;
	while(x){
		splay(x);
		c[x][1] = t;
		push_up(x);
		t = x; x = fa[x];
	}
}
void rever(int x){
	// printf("rever: %d\n", x);
	access(x); splay(x);
	rev[x]^=1;
}
void link(int x, int y){
	// printf("link: %d, %d\n", x, y);
	rever(x);
	fa[x] = y;
	// splay(x);
}
void cut(int x, int y){
	// printf("cut: %d, %d\n", x, y);
	rever(x); access(y); splay(y);
	c[y][0] = fa[x] = 0;
}
int find(int x){
	// printf("find: %d\n", x);
	access(x); splay(x);
	while(c[x][0]) x = c[x][0];
	return x;
}
int query(int x, int y){
	// printf("query: %d, %d\n", x, y);
	rever(x); access(y); splay(y);
	return mn[y];
}
int sum[N], ls[N], rs[N], ntr[N], sz, tot;
void insert(int x, int &y, int l, int r, int k){
	// printf("insert: %d, %d, %d, %d, %d\n", x, y, l, r, k);
	y = ++sz;
	sum[y] = sum[x]+1;
	if(l == r) return;
	int mid = l + r >> 1;
	ls[y] = ls[x]; rs[y] = rs[x];
	if(k <= mid) insert(ls[x], ls[y], l, mid, k);
	else insert(rs[x], rs[y], mid+1, r, k);
}
int query(int x, int y, int l, int r, int k){
	// printf("query: %d, %d, %d, %d, %d\n", x, y, l, r, k);
	if(l == r) return sum[y]-sum[x];
	int mid = l + r >> 1;
	if(k <= mid) return query(ls[x], ls[y], l, mid, k);
	else return sum[ls[y]]-sum[ls[x]]+query(rs[x], rs[y], mid+1, r, k);
}
int lastans, u[N], v[N], rt[N];
int main(int argc, char const *argv[]){
	int n = read(), m = read(), q = read(), t = read();
	tot = n;
	for(int i = 0; i <= n; i++) mn[i] = i, val[i] = 1<<30;
	for(int i = 1; i <= m; i++){
		u[i] = read(); v[i] = read();
		if(u[i] == v[i]){ntr[i] = i; continue;}
		// puts("wfwafawg");
		if(find(u[i]) == find(v[i])){
			int x = query(u[i], v[i]);
			// printf("============================>%d\n", val[x]);
			ntr[i] = val[x];
			cut(u[val[x]], x);
			cut(v[val[x]], x);
		} ++tot;
		// puts("wfawf");
		mn[tot] = tot; val[tot] = i;
		link(u[i], tot); link(v[i], tot);
	}
	for(int i = 1; i <= m; i++)
		insert(rt[i-1], rt[i], 0, m, ntr[i]);
	while(q--){
		int l = read(), r = read();
		if(t) l ^= lastans, r ^= lastans;
		printf("%d\n", lastans = n-query(rt[l-1], rt[r], 0, m, l-1));
	}
	return 0;
}