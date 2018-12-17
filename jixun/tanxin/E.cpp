#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll mx[N], mxj[N], type[N], a[N];
vector<pair<long double, ll>> ans;
vector<pair<ll, ll>> add[N];
vector<ll> res, ljz[3];
int main(int argc, char const *argv[]) {
	int n = read(), k = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int j = 1; j <= k; j++) {
		ll t = read(), i = read(), b = read();
		if (t == 1) {
			if (b > mx[i])
				mxj[i] = j;
			mx[i] = max(mx[i], b);
		} else if (t == 2) {
			add[i].push_back(make_pair(b, j));
		} else {
			ans.push_back(make_pair(b, j));
		}
		type[j] = t;
	}
	for (int i = 1; i <= n; i++) {
		if (mx[i] > a[i])
			add[i].push_back(make_pair(mx[i] - a[i], mxj[i]));
		sort(add[i].begin(), add[i].end());
		reverse(add[i].begin(), add[i].end());
		for (auto s : add[i]) {
			ans.push_back(make_pair(1. * (a[i] + s.first) / a[i], s.second));
			a[i] = a[i] + s.first;
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < m && i < ans.size(); i++)
		res.push_back(ans[i].second);
	for (auto s : res)
		ljz[type[s] - 1].push_back(s);
	cout << res.size() << endl;
	for (int i = 0; i < 3; i++)
		for (auto s : ljz[i])
			cout << s << " ";
	cout << endl;
	return 0;
}