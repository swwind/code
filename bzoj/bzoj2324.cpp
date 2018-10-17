#include <bits/stdc++.h>
#define N 305
#define M 100020
#define inf 707406378
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
namespace MCMF{
	int to[M], nxt[M], head[N], val[M], cst[M];
	int st, ed, cnt = 1, ans;
	void ins(int x, int y, int v, int c){
		to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = v; cst[cnt] = c;
		to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = 0; cst[cnt] = -c;
	}
	bool vis[N];
	int dis[N], q[M];
	bool spfa(){
		memset(vis, 0, sizeof(bool)*N);
		memset(dis, 127/3, sizeof(int)*N);
		int l = 0, r = 1;
		q[1] = ed; dis[ed] = 0; vis[ed] = 1;
		while(l < r){
			int x = q[++l];
			for(int i = head[x]; i; i = nxt[i])
				if(val[i^1] && dis[to[i]] > dis[x]-cst[i]){
					dis[to[i]] = dis[x]-cst[i];
					if(!vis[to[i]]){
						vis[to[i]] = 1;
						q[++r] = to[i];
					}
				}
			vis[x] = 0;
		}
		return dis[st] != inf;
	}
	int dfs(int x, int f){
		vis[x] = 1; if(x == ed) return f;
		int used = 0;
		for(int i = head[x]; i; i = nxt[i])
			if(!vis[to[i]] && val[i] && dis[to[i]] == dis[x]-cst[i]){
				int w = dfs(to[i], min(val[i], f-used));
				ans += w*cst[i];
				val[i] -= w; val[i^1] += w;
				used += w; if(used == f) return f;
			}
		return used;
	}
	int zkw(){
		while(spfa() && (vis[ed] = 1))
			while(vis[ed]){
				memset(vis, 0, sizeof(bool)*N);
				dfs(st, 1<<30);
			}
		return ans;
	}
};
int mp[N][N];
using namespace MCMF;
int main(){
	int n = read(), m = read(), k = read();
	st = n+1<<1;
	ed = st+1;
	memset(mp, 127/3, sizeof(int)*N*N);
	for(int i = 0; i <= n; i++) mp[i][i] = 0;
	for(int i = 1; i <= m; i++){
		int x = read(), y = read();
		mp[x][y] = mp[y][x] = min(mp[x][y], read());
	}
	for(int k = 0; k <= n; k++)
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				if(k <= i || k <= j)
					mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
	for(int i = 1; i <= n; i++)
		ins(st, i+n+1, 1, 0), ins(i, ed, 1, 0);
	ins(st, n+1, k, 0);
	for(int i = 0; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(mp[i][j] < inf) ins(i+n+1, j, 1, mp[i][j]);
	printf("%d\n", zkw());
	return 0;
}