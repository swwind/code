// WA md懒得调了。

#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll top[N], val[N], to[N<<1], nxt[N<<1], head[N], cnt, ls[N], rs[N], dep[N];
ll fa[N], tot, sz[N], son[N], mn[N<<2], tag[N<<2], id[N];
void ins(ll x, ll y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void push_down(ll x){
	if(tag[x]){
		mn[x<<1] = tag[x<<1|1] = tag[x];
		mn[x<<1|1] = tag[x<<1] = tag[x];
		tag[x] = 0;
	}
}
void push_up(ll x){
	mn[x] = min(mn[x<<1], mn[x<<1|1]);
}
void dfs(ll x, ll f){
	dep[x] = dep[f]+1;
	fa[x] = f; sz[x] = 1;
	for(ll i = head[x]; i; i = nxt[i])if(to[i] != f){
		dfs(to[i], x);
		sz[x] += sz[to[i]];
		if(sz[son[x]] < sz[to[i]])
			son[x] = to[i];
	}
}
void _dfs(ll x, ll tp){
	top[x] = tp; id[ls[x]=++tot] = x;
	if(son[x]) _dfs(son[x], tp);
	for(ll i = head[x]; i; i = nxt[i])
		if(to[i] != fa[x] && son[x] != to[i]) _dfs(to[i], to[i]);
	rs[x] = tot;
}
ll lca(ll x, ll y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y);
	return y;
}
void build(ll x, ll l, ll r){
	if(l == r){
		mn[x] = val[id[l]];
		return;
	}
	ll mid = l + r >> 1;
	build(x<<1, l, mid); build(x<<1|1, mid+1, r);
	push_up(x);
}
ll ask(ll x, ll l, ll r, ll L, ll R){
	if(L <= l && r <= R) return mn[x];
	push_down(x);
	ll mid = l + r >> 1, ans = 2247483648LL;
	if(L <= mid) ans = min(ans, ask(x<<1, l, mid, L, R));
	if(R > mid) ans = min(ans, ask(x<<1|1, mid+1, r, L, R));
	return ans;
}
void add(ll x, ll l, ll r, ll L, ll R, ll v){
	if(L <= l && r <= R){
		mn[x] = tag[x] = v;
		return;
	}
	push_down(x);
	ll mid = l + r >> 1;
	if(L <= mid) add(x<<1, l, mid, L, R, v);
	if(R > mid) add(x<<1|1, mid+1, r, L, R, v);
	push_up(x);
}
ll wson(ll x, ll y){
	ll last;
	while(top[x] != top[y])
		x = fa[last=top[x]];
	if(x == y) return last;
	return son[y];
}
ll rt, n, m;
ll ask(ll x){
	if(rt == x) return ask(1, 1, n, 1, n);
	if(ls[rt] < ls[x] || rs[x] < rs[rt]) return ask(1, 1, n, ls[x], rs[x]);
	ll ws = wson(rt, x), ans = 2247483648LL;
	ans = min(ans, ask(1, 1, n, 1, ls[x]-1));
	ans = min(ans, ask(1, 1, n, rs[x]+1, n));
	return ans;
}
void add(ll x, ll y, ll v){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		add(1, 1, n, ls[top[x]], ls[x], v);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	add(1, 1, n, ls[y], ls[x], v);
}
int main(){
	n = read(); m = read();
	for(ll i = 1; i < n; i++) ins(read(), read());
	for(ll i = 1; i <= n; i++) val[i] = read();
	rt = read();
	dfs(rt, 0); _dfs(rt, rt); build(1, 1, n);
	for(ll i = 1, op, x, y, z; i <= m; i++){
		op = read();
		if(op == 1){
			rt = read();
		}
		else if(op == 2){
			x = read(); y = read(); z = read();
			add(x, y, z);
		}
		else{
			printf("%lld\n", ask(read()));
		}
	}
	return 0;
}