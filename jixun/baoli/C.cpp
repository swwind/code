#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define pii pair<ll, ll>
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
pii p[N];
int a[N], b[N], c[N], d[N], v[N];
bool cmp1(int a, int b){return p[a].first<p[b].first;}
bool cmp2(int a, int b){return p[a].first>p[b].first;}
bool cmp3(int a, int b){return p[a].second<p[b].second;}
bool cmp4(int a, int b){return p[a].second>p[b].second;}
int main(int argc, char const *argv[]) {
	int n = read(), k = read();
	for (int i = 1; i <= n; i++) {
		ll x1 = read(), y1 = read(), x2 = read(), y2 = read();
		p[i].first = x1+x2;
		p[i].second = y1+y2;
		b[i] = c[i] = d[i] = a[i] = i;
	}
	sort(a+1, a+n+1, cmp1);
	sort(b+1, b+n+1, cmp2);
	sort(c+1, c+n+1, cmp3);
	sort(d+1, d+n+1, cmp4);
	ll ans = 1ll<<62, cnt = 0;
	for (int aa = 0; aa <= k; aa++)
		for (int bb = 0; bb <= k; bb++)
			for (int cc = 0; cc <= k; cc++)
				for (int dd = 0; dd <= k; dd++) {
					++cnt; int now = 0;
					for (int i = 1; i <= aa; i++) if (v[a[i]] != cnt) v[a[i]] = cnt, now++;
					for (int i = 1; i <= bb; i++) if (v[b[i]] != cnt) v[b[i]] = cnt, now++;
					for (int i = 1; i <= cc; i++) if (v[c[i]] != cnt) v[c[i]] = cnt, now++;
					for (int i = 1; i <= dd; i++) if (v[d[i]] != cnt) v[d[i]] = cnt, now++;
					if (now != k) continue;
					ll u = -1ll<<62, d = 1ll<<62, l = 1ll<<62, r = -1ll<<62;
					for (int i = 1; i <= n; i++)
						if (v[i] != cnt) {
							u = max(u, p[i].first);
							d = min(d, p[i].first);
							l = min(l, p[i].second);
							r = max(r, p[i].second);
						}
					ll x = max(u-d, 2ll), y = max(r-l, 2ll);
					ans = min(ans, x*y);
				}
	printf("%lld\n", ans/4);
	return 0;
}