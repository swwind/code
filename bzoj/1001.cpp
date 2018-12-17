#include <bits/stdc++.h>
#define N 1000007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<3], nxt[N<<3], head[N], val[N<<3], dep[N], cnt = 1, nm, q[N], ans;
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = z; head[y] = cnt;
}
int bfs(){
	memset(dep, 0, sizeof dep);
	int l = 0, r = 1; q[1] = 1; dep[1] = 1;
	while(l < r){
		int x = q[++l];
		for(int i = head[x]; i; i = nxt[i])
			if(val[i] && !dep[to[i]]){
				q[++r] = to[i];
				dep[to[i]] = dep[x]+1;
			}
	}
	return dep[nm];
}
int dfs(int x, int f){
	if(x == nm) return f;
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
int main(){
	int n = read(), m = read();
	nm = n*m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < m; j++)
			ins(m*(i-1)+j, m*(i-1)+j+1, read());
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++)
			ins(m*(i-1)+j, m*i+j, read());
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			ins(m*(i-1)+j, m*i+j+1, read());
	while(bfs())ans+=dfs(1, 1<<30);
	printf("%d\n", ans);
}