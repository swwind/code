#include <bits/stdc++.h>
#define N 50007
#define M 2000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int head[N], to[M], nxt[M], cnt;
int ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int dfn[N], low[N], tot, a[M], q[M], f[N], fa[N], ans;
void dp(int x, int y){
	int top = 0;
	while(x != y) a[++top] = f[y], y = fa[y]; a[++top] = f[x];
	for(int i = 1; i < top; i++) a[top+i] = a[i];
	int l = 1, r = 1, p = top/2; q[1] = 1;
	for(int i = 2; i <= top+p; i++){
		while(l <= r && i-q[l] > p) l++;
		ans = max(ans, a[q[l]]+a[i]+i-q[l]);
		while(l <= r && a[q[r]]+i-q[r] <= a[i]) r--;
		q[++r] = i;
	}
	for(int i = 1; i < top; i++)
		f[x] = max(f[x], a[i]+min(i, top-i));
}
void tarjan(int x){
	dfn[x] = low[x] = ++tot;
	for(int i = head[x]; i; i = nxt[i]) if(fa[x]!=to[i])
		if(!dfn[to[i]]){
			fa[to[i]] = x;
			tarjan(to[i]);
			low[x] = min(low[x], low[to[i]]);
			if(dfn[x] < low[to[i]]){
				ans = max(ans, f[x]+f[to[i]]+1);
				f[x] = max(f[x], f[to[i]]+1);
			}
		}
		else low[x] = min(low[x], dfn[to[i]]);
	for(int i = head[x]; i; i = nxt[i])
		if(fa[to[i]] != x && dfn[x] < dfn[to[i]])
			dp(x, to[i]);
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++){
		int time = read(), last = read(), nw;
		for(int j = 1; j < time; j++)
			ins(nw=read(), last), last = nw;
	}
	tarjan(1);
	printf("%d\n", ans);
}
/*
15 3
9 1 2 3 4 5 6 7 8 3
7 2 9 10 11 12 13 10
5 2 14 9 15 10
*/