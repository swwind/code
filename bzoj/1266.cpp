#include <bits/stdc++.h>
#define N 520
#define M 124800
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int to[M<<2], nxt[M<<2], head[N], cnt = 1, dep[N], q[N], val[M<<2];
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = z;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = 0;
}
int n, m, st = 1, ed;
int bfs(){
	memset(dep, 0, sizeof dep);
	int l = 0, r = 1; q[1] = st; dep[st] = 1;
	while(l < r){
		int x = q[++l];
		for(int i = head[x]; i; i = nxt[i])
			if(val[i] && !dep[to[i]]){
				q[++r] = to[i];
				dep[to[i]] = dep[x]+1;
			}
	}
	return dep[ed];
}
int dfs(int x, int f){
	if(x == ed) return f;
	int sum = 0;
	for(int i = head[x]; i; i = nxt[i]){
		if(val[i] && dep[to[i]] == dep[x]+1){
			int w = dfs(to[i], min(f-sum, val[i]));
			val[i] -= w; val[i^1] += w;
			sum += w; if(sum == f) return f;
		}
	}
	if(!sum) dep[x] = 0;
	return sum;
}
int mp[N][N], u[M], v[M], t[M], c[M];
int main(int argc, char const *argv[]){
	n = read(); m = read(); ed = n;
	memset(mp, 63, sizeof(int)*N*N);
	for(int i = 1; i <= n; i++) mp[i][i] = 0;
	for(int i = 1; i <= m; i++){
		u[i] = read(), v[i] = read();
		t[i] = read(), c[i] = read();
		mp[u[i]][v[i]] = mp[v[i]][u[i]] = t[i];
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
	printf("%d\n", mp[1][n]);
	for(int i = 1; i <= m; i++){
		int x = u[i], y = v[i];
		if(mp[1][x]+t[i]+mp[y][n] == mp[1][n]) ins(x, y, c[i]);
		if(mp[1][y]+t[i]+mp[x][n] == mp[1][n]) ins(y, x, c[i]);
	}
	int ans = 0;
	while(bfs()) ans += dfs(st, 1<<30);
	printf("%d\n", ans);
	return 0;
}