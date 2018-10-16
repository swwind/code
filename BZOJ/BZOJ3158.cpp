#include <bits/stdc++.h>
#define N 1020
#define M 2000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int to[M], nxt[M], head[N], val[M], dep[N], cnt = 1, st = 0, ed, q[N];
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
int a[N], b[N];
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int check(ll x, ll y){
	ll z = x*x+y*y, k = sqrt(z);
	if(k*k != z) return 1;
	if(gcd(x, y) > 1) return 1;
	return 0;
}
int main(int argc, char const *argv[]){
	int n = read(), ans = 0; ed = n+1;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) ans += b[i] = read();
	for(int i = 1; i <= n; i++)
		if(a[i]&1) ins(st, i, b[i]);
		else ins(i, ed, b[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if((a[i]&1) && (~a[j]&1) && !check(a[i], a[j]))
				ins(i, j, 1<<30);
	while(bfs())ans-=dfs(st, 1<<30);
	printf("%d\n", ans);
	return 0;
}