#include <bits/stdc++.h>
#define N 100020
#define LG 12
#define L (x << 1)
#define R (x<<1|1)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node {
	ll x, z, mk;
}t[N << 2];
ll pw[LG + 5];
ll calc(ll x) {
	return *lower_bound(pw, pw + LG + 1, x) - x;
}
void update(int x) {
	t[x].x = min(t[L].x, t[R].x);
	t[x].z = t[L].z == t[R].z ? t[L].z : 0;
}
void change(int x, ll k) {
	// cout << "???" << endl;
	t[x].z = k;
	t[x].x = calc(k);
	t[x].mk = 0;
}
void add(int x, ll k) {
	// cout << "aha ??" << endl;
	t[x].x -= k;
	if (t[x].z) t[x].z += k;
	else t[x].mk += k;
}
void push_down(int x) {
	// cout << "hwfawf" << endl;
	if (t[x].mk) add(L, t[x].mk), add(R, t[x].mk), t[x].mk = 0;
	if (t[x].z) change(L, t[x].z), change(R, t[x].z);
}
void build(int x, int l, int r) {
	if (l == r) {
		t[x].z = read();
		t[x].x = calc(t[x].z);
		return;
	}
	int mid = l + r >> 1;
	build(L, l, mid);
	build(R, mid + 1, r);
	update(x);
}
void change(int x, int l, int r, int ql, int qr, ll k) {
	// cout << "change =" << endl;
	if (l == ql && r == qr)
		return change(x, k);
	int mid = l + r >> 1;
	push_down(x);
	if (qr <= mid) change(L, l, mid, ql, qr, k);
	else if (ql > mid) change(R, mid + 1, r, ql, qr, k);
	else change(L, l, mid, ql, mid, k), change(R, mid + 1, r, mid + 1, qr, k);
	update(x);
}
void solve(int x) {
	// cout << "solve" << endl;
	if (t[x].x >= 0) return;
	if (t[x].z) {
		t[x].x = calc(t[x].z);
		return;
	}
	push_down(x);
	solve(L);
	solve(R);
	update(x);
}
void add(int x, int l, int r, int ql, int qr, ll k) {
	// cout << x << " " << l << " " << r << " " << ql << " " << qr << " " << k << endl;
	if (l == ql && r == qr) {
		add(x, k);
		return solve(x);
	}
	int mid = l + r >> 1;
	push_down(x);
	if (qr <= mid) add(L, l, mid, ql, qr, k);
	else if (ql > mid) add(R, mid + 1, r, ql, qr, k);
	else add(L, l, mid, ql, mid, k), add(R, mid + 1, r, mid + 1, qr, k);
	update(x);
}
ll query(int x, int l, int r, int k) {
	if (t[x].z) return t[x].z;
	int mid = l + r >> 1;
	push_down(x);
	return k <= mid ? query(L, l, mid, k) : query(R, mid + 1, r, k);
}
int main(int argc, char const *argv[]) {
	int n = read(), q = read();
	for (int i = pw[0] = 1; i <= LG; i++)
		pw[i] = pw[i - 1] * 42;
	build(1, 1, n);
	// puts("no");
	while (q --) {
		int op = read();
		if (op == 1)
			printf("%lld\n", query(1, 1, n, read()));
		if (op == 2) {
			int l = read(), r = read(), x = read();
			change(1, 1, n, l, r, x);
		}
		if (op == 3) {
			int l = read(), r = read(), x = read();
			do add(1, 1, n, l, r, x);
			while (!t[1].x);
		}
	}
	return 0;
}