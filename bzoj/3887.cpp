#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
struct Tobu__Alan_Walker__Janji__Smk__OMFG{
	int v, next;
	bool operator < (const Tobu__Alan_Walker__Janji__Smk__OMFG &b) const {
		return v == b.v ? next < b.next : v < b.v;
	}
}e[N], E[N], rd[N];
int head[N], HEAD[N], cnt;
void add(int u, int v){
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void ADD(int u, int v){
	e[++cnt].v = v;
	E[cnt].v = u;
	e[cnt].next = head[u];
	E[cnt].next = HEAD[v];
	head[u] = HEAD[v] = cnt;
}
bool de[N];
int num[N], n, m;
struct HOPE_T__XMY__Itro__Steerner__Martell{
	int dfn[N], cnt, vis[N], id[N];
	void dfs1(int x){
		vis[x] = 1;
		for(int i = head[x]; i; i = e[i].next)
			if(!vis[e[i].v]) dfs1(e[i].v);
		dfn[++cnt] = x;
	}
	void dfs2(int x, int group){
		id[x] = group;
		for(int i = HEAD[x]; i; i = E[i].next)
			if(!id[E[i].v]) dfs2(E[i].v, group);
	}
	void play(int x){
		for(int i = 1; i <= x; i++) if(!vis[i]) dfs1(i);
		for(int i = x; i; i--) if(!id[dfn[i]]) dfs2(dfn[i], dfn[i]);
		for(int i = 1; i <= x; i++) num[id[i]]++;
		for(int i = 1; i <= m; i++)
			rd[i].v = id[rd[i].v],
			rd[i].next = id[rd[i].next];
		sort(rd+1, rd+m+1);
		for(int i = 1; i <= m; i++)
			if(rd[i].v == rd[i-1].v && rd[i].next == rd[i-1].next) de[i] = 1;
			else if(rd[i].v == rd[i].next) de[i] = 1;
	}
}zuosi;
bool vis1[N], vis2[N];
void dfs1(int x){
	vis1[x] = 1;
	for(int i = head[x]; i; i = e[i].next)
		if(!vis1[e[i].v]) dfs1(e[i].v);
}
void dfs2(int x){
	vis2[x] = 1;
	for(int i = HEAD[x]; i; i = E[i].next)
		if(!vis2[E[i].v]) dfs2(E[i].v);
}
int f1[N], f2[N], d[N];
queue<int> q;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &rd[i].v, &rd[i].next);
		ADD(rd[i].v, rd[i].next);
	}
	dfs1(1), dfs2(1);
	zuosi.play(n);
	////////////////////////////////////////////////////////////
	memset(head, 0, sizeof head);
	memset(d, 0, sizeof d);
	cnt = 0;
	for(int i = 1; i <= m; i++) if(!de[i])
		if(vis1[rd[i].v] && vis1[rd[i].next])
			add(rd[i].v, rd[i].next), d[rd[i].next]++;
	while(!q.empty())q.pop();
	q.push(1);
	while(!q.empty()){
		int t = q.front(); q.pop();
		f1[t] += num[t];
		for(int i = head[t]; i; i = e[i].next){
			d[e[i].v]--;
			f1[e[i].v] = max(f1[e[i].v], f1[t]);
			if(!d[e[i].v]) q.push(e[i].v);
		}
	}
	////////////////////////////////////////////////////////////
	memset(head, 0, sizeof head);
	memset(d, 0, sizeof d);
	cnt = 0;
	for(int i = 1; i <= m; i++) if(!de[i])
		if(vis2[rd[i].v] && vis2[rd[i].next])
			add(rd[i].next, rd[i].v), d[rd[i].v]++;
	while(!q.empty())q.pop();
	q.push(1);
	while(!q.empty()){
		int t = q.front(); q.pop();
		f2[t] += num[t];
		for(int i = head[t]; i; i = e[i].next){
			d[e[i].v]--;
			f2[e[i].v] = max(f2[e[i].v], f2[t]);
			if(!d[e[i].v]) q.push(e[i].v);
		}
	}
	/////////////////////////////////////////////////////////////
	int ans = num[1] << 1;
	for(int i = 1; i <= m; i++) if(!de[i])
		if(vis1[rd[i].next] && vis2[rd[i].v])
			ans = max(ans, f1[rd[i].next] + f2[rd[i].v]);
	printf("%d", ans-num[1]);
	return 0;
}

