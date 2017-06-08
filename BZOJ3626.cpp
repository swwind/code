#include <bits/stdc++.h>
#define ll long long
#define N 50010
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int head[N], top[N], fa[N], dep[N], sz[N], p[N], fp[N], n, m;
int son[N], tot, pos, to[N], nxt[N], al[N], ar[N], az[N];
int ls[N<<2], rs[N<<2];
ll tag[N<<2], sum[N<<2], ans[N];
void build(int x, int l, int r){
	ls[x] = l; rs[x] = r;
	if(l == r) return;
	int mid = l + r >> 1;
	build(x<<1, l, mid); build(x<<1|1, mid+1, r);
}
void add(int x, int v){
	tag[x] += v;
	sum[x] += (rs[x]-ls[x]+1)*v;
}
void push_down(int x){
	if(tag[x]){add(x<<1, tag[x]);add(x<<1|1, tag[x]);tag[x]=0;}
}
void update(int x, int l, int r){
	if(ls[x] == l && rs[x] == r){
		sum[x]+=r-l+1;tag[x]++;
		return;
	}
	push_down(x);
	int mid = ls[x]+rs[x]>>1;
	if(r <= mid) update(x<<1, l, r);
	else if(l > mid) update(x<<1|1, l, r);
	else update(x<<1, l, mid),update(x<<1|1, mid+1, r);
	sum[x] = sum[x<<1]+sum[x<<1|1];
}
ll asksum(int x, int l, int r){
	if(ls[x] == l && rs[x] == r) return sum[x];
	push_down(x);
	int mid = ls[x] + rs[x] >> 1;
	if(r <= mid) return asksum(x<<1, l, r);
	if(l > mid) return asksum(x<<1|1, l, r);
	return asksum(x<<1, l, mid)+asksum(x<<1|1, mid+1, r);
}
void ins(int x, int y){
	to[++tot] = y; nxt[tot] = head[x]; head[x] = tot;
}
void dfs1(int x, int f){
	dep[x] = dep[f]+1; fa[x] = f; sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i]){
		dfs1(to[i], x);
		sz[x] += sz[to[i]];
		if(!son[x]|| sz[to[i]] > sz[son[x]])
			son[x] = to[i];
	}
}
void dfs2(int x, int up){
	top[x] = up;
	fp[p[x]=++pos] = x;
	if(!son[x]) return;
	dfs2(son[x], up);
	for(int i = head[x]; i; i = nxt[i])
		if(to[i] != son[x]) dfs2(to[i], to[i]);
}
int findsum(int u, int v){
	int f1 = top[u], f2 = top[v];
	int tmp = 0;
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
		tmp += asksum(1, p[f1], p[u]);
		u = fa[f1]; f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	return tmp + asksum(1, p[u], p[v]);
}
void findupdate(int u, int v){
	int f1 = top[u], f2 = top[v];
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
		update(1, p[f1], p[u]);
		u = fa[f1]; f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	return update(1, p[u], p[v]);
}
int main(){
	n = read(); m = read();
	for(int i = 2; i <= n; i++) ins(read()+1, i);
	dfs1(1, 0); dfs2(1, 1); build(1, 1, n);
	for(int i = 1; i <= m; i++){
		al[i] = read();
		ar[i] = read()+1;
		az[i] = read()+1;
	}
	for(int i = 1; i <= n; i++){
		findupdate(1, i);
		for(int j = 1; j <= m; j++){
			if(al[j] == i) ans[j] -= findsum(1, az[j]);
			if(ar[j] == i) ans[j] += findsum(1, az[j]);
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
