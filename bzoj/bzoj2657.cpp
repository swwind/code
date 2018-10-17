#include <bits/stdc++.h>
#define N 2000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int nxt[N<<1], head[N], cnt, to[N<<1];
void ins(int x, int y) {
	// printf("%d -> %d\n", x, y);
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
map<pair<int, int>, int>mp;
void check(int x, int y, int t) {
	pair<int, int> k = make_pair(x, y);
	if (mp[k]) ins(mp[k], t), mp[k] = 0;
	else mp[k] = t;
}
int dep[N], ans;
void dfs(int x, int f) {
	// printf("%d -> %d\n", x, f);
	dep[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == f) continue;
		dfs(to[i], x);
		ans = max(ans, dep[x]+dep[to[i]]);
		dep[x] = max(dep[x], dep[to[i]]+1);
	}
}
int main(int argc, char const *argv[]) {
	int n = read()-2;
	for (int i = 1; i <= n; i++) {
		int x = read(), y = read(), z = read();
		if (x > y) swap(x, y);
		if (y > z) swap(y, z);
		if (x > z) swap(x, z);
		check(x, y, i);
		check(y, z, i);
		check(x, z, i);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
