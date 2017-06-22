#include <bits/stdc++.h>
#define N 2005
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N*N], nxt[N*N], head[N], cnt, vis[N], ans;
int ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int dfs(int x, int f){
	vis[x] = f; ++ans;
	for(int i = head[x]; i; i = nxt[i])
		vis[to[i]] < f && dfs(to[i], f);
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++, getchar())
		for(int j = 1; j <= n; j++)
			getchar() == '1' && ins(i, j);
	for(int i = 1; i <= n; i++) dfs(i, i);
	printf("%d\n", ans);
	return 0;
}