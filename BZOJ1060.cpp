#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<1], nxt[N<<1], head[N], val[N<<1], cnt;
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; val[cnt] = z;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; val[cnt] = z;
}
ll fa[N], ans;
void dfs(int x, int f){
	for(int i = head[x]; i; i = nxt[i]) if(to[i] != f){
		dfs(to[i], x);
		fa[x] = max(fa[x], fa[to[i]]+val[i]);
	}
	for(int i = head[x]; i; i = nxt[i]) if(to[i] != f)
		ans += fa[x]-fa[to[i]]-val[i];
}
int main(){
	int n = read(), rt = read();
	for(int i = 1; i < n; i++){
		int x = read(), y = read(), z = read();
		ins(x, y, z);
	}
	dfs(rt, 0);
	printf("%lld\n", ans);
	return 0;
}