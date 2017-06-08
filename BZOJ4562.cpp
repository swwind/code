#include <bits/stdc++.h>
#define N 100007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int head[N], to[N<<1], nxt[N<<1], cnt, ans, dp[N], in[N], a[N];
void add(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x];
	head[x] = cnt; in[y]++;
}
void dfs(int x){
	for(int i = head[x]; i; i = nxt[i]){
		dp[to[i]] += dp[x];
		if(!--in[to[i]]) dfs(to[i]);
	}
}
int main(){
	int n = read(), m = read();
	for(int i = 1, x, y; i <= m; i++){
		x = read(); y = read();
		add(x, y);
	}
	for(int i = 1; i <= n; i++)
		if(!in[i]&&head[i])
			a[++a[0]] = i;
	for(int i = 1; i <= a[0]; i++)
			dp[a[i]] = 1, dfs(a[i]);
	for(int i = 1; i <= n; i++)
		if(!head[i]) ans += dp[i];
	printf("%d\n", ans);
}