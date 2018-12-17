#include <bits/stdc++.h>
#define N 30020
#define mod 1000000007
#define ll long long
#define update(a, b) a = (a + b % mod) % mod
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], sum[N], cnt, dp[N][120][2][2], c[120][120];
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (a[cnt] != x)
			a[++cnt] = x;
		sum[cnt]++;
	}
	for (int i = 1; i < cnt; i++)
		if (a[i] + 1 != a[i + 1])
			return puts("0") & 0;
	for (int i = 0; i <= 100; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	dp[1][sum[1] - 1][1][1] = 1;
	for (int i = 1; i < cnt; i++) {
		for (int j = 0; j <= sum[i]; j++) {
			for (int k = 0; k < 2; k++) {
				for (int s = 0; s < 2; s++) {
					if (!dp[i][j][k][s])
						continue;
					ll v = dp[i][j][k][s], x = j + k + s;
					if (k) update(dp[i + 1][sum[i + 1] - 1][1][0], v);
					if (s) update(dp[i + 1][sum[i + 1] - 1][0][1], v);
					update(dp[i + 1][sum[i + 1] - 1][0][0], j * v);
					for (int h = 1; h < x; h++) {
						ll t = v * c[sum[i + 1] - 1][h] % mod;
						if (h < j)  update(dp[i + 1][sum[i + 1] - 1 - h][0][0], t * c[j][h + 1]);
						if (k)      update(dp[i + 1][sum[i + 1] - 1 - h][1][0], t * c[j][h]);
						if (s)      update(dp[i + 1][sum[i + 1] - 1 - h][0][1], t * c[j][h]);
						if (k && s) update(dp[i + 1][sum[i + 1] - 1 - h][1][1], t * c[j][h - 1]);
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int j = 0; j <= 100; j++) {
		update(ans, dp[cnt][j][0][0]);
		update(ans, dp[cnt][j][0][1]);
		update(ans, dp[cnt][j][1][0]);
		update(ans, dp[cnt][j][1][1]);
	}
	printf("%lld\n", ans);
	return 0;
}