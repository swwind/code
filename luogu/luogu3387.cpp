#include <bits/stdc++.h>
#define N 10020
#define M 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct dag {
	int to[M], nxt[M], head[N], cnt;
	void insert(int x, int y) {
		to[++cnt] = y;
		nxt[cnt] = head[x];
		head[x] = cnt;
	}
} mp1, mp2;
int dfn[N], low[N], tnt, point_val[N], blo[N], bnt, que[N], qnt, pval[N];
void tarjan(int x) {
	dfn[x] = low[x] = ++tnt;
	que[++qnt] = x;
	for (int i = mp1.head[x]; i; i = mp1.nxt[i]) {
		int y = mp1.to[i];
		if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
		else if(!blo[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x] && ++bnt)
		while (que[qnt+1] != x) {
			int y = que[qnt--];
			blo[y] = bnt;
			pval[bnt] += point_val[y];
		}
}
int x[M], y[M], init[N], ntr[N], nnt, ans, dp[N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		point_val[i] = read();
	for (int i = 1; i <= m; i++) {
		x[i] = read(); y[i] = read();
		mp1.insert(x[i], y[i]);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= m; i++)
		if (blo[x[i]] != blo[y[i]]) {
			mp2.insert(blo[x[i]], blo[y[i]]);
			init[blo[y[i]]]++;
		}
	for (int i = 1; i <= bnt; i++) {
		ans = max(ans, dp[i] = pval[i]);
		if (!init[i])
			ntr[++nnt] = i;
	}
	while (nnt) {
		int x = ntr[nnt--];
		for (int i = mp2.head[x]; i; i = mp2.nxt[i]) {
			int y = mp2.to[i];
			ans  = max(ans, dp[y] = max(dp[y], dp[x]+pval[y]));
			if (!--init[y])
				ntr[++nnt] = y;
		}
	}
	printf("%d\n", ans);
	return 0;
}
