#include <bits/stdc++.h>
#define N 100020
#define M 500020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], nxt[M], to[M], cnt;
void ins(int x, int y) {
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int dfn[N], low[N], tot, blo[N], bnt, que[N], qnt, sz[N];
void tarjan(int x) {
	dfn[x] = low[x] = ++tot;
	que[++qnt] = x;
	for (int i = head[x]; i; i = nxt[i])
		if (!dfn[to[i]]) tarjan(to[i]), low[x] = min(low[x], low[to[i]]);
		else if (!blo[to[i]]) low[x] = min(low[x], dfn[to[i]]);
	if (low[x] == dfn[x] && ++bnt)
		while (que[qnt+1] != x)
			blo[que[qnt--]] = bnt, sz[bnt]++;
}
int in[N], rk[M], fr[M], ans;
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		ins(x, y); rk[i] = y; fr[i] = x;
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= m; i++)
		blo[fr[i]] != blo[rk[i]] && ++ in[blo[rk[i]]];
	for (int i = 1; i <= bnt; i++)
		ans += !in[i];
	cout << ans << endl;
	return 0;
}