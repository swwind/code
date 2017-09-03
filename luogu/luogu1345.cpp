#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int to[N<<3], nxt[N<<3], head[N], val[N<<3], dep[N], cnt = 1, nm, q[N], st;
void ins(int x, int y, int z){
	// printf("%d -> %d : %d\n", x, y, z);
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
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	st = read()+n; nm = read();
	for(int i = 1; i <= n; i++) ins(i, i+n, 1);
	for(int i = 1; i <= m; i++){
		int x = read(), y = read();
		ins(x+n, y, 1<<29);
		ins(y+n, x, 1<<29);
	}
	int ans = 0;
	while(bfs()) ans += dfs(st, 1<<30);
	printf("%d\n", ans);
	return 0;
}