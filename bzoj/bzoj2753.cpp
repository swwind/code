#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int vis[N], h[N], head[N], to[N<<1], nxt[N<<1], cnt, q[N], a[N], b[N], c[N], fa[N];
ll ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct node{
	int x, y, z;
	node(int x = 0, int y = 0, int z = 0):x(x),y(y),z(z){}
	bool operator < (const node &b) const {
		return h[y] > h[b.y] || h[y] == h[b.y] && z < b.z;
	}
}e[N<<1];
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
void bfs(){
	int l = 0, r = 1; q[1] = vis[1] = 1;
	while(l < r) for(int i = head[q[++l]]; i; i = nxt[i])
		if(!vis[to[i]]) vis[q[++r]=to[i]] = 1;
	printf("%d ", r);
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; h[i++]=read());
	for(int i = 1; i <= m; i++){
		a[i] = read(), b[i] = read(), c[i] = read();
		if(h[a[i]] >= h[b[i]]) ins(a[i], b[i]);
		if(h[b[i]] >= h[a[i]]) ins(b[i], a[i]);
	}bfs();cnt=0;
	for(int i = 1; i <= m; i++)
		if(vis[a[i]] && vis[b[i]]){
			if(h[a[i]] >= h[b[i]]) e[++cnt] = node(a[i], b[i], c[i]);
			if(h[b[i]] >= h[a[i]]) e[++cnt] = node(b[i], a[i], c[i]);
		}
	sort(e+1, e+cnt+1); for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= cnt; i++){
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		fa[x] = y; ans += e[i].z;
	}
	printf("%lld\n", ans);
}
