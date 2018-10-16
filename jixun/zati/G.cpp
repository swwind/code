#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int c[N], n, q;
inline void add(int x) {
	for(;x<=n;x+=x&-x)c[x]++;
}
inline int ask(int x) {
	int ans = 0;
	for(;x;x^=x&-x)ans+=c[x];
	return ans;
}
ll a[N], ans[N][4], res[N], cnt;
struct node {
	int i, k, x, y, mul;
	friend bool operator < (const node &a, const node &b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
}mitsuha[N<<3];
#define addask(s, ...) mitsuha[i << 3 | s] = (node){ __VA_ARGS__ }
int main(int argc, char const *argv[]) {
	n = read(); q = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 0; i < q; i++) {
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		res[i]	= 1ll * (x1 - 1) * (x1 - 2) / 2 + 1ll * (y1 - 1) *(y1 - 2) / 2
				+ 1ll * (n - x2) * (n - x2 - 1) / 2 + 1ll * (n - y2) * (n - y2 - 1) / 2;
		addask(0, i, 0, x1 - 1, y1 - 1, 1);
		addask(1, i, 1, x1 - 1, n, 1);
		addask(2, i, 1, x1 - 1, y2, -1);
		addask(3, i, 2, x2, y1 - 1, -1);
		addask(4, i, 2, n, y1 - 1, 1);
		addask(5, i, 3, x2, n, -1);
		addask(6, i, 3, n, y2, -1);
		addask(7, i, 3, x2, y2, 1);
	}
	q <<= 3;
	sort(mitsuha, mitsuha + q);
	int k = 0;
	while (k < q && !mitsuha[k].x) k++;
	// printf("k = %d\n", q);
	for (int i = 1; i <= n; i++) {
		add(a[i]);
		while (k < q && mitsuha[k].x == i) {
			int rs = ask(mitsuha[k].y);
			// if (mitsuha[k].i == 2) printf("%d %d (%d, %d) %d\n", mitsuha[k].i, mitsuha[k].k, i, mitsuha[k].y, rs);
			ans[mitsuha[k].i][mitsuha[k].k] += mitsuha[k].mul * rs;
			k++;
		}
	}
	q >>= 3;
	for (int i = 0; i < q; i++) {
		ans[i][3] += n;
		// printf("res => %d\n", res[i]);
		// printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
		res[i] -= 1ll * ans[i][0] * (ans[i][0] - 1) / 2 + 1ll * ans[i][1] * (ans[i][1] - 1) / 2
				+ 1ll * ans[i][2] * (ans[i][2] - 1) / 2 + 1ll * ans[i][3] * (ans[i][3] - 1) / 2;
		printf("%lld\n", 1ll * n * (n - 1) / 2 - res[i]);
	}
	return 0;
}