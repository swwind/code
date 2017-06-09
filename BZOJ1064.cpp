#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int inf = 1<<30;
int n, m, cnt, maxn, minx, ans, tmp;
struct edge{int to,nxt,val;}e[2000020];
int head[100020], vis[100020], mark[100020];
void ins(int x, int y, int v){
	e[++cnt].nxt = head[x];
	e[cnt].to = y;
	e[head[x]=cnt].val = v;
}
void ins(int x, int y){
	ins(x, y, 1); ins(y, x, -1);
}
int gcd(int a, int b){return b?gcd(b, a%b):a;}
void dfs(int x, int len){
	if(vis[x]){ans = gcd(ans, abs(mark[x]-len)); return;}
	vis[x] = 1; mark[x] = len;
	maxn = max(maxn, len); minx = min(minx, len);
	for(int i = head[x]; i; i=e[i].nxt)
		dfs(e[i].to, len+e[i].val);
}
int main(){
	n=read(); m=read();
	for(int i = 1,x,y; i <= m; i++){
		x=read();y=read();
		ins(x, y);
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		minx = inf; maxn = -inf;
		dfs(i, 1);
		tmp += maxn-minx+1;
	}
	int ans2 = 3;
	if(!ans) ans = tmp;
	else while(ans2<=ans&&ans%ans2)ans2++;
	if(ans<3) puts("-1 -1");
	else printf("%d %d\n", ans, ans2);
}