#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], nxt[N << 1], to[N << 1], cnt = 1;
void insert(int x, int y) {
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int n = read(), U, V, E, vis[N], val[N];
void dfs(int x, int fa) {
	vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (to[i] == fa) continue;
		else if (!vis[to[i]]) dfs(to[i], x);
		else U = x, V = to[i], E = i;
}
ll f[N][2], ans;
void work(int x, int fa) {
	f[x][1] = val[x]; f[x][0] = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa || (i >> 1) == (E >> 1))
			continue;
		work(to[i], x);
		f[x][1] += f[to[i]][0];
		f[x][0] += max(f[to[i]][0], f[to[i]][1]);
	}
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++) {
		val[i] = read();
		insert(read(), i);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
			work(U, 0);
			ll sum = f[U][0];
			work(V, 0);
			ans += max(sum, f[V][0]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}