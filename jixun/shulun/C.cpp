#include <bits/stdc++.h>
#define N 500020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node {
	int a, b, c, d;
	node(int a = 0, int b = 0, int c = 0, int d = 0) {
		this -> a = a;
		this -> b = b;
		this -> c = c;
		this -> d = d;
	}
};
vector<node> ans;
vector<int> mp[2][N];
int fa[2][N], f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int id, int x, int f) {
	fa[id][x] = f;
	for (auto y : mp[id][x])
		if (y != f) dfs(id, y, x);
}
void solve(int x, int f) {
	for (auto y : mp[0][x]) {
		if (y == f) continue;
		solve(y, x);
		if (y != fa[1][x] && x != fa[1][y])
			ans.push_back(node(x, y, find(y), fa[1][find(y)]));
	}
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		mp[0][x].push_back(y);
		mp[0][y].push_back(x);
	}
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		mp[1][x].push_back(y);
		mp[1][y].push_back(x);
	}
	dfs(0, 1, 0);
	dfs(1, 1, 0);
	for (int i = 1; i <= n; i++) {
		int j = fa[1][i];
		if (fa[0][i] == j || fa[0][j] == i) {
			f[i] = j;
		} else {
			f[i] = i;
		}
	}
	solve(1, 0);
	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x.a << " " << x.b << " " << x.c << " " << x.d << endl;
	return 0;
}