#include <bits/stdc++.h>
#define N 100020
#define M 3000020
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], b[N], c[N], n = read(), cnt;
void add(int x) { for (;x<=n;x+=x&-x) c[x]++; }
int ask(int x) {int ans = 0; for (;x;x^=x&-x) ans += c[x]; return ans;}
int x[N], y[N], ls[M], rs[M];
ll l[M], r[M], m[M], lm[M], mr[M], lmr[M], ans;
void update(int x) {
	m[x] = (m[ls[x]] + m[rs[x]]) % mod;
	l[x] = (l[ls[x]] + l[rs[x]]) % mod;
	r[x] = (r[ls[x]] + r[rs[x]]) % mod;
	lm[x] = (lm[ls[x]] + lm[rs[x]] + l[ls[x]] * m[rs[x]] % mod) % mod;
	mr[x] = (mr[ls[x]] + mr[rs[x]] + m[ls[x]] * r[rs[x]] % mod) % mod;
	lmr[x] = (lmr[ls[x]] + lmr[rs[x]] + l[ls[x]] * mr[rs[x]] % mod + lm[ls[x]] * r[rs[x]] % mod) % mod;
}
void change(int x, int l, int r, int k, int v1, int v2, int v3) {
	if (l == r) {
		::l[x] = v1;
		::r[x] = v2;
		::m[x] = v3;
		return;
	}
	int mid = l + r >> 1;
	if (k > mid) {
		if (!rs[x]) rs[x] = ++cnt;
		change(rs[x], mid + 1, r, k, v1, v2, v3);
	} else {
		if (!ls[x]) ls[x] = ++cnt;
		change(ls[x], l, mid, k, v1, v2, v3);
	}
	update(x);
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++)
		a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	cnt = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
	for (int i = 1; i <= n; i++)
		x[i] = ask(a[i]), add(a[i]);
	memset(c, 0, sizeof c);
	for (int i = n; i; i--)
		y[i] = ask(a[i]), add(a[i]);
	for (int i = 1; i <= n; i++) {
		ans = (ans - lmr[a[i]] + mod) % mod;
		change(a[i], 1, n, i, x[i], y[i], 1);
		ans = (ans + lmr[a[i]]) % mod;
	}
	int m = read();
	while (m --) {
		int op = read(), ps = read();
		ans = (ans - lmr[a[ps]] + mod) % mod;
		if (op == 1) change(a[ps], 1, n, ps, 0, 0, 0);
		else change(a[ps], 1, n, ps, x[ps], y[ps], 1);
		ans = (ans + lmr[a[ps]]) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
//  _________
// /---------\
//(   うるさい   )
// \_________/
//
/*
  __  _ _
 / _\|| ||
 \_ \|\ /|
 \__/|/ \|

*/