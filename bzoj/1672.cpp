#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int l, r;
	ll val;
	bool operator < (const node &b) const {
		return l < b.l;
	}
}data[10050];
ll f[10050], ans = (1LL<<60);
int main(){
	int n, m, e;
	scanf("%d%d%d", &n, &m, &e);
	for(int i = 0; i < n; i++)
		scanf("%d%d%lld", &data[i].l, &data[i].r, &data[i].val);
	sort(data, data+n);
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i < n; i++)
		if(data[i].l <= m)
			f[i] = data[i].val;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
			if(data[j].r + 1 >= data[i].l)
				f[i] = min(f[i], f[j]+data[i].val);
	for(int i = 0; i < n; i++)
		if(data[i].r >= e)
			ans = min(ans, f[i]);
	if(ans == (1LL<<60)) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}
