#include <bits/stdc++.h>
#define N 120
#define M 500000
#define ll long long
#define id(i, j) (i-1)*m+j
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[M], nxt[M], head[N*N], val[M], dep[N*N], cnt = 1, st = 0, ed, q[N*N];
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = 0; head[y] = cnt;
}
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
int mp[N][N];
int main(){
	int n = read(), m = read(); ed = n*m+1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if((mp[i][j]=read()) == 1) ins(st, id(i, j), 1<<30);
			else if(mp[i][j] == 2) ins(id(i, j), ed, 1<<30);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)if(mp[i][j]!=2){
			if(i != n && (mp[i][j] != 1 || mp[i+1][j] != 1))
				ins(id(i, j), id(i+1, j), 1);
			if(j != m && (mp[i][j] != 1 || mp[i][j+1] != 1))
				ins(id(i, j), id(i, j+1), 1);
			if(i != 1 && (mp[i][j] != 1 || mp[i-1][j] != 1))
				ins(id(i, j), id(i-1, j), 1);
			if(j != 1 && (mp[i][j] != 1 || mp[i][j-1] != 1))
				ins(id(i, j), id(i, j-1), 1);
		}
	int ans = 0;
	while(bfs())ans+=dfs(st, 1<<30);
	printf("%d\n", ans);
	return 0;
}