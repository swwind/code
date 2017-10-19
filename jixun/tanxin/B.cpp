#include <bits/stdc++.h>
#define N 2000020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[N], b[N], cnt, nxt[N], pre[N];
void merge(int x) {
	// printf("deleted %d\n", x);
	int l = pre[x], r = nxt[x];
	if (l) nxt[l] = r;
	if (r) pre[r] = l;
}
ll ans, num, tmp;
set<pair<ll, int>> q;
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; ++i) {
		if ((tmp < 0 && a[i] > 0) || (tmp > 0 && a[i] < 0)) {
			num += tmp > 0;
			b[++cnt] = tmp;
			q.insert(make_pair(abs(tmp), cnt));
			tmp = 0;
		}
		tmp += a[i];
		ans += a[i] > 0 ? a[i] : 0;
	}
	num += tmp > 0;
	b[++cnt] = tmp;
	q.insert(make_pair(abs(tmp), cnt));
	for (int i = 1; i <= cnt; i++) {
		nxt[i] = i + 1;
		pre[i] = i - 1;
	}
	nxt[cnt] = b[0] = 0;
	while (num > m) {
		auto x = (*q.begin()).second;
		// printf(" === %d\n", x);
		q.erase(q.begin());
		if (b[x] < 0 && (!pre[x] || !nxt[x]) || !b[x])
			continue;
		q.erase(make_pair(abs(b[pre[x]]), pre[x]));
		q.erase(make_pair(abs(b[nxt[x]]), nxt[x]));

		ans -= abs(b[x]);
		b[x] = b[x] + b[nxt[x]] + b[pre[x]];

		merge(pre[x]);
		merge(nxt[x]);
		q.insert(make_pair(abs(b[x]), x));
		num --;
	}
	cout << ans << endl;
	return 0;
}
