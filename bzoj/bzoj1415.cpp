#include <bits/stdc++.h>
#define N 1003
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<1], nxt[N<<1], head[N], d[N], cnt;
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; d[x]++;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; d[y]++;
}
int dis[N][N], q[N*N], pre[N];
void bfs(int p){
	int *d = dis[p];
	memset(d, -1, sizeof(int)*N);
	int l = 0, r = 1; q[1] = p; d[p] = 0;
	while(l < r){
		int x = q[++l];
		for(int i = head[x]; i; i = nxt[i])
			if(~d[to[i]] && d[to[i]] == d[x]+1)
				pre[to[i]] = min(pre[to[i]], x);
			else if(!~d[to[i]]){
				d[to[i]] = d[x]+1;
				pre[to[i]] = x;
				q[++r] = to[i];
			}
	}
}
double f[N][N];
int   wk[N][N];
bool vis[N][N];
double find(int st, int ed){
	if(st == ed) return f[st][ed] = 0;
	if(dis[st][ed] <= 2) return f[st][ed] = 1;
	if(vis[st][ed]) return f[st][ed];
	vis[st][ed] = 1; f[st][ed] = 0;
	int k = wk[wk[st][ed]][ed];
	for(int i = head[ed]; i; i = nxt[i])
		f[st][ed] += (find(k, to[i])+1)/(d[ed]+1);
	f[st][ed] += (find(k, ed)+1)/(d[ed]+1);
	return f[st][ed];
}
int main(){
	int n = read(), e = read();
	int c = read(), m = read();
	for(int i = 1; i <= e; i++)
		ins(read(), read());
	for(int i = 1; i <= n; i++){
		bfs(i);
		for(int j = 1; j <= n; j++)
			wk[j][i] = pre[j];
	}
	printf("%.3lf\n", find(c, m));
	return 0;
}