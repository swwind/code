#include <bits/stdc++.h>
#define N 100
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
int a[N];
int main(){
	int T = read();
	while(T--){
		cnt = 1; memset(head, 0, sizeof head);
		int n = read(), ans = 0, tot = 0; ed = n<<1|1;
		for(int i = 1; i <= n; i++)
			if(a[i] = read()) ins(i+n, ed, 1);
		for(int i = 1; i <= n; i++)
			if(!read()&&a[i]||!a[i]) ins(st, i, 1), tot++;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(read()||i==j) ins(i, j+n, 1);
		while(bfs())ans+=dfs(st, 1<<30);
		puts(ans == tot ? "^_^" : "T_T");
	}
	return 0;
}