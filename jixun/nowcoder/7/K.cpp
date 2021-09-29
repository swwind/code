#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

const int kMaxN = 200020;
const int kMaxNS = 200020 * 80;
const int kMaxB = 1 << 30;

int a[kMaxN];

int son[kMaxNS];
long long sum[kMaxNS];
int now;
int ls[kMaxNS], rs[kMaxNS];

int rt[2][kMaxN];
long long psum[kMaxN];

void insert(int &rt1, int rt2, int l, int r, int v) {
	rt1 = ++ now;
	son[rt1] = son[rt2] + 1;
	sum[rt1] = sum[rt2] + v;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	ls[rt1] = ls[rt2];
	rs[rt1] = rs[rt2];
	if (v <= mid) insert(ls[rt1], ls[rt2], l, mid, v);
	else insert(rs[rt1], rs[rt2], mid+1, r, v);
}

// 询问 [L, R] 区间内的 k
long long query(int rt1, int rt2, int l, int r, int k, int v) {
	if (!k) return 0;
	if (l == r) {
		return (long long) l * k;
	}
	int mid = (l + r) >> 1;
	int rson = son[rs[rt1]] - son[rs[rt2]] + (mid < v && v <= r);
	if (rson > k) {
		return query(rs[rt1], rs[rt2], mid+1, r, k, v);
	} else {
		return query(ls[rt1], ls[rt2], l, mid, k - rson, v) + sum[rs[rt1]] - sum[rs[rt2]] + (mid < v && v <= r) * v;
	}
}

// ask [l, r] answer with first s numbers
long long calculate(int l, int r, int k, int s) {
	long long ps = (psum[r] - psum[l] + a[l] + a[r]) >> 1;
	long long a1 = query(rt[0][r], rt[0][l], 0, kMaxB, s, a[l]);
	long long a2 = query(rt[1][r], rt[1][l], 0, kMaxB, s, a[r]);
	return ps - a1 - a2 + (long long) k * s;
}

long long binary_search(int L, int R, int k) {
	int l = 0, r = min(son[rt[0][R]] - son[rt[0][L]], son[rt[1][R]] - son[rt[1][L]]) + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (calculate(L, R, k, mid) > calculate(L, R, k, mid+1)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return calculate(L, R, k, l);
}

int main() {
	int n = read(), q = read();
	for (int i = 1; i <= n; ++ i) {
		a[i] = read();
	}

	for (int i = 1; i <= n; ++ i) {
		int b = abs(a[i] - a[i-1]);
		rt[0][i] = rt[0][i-1];
		rt[1][i] = rt[1][i-1];
		psum[i] = psum[i-1] + b;
		if (a[i] > a[i-1])
			insert(rt[0][i], rt[0][i-1], 0, kMaxB, b);
		else
			insert(rt[1][i], rt[1][i-1], 0, kMaxB, b);
	}

	while (q --) {
		int l = read();
		int r = read();
		int k = read();

		long long ans = binary_search(l, r, k);
		printf("%lld\n", ans);
	}
}