#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N], nxt[N<<1], to[N<<1], cnt;
void insert(int x, int y) {
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
int a[N], b[N], n = read(), k = read();
int f[N], sz[N], nt[N], sum, ans;
int dfs1(int x, int fa) {
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		dfs1(to[i], x);
		sz[x] += sz[to[i]];
		nt[x] += nt[to[i]];
	}
}
void dfs2(int x, int fa) {
	// printf("%d %d \n", x, fa);
	f[x] = 1;
	int mx = 0, sx = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		dfs2(to[i], x);
		if (!nt[to[i]]) f[x] += sz[to[i]];
		else if (!b[to[i]])
			if (f[to[i]] > mx) sx = mx, mx = f[to[i]];
			else if (f[to[i]] > sx) sx = f[to[i]];
	}
	f[x] += mx;
	if (!b[x]) {
		if (nt[x] == sum) ans = max(ans, f[x] + sx + n - sz[x]);
		else ans = max(ans, f[x] + sx);
	}
}
bool check(int mid) {
	// printf("%d:\n", mid);
	ans = sum = 0;
	for (int i = 1; i <= n; i++) {
		sz[i] = 1;
		sum += nt[i] = b[i] = a[i] <= mid;
	}
	dfs1(1, 0);
	dfs2(1, 0);
	// puts(ans >= k ? "Yes" : "No");
	return ans >= k;
}
int main(int argc, char const *argv[]) {
	int l = 1, r = 0, ans;
	for (int i = 1; i <= n; i++)
		r = max(r, a[i] = read());
	for (int i = 1; i < n; i++)
		insert(read(), read());
	r ++;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else ans = mid, r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}