#include <bits/stdc++.h>
#define N 200020
#define INF (1 << 30)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct Sword_Art_Online {
	int l, r, id;
	Sword_Art_Online(int l = 0, int r = 0, int id = 0):
		l(l), r(r), id(id){}
	friend bool operator < (const Sword_Art_Online &a, const Sword_Art_Online &b) {
		return a.l == b.l ? a.r < b.r : a.l < b.l;
	}
}sao[N];
vector <Sword_Art_Online> alo;
ll ans;
int ans1, ans2;
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		sao[i].l = read();
		sao[i].r = read();
		sao[i].id = i;
	}
	sort(sao + 1, sao + n + 1);
	alo.push_back(Sword_Art_Online(-INF, -INF));
	for (int i = 1; i <= n; i++)
		if (sao[i].r > alo.back().r)
			alo.push_back(sao[i]);
	n = alo.size();
	for (int i = 1; i <= m; i++) {
		int ki = read(), ri = read(), to = read();
		int pos = lower_bound(alo.begin(), alo.end(), Sword_Art_Online(ki, -1)) - alo.begin() - 1;
		if (!pos) pos++;
		while (pos < n && alo[pos].l <= ri) {
			ll val = 1ll * to * (min(alo[pos].r, ri) - max(alo[pos].l, ki));
			if (val > ans) {
				ans = val;
				ans1 = alo[pos].id;
				ans2 = i;
			}
			pos++;
		}
	}
	if (ans) printf("%lld\n%d %d\n", ans, ans1, ans2);
	else puts("0");
	return 0;
}