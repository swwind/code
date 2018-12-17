#include <bits/stdc++.h>
#define N 30
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int ans, vis[N];
vector<pair<int, int>> son[N];
void dfs(int x, int d) {
	ans = max(ans, d);
	for (auto s : son[x]) {
		if (!vis[s.first]) {
			vis[s.first] = 1;
			dfs(s.first, d + s.second);
			vis[s.first] = 0;
		}
	}
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read();
		son[x].push_back(make_pair(y, z));
		son[y].push_back(make_pair(x, z));
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
		dfs(i, 0);
		vis[i] = 0;
	}
	printf("%d\n", ans);
	return 0;
}