#include <bits/stdc++.h>
#define File(s) \
		freopen(s".in", "r", stdin), \
		freopen(s".out", "w", stdout)
#define ll long long
#define N 30010
using namespace std;
struct node{
	int to, next;
}e[N<<1];
int head[N], top[N], fa[N], dep[N], num[N], p[N], fp[N];
int son[N], tot, pos;
void ins(int x, int y){
	e[tot].to = y;
	e[tot].next = head[x];
	head[x] = tot++;
}
void dfs1(int x, int f, int d){
	dep[x] = d;
	fa[x] = f;
	num[x] = 1;
	for(int i = head[x]; i != -1; i = e[i].next){
		int s = e[i].to;
		if(s == f) continue;
		dfs1(s, x, d+1);
		num[x] += num[s];
		if(son[x] == -1 || num[s] > num[son[x]])
			son[x] = s;
	}
}
void dfs2(int x, int up){
	top[x] = up;
	p[x] = pos++;
	fp[p[x]] = x;
	if(son[x]==-1) return;
	dfs2(son[x], up);
	for(int i = head[x]; i != -1; i = e[i].next){
		int s = e[i].to;
		if(s != son[x] && s != fa[x]) dfs2(s, s);
	}
}
int ls[N<<2], rs[N<<2], sum[N<<2], mx[N<<2], s[N];
void push_up(int x){
	sum[x] = sum[x<<1] + sum[x<<1|1];
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void build(int x, int l, int r){
	ls[x] = l; rs[x] = r;
	if(l == r){
		sum[x] = mx[x] = s[fp[l]];
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	push_up(x);
}
void update(int x, int k, int val){
	if(ls[x] == rs[x] && ls[x] == k){
		sum[x] = mx[x] = val;
		return;
	}
	int mid = ls[x] + rs[x] >> 1;
	if(k <= mid) update(x<<1, k, val);
	else update(x<<1|1, k, val);
	push_up(x);
}
int askmax(int x, int l, int r){
	if(ls[x] == l && rs[x] == r) return mx[x];
	int mid = rs[x] + ls[x] >> 1;
	if(r <= mid) return askmax(x<<1, l, r);
	if(l > mid) return askmax(x<<1|1, l, r);
	return max(askmax(x<<1, l, mid), askmax(x<<1|1, mid+1, r));
}
int asksum(int x, int l, int r){
	if(ls[x] == l && rs[x] == r) return sum[x];
	int mid = rs[x] + ls[x] >> 1;
	if(r <= mid) return asksum(x<<1, l, r);
	if(l > mid) return asksum(x<<1|1, l, r);
	return asksum(x<<1, l, mid) + asksum(x<<1|1, mid+1, r);
}
int findmax(int u, int v){
	int f1 = top[u], f2 = top[v];
	int tmp = -1000000000;
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
		tmp = max(tmp, askmax(1, p[f1], p[u]));
		u = fa[f1];
		f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	return max(tmp, askmax(1, p[u], p[v]));
}
int findsum(int u, int v){
	int f1 = top[u], f2 = top[v];
	int tmp = 0;
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
		tmp += asksum(1, p[f1], p[u]);
		u = fa[f1];
		f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	return tmp + asksum(1, p[u], p[v]);
}
int n, q, x, y;
char op[50];
int main(){
	memset(head, -1, sizeof head);
	memset(son, -1, sizeof son);
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		ins(x, y); ins(y, x);
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", s+i);
	dfs1(1, 0, 0);
	dfs2(1, 1);
	build(1, 0, pos-1);
	scanf("%d", &q);
	while(q--){
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'C') update(1, p[x], y);
		else if(op[1] == 'M')
			printf("%d\n", findmax(x, y));
		else
			printf("%d\n", findsum(x, y));
	}
	return 0;
}
/*
4
1 2
2 3
4 1
4 2 1 3
12
QMAX 3 4
QMAX 3 3
QMAX 3 2
QMAX 2 3
QSUM 3 4
QSUM 2 1
CHANGE 1 5
QMAX 3 4
CHANGE 3 6
QMAX 3 4
QMAX 2 4
QSUM 3 4
*/
