#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() {
	int x = 0, f = 1; char ch = getchar();
	for ( ; !isdigit(ch); ch = getchar()) {
		if (ch == '-') {
			f = -1;
		}
	}
	for ( ; isdigit(ch); ch = getchar()) {
		x = x * 10 + ch - '0';
	}
	return x * f;
}
const int N = 1e6 + 5, M = 21;
int n, las, ans, a[N], mn[M][N], mx[M][N];
int Qmin(int l, int r) {
	int c = (int)(log(r - l + 1) / log(2));
	return min(mn[c][l], mn[c][r - (1 << c) + 1]);
}
int Qmax(int l, int r) {
	int c = (int)(log(r - l + 1) / log(2));
	return max(mx[c][l], mx[c][r - (1 << c) + 1]);
}
int main() {
	n = read();
	memset(mn, 0x3f, sizeof mn);
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		mn[0][i] = mx[0][i] = a[i];
	}
	for (int j = 1; j < M; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (i + (1 << (j - 1)) > n) {
				break;
			}
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
			mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
		}
	}
	ans = las = 1;
	for (int i = 1; i < n; ++i) {
		if (Qmax(las, i) <= Qmin(i + 1, n)) {
			++ans, las = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}