#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[4002][102][102][2], a[4002];
int n = read();
int solve(int l, int c, int k, int p) {
	int &res = f[l][c][k][p];
	if (~res) return res;
	int r = n - l - c + 1;
	if (!p) r += k;
	if (r - l + 1 < k) return res = 0;
	if (p) {
		res = solve(l + k, c, k, !p) + a[l + k - 1] - a[l - 1];
		if (r - l >= k)
			res = max(res, solve(l + k + 1, c, k + 1, !p) + a[l + k] - a[l - 1]);
	} else {
		res = solve(l, c, k, !p) - a[r] + a[r - k];
		if (r - l >= k)
			res = min(res, solve(l, c + 1, k + 1, !p) - a[r] + a[r - k - 1]);
	}
	return res;
}
int main(int argc, char const *argv[]) {
	// printf("%d\n", sizeof f);
	for (int i = 1; i <= n; i++)
		a[i] = read() + a[i - 1];
	memset(f, -1, sizeof f);
	printf("%d\n", solve(1, 0, 1, 1));
	return 0;
}
