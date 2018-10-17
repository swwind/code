#include <bits/stdc++.h>
#define N 10020
#define M 50020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int nxt[M], head[N], to[M], cnt;
void insert(int x, int y) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
int dfn[N], low[N], que[N], blo[N], qnt, bnt, tot, sz[N];
void tarjan(int x) {
	dfn[x] = low[x] = ++ tot;
	que[++ qnt] = x;
	for (int i = head[x]; i; i = nxt[i])
		if (!dfn[to[i]]) tarjan(to[i]), low[x] = min(low[x], low[to[i]]);
		else if (!blo[to[i]]) low[x] = min(low[x], dfn[to[i]]);
	if (dfn[x] == low[x] && ++ bnt)
		while (que[qnt + 1] != x)
			blo[que[qnt --]] = bnt, sz[bnt] ++;
}
int x[M], y[M], in[N], out[N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i ++) {
		x[i] = read();
		y[i] = read();
		insert(x[i], y[i]);
	}
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= m; i ++) {
		if (blo[x[i]] != blo[y[i]]) {
			out[blo[x[i]]] ++;
			in[blo[y[i]]] --;
		}
	}
	int ans = 0;
	for (int i = 1; i <= bnt; i ++)
		if (!out[i]) if (ans) return puts("0"), 0; else ans = sz[i];
	printf("%d\n", ans);
	return 0;
}