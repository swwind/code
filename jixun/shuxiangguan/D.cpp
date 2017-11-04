#include <bits/stdc++.h>
#define ll long long
#define N 200020
#define fs first
#define sc second
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f?x:-x;
}
int n = read();
int dep[N], fa[N];
vector <int> mp[N];
void dfs(int x, int f, int d) {
	dep[x] = d; fa[x] = f;
	for (auto y : mp[x])
		if (y != f) dfs(y, x, d + 1);
}
pair<int, int> get_center() {
	dfs(1, 0, 0);
	dfs(max_element(dep + 1, dep + n + 1) - dep, 0, 0);
	int ct = max_element(dep + 1, dep + n + 1) - dep;
	int ht = dep[ct];
	for (int i = 0; i < ht / 2; i++)
		ct = fa[ct];
	return make_pair(ct, (ht & 1) ? fa[ct] : ct);
}
ll hsh[N];
ll get_hash(int x, int f) {
	hsh[x] = 17;
	for (auto y : mp[x])
		if (y != f) get_hash(y, x);
	sort(mp[x].begin(), mp[x].end(), [&] (int a, int b) {
		return hsh[a] < hsh[b];
	});
	for (auto y : mp[x]) {
		if (y == f)
			continue;
		hsh[x] = (hsh[x] + hsh[y]) ^ (hsh[x] * hsh[y]);
		hsh[x] %= mod;
	}
	return hsh[x] = hsh[x] * hsh[x] % mod;
}
int get_ans(int x, int f) {
	int ret = mp[x].size() < 4;
	int lst = -1;
	for (auto y : mp[x]) {
		if (y == f)
			continue;
		if (lst == -1 || hsh[lst] != hsh[y])
			ret += get_ans(y, x);
		lst = y;
	}
	return ret;
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	auto ctr = get_center();
	get_hash(ctr.fs, ctr.sc);
	get_hash(ctr.sc, ctr.fs);
	int res = get_ans(ctr.fs, ctr.sc) + get_ans(ctr.sc, ctr.fs);
	if (hsh[ctr.fs] == hsh[ctr.sc]) res >>= 1;
	printf("%d\n", res);
	return 0;
}
