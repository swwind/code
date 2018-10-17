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
int head[N], top[N], fa[N], dep[N], sz[N], p[N], fp[N], n, m, cal[N];
int son[N], tot, pos, to[N<<1], nxt[N<<1], al[N], ar[N], az[N], tag[N];
struct node{
	int ls, rs, num;
	node():num(0){}
}tr[N<<2];
node operator + (const node &a, const node &b){
	node c;
	if(!a.num)return b;
	if(!b.num)return a;
	c.ls = a.ls; c.rs = b.rs; c.num = a.num+b.num;
	if(a.rs == b.ls) c.num--;
	return c;
}
void push_down(int x, int l, int r){
	if(!tag[x] || l == r) return;
	tag[x<<1] = tag[x<<1|1] = tag[x];
	tr[x<<1].ls = tr[x<<1|1].ls = tag[x];
	tr[x<<1].rs = tr[x<<1|1].rs = tag[x];
	tr[x<<1].num = tr[x<<1|1].num = 1;
	tag[x] = 0;
}
void build(int x, int l, int r){
	if(l == r){
		tr[x].ls = tr[x].rs = cal[fp[l]];
		tr[x].num = 1;
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	tr[x] = tr[x<<1]+tr[x<<1|1];
}
void update(int x, int l, int r, int L, int R, int c){
	if(l == L && r == R){
		tr[x].ls = tr[x].rs = c;
		tr[x].num = 1; tag[x] = c;
		return;
	}
	int mid = L + R >> 1;
	if(r <= mid) update(x<<1, l, r, L, mid, c);
	else if(l > mid) update(x<<1|1, l, r, mid+1, R, c);
	else update(x<<1, l, mid, L, mid, c), update(x<<1|1, mid+1, r, mid+1, R, c);
	tr[x] = tr[x<<1]+tr[x<<1|1];
}
node ask(int x, int l, int r, int L, int R){
	if(l == L && r == R) return tr[x];
	push_down(x, L, R);
	int mid = L + R >> 1;
	if(r <= mid) return ask(x<<1, l, r, L, mid);
	else if(l > mid) return ask(x<<1|1, l, r, mid+1, r);
	return ask(x<<1|1, l, mid, L, mid)+ask(x<<1|1, mid+1, r, mid+1, R);
}
void ins(int x, int y){
	to[++tot] = y; nxt[tot] = head[x]; head[x] = tot;
	to[++tot] = x; nxt[tot] = head[y]; head[y] = tot;
}
void dfs1(int x, int f){
	dep[x] = dep[f]+1; fa[x] = f; sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])if(to[i]!=f){
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
		if(to[i] != son[x] && to[i] != fa[x]) dfs2(to[i], to[i]);
}
node findsum(int u, int v){
	int f1 = top[u], f2 = top[v];
	node tmp1, tmp0;
	int flag = 0;
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v), flag++;
		if(flag&1){
			tmp1 = tmp1+ask(1, p[f1], p[u], 1, n);
		}
		else tmp0 = ask(1, p[f1], p[u], 1, n)+tmp0;
		u = fa[f1]; f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v), flag++;
	if(flag&1) swap(tmp1.ls, tmp1.rs);
	else swap(tmp0.ls, tmp0.rs);
	return tmp0+ask(1, p[u], p[v], 1, n)+tmp1;
}
void findupdate(int u, int v, int c){
	int f1 = top[u], f2 = top[v];
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
		update(1, p[f1], p[u], 1, n, c);
		u = fa[f1]; f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	return update(1, p[u], p[v], 1, n, c);
}
char ch[20];
int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i++) cal[i] = read();
	for(int i = 2; i <= n; i++) ins(read(), read());
	dfs1(1, 0); dfs2(1, 1); build(1, 1, n);
	for(int i = 1, x, y; i <= m; i++){
		scanf("%s", ch); x = read(); y = read();
		if(ch[0] == 'Q') printf("%d\n", findsum(x, y).num);
		else findupdate(x, y, read());
	}
	return 0;
}
/*
6 5
2 2 1 2 1 1
1 2
1 3
2 4
2 5
2 6
Q 3 5
C 2 1 1
Q 3 4
Q 3 6
Q 4 5

15 10
1 2 1 2 1 2 1 2 1 2 1 2 1 2 1
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
*/