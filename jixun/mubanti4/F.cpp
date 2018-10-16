#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll f[N][22], a[N], lg[N], ans;
ll ask(int l, int r) {
	// printf("%d %d\n", l, r);
	int t = lg[r - l + 1];
	// printf("%lld\n", min(f[l][t], f[r - (1 << t) + 1][t]));
	return min(f[l][t], f[r - (1 << t) + 1][t]);
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = a[i + n] = read();
	for (int i = 1; i <= n*2; i++)
		f[i][0] = a[i] += a[i - 1];
	for (int i = 1; i < 22; i++)
		for (int j = 1; j <= n*2; j++) if (j + (1 << i - 1) <= n*2)
			f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i >> 1] + 1;
	for (int i = n + 1; i <= n*2; i++)
		ans = max(ans, a[i] - ask(i - n, i - 1));
	printf("%lld\n", ans);
	return 0;
}