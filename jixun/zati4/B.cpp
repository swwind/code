#include <bits/stdc++.h>
#define N 100020
#define ll unsigned long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[50], k;
vector<ll> ans[2];
void work(int l, int r, int z) {
	vector<ll> &res = ans[z];
	for (int i = l; i <= r; i++) {
		if (a[i] > k) continue;
		int res_end = res.size();
		for (int j = 0; j < res_end; j++) {
			if (k / a[i] >= res[j])
				res.push_back(res[j] * a[i]);
		}
		res.push_back(a[i]);
	}
}
int main(int argc, char const *argv[]) {
	int n = read(); k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	int mid = n >> 1;
	work(1, mid, 0);
	work(mid + 1, n, 1);
	sort(ans[0].begin(), ans[0].end());
	sort(ans[1].begin(), ans[1].end());
	ll result = 0;
	for (auto s : ans[0]) {
		ll f = k / s;
		ll g = upper_bound(ans[1].begin(), ans[1].end(), f) - ans[1].begin();
		// printf("%lld %lld\n", f, g);
		result += g;
	}
	printf("%llu\n", result + ans[0].size() + ans[1].size());
	return 0;
}