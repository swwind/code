#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define N 200050
using namespace std;
struct node{
	int to, next;
	ll v;
}e[N<<1];
int head[N], cnt, n, m, x, y, z;
ll f[N], ans;
void ins(int u, int v, ll w){
	e[++cnt] = (node){v, head[u], w};
	head[u] = cnt;
	e[++cnt] = (node){u, head[v], w};
	head[v] = cnt;
}
void dp(int u, int fa){
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		dp(v, u);
		f[u] = max(f[u], f[v]+e[i].v);
	}
}
bool cmp(ll i, ll j){
	return i > j;
}
void dfs(int u, int fa, ll x){
	vector<ll> g;
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		g.push_back(f[v]+e[i].v);
	}
	g.push_back(0);
	g.push_back(x);
	sort(g.begin(), g.end(), cmp);
	if(g.size() >= 3)
		ans = max(ans, g[0] + g[1]*2 + g[2]);
	for(int i = head[u]; i; i = e[i].next){
		int v = e[i].to;
		if(v == fa)
			continue;
		ll t = g[0];
		if(t == e[i].v + f[v])
			t = g[1];
		dfs(v, u, t+e[i].v);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	while(m--)
		scanf("%d%d%d", &x, &y, &z),
		ins(x, y, z);
	ans = 0;
	dp(1, -1);
	dfs(1, -1, 0);
	printf("%lld", ans);
	return 0;
}

