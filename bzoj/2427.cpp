#include <bits/stdc++.h>
#define N 120
#define M 520
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], to[M], nxt[M], cnt;
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int head2[N], to2[M], nxt2[M], cnt2, in[N];
void ins2(int x, int y){ in[y] = 1;
	to2[++cnt2] = y; nxt2[cnt2] = head2[x]; head2[x] = cnt2;
}
int w[N], v[N], sw[N], sv[N], id[N];
int dfn[N], low[N], ind, q[N], top, tot;
bool inq[N];
void tarjan(int x){
	dfn[x] = low[x] = ++ind;
	q[++top] = x; inq[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
		if(!dfn[to[i]]) tarjan(to[i]), low[x] = min(low[x], low[to[i]]);
		else if(inq[to[i]]) low[x] = min(low[x], dfn[to[i]]);
	int now = 0;
	if(low[x] == dfn[x] && ++tot)
		while(now != x){
			now = q[top--];
			inq[now] = 0;
			id[now] = tot;
			sv[tot] += v[now];
			sw[tot] += w[now];
		}
}
int n, m, f[N][M];
void dp(int x){
	for(int i = head2[x]; i; i = nxt2[i]){
		dp(to2[i]);
		for(int j = max(m-sw[x], -1); ~j; j--)
			for(int k = 0; k <= j; k++)
				f[x][j] = max(f[x][j], f[x][k]+f[to2[i]][j-k]);
	}	
	for(int i = m; ~i; i--)
		f[x][i] = sw[x] <= i ? f[x][i-sw[x]]+sv[x] : 0;
}
int main(int argc, char const *argv[]){
	n = read(); m = read();
	for(int i = 1; i <= n; i++) w[i] = read();
	for(int i = 1; i <= n; i++) v[i] = read();
	for(int i = 1; i <= n; i++) if(int x = read()) ins(x, i);
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	for(int x = 1; x <= n; x++)
		for(int i = head[x]; i; i = nxt[i])
			if(id[to[i]] != id[x]) ins2(id[x], id[to[i]]);
	for(int i = 1; i <= tot; i++) if(!in[i]) ins2(tot+1, i);
	dp(tot+1);
	printf("%d\n", f[tot+1][m]);
	return 0;
}
