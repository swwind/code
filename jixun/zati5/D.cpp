#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') ch == '-' && (f = 0) || (ch = getchar());
	while (ch <= '9' && ch >= '0')
		x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? x : -x;
}
int head[N], to[N << 1], nxt[N << 1], cnt;
void insert(int x, int y) {
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	to[++cnt] = x;
	nxt[cnt] = head[y];
	head[y] = cnt;
}
int dfn[N], low[N], tot, ans;
void tarjan(int x, int fa) {
	dfn[x] = low[x] = ++tot;
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		if (!dfn[to[i]]) {
			tarjan(to[i], x);
			low[x] = min(low[x], low[to[i]]);
			if (low[to[i]] > dfn[x]) ans++;
		} else {
			low[x] = min(low[x], dfn[to[i]]);
		}
	}
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) insert(read(), read());
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i, 0);
	printf("%d\n", ans);
	return 0;
}